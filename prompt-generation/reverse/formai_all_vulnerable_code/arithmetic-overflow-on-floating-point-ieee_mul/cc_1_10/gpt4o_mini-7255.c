//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: inquisitive
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

void calculateCircle() {
    double radius;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    
    double area = PI * radius * radius;
    double perimeter = 2 * PI * radius;
    
    printf("Circle with radius %.2f has an area of %.2f and a perimeter of %.2f.\n", radius, area, perimeter);
}

void calculateTriangle() {
    double base, height, side1, side2, side3;
    printf("Enter the base of the triangle: ");
    scanf("%lf", &base);
    printf("Enter the height of the triangle: ");
    scanf("%lf", &height);
    
    printf("Enter the lengths of the three sides of the triangle: \n");
    printf("Side 1: "); scanf("%lf", &side1);
    printf("Side 2: "); scanf("%lf", &side2);
    printf("Side 3: "); scanf("%lf", &side3);
    
    double area = 0.5 * base * height;
    double perimeter = side1 + side2 + side3;
    
    printf("Triangle with base %.2f and height %.2f has an area of %.2f and a perimeter of %.2f.\n", base, height, area, perimeter);
}

void calculateRectangle() {
    double length, width;
    printf("Enter the length of the rectangle: ");
    scanf("%lf", &length);
    printf("Enter the width of the rectangle: ");
    scanf("%lf", &width);
    
    double area = length * width;
    double perimeter = 2 * (length + width);
    
    printf("Rectangle with length %.2f and width %.2f has an area of %.2f and a perimeter of %.2f.\n", length, width, area, perimeter);
}

int main() {
    int choice;
    
    printf("Geometric Area and Perimeter Calculator\n");
    printf("Choose a shape to calculate:\n");
    printf("1. Circle\n");
    printf("2. Triangle\n");
    printf("3. Rectangle\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            calculateCircle();
            break;
        case 2:
            calculateTriangle();
            break;
        case 3:
            calculateRectangle();
            break;
        default:
            printf("Invalid choice! Please select 1, 2, or 3.\n");
    }
    
    return 0;
}