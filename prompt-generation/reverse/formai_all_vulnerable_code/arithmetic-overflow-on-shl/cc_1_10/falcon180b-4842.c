//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Ada Lovelace style C program to perform bitwise operations

int main() {
    int num1, num2;
    int choice, i;

    // Ada Lovelace style C program to perform bitwise operations

    // Display menu
    printf("\nAda Lovelace Bitwise Operations Program\n");
    printf("----------------------------------------\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Bitwise Left Shift\n");
    printf("6. Bitwise Right Shift\n");
    printf("7. Exit\n");

    // Get user choice
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    // Ada Lovelace style C program to perform bitwise operations

    switch (choice) {
        case 1:
            // Bitwise AND operation
            printf("\nEnter two numbers for Bitwise AND operation:\n");
            scanf("%d %d", &num1, &num2);
            printf("Bitwise AND of %d and %d is %d\n", num1, num2, num1 & num2);
            break;

        case 2:
            // Bitwise OR operation
            printf("\nEnter two numbers for Bitwise OR operation:\n");
            scanf("%d %d", &num1, &num2);
            printf("Bitwise OR of %d and %d is %d\n", num1, num2, num1 | num2);
            break;

        case 3:
            // Bitwise XOR operation
            printf("\nEnter two numbers for Bitwise XOR operation:\n");
            scanf("%d %d", &num1, &num2);
            printf("Bitwise XOR of %d and %d is %d\n", num1, num2, num1 ^ num2);
            break;

        case 4:
            // Bitwise NOT operation
            printf("\nEnter a number for Bitwise NOT operation:\n");
            scanf("%d", &num1);
            printf("Bitwise NOT of %d is %d\n", num1, ~num1);
            break;

        case 5:
            // Bitwise Left Shift operation
            printf("\nEnter a number and a shift value for Bitwise Left Shift operation:\n");
            scanf("%d %d", &num1, &i);
            printf("Bitwise Left Shift of %d by %d is %d\n", num1, i, num1 << i);
            break;

        case 6:
            // Bitwise Right Shift operation
            printf("\nEnter a number and a shift value for Bitwise Right Shift operation:\n");
            scanf("%d %d", &num1, &i);
            printf("Bitwise Right Shift of %d by %d is %d\n", num1, i, num1 >> i);
            break;

        case 7:
            printf("\nExiting Ada Lovelace Bitwise Operations Program...\n");
            exit(0);

        default:
            printf("\nInvalid choice! Please enter a valid choice.\n");
    }

    return 0;
}