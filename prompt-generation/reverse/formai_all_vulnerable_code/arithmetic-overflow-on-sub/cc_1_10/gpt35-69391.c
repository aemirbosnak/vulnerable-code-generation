//FormAI DATASET v1.0 Category: Math exercise ; Style: future-proof
#include <stdio.h>
#include <math.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // calculate the square root of the number
    double squareRoot = sqrt(num);

    // check if the number is a perfect square
    if (squareRoot == (int)squareRoot) {
        printf("%d is a perfect square\n", num);
    } else {
        printf("%d is not a perfect square\n", num);

        // find the nearest perfect square
        int lowerSqrt = (int)squareRoot;
        int higherSqrt = lowerSqrt + 1;
        int lowerDifference = num - (lowerSqrt * lowerSqrt);
        int higherDifference = (higherSqrt * higherSqrt) - num;

        int nearestSquare;
        if (lowerDifference <= higherDifference) {
            nearestSquare = lowerSqrt * lowerSqrt;
        } else {
            nearestSquare = higherSqrt * higherSqrt;
        }
        printf("The nearest perfect square is %d\n", nearestSquare);

        // find the square root of the nearest perfect square
        double nearestSquareRoot = sqrt(nearestSquare);
        printf("Its square root is %lf\n", nearestSquareRoot);

        // find the difference between the actual number and the nearest perfect square
        int difference = nearestSquare - num;
        printf("The difference between %d and %d is %d\n", num, nearestSquare, difference);

        // find the square root of the difference
        double differenceRoot = sqrt(difference);
        printf("The square root of the difference is %lf\n", differenceRoot);

        // calculate the sum of the square root of the nearest perfect square and the square root of the difference
        double sum = nearestSquareRoot + differenceRoot;
        printf("The sum of the square root of the nearest perfect square and the square root of the difference is %lf\n", sum);
    }

    return 0;
}