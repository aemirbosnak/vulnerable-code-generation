//FormAI DATASET v1.0 Category: Math exercise ; Style: future-proof
// C math exercise example program
#include <stdio.h>
#include <math.h>

int main()
{
    int num1, num2, choice = 1;
    double result;

    while (choice != 0) {
        printf("Enter the first number: ");
        scanf("%d", &num1);

        printf("Enter the second number: ");
        scanf("%d", &num2);

        printf("\nChoose an operation to perform:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square root\n");
        printf("6. Modulus\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            result = num1 + num2;
            printf("%d + %d = %.2lf\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("%d - %d = %.2lf\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("%d * %d = %.2lf\n", num1, num2, result);
            break;
        case 4:
            if (num2 == 0) {
                printf("Cannot divide by zero.\n");
            }
            else {
                result = (double) num1 / num2;
                printf("%d / %d = %.2lf\n", num1, num2, result);
            }
            break;
        case 5:
            if (num1 < 0) {
                printf("Cannot calculate square root of negative number.\n");
            }
            else {
                result = sqrt(num1);
                printf("Square root of %d = %.2lf\n", num1, result);
            }
            break;
        case 6:
            result = num1 % num2;
            printf("%d %% %d = %.2lf\n", num1, num2, result);
            break;
        case 0:
            printf("Thank you for using the program.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
        getchar();
        printf("Press enter to continue..");
        getchar();
    }
    return 0;
}