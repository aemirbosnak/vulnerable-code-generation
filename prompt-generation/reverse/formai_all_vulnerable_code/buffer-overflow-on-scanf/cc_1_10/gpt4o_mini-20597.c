//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: synchronous
#include <stdio.h>
#include <math.h>

// Function to calculate the area of a triangle
double triangle_area(double base, double height) {
    return 0.5 * base * height;
}

// Function to calculate the area of a square
double square_area(double side) {
    return side * side;
}

// Function to calculate the area of a circle
double circle_area(double radius) {
    return M_PI * radius * radius; // use M_PI for the value of π
}

int main() {
    int choice;
    double base, height, side, radius, area;

    printf("Geometry Area Calculator\n");
    printf("1. Triangle\n");
    printf("2. Square\n");
    printf("3. Circle\n");
    printf("Please choose a shape (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the base of the triangle: ");
            scanf("%lf", &base);
            printf("Enter the height of the triangle: ");
            scanf("%lf", &height);
            area = triangle_area(base, height);
            printf("The area of the triangle is: %.2f\n", area);
            break;

        case 2:
            printf("Enter the side of the square: ");
            scanf("%lf", &side);
            area = square_area(side);
            printf("The area of the square is: %.2f\n", area);
            break;

        case 3:
            printf("Enter the radius of the circle: ");
            scanf("%lf", &radius);
            area = circle_area(radius);
            printf("The area of the circle is: %.2f\n", area);
            break;

        default:
            printf("Invalid choice. Please run the program again and select a valid option.\n");
            break;
    }

    return 0;
}