//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Function to print binary representation of number
void printBinary(int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        if (num & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
}

// Function to perform bitwise operations on two numbers
void bitwiseOperations(int num1, int num2) {
    printf("\nBitwise operations:\n");
    printf("AND: ");
    printf("%d & %d = %d\n", num1, num2, num1 & num2);
    printf("OR: ");
    printf("%d | %d = %d\n", num1, num2, num1 | num2);
    printf("XOR: ");
    printf("%d ^ %d = %d\n", num1, num2, num1 ^ num2);
    printf("NOT: ");
    printf("%d = %d\n", num1, ~num1);
}

int main() {
    int num1, num2, choice;

    // Input two numbers
    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);

    // Print binary representation of numbers
    printf("\nBinary representation:\n");
    printf("num1: ");
    printBinary(num1);
    printf("\nnum2: ");
    printBinary(num2);

    // Perform bitwise operations
    printf("\nEnter choice of operation:\n1. AND\n2. OR\n3. XOR\n4. NOT\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bitwiseOperations(num1, num2);
            break;
        case 2:
            bitwiseOperations(num1, num2);
            break;
        case 3:
            bitwiseOperations(num1, num2);
            break;
        case 4:
            bitwiseOperations(num1, num2);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}