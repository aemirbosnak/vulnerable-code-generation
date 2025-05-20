//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: single-threaded
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function prototypes
void calculateCircleArea();
void calculateRectangleArea();
void calculateTriangleArea();
void calculateTrapezoidArea();

int main() {
    int choice;

    do {
        printf("\nGeometric Area Calculator\n");
        printf("1. Circle\n");
        printf("2. Rectangle\n");
        printf("3. Triangle\n");
        printf("4. Trapezoid\n");
        printf("5. Exit\n");
        printf("Select an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculateCircleArea();
                break;
            case 2:
                calculateRectangleArea();
                break;
            case 3:
                calculateTriangleArea();
                break;
            case 4:
                calculateTrapezoidArea();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void calculateCircleArea() {
    double radius, area;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    area = PI * radius * radius;
    printf("Area of the circle: %.2lf\n", area);
}

void calculateRectangleArea() {
    double length, width, area;
    printf("Enter the length of the rectangle: ");
    scanf("%lf", &length);
    printf("Enter the width of the rectangle: ");
    scanf("%lf", &width);
    area = length * width;
    printf("Area of the rectangle: %.2lf\n", area);
}

void calculateTriangleArea() {
    double base, height, area;
    printf("Enter the base of the triangle: ");
    scanf("%lf", &base);
    printf("Enter the height of the triangle: ");
    scanf("%lf", &height);
    area = 0.5 * base * height;
    printf("Area of the triangle: %.2lf\n", area);
}

void calculateTrapezoidArea() {
    double base1, base2, height, area;
    printf("Enter the length of the first base of the trapezoid: ");
    scanf("%lf", &base1);
    printf("Enter the length of the second base of the trapezoid: ");
    scanf("%lf", &base2);
    printf("Enter the height of the trapezoid: ");
    scanf("%lf", &height);
    area = 0.5 * (base1 + base2) * height;
    printf("Area of the trapezoid: %.2lf\n", area);
}