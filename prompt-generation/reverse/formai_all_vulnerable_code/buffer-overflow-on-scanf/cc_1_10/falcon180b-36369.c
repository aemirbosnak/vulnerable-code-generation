//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Function to print binary representation of a number
void printBinary(int num) {
    int i = 0;
    while (num > 0) {
        printf("%d", num & 1);
        num >>= 1;
    }
}

int main() {
    int num1, num2, choice;

    // Get user input for two numbers
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Display menu of bitwise operations
    printf("\nChoose an operation:\n");
    printf("1 - Bitwise AND\n");
    printf("2 - Bitwise OR\n");
    printf("3 - Bitwise XOR\n");
    printf("4 - Bitwise NOT\n");
    printf("5 - Left shift\n");
    printf("6 - Right shift\n");
    printf("7 - Bitwise complement\n");
    scanf("%d", &choice);

    // Perform selected operation and print results
    switch (choice) {
        case 1:
            printf("\nBitwise AND:\n");
            printf("%d AND %d = %d\n", num1, num2, num1 & num2);
            break;
        case 2:
            printf("\nBitwise OR:\n");
            printf("%d OR %d = %d\n", num1, num2, num1 | num2);
            break;
        case 3:
            printf("\nBitwise XOR:\n");
            printf("%d XOR %d = %d\n", num1, num2, num1 ^ num2);
            break;
        case 4:
            printf("\nBitwise NOT:\n");
            printf("%d NOT = %d\n", num1, ~num1);
            break;
        case 5:
            printf("\nLeft shift:\n");
            printf("%d left shifted by 2 = %d\n", num1, num1 << 2);
            break;
        case 6:
            printf("\nRight shift:\n");
            printf("%d right shifted by 2 = %d\n", num1, num1 >> 2);
            break;
        case 7:
            printf("\nBitwise complement:\n");
            printf("%d complement = %d\n", num1, ~num1);
            break;
        default:
            printf("\nInvalid choice!\n");
            break;
    }

    return 0;
}