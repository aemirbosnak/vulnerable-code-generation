//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Declare variables
    int a, b, c;
    float x, y, z;

    // Get input from the user
    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("Enter three floats: ");
    scanf("%f %f %f", &x, &y, &z);

    // Perform mathematical operations
    int sum = a + b + c;
    int product = a * b * c;
    int average = (a + b + c) / 3;
    float sumf = x + y + z;
    float productf = x * y * z;
    float averagef = (x + y + z) / 3;

    // Print the results
    printf("The sum of the integers is: %d\n", sum);
    printf("The product of the integers is: %d\n", product);
    printf("The average of the integers is: %d\n", average);
    printf("The sum of the floats is: %f\n", sumf);
    printf("The product of the floats is: %f\n", productf);
    printf("The average of the floats is: %f\n", averagef);

    // Calculate the square root of a number
    float number;
    printf("Enter a number to find its square root: ");
    scanf("%f", &number);
    float squareRoot = sqrt(number);
    printf("The square root of %f is: %f\n", number, squareRoot);

    // Calculate the sine of an angle
    float angle;
    printf("Enter an angle in degrees to find its sine: ");
    scanf("%f", &angle);
    float sine = sin(angle * M_PI / 180);
    printf("The sine of %f degrees is: %f\n", angle, sine);

    // Calculate the area of a triangle
    float base, height;
    printf("Enter the base and height of the triangle: ");
    scanf("%f %f", &base, &height);
    float area = 0.5 * base * height;
    printf("The area of the triangle is: %f\n", area);

    // Calculate the volume of a sphere
    float radius;
    printf("Enter the radius of the sphere: ");
    scanf("%f", &radius);
    float volume = (4.0 / 3.0) * M_PI * pow(radius, 3);
    printf("The volume of the sphere is: %f\n", volume);

    return 0;
}