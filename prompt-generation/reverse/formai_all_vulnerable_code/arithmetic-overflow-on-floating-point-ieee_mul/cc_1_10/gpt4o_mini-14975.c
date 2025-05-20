//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

void displayMenu() {
    printf("Choose a shape to calculate:\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("4. Quit\n");
}

double calculateCircleArea(double radius) {
    return PI * radius * radius;
}

double calculateCirclePerimeter(double radius) {
    return 2 * PI * radius;
}

double calculateRectangleArea(double length, double width) {
    return length * width;
}

double calculateRectanglePerimeter(double length, double width) {
    return 2 * (length + width);
}

double calculateTriangleArea(double base, double height) {
    return 0.5 * base * height;
}

double calculateTrianglePerimeter(double side1, double side2, double side3) {
    return side1 + side2 + side3;
}

int main() {
    int choice;
    double radius, length, width, base, height, side1, side2, side3;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the radius of the circle: ");
                scanf("%lf", &radius);
                printf("Area of circle: %.2lf\n", calculateCircleArea(radius));
                printf("Perimeter of circle: %.2lf\n", calculateCirclePerimeter(radius));
                break;
            case 2:
                printf("Enter the length and width of the rectangle: ");
                scanf("%lf %lf", &length, &width);
                printf("Area of rectangle: %.2lf\n", calculateRectangleArea(length, width));
                printf("Perimeter of rectangle: %.2lf\n", calculateRectanglePerimeter(length, width));
                break;
            case 3:
                printf("Enter the base and height of the triangle: ");
                scanf("%lf %lf", &base, &height);
                printf("Area of triangle: %.2lf\n", calculateTriangleArea(base, height));
                printf("Enter the lengths of the three sides of the triangle: ");
                scanf("%lf %lf %lf", &side1, &side2, &side3);
                printf("Perimeter of triangle: %.2lf\n", calculateTrianglePerimeter(side1, side2, side3));
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        
        printf("\n");
    }
    
    return 0;
}