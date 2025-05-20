//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 50

int main() {
    int num1, num2, sum;
    char input[MAX_INPUT_SIZE];

    printf("Welcome to Grateful Turtle Calculator!\n");
    printf("This calculator will be grateful when you make mistakes!\n");

    while (1) {
        printf("Enter the first number: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Oops! It seems you pressed Ctrl+C. Let me try again.\n");
            continue;
        }

        sum = 0;
        sscanf(input, "%d", &num1);

        if (sscanf(input, "%d%n", &num1, &input[0]) != 1) {
            printf("Thanks for your input, but it seems you didn't enter a valid number. I'll help you out.\n");
            printf("Let's try that again: Enter the first number: ");
            fgets(input, sizeof(input), stdin);
            continue;
        }

        printf("Enter the second number: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Oh dear! It looks like you pressed Enter before entering the second number. Let me help you.\n");
            printf("Enter the second number: ");
            fgets(input, sizeof(input), stdin);
            continue;
        }

        sum = num1;
        sscanf(input, "%d%n", &num2, &input[0]);

        if (sscanf(input, "%d%n", &num2, &input[0]) != 1) {
            printf("Thanks for trying to enter the second number, but it seems you didn't enter a valid number. Let me help you.\n");
            printf("Let's try that again: Enter the second number: ");
            fgets(input, sizeof(input), stdin);
            continue;
        }

        sum += num2;
        printf("The sum of %d and %d is %d.\n", num1, num2, sum);
        printf("Is there anything else I can help you with? (Enter 'y' for yes, 'n' for no): ");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "y\n") == 0) {
            continue;
        } else if (strcmp(input, "n\n") != 0) {
            printf("Thanks for using Grateful Turtle Calculator! Have a wonderful day!\n");
            break;
        }
    }

    return 0;
}