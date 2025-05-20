//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main(void) {
    // Define some variables
    int a = 10;
    int b = 20;
    float c = 3.14;
    double d = 6.28;

    // Perform some arithmetic operations
    int sum = a + b;
    int difference = b - a;
    int product = a * b;
    int quotient = b / a;
    int remainder = b % a;
    float division = c / a;
    double power = pow(d, 2);
    double square_root = sqrt(d);

    // Print the results
    printf("The sum of %d and %d is %d\n", a, b, sum);
    printf("The difference of %d and %d is %d\n", b, a, difference);
    printf("The product of %d and %d is %d\n", a, b, product);
    printf("The quotient of %d and %d is %d\n", b, a, quotient);
    printf("The remainder of %d and %d is %d\n", b, a, remainder);
    printf("The division of %f and %d is %f\n", c, a, division);
    printf("The power of %f to the power of 2 is %f\n", d, power);
    printf("The square root of %f is %f\n", d, square_root);

    // Check the limits of the data types
    printf("The maximum value of an int is %d\n", INT_MAX);
    printf("The minimum value of an int is %d\n", INT_MIN);
    printf("The maximum value of a float is %f\n", FLT_MAX);
    printf("The minimum value of a float is %f\n", FLT_MIN);
    printf("The maximum value of a double is %f\n", DBL_MAX);
    printf("The minimum value of a double is %f\n", DBL_MIN);

    // Check the size of the data types
    printf("The size of an int is %zu bytes\n", sizeof(int));
    printf("The size of a float is %zu bytes\n", sizeof(float));
    printf("The size of a double is %zu bytes\n", sizeof(double));

    // Check if a number is odd or even
    if (a % 2 == 0) {
        printf("%d is even\n", a);
    } else {
        printf("%d is odd\n", a);
    }

    // Check if a number is prime
    bool is_prime = true;
    for (int i = 2; i <= a / 2; ++i) {
        if (a % i == 0) {
            is_prime = false;
            break;
        }
    }

    if (is_prime) {
        printf("%d is prime\n", a);
    } else {
        printf("%d is not prime\n", a);
    }

    return 0;
}