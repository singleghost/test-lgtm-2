#include<stdio.h>
int getConstant() {
	return 2;
}
void vulnerable() {
	unsigned left = 0xffffffff;
	unsigned right = getConstant();
	left += right;
	if(left < right) {
		printf("overflowed\n");
	}
	else {
		printf("not overflowed\n");
	}
}

unsigned nonVulnerable() {
	unsigned left = 0xffffffff;
	unsigned right = getConstant();
	left += right;
	return left;
}
int main() {
	vulnerable();
	printf("%x\n", nonVulnerable());
}

