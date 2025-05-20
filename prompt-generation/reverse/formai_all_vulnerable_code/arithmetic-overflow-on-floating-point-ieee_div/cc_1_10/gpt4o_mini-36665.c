//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: excited
#include <stdio.h>
#include <math.h>

void calculateRoots(float a, float b, float c) {
    float discriminant, root1, root2, realPart, imaginaryPart;

    // Calculate the discriminant
    discriminant = b * b - 4 * a * c;

    // Check if the roots are real or complex
    if (discriminant > 0) {
        printf("The roots are real and different.\n");
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Root 1 = %.2f\n", root1);
        printf("Root 2 = %.2f\n", root2);
    } else if (discriminant == 0) {
        printf("The roots are real and the same.\n");
        root1 = root2 = -b / (2 * a);
        printf("Root = %.2f\n", root1);
    } else {
        printf("The roots are complex and different.\n");
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Root 1 = %.2f + %.2fi\n", realPart, imaginaryPart);
        printf("Root 2 = %.2f - %.2fi\n", realPart, imaginaryPart);
    }
}

int main() {
    float a, b, c;

    printf("Welcome to the Quadratic Equation Solver! 🎉\n");
    printf("Let's find the roots of a quadratic equation of the form ax^2 + bx + c = 0\n");

    // Getting coefficients from user
    printf("Please enter the coefficient a (non-zero): ");
    scanf("%f", &a);
    
    // Ensure 'a' is not zero
    while (a == 0) {
        printf("Coefficient 'a' cannot be zero. Please enter a non-zero value for a: ");
        scanf("%f", &a);
    }
    
    printf("Please enter the coefficient b: ");
    scanf("%f", &b);
    
    printf("Please enter the coefficient c: ");
    scanf("%f", &c);

    printf("\nThank you!\nLet’s do some math magic with your coefficients: a = %.2f, b = %.2f, c = %.2f\n", a, b, c);
    printf("Calculating the roots...\n");
    calculateRoots(a, b, c);

    printf("\nThank you for using the Quadratic Equation Solver! Have a great day! 🌟\n");
    
    return 0;
}