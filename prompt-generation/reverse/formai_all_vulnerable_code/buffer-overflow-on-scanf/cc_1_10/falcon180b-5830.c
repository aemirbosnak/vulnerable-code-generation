//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print binary representation of a number
void printBinary(unsigned int num) {
    for (int i = 0; i < 32; i++) {
        if (num & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
}

// Function to perform bitwise operations
void bitwiseOps(int choice, unsigned int num1, unsigned int num2) {
    unsigned int result;
    switch (choice) {
        case 1: // Bitwise AND
            result = num1 & num2;
            printf("\nBitwise AND: ");
            printBinary(result);
            break;
        case 2: // Bitwise OR
            result = num1 | num2;
            printf("\nBitwise OR: ");
            printBinary(result);
            break;
        case 3: // Bitwise XOR
            result = num1 ^ num2;
            printf("\nBitwise XOR: ");
            printBinary(result);
            break;
        case 4: // Bitwise NOT
            result = ~num1;
            printf("\nBitwise NOT: ");
            printBinary(result);
            break;
        case 5: // Left Shift
            result = num1 << num2;
            printf("\nLeft Shift: ");
            printBinary(result);
            break;
        case 6: // Right Shift
            result = num1 >> num2;
            printf("\nRight Shift: ");
            printBinary(result);
            break;
        default:
            printf("\nInvalid choice!");
    }
}

// Main function
int main() {
    unsigned int num1, num2;
    int choice;

    // Take input from user
    printf("\nEnter the first number: ");
    scanf("%u", &num1);
    printf("\nEnter the second number: ");
    scanf("%u", &num2);
    printf("\nEnter the choice of bitwise operation:\n1. Bitwise AND\n2. Bitwise OR\n3. Bitwise XOR\n4. Bitwise NOT\n5. Left Shift\n6. Right Shift\n");
    scanf("%d", &choice);

    // Perform bitwise operation
    bitwiseOps(choice, num1, num2);

    return 0;
}