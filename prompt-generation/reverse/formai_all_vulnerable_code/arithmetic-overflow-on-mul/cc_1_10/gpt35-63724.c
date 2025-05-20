//FormAI DATASET v1.0 Category: Calculator ; Style: enthusiastic
// Welcome to the Calculator program!
// This is the perfect tool for all your mathematical needs!
// Let's get started!

#include <stdio.h>

int main() {

    int num1, num2, result, choice;

    printf("Welcome to the Calculator program!\n");
    printf("Please enter the first number: ");
    scanf("%d", &num1);

    printf("\nGreat! Now, enter the second number: ");
    scanf("%d", &num2);

    printf("\nWhat would you like to do with these numbers?\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\nYour choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1:
            result = num1 + num2;
            printf("\nThe answer is: %d\n", result);
            break;

        case 2:
            result = num1 - num2;
            printf("\nThe answer is: %d\n", result);
            break;

        case 3:
            result = num1 * num2;
            printf("\nThe answer is: %d\n", result);
            break;

        case 4:
            result = num1 / num2;
            printf("\nThe answer is: %d\n", result);
            break;

        default:
            printf("\nInvalid option! Please try again.\n");
            break;
    }

    printf("\nThank you for using our program!\n");
    printf("We hope to see you again soon!");

    return 0;
}