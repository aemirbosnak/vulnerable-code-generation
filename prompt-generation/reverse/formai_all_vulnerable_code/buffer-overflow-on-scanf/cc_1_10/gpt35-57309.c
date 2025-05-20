//FormAI DATASET v1.0 Category: Bitwise operations ; Style: calm
#include <stdio.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    int remainder;
    int binary = 0;
    int i = 1;

    while (decimal != 0) {
        remainder = decimal % 2;
        decimal /= 2;
        binary += remainder * i;
        i *= 10;
    }

    printf("Binary = %d\n", binary);
}

// Function to perform bitwise OR operation
void bitwiseOR(int a, int b) {
    int result = a | b;
    printf("%d | %d = %d\n", a, b, result);
    decimalToBinary(result);
}

// Function to perform bitwise AND operation
void bitwiseAND(int a, int b) {
    int result = a & b;
    printf("%d & %d = %d\n", a, b, result);
    decimalToBinary(result);
}

// Function to perform bitwise XOR operation
void bitwiseXOR(int a, int b) {
    int result = a ^ b;
    printf("%d ^ %d = %d\n", a, b, result);
    decimalToBinary(result);
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    bitwiseOR(num1, num2);
    printf("\n");

    bitwiseAND(num1, num2);
    printf("\n");

    bitwiseXOR(num1, num2);
    printf("\n");

    return 0;
}