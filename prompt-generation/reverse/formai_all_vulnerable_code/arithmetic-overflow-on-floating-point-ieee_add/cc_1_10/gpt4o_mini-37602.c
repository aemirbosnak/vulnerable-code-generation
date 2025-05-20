//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <math.h>

#define PI 3.14159

void calculateTriangle();
void calculateRectangle();
void calculateCircle();
void displayMenu();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Select a shape (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculateTriangle();
                break;
            case 2:
                calculateRectangle();
                break;
            case 3:
                calculateCircle();
                break;
            case 4:
                printf("Exiting... Goodbye!\n");
                return 0;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }

    return 0;
}

void displayMenu() {
    printf("\nGeometry Calculator\n");
    printf("1. Triangle\n");
    printf("2. Rectangle\n");
    printf("3. Circle\n");
    printf("4. Exit\n");
}

void calculateTriangle() {
    double base, height, sideA, sideB, sideC, area, perimeter;

    printf("Enter base of the triangle: ");
    scanf("%lf", &base);
    printf("Enter height of the triangle: ");
    scanf("%lf", &height);
    
    area = 0.5 * base * height;
    
    printf("Enter sides of the triangle (side A, side B, side C): \n");
    scanf("%lf %lf %lf", &sideA, &sideB, &sideC);
    
    perimeter = sideA + sideB + sideC;

    printf("Triangle Area: %.2lf\n", area);
    printf("Triangle Perimeter: %.2lf\n", perimeter);
}

void calculateRectangle() {
    double length, width, area, perimeter;

    printf("Enter length of the rectangle: ");
    scanf("%lf", &length);
    printf("Enter width of the rectangle: ");
    scanf("%lf", &width);
    
    area = length * width;
    perimeter = 2 * (length + width);

    printf("Rectangle Area: %.2lf\n", area);
    printf("Rectangle Perimeter: %.2lf\n", perimeter);
}

void calculateCircle() {
    double radius, area, circumference;

    printf("Enter radius of the circle: ");
    scanf("%lf", &radius);
    
    area = PI * radius * radius;
    circumference = 2 * PI * radius;

    printf("Circle Area: %.2lf\n", area);
    printf("Circle Circumference: %.2lf\n", circumference);
}