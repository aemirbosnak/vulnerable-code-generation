//FormAI DATASET v1.0 Category: Math exercise ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    // Greetings!
    printf("Welcome to the high-energy C math exercise program!\n\n");

    // Instruction for user
    printf("Today we will be solving for the roots of a quadratic equation of the form ax^2 + bx + c = 0\n");

    // Initialize variables
    float a, b, c, discriminant, root1, root2;

    // Ask user for inputs
    printf("\nEnter the value of coefficient a: ");
    scanf("%f", &a);

    printf("\nEnter the value of coefficient b: ");
    scanf("%f", &b);

    printf("\nEnter the value of coefficient c: ");
    scanf("%f", &c);

    // Calculate discriminant
    discriminant = (b * b) - (4 * a * c);

    if (discriminant > 0) {
        // Calculate roots
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);

        // Print results
        printf("\nThe roots are real and different.\n");
        printf("\nRoot 1 = %.2f \nRoot 2 = %.2f", root1, root2);
    }
    else if (discriminant == 0) {
        // Calculate root
        root1 = -b / (2 * a);

        // Print result
        printf("\nThe roots are real and equal.\n");
        printf("\nRoot 1 = Root 2 = %.2f", root1);
    }
    else {
        // Calculate real and imaginary parts of roots
        float real_part = -b / (2 * a);
        float imaginary_part = sqrt(-discriminant) / (2 * a);

        // Print results
        printf("\nThe roots are complex and different.\n");
        printf("\nRoot 1 = %.2f + %.2fi \nRoot 2 = %.2f - %.2fi", real_part, imaginary_part, real_part, imaginary_part);
    }

    return 0;
}