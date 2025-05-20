//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function to print binary representation of a number
void printBinary(unsigned int num) {
    int i = 0;
    while (num > 0) {
        printf("%d", num & 1);
        num = num >> 1;
        i++;
        if (i == 8) {
            printf("\n");
            i = 0;
        }
    }
}

int main() {
    unsigned int num1, num2, result;

    // Get user input for two numbers
    printf("Enter first number: ");
    scanf("%u", &num1);
    printf("Enter second number: ");
    scanf("%u", &num2);

    // Perform bitwise operations
    result = num1 & num2;
    printf("Bitwise AND: ");
    printBinary(result);

    result = num1 | num2;
    printf("\nBitwise OR: ");
    printBinary(result);

    result = num1 ^ num2;
    printf("\nBitwise XOR: ");
    printBinary(result);

    result = num1 << 2;
    printf("\nBitwise left shift: ");
    printBinary(result);

    result = num1 >> 2;
    printf("\nBitwise right shift: ");
    printBinary(result);

    result = ~num1;
    printf("\nBitwise NOT: ");
    printBinary(result);

    return 0;
}