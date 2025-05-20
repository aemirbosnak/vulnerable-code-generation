//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PI 3.14159

int main() {
    int num1, num2, sum;
    char op;

    printf("Welcome to the C Math Exercise! \n");

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    if (op == '+') {
        sum = num1 + num2;
    } else if (op == '-') {
        sum = num1 - num2;
    } else if (op == '*') {
        sum = num1 * num2;
    } else if (op == '/') {
        if (num2 == 0) {
            printf("Error: cannot divide by zero! \n");
            return 1;
        }
        sum = num1 / num2;
    } else {
        printf("Invalid operation! \n");
        return 1;
    }

    printf("The result of %d %c %d is %d. \n", num1, op, num2, sum);

    // Add some randomness to the program
    srand(time(NULL));
    int random = rand() % 10;
    if (random == 0) {
        printf("Congratulations, you got a 0! \n");
    } else {
        printf("Better luck next time! \n");
    }

    return 0;
}