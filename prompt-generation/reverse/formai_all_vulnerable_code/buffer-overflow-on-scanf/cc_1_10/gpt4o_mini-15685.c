//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: multivariable
#include <stdio.h>

#define MAX_BITS 8 // Define the maximum number of bits for the demonstration

// Function to print binary representation of an integer
void printBinary(int num) {
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

void bitwiseOperations(int num1, int num2) {
    int result;

    // Perform AND operation
    result = num1 & num2;
    printf("AND Operation: %d & %d = %d\n", num1, num2, result);
    printf("Binary: ");
    printBinary(result);

    // Perform OR operation
    result = num1 | num2;
    printf("OR Operation: %d | %d = %d\n", num1, num2, result);
    printf("Binary: ");
    printBinary(result);

    // Perform XOR operation
    result = num1 ^ num2;
    printf("XOR Operation: %d ^ %d = %d\n", num1, num2, result);
    printf("Binary: ");
    printBinary(result);

    // Perform NOT operation on num1
    result = ~num1;
    printf("NOT Operation: ~%d = %d\n", num1, result);
    printf("Binary: ");
    printBinary(result);

    // Perform NOT operation on num2
    result = ~num2;
    printf("NOT Operation: ~%d = %d\n", num2, result);
    printf("Binary: ");
    printBinary(result);

    // Perform left shift operation on num1
    result = num1 << 1;
    printf("Left Shift Operation: %d << 1 = %d\n", num1, result);
    printf("Binary: ");
    printBinary(result);

    // Perform left shift operation on num2
    result = num2 << 1;
    printf("Left Shift Operation: %d << 1 = %d\n", num2, result);
    printf("Binary: ");
    printBinary(result);

    // Perform right shift operation on num1
    result = num1 >> 1;
    printf("Right Shift Operation: %d >> 1 = %d\n", num1, result);
    printf("Binary: ");
    printBinary(result);

    // Perform right shift operation on num2
    result = num2 >> 1;
    printf("Right Shift Operation: %d >> 1 = %d\n", num2, result);
    printf("Binary: ");
    printBinary(result);
}

int main() {
    int number1, number2;

    printf("Enter two integers: ");
    scanf("%d %d", &number1, &number2);

    printf("You entered: %d and %d\n\n", number1, number2);
    printf("=== Bitwise Operations ===\n");
    bitwiseOperations(number1, number2);

    return 0;
}