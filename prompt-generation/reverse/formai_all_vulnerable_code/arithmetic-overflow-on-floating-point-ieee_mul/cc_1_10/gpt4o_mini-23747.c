//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: protected
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function prototypes
double calculateTriangleArea(double base, double height);
double calculateTrianglePerimeter(double side1, double side2, double side3);
double calculateRectangleArea(double length, double width);
double calculateRectanglePerimeter(double length, double width);
double calculateCircleArea(double radius);
double calculateCirclePerimeter(double radius);
void displayMenu();
int getShapeChoice();

int main() {
    int choice;
    double base, height, side1, side2, side3;
    double length, width, radius;

    do {
        displayMenu();
        choice = getShapeChoice();

        switch (choice) {
            case 1:
                printf("Enter base of triangle: ");
                scanf("%lf", &base);
                printf("Enter height of triangle: ");
                scanf("%lf", &height);
                printf("Enter side1 of triangle: ");
                scanf("%lf", &side1);
                printf("Enter side2 of triangle: ");
                scanf("%lf", &side2);
                printf("Enter side3 of triangle: ");
                scanf("%lf", &side3);
                printf("Area of Triangle: %.2lf\n", calculateTriangleArea(base, height));
                printf("Perimeter of Triangle: %.2lf\n", calculateTrianglePerimeter(side1, side2, side3));
                break;
            
            case 2:
                printf("Enter length of rectangle: ");
                scanf("%lf", &length);
                printf("Enter width of rectangle: ");
                scanf("%lf", &width);
                printf("Area of Rectangle: %.2lf\n", calculateRectangleArea(length, width));
                printf("Perimeter of Rectangle: %.2lf\n", calculateRectanglePerimeter(length, width));
                break;
            
            case 3:
                printf("Enter radius of circle: ");
                scanf("%lf", &radius);
                printf("Area of Circle: %.2lf\n", calculateCircleArea(radius));
                printf("Perimeter (Circumference) of Circle: %.2lf\n", calculateCirclePerimeter(radius));
                break;
            
            case 4:
                printf("Exiting...\n");
                break;
            
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

void displayMenu() {
    printf("\n---- Geometric Calculator ----\n");
    printf("1. Triangle\n");
    printf("2. Rectangle\n");
    printf("3. Circle\n");
    printf("4. Exit\n");
    printf("Choose a shape to calculate: ");
}

int getShapeChoice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

double calculateTriangleArea(double base, double height) {
    return 0.5 * base * height;
}

double calculateTrianglePerimeter(double side1, double side2, double side3) {
    return side1 + side2 + side3;
}

double calculateRectangleArea(double length, double width) {
    return length * width;
}

double calculateRectanglePerimeter(double length, double width) {
    return 2 * (length + width);
}

double calculateCircleArea(double radius) {
    return PI * radius * radius;
}

double calculateCirclePerimeter(double radius) {
    return 2 * PI * radius;
}