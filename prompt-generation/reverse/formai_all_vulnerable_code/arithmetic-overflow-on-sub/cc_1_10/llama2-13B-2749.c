//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100
#define MIN_NUM 1

int main() {
    int num1, num2, sum;
    char operation;

    printf("Welcome to the Surprising Math Game! \n");

    do {
        printf("Enter a number: ");
        scanf("%d", &num1);

        printf("Enter another number: ");
        scanf("%d", &num2);

        printf("Enter an operation (+, -, *, /): ");
        scanf(" %c", &operation);

        if (operation == '+') {
            sum = num1 + num2;
            printf("The sum of %d and %d is %d! \n", num1, num2, sum);
        } else if (operation == '-') {
            sum = num1 - num2;
            printf("The difference of %d and %d is %d! \n", num1, num2, sum);
        } else if (operation == '*') {
            sum = num1 * num2;
            printf("The product of %d and %d is %d! \n", num1, num2, sum);
        } else if (operation == '/') {
            if (num2 == 0) {
                printf("Oops! Division by zero! \n");
            } else {
                sum = num1 / num2;
                printf("The quotient of %d and %d is %d! \n", num1, num2, sum);
            }
        } else {
            printf("Invalid operation! \n");
        }

        printf("Do you want to play again? (y/n): ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'y') {
            continue;
        } else {
            break;
        }

    } while (1);

    return 0;
}