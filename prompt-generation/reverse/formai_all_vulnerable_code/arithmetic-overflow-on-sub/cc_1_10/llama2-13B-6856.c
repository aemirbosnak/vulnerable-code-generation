//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 1000000
#define MIN_VALUE -1000000

int main() {
    int num1, num2, sum, diff, mult, div, mod;
    float avg, stddev, variance, mean;
    char operation;

    srand(time(NULL));

    printf("Welcome to the Arithmetic Statistics Program!\n");

    do {
        printf("Enter a number: ");
        scanf("%d", &num1);

        printf("Enter another number: ");
        scanf("%d", &num2);

        printf("Enter an operation (+, -, *, /, %): ");
        scanf(" %c", &operation);

        if (operation == '+') {
            sum = num1 + num2;
        } else if (operation == '-') {
            diff = num1 - num2;
        } else if (operation == '*') {
            mult = num1 * num2;
        } else if (operation == '/') {
            div = num1 / num2;
        } else if (operation == '%') {
            mod = num1 % num2;
        }

        printf("Result: %d\n", sum);

        printf("Avg: %f\n", (float)sum / 2);

        printf("Stddev: %f\n", sqrt(avg));

        printf("Variance: %f\n", (float)sum * (float)sum / 2);

        printf("Mean: %f\n", avg);

    } while (1);

    return 0;
}