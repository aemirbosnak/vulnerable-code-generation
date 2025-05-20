//FormAI DATASET v1.0 Category: Calculator ; Style: happy
#include <stdio.h>

int main() {
    int num1, num2, sum, choice;

    printf("Hello there! I am a happy calculator!\n");
    printf("What operation would you like to perform?\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nGreat choice! Let's add some numbers.\n");
            printf("Please enter the first number: ");
            scanf("%d", &num1);
            printf("Please enter the second number: ");
            scanf("%d", &num2);
            sum = num1 + num2;
            printf("\nThe sum of %d and %d is %d.\n", num1, num2, sum);
            break;

        case 2:
            printf("\nSubtraction it is! Let's get started.\n");
            printf("Please enter the first number: ");
            scanf("%d", &num1);
            printf("Please enter the second number: ");
            scanf("%d", &num2);
            sum = num1 - num2;
            printf("\nThe difference of %d and %d is %d.\n", num1, num2, sum);
            break;

        case 3:
            printf("\nMultiplication it is! Here we go.\n");
            printf("Please enter the first number: ");
            scanf("%d", &num1);
            printf("Please enter the second number: ");
            scanf("%d", &num2);
            sum = num1 * num2;
            printf("\nThe product of %d and %d is %d.\n", num1, num2, sum);
            break;

        case 4:
            printf("\nDivision, huh? Let's see what we can do.\n");
            printf("Please enter the first number: ");
            scanf("%d", &num1);
            printf("Please enter the second number: ");
            scanf("%d", &num2);
            if(num2 == 0) {
                printf("\nOops! Division by zero is not possible.\n");
            } else {
                sum = num1 / num2;
                printf("\nThe quotient of %d and %d is %d.\n", num1, num2, sum);
            }
            break;

        default:
            printf("\nInvalid choice!\n");
    }

    printf("Thank you for using Happy Calculator! Have a great day!\n");

    return 0;
}