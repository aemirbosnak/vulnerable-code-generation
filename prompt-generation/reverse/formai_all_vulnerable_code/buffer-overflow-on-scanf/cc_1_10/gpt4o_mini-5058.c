//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function prototypes
double area_triangle(double base, double height);
double area_circle(double radius);
double area_rectangle(double length, double width);

// Main function
int main() {
    int choice;
    double area;

    printf("Geometric Area Calculator\n");
    printf("Choose the shape to calculate the area:\n");
    printf("1. Triangle\n");
    printf("2. Circle\n");
    printf("3. Rectangle\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            double base, height;
            printf("You selected Triangle.\n");
            printf("Enter the base: ");
            scanf("%lf", &base);
            printf("Enter the height: ");
            scanf("%lf", &height);
            area = area_triangle(base, height);
            printf("The area of the triangle is: %.2lf\n", area);
            break;
        }
        case 2: {
            double radius;
            printf("You selected Circle.\n");
            printf("Enter the radius: ");
            scanf("%lf", &radius);
            area = area_circle(radius);
            printf("The area of the circle is: %.2lf\n", area);
            break;
        }
        case 3: {
            double length, width;
            printf("You selected Rectangle.\n");
            printf("Enter the length: ");
            scanf("%lf", &length);
            printf("Enter the width: ");
            scanf("%lf", &width);
            area = area_rectangle(length, width);
            printf("The area of the rectangle is: %.2lf\n", area);
            break;
        }
        default:
            printf("Invalid choice! Please select a correct option.\n");
    }

    return 0;
}

// Function to calculate the area of a triangle
double area_triangle(double base, double height) {
    return (base * height) / 2;
}

// Function to calculate the area of a circle
double area_circle(double radius) {
    return PI * radius * radius;
}

// Function to calculate the area of a rectangle
double area_rectangle(double length, double width) {
    return length * width;
}