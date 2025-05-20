//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

// Structure to hold triangle information
typedef struct {
    double base;
    double height;
} Triangle;

// Structure to hold rectangle information
typedef struct {
    double length;
    double width;
} Rectangle;

// Structure to hold circle information
typedef struct {
    double radius;
} Circle;

// Function prototypes
double calculateTriangleArea(Triangle t);
double calculateRectangleArea(Rectangle r);
double calculateCircleArea(Circle c);
void displayMenu();

int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Triangle t;
                printf("Enter base of triangle: ");
                scanf("%lf", &t.base);
                printf("Enter height of triangle: ");
                scanf("%lf", &t.height);
                printf("Area of Triangle: %.2lf\n", calculateTriangleArea(t));
                break;
            }
            case 2: {
                Rectangle r;
                printf("Enter length of rectangle: ");
                scanf("%lf", &r.length);
                printf("Enter width of rectangle: ");
                scanf("%lf", &r.width);
                printf("Area of Rectangle: %.2lf\n", calculateRectangleArea(r));
                break;
            }
            case 3: {
                Circle c;
                printf("Enter radius of circle: ");
                scanf("%lf", &c.radius);
                printf("Area of Circle: %.2lf\n", calculateCircleArea(c));
                break;
            }
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    } while (choice != 4);
    
    return 0;
}

void displayMenu() {
    printf("Geometric Area Calculator\n");
    printf("1. Calculate Area of Triangle\n");
    printf("2. Calculate Area of Rectangle\n");
    printf("3. Calculate Area of Circle\n");
    printf("4. Exit\n");
}

double calculateTriangleArea(Triangle t) {
    return 0.5 * t.base * t.height;
}

double calculateRectangleArea(Rectangle r) {
    return r.length * r.width;
}

double calculateCircleArea(Circle c) {
    return PI * c.radius * c.radius;
}