//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: introspective
#include <stdio.h>
#include <math.h>

// Constants
#define PI 3.14159265358979323846

// Function prototypes
void calculateCircle();
void calculateRectangle();
void calculateTriangle();

int main() {
    int choice;

    while (1) {
        printf("Geometric Calculator\n");
        printf("1. Circle\n");
        printf("2. Rectangle\n");
        printf("3. Triangle\n");
        printf("4. Exit\n");
        printf("Please choose an option (1-4): ");
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
                printf("Invalid option. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}

void calculateCircle() {
    double radius;
    printf("Enter radius of the circle: ");
    scanf("%lf", &radius);
    
    double area = PI * radius * radius;
    double perimeter = 2 * PI * radius;

    printf("Circle with radius %.2lf:\n", radius);
    printf("Area: %.2lf\n", area);
    printf("Perimeter: %.2lf\n", perimeter);
}

void calculateRectangle() {
    double length, width;
    
    printf("Enter length of the rectangle: ");
    scanf("%lf", &length);
    printf("Enter width of the rectangle: ");
    scanf("%lf", &width);

    double area = length * width;
    double perimeter = 2 * (length + width);

    printf("Rectangle with length %.2lf and width %.2lf:\n", length, width);
    printf("Area: %.2lf\n", area);
    printf("Perimeter: %.2lf\n", perimeter);
}

void calculateTriangle() {
    double base, height, side1, side2, side3;

    printf("Enter base of the triangle: ");
    scanf("%lf", &base);
    printf("Enter height of the triangle: ");
    scanf("%lf", &height);
    printf("Enter side lengths (side1, side2, side3): ");
    scanf("%lf %lf %lf", &side1, &side2, &side3);

    double area = 0.5 * base * height;
    double perimeter = side1 + side2 + side3;

    printf("Triangle with base %.2lf and height %.2lf:\n", base, height);
    printf("Area: %.2lf\n", area);
    printf("Perimeter: %.2lf\n", perimeter);
}