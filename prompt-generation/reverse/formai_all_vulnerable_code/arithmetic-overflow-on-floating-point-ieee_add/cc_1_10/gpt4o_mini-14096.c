//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: systematic
#include <stdio.h>
#include <math.h>

// Function prototypes
double calculateCircleArea(double radius);
double calculateRectangleArea(double length, double width);
double calculateTriangleArea(double base, double height);
double calculateTrapezoidArea(double base1, double base2, double height);
void displayMenu();

int main() {
    int choice;
    double area;
    double radius, length, width, base, height, base1, base2;

    while (1) {
        displayMenu();
        printf("Select a shape (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 5.\n");
            while(getchar() != '\n'); // Clear invalid input
            continue;
        }

        switch (choice) {
            case 1: // Circle
                printf("Enter the radius of the circle: ");
                if (scanf("%lf", &radius) != 1 || radius <= 0) {
                    printf("Invalid input! Please enter a positive number.\n");
                    while(getchar() != '\n');
                    continue;
                }
                area = calculateCircleArea(radius);
                printf("Area of Circle: %.2f\n", area);
                break;

            case 2: // Rectangle
                printf("Enter the length of the rectangle: ");
                if (scanf("%lf", &length) != 1 || length <= 0) {
                    printf("Invalid input! Please enter a positive number.\n");
                    while(getchar() != '\n');
                    continue;
                }
                printf("Enter the width of the rectangle: ");
                if (scanf("%lf", &width) != 1 || width <= 0) {
                    printf("Invalid input! Please enter a positive number.\n");
                    while(getchar() != '\n');
                    continue;
                }
                area = calculateRectangleArea(length, width);
                printf("Area of Rectangle: %.2f\n", area);
                break;

            case 3: // Triangle
                printf("Enter the base of the triangle: ");
                if (scanf("%lf", &base) != 1 || base <= 0) {
                    printf("Invalid input! Please enter a positive number.\n");
                    while(getchar() != '\n');
                    continue;
                }
                printf("Enter the height of the triangle: ");
                if (scanf("%lf", &height) != 1 || height <= 0) {
                    printf("Invalid input! Please enter a positive number.\n");
                    while(getchar() != '\n');
                    continue;
                }
                area = calculateTriangleArea(base, height);
                printf("Area of Triangle: %.2f\n", area);
                break;

            case 4: // Trapezoid
                printf("Enter the length of the first base of the trapezoid: ");
                if (scanf("%lf", &base1) != 1 || base1 <= 0) {
                    printf("Invalid input! Please enter a positive number.\n");
                    while(getchar() != '\n');
                    continue;
                }
                printf("Enter the length of the second base of the trapezoid: ");
                if (scanf("%lf", &base2) != 1 || base2 <= 0) {
                    printf("Invalid input! Please enter a positive number.\n");
                    while(getchar() != '\n');
                    continue;
                }
                printf("Enter the height of the trapezoid: ");
                if (scanf("%lf", &height) != 1 || height <= 0) {
                    printf("Invalid input! Please enter a positive number.\n");
                    while(getchar() != '\n');
                    continue;
                }
                area = calculateTrapezoidArea(base1, base2, height);
                printf("Area of Trapezoid: %.2f\n", area);
                break;

            case 5: // Exit
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    }

    return 0;
}

double calculateCircleArea(double radius) {
    return M_PI * radius * radius;
}

double calculateRectangleArea(double length, double width) {
    return length * width;
}

double calculateTriangleArea(double base, double height) {
    return 0.5 * base * height;
}

double calculateTrapezoidArea(double base1, double base2, double height) {
    return 0.5 * (base1 + base2) * height;
}

void displayMenu() {
    printf("\n---- Area Calculator ----\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("4. Trapezoid\n");
    printf("5. Exit\n");
}