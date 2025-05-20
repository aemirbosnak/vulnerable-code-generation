//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MIN_NUMBER 100
#define MAX_NUMBER 1000
#define MIN_SQUARE 100
#define MAX_SQUARE 10000
#define STEP 10

int main() {
    int num, square, sum = 0;
    char op;

    printf("Welcome to the C Math Exercise Program!\n");

    do {
        printf("Enter a number (%d-%d): ", MIN_NUMBER, MAX_NUMBER);
        scanf("%d", &num);

        if (num < MIN_NUMBER || num > MAX_NUMBER) {
            printf("Invalid input. Please enter a number between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);
            continue;
        }

        printf("Enter an operation (+, -, x, /): ");
        scanf(" %c", &op);

        if (op == '+') {
            square = num * num;
            sum += square;
        } else if (op == '-') {
            square = num * num;
            sum -= square;
        } else if (op == '*') {
            square = num * num;
            sum += square;
        } else if (op == '/') {
            square = num * num;
            sum -= square;
        } else {
            printf("Invalid operation. Please enter a valid operation (+, -, x, /).\n");
            continue;
        }

        printf("Your result is: %d\n", sum);
    } while (1);

    return 0;
}