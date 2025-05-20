//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include <stdio.h>
#include <math.h>

// Function prototypes
void calculateCircle();
void calculateRectangle();
void calculateTriangle();

int main() {
    int choice;

    // Menu for shape selection
    while (1) {
        printf("\nGeometric Shape Calculator\n");
        printf("1. Circle\n");
        printf("2. Rectangle\n");
        printf("3. Triangle\n");
        printf("4. Exit\n");
        printf("Select a shape to calculate (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculateCircle();
                break;
            case 2:
                calculateRectangle();
                break;
            case 3:
                calculateTriangle();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}

// Function to calculate the area and perimeter of a circle
void calculateCircle() {
    double radius, area, circumference;

    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    // Calculate area and circumference
    area = M_PI * radius * radius; // Area = πr²
    circumference = 2 * M_PI * radius; // Circumference = 2πr

    // Display results
    printf("Circle:\n");
    printf("Area: %.2lf\n", area);
    printf("Circumference: %.2lf\n", circumference);
}

// Function to calculate the area and perimeter of a rectangle
void calculateRectangle() {
    double length, width, area, perimeter;

    printf("Enter the length of the rectangle: ");
    scanf("%lf", &length);
    printf("Enter the width of the rectangle: ");
    scanf("%lf", &width);

    // Calculate area and perimeter
    area = length * width; // Area = length * width
    perimeter = 2 * (length + width); // Perimeter = 2*(length + width)

    // Display results
    printf("Rectangle:\n");
    printf("Area: %.2lf\n", area);
    printf("Perimeter: %.2lf\n", perimeter);
}

// Function to calculate the area and perimeter of a triangle
void calculateTriangle() {
    double base, height, sideA, sideB, sideC, area, perimeter;

    printf("Enter the base of the triangle: ");
    scanf("%lf", &base);
    printf("Enter the height of the triangle: ");
    scanf("%lf", &height);
    printf("Enter the lengths of the three sides of the triangle:\n");
    printf("Side A: ");
    scanf("%lf", &sideA);
    printf("Side B: ");
    scanf("%lf", &sideB);
    printf("Side C: ");
    scanf("%lf", &sideC);

    // Calculate area and perimeter
    area = (base * height) / 2; // Area = 1/2 * base * height
    perimeter = sideA + sideB + sideC; // Perimeter = sideA + sideB + sideC

    // Display results
    printf("Triangle:\n");
    printf("Area: %.2lf\n", area);
    printf("Perimeter: %.2lf\n", perimeter);
}