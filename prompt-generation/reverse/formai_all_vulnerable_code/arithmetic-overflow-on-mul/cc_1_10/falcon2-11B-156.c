//Falcon2-11B DATASET v1.0 Category: Educational ; Style: realistic
#include <stdio.h>

int add(int a, int b) {
	return a + b;
}

int subtract(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}

int divide(int a, int b) {
	if (b == 0) {
		printf("Error: Division by zero\n");
		return -1;
	}
	return a / b;
}

void print_result(int result) {
	printf("%d\n", result);
}

int main() {
	int num1, num2;

	printf("Enter two numbers: ");
	scanf("%d %d", &num1, &num2);

	int operation;
	printf("Enter an operation (+, -, *, /): ");
	scanf("%d", &operation);

	switch (operation) {
		case 1:
			print_result(add(num1, num2));
			break;
		case 2:
			print_result(subtract(num1, num2));
			break;
		case 3:
			print_result(multiply(num1, num2));
			break;
		case 4:
			print_result(divide(num1, num2));
			break;
		default:
			printf("Invalid operation\n");
	}

	return 0;
}