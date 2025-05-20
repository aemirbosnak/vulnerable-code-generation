//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: happy
#include <stdio.h>
#include <math.h>

// Function to calculate the area of a circle
double areaCircle(double radius) {
    return M_PI * radius * radius;
}

// Function to calculate the area of a rectangle
double areaRectangle(double width, double height) {
    return width * height;
}

// Function to calculate the area of a triangle
double areaTriangle(double base, double height) {
    return 0.5 * base * height;
}

// Function to display the menu and get user's choice
int displayMenu() {
    int choice;

    printf("\nWelcome to the Happy Geometric Area Calculator!\n");
    printf("Please choose a shape to calculate its area:\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    return choice;
}

int main() {
    int choice;
    double radius, width, height, base, area;

    do {
        choice = displayMenu();

        switch (choice) {
            case 1: // Circle
                printf("You chose Circle. Please enter the radius: ");
                scanf("%lf", &radius);
                area = areaCircle(radius);
                printf("The area of the circle is: %.2f\n", area);
                break;

            case 2: // Rectangle
                printf("You chose Rectangle. Please enter the width and height: ");
                scanf("%lf %lf", &width, &height);
                area = areaRectangle(width, height);
                printf("The area of the rectangle is: %.2f\n", area);
                break;

            case 3: // Triangle
                printf("You chose Triangle. Please enter the base and height: ");
                scanf("%lf %lf", &base, &height);
                area = areaTriangle(base, height);
                printf("The area of the triangle is: %.2f\n", area);
                break;

            case 4: // Exit
                printf("Thank you for using the Happy Geometric Area Calculator! Goodbye!\n");
                break;

            default:
                printf("That's not a valid choice! Please try again.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}