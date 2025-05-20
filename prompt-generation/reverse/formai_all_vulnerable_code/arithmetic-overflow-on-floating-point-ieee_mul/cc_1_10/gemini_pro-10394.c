//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Define the variables
    int a = 10;
    int b = 5;
    float c = 3.14;
    double d = 6.28;

    // Perform arithmetic operations
    int sum = a + b;
    int difference = a - b;
    int product = a * b;
    int quotient = a / b;
    int remainder = a % b;

    float sum_float = c + d;
    float difference_float = c - d;
    float product_float = c * d;
    float quotient_float = c / d;

    double sum_double = d + d;
    double difference_double = d - d;
    double product_double = d * d;
    double quotient_double = d / d;

    // Print the results
    printf("Sum of a and b: %d\n", sum);
    printf("Difference of a and b: %d\n", difference);
    printf("Product of a and b: %d\n", product);
    printf("Quotient of a and b: %d\n", quotient);
    printf("Remainder of a and b: %d\n", remainder);

    printf("Sum of c and d: %f\n", sum_float);
    printf("Difference of c and d: %f\n", difference_float);
    printf("Product of c and d: %f\n", product_float);
    printf("Quotient of c and d: %f\n", quotient_float);

    printf("Sum of d and d: %lf\n", sum_double);
    printf("Difference of d and d: %lf\n", difference_double);
    printf("Product of d and d: %lf\n", product_double);
    printf("Quotient of d and d: %lf\n", quotient_double);

    // Perform some advanced arithmetic operations
    int power = pow(a, b);
    double square_root = sqrt(d);
    double absolute_value = fabs(d);
    double sine = sin(d);
    double cosine = cos(d);
    double tangent = tan(d);

    // Print the results
    printf("Power of a to the power of b: %d\n", power);
    printf("Square root of d: %f\n", square_root);
    printf("Absolute value of d: %f\n", absolute_value);
    printf("Sine of d: %f\n", sine);
    printf("Cosine of d: %f\n", cosine);
    printf("Tangent of d: %f\n", tangent);

    return 0;
}