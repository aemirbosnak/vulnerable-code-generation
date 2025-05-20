//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Function to print binary representation of an integer
void printBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }

    char binary[33]; // Maximum 32 bits + terminating null character
    int i = 0;
    while (n > 0) {
        binary[i++] = (n & 1) + '0';
        n >>= 1;
    }
    binary[i] = '\0';
    printf("%s", binary);
}

int main() {
    int num1, num2, result;

    // Prompt user for input
    printf("Enter first integer: ");
    scanf("%d", &num1);
    printf("Enter second integer: ");
    scanf("%d", &num2);

    // Perform bitwise operations
    result = num1 & num2;
    printf("Bitwise AND: ");
    printBinary(result);

    result = num1 | num2;
    printf("Bitwise OR: ");
    printBinary(result);

    result = num1 ^ num2;
    printf("Bitwise XOR: ");
    printBinary(result);

    result = num1 << 2;
    printf("Bitwise left shift by 2: ");
    printBinary(result);

    result = num1 >> 2;
    printf("Bitwise right shift by 2: ");
    printBinary(result);

    result = ~num1;
    printf("Bitwise NOT: ");
    printBinary(result);

    // Clean up and exit
    return 0;
}