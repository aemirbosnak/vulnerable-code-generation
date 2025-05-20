//FormAI DATASET v1.0 Category: Arithmetic ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

int main() {
    // initialize variables
    int a = 5, b = 10, c = 15;
    float d = 2.5, e = 5.2, f = 7.8;
    double g = 9.6754, h = 8.2346, i = 6.9087;

    // perform arithmetic operations
    int sum = a + b + c;
    float product = d * e * f;
    double quotient = g / h / i;

    // display results
    printf("The sum of %d, %d, and %d is %d\n", a, b, c, sum);
    printf("The product of %f, %f, and %f is %f\n", d, e, f, product);
    printf("The quotient of %lf, %lf, and %lf is %lf\n", g, h, i, quotient);

    // generate random numbers
    int rand1 = rand() % 10;
    int rand2 = rand() % 10;

    // perform conditional operations
    if (rand1 > rand2) {
        printf("%d is greater than %d\n", rand1, rand2);
    } else if (rand2 > rand1) {
        printf("%d is greater than %d\n", rand2, rand1);
    } else {
        printf("The random numbers are equal\n");
    }

    // generate more random numbers
    int rand3 = rand() % 50;
    int rand4 = rand() % 50;

    // perform bitwise operations
    int bitwise_and = rand3 & rand4;
    int bitwise_or = rand3 | rand4;
    int bitwise_xor = rand3 ^ rand4;

    // display results
    printf("The bitwise AND of %d and %d is %d\n", rand3, rand4, bitwise_and);
    printf("The bitwise OR of %d and %d is %d\n", rand3, rand4, bitwise_or);
    printf("The bitwise XOR of %d and %d is %d\n", rand3, rand4, bitwise_xor);

    // perform more arithmetic operations
    float diff = e - d;
    double power = pow(h, 2);

    // display results
    printf("The difference between %f and %f is %f\n", e, d, diff);
    printf("%lf raised to the power of 2 is %lf\n", h, power);

    return 0;
}