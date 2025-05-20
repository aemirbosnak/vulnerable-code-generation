//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265

typedef struct {
    int num1;
    int num2;
    int sum;
} Addition;

typedef struct {
    int num;
    int square;
} Square;

int main(void) {
    Addition addition;
    Square square;

    printf("Enter first number: ");
    scanf("%d", &addition.num1);

    printf("Enter second number: ");
    scanf("%d", &addition.num2);

    addition.sum = addition.num1 + addition.num2;

    printf("\nThe sum of %d and %d is %d\n", addition.num1, addition.num2, addition.sum);

    printf("Enter a number to find its square: ");
    scanf("%d", &square.num);

    square.square = square.num * square.num;

    printf("\nThe square of %d is %d\n", square.num, square.square);

    printf("\nCalculating PI with Monte Carlo Method...\n");

    int insideCircle = 0;
    int totalPoints = 100000;

    for (int i = 0; i < totalPoints; i++) {
        double x = (double) rand() / RAND_MAX;
        double y = (double) rand() / RAND_MAX;

        if (x * x + y * y <= 1) {
            insideCircle++;
        }
    }

    double piEstimation = (double) insideCircle / totalPoints * 4;

    printf("\nEstimated PI value: %.8f\n", piEstimation);

    printf("\nPeace out! :)\n");

    return EXIT_SUCCESS;
}