//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, result, choice;
    char operation;

    // Prompt user to enter first number
    printf("Enter first number: ");
    scanf("%d", &num1);

    // Prompt user to enter second number
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Prompt user to enter arithmetic operation
    printf("Enter arithmetic operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform arithmetic operation based on user input
    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            // Check for division by zero
            if (num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
                exit(1);
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid arithmetic operation.\n");
            exit(1);
    }

    // Prompt user to choose whether to continue or exit
    printf("Do you want to continue? (y/n): ");
    scanf(" %c", &choice);

    // Continue program if user chooses to continue, otherwise exit
    while (choice == 'y' || choice == 'Y') {
        // Repeat program from beginning
        main();
    }

    return 0;
}