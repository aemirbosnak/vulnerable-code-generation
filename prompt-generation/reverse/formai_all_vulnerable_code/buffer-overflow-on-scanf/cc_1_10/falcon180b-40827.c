//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Define variables
    int num1, num2, operation;
    char choice;

    // Loop until user decides to quit
    while (1) {
        // Generate random numbers
        num1 = rand() % 100;
        num2 = rand() % 100;

        // Print numbers and ask for operation
        printf("Numbers: %d and %d\n", num1, num2);
        printf("Enter operation (+, -, *, /): ");
        scanf("%c", &operation);

        // Perform operation and print result
        switch (operation) {
            case '+':
                printf("Result: %d\n", num1 + num2);
                break;
            case '-':
                printf("Result: %d\n", num1 - num2);
                break;
            case '*':
                printf("Result: %d\n", num1 * num2);
                break;
            case '/':
                if (num2 == 0) {
                    printf("Error: Division by zero\n");
                } else {
                    printf("Result: %d\n", num1 / num2);
                }
                break;
            default:
                printf("Error: Invalid operation\n");
        }

        // Ask if user wants to continue
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    return 0;
}