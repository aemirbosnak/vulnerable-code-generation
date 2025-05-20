//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}

int main() {
    float *num1 = malloc(sizeof(float));  // Dynamic allocation for first number
    float *num2 = malloc(sizeof(float));  // Dynamic allocation for second number
    char operator;
    char choice;

    if (num1 == NULL || num2 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    do {
        printf("Enter first number: ");
        scanf("%f", num1);
        clearInputBuffer();

        printf("Enter second number: ");
        scanf("%f", num2);
        clearInputBuffer();

        printf("Choose an operator (+, -, *, /): ");
        scanf("%c", &operator);
        clearInputBuffer();

        switch (operator) {
            case '+':
                printf("Result: %.2f + %.2f = %.2f\n", *num1, *num2, *num1 + *num2);
                break;
            case '-':
                printf("Result: %.2f - %.2f = %.2f\n", *num1, *num2, *num1 - *num2);
                break;
            case '*':
                printf("Result: %.2f * %.2f = %.2f\n", *num1, *num2, *num1 * *num2);
                break;
            case '/':
                if (*num2 != 0) {
                    printf("Result: %.2f / %.2f = %.2f\n", *num1, *num2, *num1 / *num2);
                } else {
                    printf("Error: Division by zero is not allowed.\n");
                }
                break;
            default:
                printf("Invalid operator. Please use +, -, * or /.\n");
                break;
        }

        printf("Do you want to perform another calculation? (y/n): ");
        scanf(" %c", &choice);
        clearInputBuffer();

    } while (choice == 'y' || choice == 'Y');

    free(num1); // Free the dynamically allocated memory
    free(num2); // Free the dynamically allocated memory

    printf("Thank you for using the simple calculator.\n");
    return 0;
}