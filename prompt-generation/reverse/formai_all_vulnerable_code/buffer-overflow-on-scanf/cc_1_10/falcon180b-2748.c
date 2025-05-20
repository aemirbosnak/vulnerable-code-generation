//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// function to print binary representation of a number
void printBinary(int num) {
    int i = 1;
    while (num > 0) {
        printf("%d", num & 1);
        num >>= 1;
        i++;
    }
    printf("\n");
}

// function to print decimal representation of a binary number
void printDecimal(int num) {
    int decimal = 0, power = 0;
    while (num > 0) {
        int bit = num & 1;
        decimal += bit * (int)pow(2, power);
        num >>= 1;
        power++;
    }
    printf("%d\n", decimal);
}

// function to perform bitwise operations
void bitwiseOperations(int num1, int num2) {
    printf("Bitwise operations:\n");
    printf("OR operation: ");
    printf("%d | %d = ", num1, num2);
    printf("%d\n", num1 | num2);

    printf("AND operation: ");
    printf("%d & %d = ", num1, num2);
    printf("%d\n", num1 & num2);

    printf("XOR operation: ");
    printf("%d ^ %d = ", num1, num2);
    printf("%d\n", num1 ^ num2);

    printf("Left shift operation: ");
    printf("%d << %d = ", num1, num2);
    printf("%d\n", num1 << num2);

    printf("Right shift operation: ");
    printf("%d >> %d = ", num1, num2);
    printf("%d\n", num1 >> num2);
}

// main function
int main() {
    int num1, num2;

    // taking input from user
    printf("Enter two integers:\n");
    scanf("%d %d", &num1, &num2);

    // printing binary representation of numbers
    printf("Binary representation of %d: ", num1);
    printBinary(num1);

    printf("Binary representation of %d: ", num2);
    printBinary(num2);

    // performing bitwise operations
    bitwiseOperations(num1, num2);

    return 0;
}