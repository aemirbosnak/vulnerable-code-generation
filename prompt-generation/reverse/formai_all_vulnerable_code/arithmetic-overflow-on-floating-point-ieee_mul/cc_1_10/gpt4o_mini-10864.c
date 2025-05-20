//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: light-weight
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

void calculateTriangleArea() {
    double base, height;
    printf("Enter the base of the triangle: ");
    scanf("%lf", &base);
    printf("Enter the height of the triangle: ");
    scanf("%lf", &height);
    
    double area = 0.5 * base * height;
    printf("The area of the triangle is: %.2f\n", area);
}

void calculateRectangleArea() {
    double length, width;
    printf("Enter the length of the rectangle: ");
    scanf("%lf", &length);
    printf("Enter the width of the rectangle: ");
    scanf("%lf", &width);
    
    double area = length * width;
    printf("The area of the rectangle is: %.2f\n", area);
}

void calculateCircleArea() {
    double radius;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    
    double area = PI * radius * radius;
    printf("The area of the circle is: %.2f\n", area);
}

void displayMenu() {
    printf("\nChoose a shape to calculate the area:\n");
    printf("1. Triangle\n");
    printf("2. Rectangle\n");
    printf("3. Circle\n");
    printf("0. Exit\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculateTriangleArea();
                break;
            case 2:
                calculateRectangleArea();
                break;
            case 3:
                calculateCircleArea();
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}