//FormAI DATASET v1.0 Category: Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, result;
    char operation;

    printf("Welcome to my magical calculator! Please enter the first number:\n");
    scanf("%d", &num1);

    printf("Great! Now please enter the second number:\n");
    scanf("%d", &num2);

    printf("Awesome! Now please choose the operation you wish to perform: \n");
    printf("(+) Addition\n");
    printf("(-) Subtraction\n");
    printf("(*) Multiplication\n");
    printf("(/) Division\n");
    printf("(%%) Modulus\n");
    scanf(" %c", &operation);

    switch (operation) {
        case '+':
            result = num1 + num2;
            printf("The result of %d + %d is: %d", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("The result of %d - %d is: %d", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("The result of %d * %d is: %d", num1, num2, result);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by 0 is not allowed!");
                exit(0);
            } else {
                result = num1 / num2;
                printf("The result of %d / %d is: %d", num1, num2, result);
            }
            break;
        case '%':
            result = num1 % num2;
            printf("The result of %d %% %d is: %d", num1, num2, result);
            break;
        default:
            printf("Invalid operation selected! Please try again.");
            exit(0);
    }

    printf("\nThanks for using my magical calculator! Have a nice day :)");
    return 0;
}