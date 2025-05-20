//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: light-weight
#include <stdio.h>
#include <math.h>

int main() {
    // Define constants
    const double PI = 3.14159265358979323846;
    const double E = 2.71828182845904523536;

    // Declare variables
    double x, y, z;

    // Get input from the user
    printf("Enter a value for x: ");
    scanf("%lf", &x);
    printf("Enter a value for y: ");
    scanf("%lf", &y);

    // Perform mathematical operations
    z = sin(x) + cos(y);
    printf("The result of sin(%lf) + cos(%lf) is: %lf\n", x, y, z);

    z = pow(E, x);
    printf("The result of e^%lf is: %lf\n", x, z);

    z = log(y);
    printf("The result of ln(%lf) is: %lf\n", y, z);

    z = sqrt(x);
    printf("The result of sqrt(%lf) is: %lf\n", x, z);

    z = fabs(x);
    printf("The result of fabs(%lf) is: %lf\n", x, z);

    z = ceil(x);
    printf("The result of ceil(%lf) is: %lf\n", x, z);

    z = floor(x);
    printf("The result of floor(%lf) is: %lf\n", x, z);

    z = round(x);
    printf("The result of round(%lf) is: %lf\n", x, z);

    z = fmod(x, y);
    printf("The result of fmod(%lf, %lf) is: %lf\n", x, y, z);

    z = hypot(x, y);
    printf("The result of hypot(%lf, %lf) is: %lf\n", x, y, z);

    return 0;
}