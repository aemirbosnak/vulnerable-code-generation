//FormAI DATASET v1.0 Category: Calculator ; Style: imaginative
#include<stdio.h>

/* This program is a calculator that performs basic arithmetic operations
   on two numbers input by the user. It has been modified with creative 
   additions to make it more fun and interesting. */

int main() {
    int num1, num2, result;
    char operator;

    printf("Welcome to the Fun Calculator 2.0!\n");
    printf("Enter two numbers to perform arithmetic operations on:\n");
    scanf("%d %d", &num1, &num2);

    printf("Enter an operator (+, -, *, / or %%):\n");
    scanf(" %c", &operator);

    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("The sum of %d and %d is %d! Fun-tastic!\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%d minus %d is %d! That's fun subtraction!\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("Wow, %d times %d is %d! Such multiplication fun!\n", num1, num2, result);
            break;
        case '/':
            if(num2 != 0) {
                result = num1 / num2;
                printf("%d divided by %d is %d! That's hilarious division!\n", num1, num2, result);
            } else {
                printf("Hey, you can't divide by zero! That's not funny!\n");
            }
            break;
        case '%':
            result = num1 % num2;
            printf("When you take %d and modulo it with %d, you get %d! Fun stuff!\n", num1, num2, result);
            break;
        default:
            printf("Invalid operator entered. Sorry, no fun for you.\n");
    }

    printf("Thanks for using the Fun Calculator 2.0! Have a fun-tastic day!\n");

    return 0;
}