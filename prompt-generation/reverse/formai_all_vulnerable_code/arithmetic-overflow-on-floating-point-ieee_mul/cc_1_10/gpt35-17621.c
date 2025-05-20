//FormAI DATASET v1.0 Category: Math exercise ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x = 3.0;
    double y = 4.0;
    double z;

    z = sqrt(x * x + y * y);
    printf("The magnitude of the vector (%f, %f) is %f\n", x, y, z);

    double a = -5.7;
    double b = 3.4;
    double c = -2.1;
    double root1, root2;

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        printf("The equation has no real roots\n");
    }
    else {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("The roots of the equation %fx^2 + %fx + %f are %f and %f\n", a, b, c, root1, root2);
    }

    double angle_in_radians = 1.0;
    double sine, cosine, tangent;

    sine = sin(angle_in_radians);
    cosine = cos(angle_in_radians);
    tangent = tan(angle_in_radians);

    printf("The sine of %f radians is %f\n", angle_in_radians, sine);
    printf("The cosine of %f radians is %f\n", angle_in_radians, cosine);
    printf("The tangent of %f radians is %f\n", angle_in_radians, tangent);

    double degree = 30.0;

    double radian = degree * M_PI / 180.0;

    double sin_value = sin(radian);
    double cos_value = cos(radian);
    double tan_value = tan(radian);

    printf("%f degrees is %f radians\n", degree, radian);
    printf("The sine of %f radians is %f\n", radian, sin_value);
    printf("The cosine of %f radians is %f\n", radian, cos_value);
    printf("The tangent of %f radians is %f\n", radian, tan_value);

    double num1 = 10.0;
    double num2 = 5.0;

    double result = pow(num1, num2);

    printf("%f raised to the power of %f is %f\n", num1, num2, result);

    double logarithm = log(num1);

    printf("The natural logarithm of %f is %f\n", num1, logarithm);

    return 0;
}