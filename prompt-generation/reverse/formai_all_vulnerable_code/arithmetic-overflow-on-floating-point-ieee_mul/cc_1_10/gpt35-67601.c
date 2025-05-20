//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Ensure that the program is running as intended by displaying a message
    printf("This is a highly secure scientific calculator. Only authorized personnel should use this program.\n");

    // Ask for user input for the calculation type
    int calculation_type;
    printf("\nPlease select the type of calculation you would like to perform.\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Selection: ");
    scanf("%d", &calculation_type);

    // Check if user input is within acceptable range
    while (calculation_type < 1 || calculation_type > 4) {
        printf("\nInvalid selection. Please try again.\n");
        printf("Selection: ");
        scanf("%d", &calculation_type);
    }

    // Ask for user input for numbers to calculate
    double first_num, second_num;
    printf("\nPlease enter the first number: ");
    scanf("%lf", &first_num);
    printf("Please enter the second number: ");
    scanf("%lf", &second_num);

    // Perform the calculation based on user input and display the result
    double result;
    if (calculation_type == 1) {
        result = first_num + second_num;
        printf("\nResult: %.2lf\n", result);
    }
    if (calculation_type == 2) {
        result = first_num - second_num;
        printf("\nResult: %.2lf\n", result);
    }
    if (calculation_type == 3) {
        result = first_num * second_num;
        printf("\nResult: %.2lf\n", result);
    }
    if (calculation_type == 4) {
        // Check if the second number is 0 to avoid a divide-by-zero error
        if (second_num == 0) {
            printf("\nError: Cannot divide by 0.\n");
            exit(0);
        }
        result = first_num / second_num;
        printf("\nResult: %.2lf\n", result);
    }

    // Display a message to indicate the program is ending
    printf("\nThank you for using this highly secure scientific calculator.\n");

    // Ensure that the program ends as intended by returning 0
    return 0;
}