//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

void calculateRectangleArea() {
    double length, width, area;
    printf("Enter length of rectangle: ");
    scanf("%lf", &length);
    printf("Enter width of rectangle: ");
    scanf("%lf", &width);
    area = length * width;
    printf("Area of Rectangle: %.2lf\n", area);
}

void calculateTriangleArea() {
    double base, height, area;
    printf("Enter base of triangle: ");
    scanf("%lf", &base);
    printf("Enter height of triangle: ");
    scanf("%lf", &height);
    area = 0.5 * base * height;
    printf("Area of Triangle: %.2lf\n", area);
}

void calculateCircleArea() {
    double radius, area;
    printf("Enter radius of circle: ");
    scanf("%lf", &radius);
    area = PI * radius * radius;
    printf("Area of Circle: %.2lf\n", area);
}

int main() {
    int choice;
    do {
        printf("\nGeometric Area Calculator\n");
        printf("1. Calculate Area of Rectangle\n");
        printf("2. Calculate Area of Triangle\n");
        printf("3. Calculate Area of Circle\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculateRectangleArea();
                break;
            case 2:
                calculateTriangleArea();
                break;
            case 3:
                calculateCircleArea();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}