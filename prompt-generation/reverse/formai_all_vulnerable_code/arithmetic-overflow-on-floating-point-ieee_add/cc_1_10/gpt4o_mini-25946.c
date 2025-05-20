//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: grateful
#include <stdio.h>
#include <math.h>

// Function prototypes
void displayMenu();
double calculateCircleArea(double radius);
double calculateCircleCircumference(double radius);
double calculateRectangleArea(double length, double width);
double calculateRectanglePerimeter(double length, double width);
double calculateTriangleArea(double base, double height);
double calculateTrianglePerimeter(double side1, double side2, double side3);

int main() {
    int choice;
    double radius, length, width, base, height, side1, side2, side3;

    printf("Welcome to the Grateful Geometry Calculator!\n");
    printf("We appreciate your willingness to explore mathematical concepts.\n\n");

    while (1) {
        displayMenu();
        printf("Please enter your choice (1-6, or 0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Thank you for using the Grateful Geometry Calculator! Have a wonderful day!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("You chose to calculate the area of a Circle.\n");
                printf("Please enter the radius: ");
                scanf("%lf", &radius);
                printf("The area of the circle is: %.2f\n", calculateCircleArea(radius));
                printf("The circumference of the circle is: %.2f\n\n", calculateCircleCircumference(radius));
                break;

            case 2:
                printf("You chose to calculate the area of a Rectangle.\n");
                printf("Please enter the length: ");
                scanf("%lf", &length);
                printf("Please enter the width: ");
                scanf("%lf", &width);
                printf("The area of the rectangle is: %.2f\n", calculateRectangleArea(length, width));
                printf("The perimeter of the rectangle is: %.2f\n\n", calculateRectanglePerimeter(length, width));
                break;

            case 3:
                printf("You chose to calculate the area of a Triangle.\n");
                printf("Please enter the base: ");
                scanf("%lf", &base);
                printf("Please enter the height: ");
                scanf("%lf", &height);
                printf("The area of the triangle is: %.2f\n", calculateTriangleArea(base, height));

                printf("Now, please enter the lengths of all three sides to calculate the perimeter.\n");
                printf("Enter side 1: ");
                scanf("%lf", &side1);
                printf("Enter side 2: ");
                scanf("%lf", &side2);
                printf("Enter side 3: ");
                scanf("%lf", &side3);
                printf("The perimeter of the triangle is: %.2f\n\n", calculateTrianglePerimeter(side1, side2, side3));
                break;

            case 4:
                printf("You chose to exit. We are grateful for your time today!\n");
                return 0;

            default:
                printf("Invalid choice. Please choose a valid option (1-6).\n\n");
        }
    }

    return 0;
}

// Function declarations
void displayMenu() {
    printf("Choose a geometric shape to calculate:\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("0. Exit\n");
    printf("---------------------------\n");
}

double calculateCircleArea(double radius) {
    return M_PI * radius * radius;
}

double calculateCircleCircumference(double radius) {
    return 2 * M_PI * radius;
}

double calculateRectangleArea(double length, double width) {
    return length * width;
}

double calculateRectanglePerimeter(double length, double width) {
    return 2 * (length + width);
}

double calculateTriangleArea(double base, double height) {
    return 0.5 * base * height;
}

double calculateTrianglePerimeter(double side1, double side2, double side3) {
    return side1 + side2 + side3;
}