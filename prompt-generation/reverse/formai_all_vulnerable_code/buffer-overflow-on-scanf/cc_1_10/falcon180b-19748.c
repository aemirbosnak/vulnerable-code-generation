//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    // Declare variables
    int num1, num2, result;
    char choice;

    // Print menu
    printf("Welcome to the Bitwise Operations Game!\n");
    printf("Please choose an operation:\n");
    printf("A. AND\n");
    printf("B. OR\n");
    printf("C. XOR\n");
    printf("D. NOT\n");
    printf("E. Shift Left\n");
    printf("F. Shift Right\n");
    printf("G. Exit\n");

    // Get user input
    scanf("%c", &choice);

    // Perform operation based on user input
    switch (choice) {
        case 'A': // AND operation
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 & num2;
            printf("The result is: %d\n", result);
            break;
        case 'B': // OR operation
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 | num2;
            printf("The result is: %d\n", result);
            break;
        case 'C': // XOR operation
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 ^ num2;
            printf("The result is: %d\n", result);
            break;
        case 'D': // NOT operation
            printf("Enter a number:\n");
            scanf("%d", &num1);
            result = ~num1;
            printf("The result is: %d\n", result);
            break;
        case 'E': // Shift Left operation
            printf("Enter a number and the number of positions to shift:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 << num2;
            printf("The result is: %d\n", result);
            break;
        case 'F': // Shift Right operation
            printf("Enter a number and the number of positions to shift:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 >> num2;
            printf("The result is: %d\n", result);
            break;
        case 'G': // Exit program
            printf("Thank you for playing!\n");
            break;
        default: // Invalid input
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}