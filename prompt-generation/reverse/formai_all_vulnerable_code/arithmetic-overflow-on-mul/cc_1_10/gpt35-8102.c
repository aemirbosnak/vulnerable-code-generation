//FormAI DATASET v1.0 Category: Calculator ; Style: creative
#include <stdio.h>

int main() {

    int num1, num2, option, result;

    printf("Welcome to the Calculator\n");

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("\nPlease select an operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &option);

    switch (option) {

        case 1:
            result = num1 + num2;
            printf("\n%d + %d = %d\n", num1, num2, result);
            break;

        case 2:
            result = num1 - num2;
            printf("\n%d - %d = %d\n", num1, num2, result);
            break;

        case 3:
            result = num1 * num2;
            printf("\n%d * %d = %d\n", num1, num2, result);
            break;

        case 4:
            if (num2 != 0) {
                result = num1 / num2;
                printf("\n%d / %d = %d\n", num1, num2, result);
            } else {
                printf("\nCannot divide by zero\n");
            }
            break;

        default:
            printf("\nInvalid option selected\n");
            break;
    }

    return 0;

}