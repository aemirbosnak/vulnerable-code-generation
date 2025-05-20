//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: unmistakable
#include <stdio.h>
#include <math.h>

// Function to calculate the area of a triangle
double triangle_area(double a, double b, double c) {
    double s = (a + b + c) / 2; // Calculate semiperimeter
    return sqrt(s * (s - a) * (s - b) * (s - c)); // Calculate area using Heron's formula
}

// Function to calculate the perimeter of a triangle
double triangle_perimeter(double a, double b, double c) {
    return a + b + c;
}

// Function to calculate the volume of a pyramid
double pyramid_volume(double base_area, double height) {
    return base_area * height / 3;
}

// Function to calculate the surface area of a pyramid
double pyramid_surface_area(double base_area, double height) {
    return (base_area * (sqrt(8 * base_area + 12 * height) - 6 * height)) / 6;
}

int main() {
    double side1, side2, side3, base1, base2, height, radius, area, perimeter, volume, surface_area;
    int choice;

    // Get user input for triangle
    printf("Enter the length of side 1: ");
    scanf("%lf", &side1);
    printf("Enter the length of side 2: ");
    scanf("%lf", &side2);
    printf("Enter the length of side 3: ");
    scanf("%lf", &side3);

    // Calculate area and perimeter of triangle
    area = triangle_area(side1, side2, side3);
    perimeter = triangle_perimeter(side1, side2, side3);

    // Display results
    printf("The area of the triangle is %.2lf\n", area);
    printf("The perimeter of the triangle is %.2lf\n", perimeter);

    // Get user input for pyramid
    printf("Enter the length of the base edge: ");
    scanf("%lf", &base1);
    printf("Enter the length of the base edge: ");
    scanf("%lf", &base2);
    printf("Enter the height: ");
    scanf("%lf", &height);

    // Calculate volume and surface area of pyramid
    volume = pyramid_volume(base1 * base2, height);
    surface_area = pyramid_surface_area(base1 * base2, height);

    // Display results
    printf("The volume of the pyramid is %.2lf\n", volume);
    printf("The surface area of the pyramid is %.2lf\n", surface_area);

    // Exit program
    printf("Press 1 to exit\n");
    scanf("%d", &choice);
    if (choice!= 1) {
        printf("Invalid choice\n");
    }
    return 0;
}