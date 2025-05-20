//FormAI DATASET v1.0 Category: Arithmetic ; Style: creative
#include <stdio.h>

int main() {
    int num1, num2, result, choice;

    printf("Welcome to the Arithmetic Operations Program!\n");
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("Choose an operation:\n");
    printf("\t 1 - Addition\n");
    printf("\t 2 - Subtraction\n");
    printf("\t 3 - Multiplication\n");
    printf("\t 4 - Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = num1 + num2;
            printf("The sum of %d and %d is %d.\n", num1, num2, result);
            break;

        case 2:
            result = num1 - num2;
            printf("The difference between %d and %d is %d.\n", num1, num2, result);
            break;

        case 3:
            result = num1 * num2;
            printf("The product of %d and %d is %d.\n", num1, num2, result);
            break;

        case 4:
            if (num2 == 0) {
                printf("Error! Cannot divide by zero.\n");
            } else {
                result = num1 / num2;
                printf("%d divided by %d is %d.\n", num1, num2, result);
            }
            break;

        default:
            printf("Invalid choice! Please choose a number between 1 and 4.\n");
    }

    printf("Thank you for using the Arithmetic Operations Program!");

    return 0;
}