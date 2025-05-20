//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char buffer[MAX_BUFFER_SIZE] = "";
    int index = 0;

    // Loop until the user enters a valid command or exits
    while (1)
    {
        printf("Enter a command: ");

        // Clear the buffer
        memset(buffer, 0, MAX_BUFFER_SIZE);

        // Get the user input
        fgets(buffer, MAX_BUFFER_SIZE, stdin);

        // Remove the newline character
        buffer[strcspn(buffer, "\n")] = '\0';

        // Check if the command is valid
        if (strcmp(buffer, "quit") == 0)
        {
            break;
        }
        else if (strcmp(buffer, "help") == 0)
        {
            printf("Available commands:\n");
            printf("  quit: Exit the program\n");
            printf("  help: Show this message\n");
            printf("  add: Add two numbers\n");
            printf("  subtract: Subtract two numbers\n");
            printf("  multiply: Multiply two numbers\n");
            printf("  divide: Divide two numbers\n");
        }
        else if (strcmp(buffer, "add") == 0)
        {
            double num1, num2;

            printf("Enter two numbers: ");

            // Get the first number
            scanf("%lf", &num1);

            // Get the second number
            scanf("%lf", &num2);

            // Calculate the sum
            double sum = num1 + num2;

            // Print the sum
            printf("The sum of the two numbers is: %.2lf\n", sum);
        }
        else if (strcmp(buffer, "subtract") == 0)
        {
            double num1, num2;

            printf("Enter two numbers: ");

            // Get the first number
            scanf("%lf", &num1);

            // Get the second number
            scanf("%lf", &num2);

            // Calculate the difference
            double difference = num1 - num2;

            // Print the difference
            printf("The difference of the two numbers is: %.2lf\n", difference);
        }
        else if (strcmp(buffer, "multiply") == 0)
        {
            double num1, num2;

            printf("Enter two numbers: ");

            // Get the first number
            scanf("%lf", &num1);

            // Get the second number
            scanf("%lf", &num2);

            // Calculate the product
            double product = num1 * num2;

            // Print the product
            printf("The product of the two numbers is: %.2lf\n", product);
        }
        else if (strcmp(buffer, "divide") == 0)
        {
            double num1, num2;

            printf("Enter two numbers: ");

            // Get the first number
            scanf("%lf", &num1);

            // Get the second number
            scanf("%lf", &num2);

            // Calculate the quotient
            double quotient = num1 / num2;

            // Print the quotient
            printf("The quotient of the two numbers is: %.2lf\n", quotient);
        }
        else
        {
            printf("Invalid command. Please try again.\n");
        }

        // Increment the index
        index++;
    }

    // Print a farewell message
    printf("Thank you for using the program. Goodbye!\n");

    return 0;
}