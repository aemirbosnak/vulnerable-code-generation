//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    // Define variables
    int a, b, c;
    float x, y, z;

    // Get input from user
    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("Enter three floating-point numbers: ");
    scanf("%f %f %f", &x, &y, &z);

    // Perform basic arithmetic operations
    int sum = a + b + c;
    int product = a * b * c;
    int difference = a - b - c;
    int quotient = a / b / c;
    int remainder = a % b % c;

    float sum_f = x + y + z;
    float product_f = x * y * z;
    float difference_f = x - y - z;
    float quotient_f = x / y / z;
    float remainder_f = fmod(x, y) / z;

    // Print the results
    printf("\nInteger results:\n");
    printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);
    printf("Difference: %d\n", difference);
    printf("Quotient: %d\n", quotient);
    printf("Remainder: %d\n", remainder);

    printf("\nFloating-point results:\n");
    printf("Sum: %.2f\n", sum_f);
    printf("Product: %.2f\n", product_f);
    printf("Difference: %.2f\n", difference_f);
    printf("Quotient: %.2f\n", quotient_f);
    printf("Remainder: %.2f\n", remainder_f);

    // Calculate the square root of each number
    float sqrt_a = sqrt(a);
    float sqrt_b = sqrt(b);
    float sqrt_c = sqrt(c);
    float sqrt_x = sqrt(x);
    float sqrt_y = sqrt(y);
    float sqrt_z = sqrt(z);

    // Print the square roots
    printf("\nSquare roots:\n");
    printf("Sqrt(a): %.2f\n", sqrt_a);
    printf("Sqrt(b): %.2f\n", sqrt_b);
    printf("Sqrt(c): %.2f\n", sqrt_c);
    printf("Sqrt(x): %.2f\n", sqrt_x);
    printf("Sqrt(y): %.2f\n", sqrt_y);
    printf("Sqrt(z): %.2f\n", sqrt_z);

    return 0;
}