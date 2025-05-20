//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: Alan Turing
#include <stdio.h>
#include <math.h>

// Function declarations
double calculateTriangleArea(double base, double height);
double calculateRectangleArea(double length, double breadth);
double calculateCircleArea(double radius);

int main() {
    int choice;
    double area;

    printf("Welcome to the Geometric Area Calculator!\n");
    printf("Choose the shape to calculate the area:\n");
    printf("1. Triangle\n");
    printf("2. Rectangle\n");
    printf("3. Circle\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid choice.\n");
            while (getchar() != '\n'); // clear invalid input
            continue;
        }

        switch (choice) {
            case 1: {
                double base, height;
                printf("Enter the base of the triangle: ");
                scanf("%lf", &base);
                printf("Enter the height of the triangle: ");
                scanf("%lf", &height);

                if (base < 0 || height < 0) {
                    printf("Base and height should be non-negative.\n");
                    break;
                }

                area = calculateTriangleArea(base, height);
                printf("The area of the triangle is: %.2lf\n", area);
                break;
            }
            case 2: {
                double length, breadth;
                printf("Enter the length of the rectangle: ");
                scanf("%lf", &length);
                printf("Enter the breadth of the rectangle: ");
                scanf("%lf", &breadth);

                if (length < 0 || breadth < 0) {
                    printf("Length and breadth should be non-negative.\n");
                    break;
                }

                area = calculateRectangleArea(length, breadth);
                printf("The area of the rectangle is: %.2lf\n", area);
                break;
            }
            case 3: {
                double radius;
                printf("Enter the radius of the circle: ");
                scanf("%lf", &radius);

                if (radius < 0) {
                    printf("Radius should be non-negative.\n");
                    break;
                }

                area = calculateCircleArea(radius);
                printf("The area of the circle is: %.2lf\n", area);
                break;
            }
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    }

    return 0;
}

// Function definitions
double calculateTriangleArea(double base, double height) {
    return 0.5 * base * height;
}

double calculateRectangleArea(double length, double breadth) {
    return length * breadth;
}

double calculateCircleArea(double radius) {
    return M_PI * radius * radius; // Use the mathematical constant π
}