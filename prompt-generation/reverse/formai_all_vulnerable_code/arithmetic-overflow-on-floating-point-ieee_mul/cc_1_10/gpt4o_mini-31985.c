//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: realistic
#include <stdio.h>
#include <math.h>

// Function prototypes
double rectangle_area(double width, double height);
double rectangle_perimeter(double width, double height);
double circle_area(double radius);
double circle_circumference(double radius);
double triangle_area(double base, double height);
double triangle_perimeter(double a, double b, double c);

int main() {
    int choice;
    double width, height, radius, base, triangle_height, a, b, c;

    do {
        printf("\nGeometry Calculator Menu:\n");
        printf("1. Rectangle Area and Perimeter\n");
        printf("2. Circle Area and Circumference\n");
        printf("3. Triangle Area and Perimeter\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter width of the rectangle: ");
                scanf("%lf", &width);
                printf("Enter height of the rectangle: ");
                scanf("%lf", &height);
                printf("Area of the rectangle: %.2lf\n", rectangle_area(width, height));
                printf("Perimeter of the rectangle: %.2lf\n", rectangle_perimeter(width, height));
                break;

            case 2:
                printf("Enter radius of the circle: ");
                scanf("%lf", &radius);
                printf("Area of the circle: %.2lf\n", circle_area(radius));
                printf("Circumference of the circle: %.2lf\n", circle_circumference(radius));
                break;

            case 3:
                printf("Enter base of the triangle: ");
                scanf("%lf", &base);
                printf("Enter height of the triangle: ");
                scanf("%lf", &triangle_height);
                printf("Enter lengths of the other two sides of the triangle (a and b): ");
                scanf("%lf %lf", &a, &b);
                printf("Enter the length of the third side (c): ");
                scanf("%lf", &c);
                printf("Area of the triangle: %.2lf\n", triangle_area(base, triangle_height));
                printf("Perimeter of the triangle: %.2lf\n", triangle_perimeter(a, b, c));
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while(choice != 4);

    return 0;
}

double rectangle_area(double width, double height) {
    return width * height;
}

double rectangle_perimeter(double width, double height) {
    return 2 * (width + height);
}

double circle_area(double radius) {
    return M_PI * radius * radius;
}

double circle_circumference(double radius) {
    return 2 * M_PI * radius;
}

double triangle_area(double base, double height) {
    return 0.5 * base * height;
}

double triangle_perimeter(double a, double b, double c) {
    return a + b + c;
}