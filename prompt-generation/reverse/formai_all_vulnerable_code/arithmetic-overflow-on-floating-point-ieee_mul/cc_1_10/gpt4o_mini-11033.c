//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void display_menu() {
    printf("\nWelcome to the Grateful Scientific Calculator!\n");
    printf("Please choose an operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Sine\n");
    printf("6. Cosine\n");
    printf("7. Tangent\n");
    printf("8. Logarithm (base 10)\n");
    printf("9. Exit\n");
}

void perform_calculation(int choice) {
    double num1, num2, result;

    switch (choice) {
        case 1:
            printf("You chose Addition. Please enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("Result: %.2lf\n", result);
            break;
        case 2:
            printf("You chose Subtraction. Please enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("Result: %.2lf\n", result);
            break;
        case 3:
            printf("You chose Multiplication. Please enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("Result: %.2lf\n", result);
            break;
        case 4:
            printf("You chose Division. Please enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result: %.2lf\n", result);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        case 5:
            printf("You chose Sine. Please enter an angle in degrees: ");
            scanf("%lf", &num1);
            result = sin(num1 * M_PI / 180); // Convert to radians
            printf("Result: %.2lf\n", result);
            break;
        case 6:
            printf("You chose Cosine. Please enter an angle in degrees: ");
            scanf("%lf", &num1);
            result = cos(num1 * M_PI / 180); // Convert to radians
            printf("Result: %.2lf\n", result);
            break;
        case 7:
            printf("You chose Tangent. Please enter an angle in degrees: ");
            scanf("%lf", &num1);
            result = tan(num1 * M_PI / 180); // Convert to radians
            printf("Result: %.2lf\n", result);
            break;
        case 8:
            printf("You chose Logarithm. Please enter a positive number: ");
            scanf("%lf", &num1);
            if (num1 > 0) {
                result = log10(num1);
                printf("Result: %.2lf\n", result);
            } else {
                printf("Error: Logarithm of non-positive numbers is undefined.\n");
            }
            break;
        case 9:
            printf("Thank you for using the Grateful Scientific Calculator! Goodbye!\n");
            exit(0);
            break;
        default:
            printf("Invalid choice! Please select a valid operation.\n");
    }
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice (1-9): ");
        scanf("%d", &choice);
        perform_calculation(choice);
    }

    return 0;
}