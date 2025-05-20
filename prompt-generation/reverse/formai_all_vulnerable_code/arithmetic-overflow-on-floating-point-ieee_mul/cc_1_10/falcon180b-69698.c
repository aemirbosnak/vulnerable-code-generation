//Falcon-180B DATASET v1.0 Category: Educational ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a function to calculate the area of a circle
double calculateCircleArea(double radius) {
    return M_PI * radius * radius;
}

// Define a function to calculate the area of a rectangle
double calculateRectangleArea(double width, double height) {
    return width * height;
}

// Define a function to calculate the area of a triangle
double calculateTriangleArea(double base, double height) {
    return 0.5 * base * height;
}

// Define a function to calculate the perimeter of a circle
double calculateCirclePerimeter(double radius) {
    return 2 * M_PI * radius;
}

// Define a function to calculate the perimeter of a rectangle
double calculateRectanglePerimeter(double width, double height) {
    return 2 * (width + height);
}

// Define a function to calculate the perimeter of a triangle
double calculateTrianglePerimeter(double a, double b, double c) {
    return a + b + c;
}

int main() {
    int choice;
    double radius, width, height, base, side1, side2, side3, area, perimeter;

    // Display menu
    printf("Please choose a shape:\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    scanf("%d", &choice);

    // Calculate area and perimeter based on user choice
    switch (choice) {
        case 1:
            // Circle
            printf("Enter the radius of the circle: ");
            scanf("%lf", &radius);
            area = calculateCircleArea(radius);
            perimeter = calculateCirclePerimeter(radius);
            printf("The area of the circle is %.2lf\n", area);
            printf("The perimeter of the circle is %.2lf\n", perimeter);
            break;
        case 2:
            // Rectangle
            printf("Enter the width of the rectangle: ");
            scanf("%lf", &width);
            printf("Enter the height of the rectangle: ");
            scanf("%lf", &height);
            area = calculateRectangleArea(width, height);
            perimeter = calculateRectanglePerimeter(width, height);
            printf("The area of the rectangle is %.2lf\n", area);
            printf("The perimeter of the rectangle is %.2lf\n", perimeter);
            break;
        case 3:
            // Triangle
            printf("Enter the base of the triangle: ");
            scanf("%lf", &base);
            printf("Enter the height of the triangle: ");
            scanf("%lf", &height);
            area = calculateTriangleArea(base, height);
            perimeter = calculateTrianglePerimeter(base, height, height);
            printf("The area of the triangle is %.2lf\n", area);
            printf("The perimeter of the triangle is %.2lf\n", perimeter);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}