//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INT 2147483647
#define MIN_INT -2147483648

int main() {
    int num1, num2, sum, difference, product, quotient, remainder;
    float frac1, frac2, sum_frac, diff_frac;
    double result;

    printf("Welcome to the Math Exercise Program!\n");

    // Exercise 1: Addition
    printf("Enter two integers: ");
    scanf("%d%d", &num1, &num2);
    sum = num1 + num2;
    printf("Sum: %d\n", sum);

    // Exercise 2: Subtraction
    printf("Enter two integers: ");
    scanf("%d%d", &num1, &num2);
    difference = num1 - num2;
    printf("Difference: %d\n", difference);

    // Exercise 3: Multiplication
    printf("Enter two integers: ");
    scanf("%d%d", &num1, &num2);
    product = num1 * num2;
    printf("Product: %d\n", product);

    // Exercise 4: Division
    printf("Enter two integers: ");
    scanf("%d%d", &num1, &num2);
    quotient = num1 / num2;
    remainder = num1 % num2;
    printf("Quotient: %d\nRemainder: %d\n", quotient, remainder);

    // Exercise 5: Fractions
    printf("Enter two fractions: ");
    scanf("%.2f%.2f", &frac1, &frac2);
    sum_frac = frac1 + frac2;
    diff_frac = frac1 - frac2;
    printf("Sum of fractions: %.2f\nDifference of fractions: %.2f\n", sum_frac, diff_frac);

    // Exercise 6: Decimals
    printf("Enter two decimals: ");
    scanf("%.2f%.2f", &frac1, &frac2);
    sum_frac = frac1 + frac2;
    diff_frac = frac1 - frac2;
    printf("Sum of decimals: %.2f\nDifference of decimals: %.2f\n", sum_frac, diff_frac);

    // Exercise 7: Double Precision
    printf("Enter a double precision number: ");
    scanf("%lf", &result);
    printf("Double precision result: %lf\n", result);

    return 0;
}