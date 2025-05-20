//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void calculateCircleArea();
void calculateRectangleArea();
void calculateTriangleArea();

int main() {
    int choice;

    while (1) {
        printf("Choose a shape to calculate area:\n");
        printf("1. Circle\n");
        printf("2. Rectangle\n");
        printf("3. Triangle\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
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
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void calculateCircleArea() {
    double radius, area;

    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    if (radius < 0) {
        printf("Radius cannot be negative.\n");
        return;
    }
    
    area = M_PI * radius * radius;
    printf("Area of the circle: %.2lf\n", area);
}

void calculateRectangleArea() {
    double length, width, area;

    printf("Enter the length of the rectangle: ");
    scanf("%lf", &length);
    printf("Enter the width of the rectangle: ");
    scanf("%lf", &width);
    
    if (length < 0 || width < 0) {
        printf("Length and width cannot be negative.\n");
        return;
    }

    area = length * width;
    printf("Area of the rectangle: %.2lf\n", area);
}

void calculateTriangleArea() {
    double base, height, area;

    printf("Enter the base of the triangle: ");
    scanf("%lf", &base);
    printf("Enter the height of the triangle: ");
    scanf("%lf", &height);
    
    if (base < 0 || height < 0) {
        printf("Base and height cannot be negative.\n");
        return;
    }

    area = 0.5 * base * height;
    printf("Area of the triangle: %.2lf\n", area);
}