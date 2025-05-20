//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: authentic
#include <stdio.h>
#include <math.h>

// Function to calculate the area of a circle
double area_circle(double radius) {
    return M_PI * radius * radius;
}

// Function to calculate the area of a rectangle
double area_rectangle(double length, double width) {
    return length * width;
}

// Function to calculate the area of a triangle using Heron's Formula
double area_triangle(double a, double b, double c) {
    double s = (a + b + c) / 2; // semi-perimeter
    return sqrt(s * (s - a) * (s - b) * (s - c)); // area calculation
}

// Function to display menu options
void display_menu() {
    printf("Choose the shape to calculate area:\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    double radius, length, width;
    double side_a, side_b, side_c;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter radius of the circle: ");
                scanf("%lf", &radius);
                printf("Area of the circle: %.2f\n", area_circle(radius));
                break;

            case 2:
                printf("Enter length of the rectangle: ");
                scanf("%lf", &length);
                printf("Enter width of the rectangle: ");
                scanf("%lf", &width);
                printf("Area of the rectangle: %.2f\n", area_rectangle(length, width));
                break;

            case 3:
                printf("Enter length of side A: ");
                scanf("%lf", &side_a);
                printf("Enter length of side B: ");
                scanf("%lf", &side_b);
                printf("Enter length of side C: ");
                scanf("%lf", &side_c);
                
                // Validate if a triangle can exist with the given sides
                if (side_a + side_b > side_c && side_a + side_c > side_b && side_b + side_c > side_a) {
                    printf("Area of the triangle: %.2f\n", area_triangle(side_a, side_b, side_c));
                } else {
                    printf("Error: The lengths entered do not form a valid triangle.\n");
                }
                break;

            case 4:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }

        printf("\n"); // Add space for better readability
    }

    return 0;
}