//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Function to print binary representation of a number
void printBinary(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        if (num & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

// Function to perform bitwise operations
void bitwiseOperations() {
    // Example of bitwise AND operation
    unsigned int num1 = 0b11010110;
    unsigned int num2 = 0b10101010;
    unsigned int result = num1 & num2;
    printf("Bitwise AND operation:\n");
    printBinary(num1);
    printBinary(num2);
    printBinary(result);

    // Example of bitwise OR operation
    num1 = 0b11010110;
    num2 = 0b10101010;
    result = num1 | num2;
    printf("Bitwise OR operation:\n");
    printBinary(num1);
    printBinary(num2);
    printBinary(result);

    // Example of bitwise XOR operation
    num1 = 0b11010110;
    num2 = 0b10101010;
    result = num1 ^ num2;
    printf("Bitwise XOR operation:\n");
    printBinary(num1);
    printBinary(num2);
    printBinary(result);

    // Example of left shift operation
    num1 = 0b11010110;
    num2 = 2;
    result = num1 << num2;
    printf("Left shift operation:\n");
    printBinary(num1);
    printf("%d << %d = ", num1, num2);
    printBinary(result);

    // Example of right shift operation
    num1 = 0b11010110;
    num2 = 2;
    result = num1 >> num2;
    printf("Right shift operation:\n");
    printBinary(num1);
    printf("%d >> %d = ", num1, num2);
    printBinary(result);
}

int main() {
    bitwiseOperations();
    return 0;
}