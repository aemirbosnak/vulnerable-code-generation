//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    int num1, num2, result;
    char operator;

    printf("Welcome to the Funny Arithmetic Calculator!\n");
    printf("Please enter two numbers and an operator:\n");
    scanf("%d %c %d", &num1, &operator, &num2);

    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("The result is: %d\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("The result is: %d\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("The result is: %d\n", result);
            break;
        case '/':
            if(num2 == 0) {
                printf("Error: Division by zero is not allowed!\n");
            } else {
                result = num1 / num2;
                printf("The result is: %d\n", result);
            }
            break;
        default:
            printf("Error: Invalid operator!\n");
            break;
    }

    return 0;
}

/*
Sample Input/Output:
Welcome to the Funny Arithmetic Calculator!
Please enter two numbers and an operator:
5 + 3
The result is: 8

Please enter two numbers and an operator:
10 * 0
The result is: 0

Please enter two numbers and an operator:
7 / 0
Error: Division by zero is not allowed!

Please enter two numbers and an operator:
2 ^ 3
Error: Invalid operator!
*/