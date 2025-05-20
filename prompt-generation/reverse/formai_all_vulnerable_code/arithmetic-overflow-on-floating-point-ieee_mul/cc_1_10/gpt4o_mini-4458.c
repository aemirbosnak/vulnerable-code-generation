//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: automated
#include <stdio.h>
#include <math.h>

#define PI 3.14159

void calculateCircle();
void calculateRectangle();
void calculateTriangle();
void displayMenu();

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        printf("Enter your choice (1-4): ");
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
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
        printf("\n");
    }
    
    return 0;
}

void displayMenu() {
    printf("----- Geometry Calculator -----\n");
    printf("1. Calculate Circle\n");
    printf("2. Calculate Rectangle\n");
    printf("3. Calculate Triangle\n");
    printf("4. Exit\n");
}

void calculateCircle() {
    double radius, area, perimeter;

    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    area = PI * radius * radius;
    perimeter = 2 * PI * radius;

    printf("Circle:\n");
    printf("Area: %.2lf\n", area);
    printf("Perimeter: %.2lf\n", perimeter);
}

void calculateRectangle() {
    double length, width, area, perimeter;

    printf("Enter the length of the rectangle: ");
    scanf("%lf", &length);
    printf("Enter the width of the rectangle: ");
    scanf("%lf", &width);

    area = length * width;
    perimeter = 2 * (length + width);

    printf("Rectangle:\n");
    printf("Area: %.2lf\n", area);
    printf("Perimeter: %.2lf\n", perimeter);
}

void calculateTriangle() {
    double base, height, side1, side2, area, perimeter;

    printf("Enter the base of the triangle: ");
    scanf("%lf", &base);
    printf("Enter the height of the triangle: ");
    scanf("%lf", &height);
    printf("Enter the length of the first side of the triangle: ");
    scanf("%lf", &side1);
    printf("Enter the length of the second side of the triangle: ");
    scanf("%lf", &side2);

    area = (base * height) / 2;
    perimeter = base + side1 + side2;

    printf("Triangle:\n");
    printf("Area: %.2lf\n", area);
    printf("Perimeter: %.2lf\n", perimeter);
}