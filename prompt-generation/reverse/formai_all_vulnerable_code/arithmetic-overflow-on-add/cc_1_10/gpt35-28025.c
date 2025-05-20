//FormAI DATASET v1.0 Category: Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Welcome message to the user
    printf("Welcome to the Super Calculator!\n");

    int choice; // Stores the user's menu choice
    int num1, num2; // Stores the user's numbers
    float result; // Stores the result of any calculation

    // Loop until the user decides to quit
    while(1) {

        // Display the menu options
        printf("\nWhat would you like to do?\n");
        printf("1. Add two numbers\n");
        printf("2. Subtract two numbers\n");
        printf("3. Multiply two numbers\n");
        printf("4. Divide two numbers\n");
        printf("5. Exit the program\n");

        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected operation
        switch(choice) {
            case 1:
                // Get the user's numbers
                printf("Enter the first number: ");
                scanf("%d", &num1);
                printf("Enter the second number: ");
                scanf("%d", &num2);
                // Add the numbers
                result = num1 + num2;
                // Display the result
                printf("%d + %d = %.2f\n", num1, num2, result);
                break;

            case 2:
                // Get the user's numbers
                printf("Enter the first number: ");
                scanf("%d", &num1);
                printf("Enter the second number: ");
                scanf("%d", &num2);
                // Subtract the numbers
                result = num1 - num2;
                // Display the result
                printf("%d - %d = %.2f\n", num1, num2, result);
                break;

            case 3:
                // Get the user's numbers
                printf("Enter the first number: ");
                scanf("%d", &num1);
                printf("Enter the second number: ");
                scanf("%d", &num2);
                // Multiply the numbers
                result = num1 * num2;
                // Display the result
                printf("%d * %d = %.2f\n", num1, num2, result);
                break;

            case 4:
                // Get the user's numbers
                printf("Enter the first number: ");
                scanf("%d", &num1);
                printf("Enter the second number: ");
                scanf("%d", &num2);
                // Divide the numbers
                result = (float)num1 / num2;
                // Display the result
                if (num2 == 0) {
                    printf("Error: cannot divide by zero!\n");
                } else {
                    printf("%d / %d = %.2f\n", num1, num2, result);
                }
                break;

            case 5:
                // Exit the program
                printf("Goodbye!\n");
                exit(0);
                break;

            default:
                // Invalid choice
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}