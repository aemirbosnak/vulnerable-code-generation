//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Define constants
    const double PI = 3.141592653589793;
    const double E = 2.718281828459045;

    // Define variables
    double x, y, z;
    int i, j, k;

    // Get input from the user
    printf("Enter a value for x: ");
    scanf("%lf", &x);
    printf("Enter a value for y: ");
    scanf("%lf", &y);
    printf("Enter a value for z: ");
    scanf("%lf", &z);

    // Calculate the sine of x
    double sine_x = sin(x);

    // Calculate the cosine of y
    double cosine_y = cos(y);

    // Calculate the tangent of z
    double tangent_z = tan(z);

    // Calculate the exponential of x
    double exponential_x = exp(x);

    // Calculate the logarithm of y
    double logarithm_y = log(y);

    // Calculate the square root of z
    double square_root_z = sqrt(z);

    // Calculate the absolute value of x
    double absolute_value_x = fabs(x);

    // Calculate the ceiling of y
    double ceiling_y = ceil(y);

    // Calculate the floor of z
    double floor_z = floor(z);

    // Print the results
    printf("The sine of x is: %lf\n", sine_x);
    printf("The cosine of y is: %lf\n", cosine_y);
    printf("The tangent of z is: %lf\n", tangent_z);
    printf("The exponential of x is: %lf\n", exponential_x);
    printf("The logarithm of y is: %lf\n", logarithm_y);
    printf("The square root of z is: %lf\n", square_root_z);
    printf("The absolute value of x is: %lf\n", absolute_value_x);
    printf("The ceiling of y is: %lf\n", ceiling_y);
    printf("The floor of z is: %lf\n", floor_z);

    return 0;
}