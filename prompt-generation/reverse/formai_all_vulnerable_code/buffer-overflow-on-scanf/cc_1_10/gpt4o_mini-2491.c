//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void displayMenu();
double calculateCircleArea(double radius);
double calculateRectangleArea(double length, double width);
double calculateTriangleArea(double base, double height);
double calculateCircleCircumference(double radius);
void circleTrivia();
void rectangleTrivia();
void triangleTrivia();

int main() {
    int choice;
    double radius, length, width, base, height;

    while (1) {
        displayMenu();
        printf("Choose a shape (1-5, or 0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Circle
                printf("Enter the radius of the circle: ");
                scanf("%lf", &radius);
                printf("Area of the circle: %.2f\n", calculateCircleArea(radius));
                printf("Circumference of the circle: %.2f\n", calculateCircleCircumference(radius));
                circleTrivia();
                break;

            case 2: // Rectangle
                printf("Enter the length and width of the rectangle: ");
                scanf("%lf %lf", &length, &width);
                printf("Area of the rectangle: %.2f\n", calculateRectangleArea(length, width));
                rectangleTrivia();
                break;

            case 3: // Triangle
                printf("Enter the base and height of the triangle: ");
                scanf("%lf %lf", &base, &height);
                printf("Area of the triangle: %.2f\n", calculateTriangleArea(base, height));
                triangleTrivia();
                break;

            case 4: // Exit
                printf("Exiting the program. Thank you for playing!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}

void displayMenu() {
    printf("Geometric Puzzle Menu:\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("4. Exit\n");
    printf("------------------------\n");
}

double calculateCircleArea(double radius) {
    return M_PI * radius * radius; // Using area formula A = πr²
}

double calculateCircleCircumference(double radius) {
    return 2 * M_PI * radius; // Using circumference formula C = 2πr
}

double calculateRectangleArea(double length, double width) {
    return length * width; // Using area formula A = l * w
}

double calculateTriangleArea(double base, double height) {
    return 0.5 * base * height; // Using area formula A = 0.5 * b * h
}

void circleTrivia() {
    printf("Did you know? The concept of the circle has been used in many cultures for thousands of years, from ancient Greek mathematicians to modern-day architects!\n");
}

void rectangleTrivia() {
    printf("Fun fact: The rectangle is often used in design and architecture due to its simplicity, and humans find rectangular shapes pleasing to the eye!\n");
}

void triangleTrivia() {
    printf("Interesting fact: Triangles are the strongest shape! That’s why they are often used in construction!\n");
}