//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

void main() {
    char choice;
    double num1, num2, result;

    while (1) {
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 + num2;
                printf("The result is: %.2lf\n", result);
                break;

            case '2':
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 - num2;
                printf("The result is: %.2lf\n", result);
                break;

            case '3':
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 * num2;
                printf("The result is: %.2lf\n", result);
                break;

            case '4':
                if (num2 == 0) {
                    printf("Error! Division by zero is not allowed.\n");
                } else {
                    printf("Enter first number: ");
                    scanf("%lf", &num1);
                    printf("Enter second number: ");
                    scanf("%lf", &num2);
                    result = num1 / num2;
                    printf("The result is: %.2lf\n", result);
                }
                break;

            case '5':
                printf("Exiting the calculator...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}