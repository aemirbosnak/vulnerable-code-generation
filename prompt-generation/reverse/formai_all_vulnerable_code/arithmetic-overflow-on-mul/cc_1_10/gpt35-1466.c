//FormAI DATASET v1.0 Category: Calculator ; Style: excited
#include <stdio.h>

int main() {

    printf("Welcome to the Exciting Calculator Program!\n");
    printf("This calculator can add, subtract, multiply, and divide numbers!\n\n");

    int choice, num1, num2, result;

    printf("Please select the operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter two numbers to add:\n");
                printf("Number 1: ");
                scanf("%d", &num1);
                printf("Number 2: ");
                scanf("%d", &num2);
                result = num1 + num2;
                printf("The sum of %d and %d is %d.\n", num1, num2, result);
                break;

            case 2:
                printf("Enter two numbers to subtract:\n");
                printf("Number 1: ");
                scanf("%d", &num1);
                printf("Number 2: ");
                scanf("%d", &num2);
                result = num1 - num2;
                printf("The difference between %d and %d is %d.\n", num1, num2, result);
                break;

            case 3:
                printf("Enter two numbers to multiply:\n");
                printf("Number 1: ");
                scanf("%d", &num1);
                printf("Number 2: ");
                scanf("%d", &num2);
                result = num1 * num2;
                printf("%d multiplied by %d is %d.\n", num1, num2, result);
                break;

            case 4:
                printf("Enter two numbers to divide:\n");
                printf("Number 1: ");
                scanf("%d", &num1);
                printf("Number 2: ");
                scanf("%d", &num2);
                if(num2 == 0) {
                    printf("Error: Cannot divide by 0.\n");
                } else {
                    result = num1 / num2;
                    printf("%d divided by %d is %d.\n", num1, num2, result);
                }
                break;

            case 5:
                printf("Exiting the calculator program! Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a number from 1 to 5.\n");
                break;
        }

    } while(choice != 5);

    return 0;
}