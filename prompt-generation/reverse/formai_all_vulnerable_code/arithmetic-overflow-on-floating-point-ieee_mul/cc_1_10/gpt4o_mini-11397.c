//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: energetic
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function declarations
void displayMenu();
double calculateTriangleArea(double base, double height);
double calculateRectangleArea(double length, double width);
double calculateCircleArea(double radius);
double calculateTrapezoidArea(double base1, double base2, double height);

// Main function
int main() {
    int choice;
    double area;

    printf("Welcome to the Geometric Area Calculator!\n");
    printf("Let's unleash the power of shapes!\n");

    while (1) {
        displayMenu();
        printf("Choose a shape to calculate its area (1-4) or 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Thank you for using the Geometric Area Calculator! Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1: {
                double base, height;
                printf("You chose Triangle!\n");
                printf("Enter the base: ");
                scanf("%lf", &base);
                printf("Enter the height: ");
                scanf("%lf", &height);
                area = calculateTriangleArea(base, height);
                printf("The area of the triangle is: %.2lf\n", area);
                break;
            }
            case 2: {
                double length, width;
                printf("You chose Rectangle!\n");
                printf("Enter the length: ");
                scanf("%lf", &length);
                printf("Enter the width: ");
                scanf("%lf", &width);
                area = calculateRectangleArea(length, width);
                printf("The area of the rectangle is: %.2lf\n", area);
                break;
            }
            case 3: {
                double radius;
                printf("You chose Circle!\n");
                printf("Enter the radius: ");
                scanf("%lf", &radius);
                area = calculateCircleArea(radius);
                printf("The area of the circle is: %.2lf\n", area);
                break;
            }
            case 4: {
                double base1, base2, height;
                printf("You chose Trapezoid!\n");
                printf("Enter the length of base 1: ");
                scanf("%lf", &base1);
                printf("Enter the length of base 2: ");
                scanf("%lf", &base2);
                printf("Enter the height: ");
                scanf("%lf", &height);
                area = calculateTrapezoidArea(base1, base2, height);
                printf("The area of the trapezoid is: %.2lf\n", area);
                break;
            }
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }
    return 0;
}

// Function definitions
void displayMenu() {
    printf("\nChoose the shape you wish to calculate the area:\n");
    printf("1. Triangle\n");
    printf("2. Rectangle\n");
    printf("3. Circle\n");
    printf("4. Trapezoid\n");
}

double calculateTriangleArea(double base, double height) {
    return 0.5 * base * height;
}

double calculateRectangleArea(double length, double width) {
    return length * width;
}

double calculateCircleArea(double radius) {
    return PI * radius * radius;
}

double calculateTrapezoidArea(double base1, double base2, double height) {
    return 0.5 * (base1 + base2) * height;
}