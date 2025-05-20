//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: thoughtful
#include <stdio.h>
#include <math.h>

// Function to calculate area and perimeter of a circle
void circleCalculations(double radius) {
    double area = M_PI * radius * radius;
    double perimeter = 2 * M_PI * radius;

    printf("Circle:\n");
    printf("Radius: %.2f\n", radius);
    printf("Area: %.2f\n", area);
    printf("Perimeter: %.2f\n", perimeter);
}

// Function to calculate area and perimeter of a rectangle
void rectangleCalculations(double width, double height) {
    double area = width * height;
    double perimeter = 2 * (width + height);

    printf("Rectangle:\n");
    printf("Width: %.2f, Height: %.2f\n", width, height);
    printf("Area: %.2f\n", area);
    printf("Perimeter: %.2f\n", perimeter);
}

// Function to calculate area and perimeter of a triangle
void triangleCalculations(double base, double height) {
    double area = (base * height) / 2;
    double hypotenuse = sqrt((base * base) + (height * height));
    double perimeter = base + height + hypotenuse;

    printf("Triangle:\n");
    printf("Base: %.2f, Height: %.2f\n", base, height);
    printf("Area: %.2f\n", area);
    printf("Perimeter: %.2f\n", perimeter);
}

// Main function
int main() {
    int choice;
    
    printf("Geometric Calculations Program\n");
    printf("Select the shape you want to calculate:\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            double radius;
            printf("Enter the radius of the circle: ");
            scanf("%lf", &radius);
            circleCalculations(radius);
            break;
        }
        case 2: {
            double width, height;
            printf("Enter the width of the rectangle: ");
            scanf("%lf", &width);
            printf("Enter the height of the rectangle: ");
            scanf("%lf", &height);
            rectangleCalculations(width, height);
            break;
        }
        case 3: {
            double base, height;
            printf("Enter the base of the triangle: ");
            scanf("%lf", &base);
            printf("Enter the height of the triangle: ");
            scanf("%lf", &height);
            triangleCalculations(base, height);
            break;
        }
        default:
            printf("Invalid choice! Please select 1, 2, or 3.\n");
            break;
    }

    printf("Thank you for using the Geometric Calculations Program!\n");
    return 0;
}