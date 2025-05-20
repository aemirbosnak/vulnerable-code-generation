//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100
#define MAX_SQUARE 1000

int main() {
    int num, square, sum = 0;
    char op;

    srand(time(NULL));

    printf("Welcome to the Dynamic Math Game!\n");

    while (1) {
        printf("Enter a number: ");
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        op = '+';
        square = num * num;

        sum = num + square;

        printf("Your current score is %d\n", sum);

        if (sum % 2 == 0) {
            op = '*';
            square = sum / 2;
            sum = sum + square;
            printf("You got a bonus of %d\n", square);
        }

        if (sum > MAX_SQUARE) {
            printf("Oops! You exceeded the maximum square of %d\n", MAX_SQUARE);
            break;
        }

        if (op == '+') {
            printf("Your next operation is +%c\n", op);
        } else {
            printf("Your next operation is %c\n", op);
        }
    }

    printf("Your final score is %d\n", sum);

    return 0;
}