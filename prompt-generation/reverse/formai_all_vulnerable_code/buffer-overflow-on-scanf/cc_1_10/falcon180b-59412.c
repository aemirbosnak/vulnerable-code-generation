//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, result;
    char operator;

    printf("Welcome to the Arithmetic Adventure!\n");
    printf("In this game, you will be given two numbers and an operator.\n");
    printf("Your task is to perform the operation and get the result.\n");
    printf("Are you ready? (y/n)\n");

    scanf("%c", &operator);

    if (operator == 'y' || operator == 'Y') {
        srand(time(NULL));
        num1 = rand() % 100;
        num2 = rand() % 100;

        switch(operator) {
            case '+':
                result = num1 + num2;
                printf("The result is %d.\n", result);
                break;
            case '-':
                result = num1 - num2;
                printf("The result is %d.\n", result);
                break;
            case '*':
                result = num1 * num2;
                printf("The result is %d.\n", result);
                break;
            case '/':
                if (num2 == 0) {
                    printf("Error: Division by zero.\n");
                } else {
                    result = num1 / num2;
                    printf("The result is %d.\n", result);
                }
                break;
            default:
                printf("Invalid operator.\n");
        }
    } else {
        printf("Exiting program...\n");
    }

    return 0;
}