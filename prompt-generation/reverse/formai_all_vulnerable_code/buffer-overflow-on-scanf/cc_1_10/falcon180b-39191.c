//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

double calculate_circle_area(double radius) {
    return PI * radius * radius;
}

double calculate_circle_circumference(double radius) {
    return 2 * PI * radius;
}

double calculate_triangle_area(double base, double height) {
    return 0.5 * base * height;
}

double calculate_triangle_perimeter(double base, double height) {
    return base + 2 * sqrt(height * height + base * base / 4);
}

double calculate_rectangle_area(double width, double height) {
    return width * height;
}

double calculate_rectangle_perimeter(double width, double height) {
    return 2 * (width + height);
}

int main() {
    double radius, base, height, width, result;
    int choice;

    printf("Enter the shape you want to calculate:\n1. Circle\n2. Triangle\n3. Rectangle\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the radius of the circle: ");
            scanf("%lf", &radius);
            result = calculate_circle_area(radius);
            printf("The area of the circle is %.2lf\n", result);

            printf("Enter the radius of the circle: ");
            scanf("%lf", &radius);
            result = calculate_circle_circumference(radius);
            printf("The circumference of the circle is %.2lf\n", result);
            break;

        case 2:
            printf("Enter the base of the triangle: ");
            scanf("%lf", &base);
            printf("Enter the height of the triangle: ");
            scanf("%lf", &height);
            result = calculate_triangle_area(base, height);
            printf("The area of the triangle is %.2lf\n", result);

            printf("Enter the base of the triangle: ");
            scanf("%lf", &base);
            printf("Enter the height of the triangle: ");
            scanf("%lf", &height);
            result = calculate_triangle_perimeter(base, height);
            printf("The perimeter of the triangle is %.2lf\n", result);
            break;

        case 3:
            printf("Enter the width of the rectangle: ");
            scanf("%lf", &width);
            printf("Enter the height of the rectangle: ");
            scanf("%lf", &height);
            result = calculate_rectangle_area(width, height);
            printf("The area of the rectangle is %.2lf\n", result);

            printf("Enter the width of the rectangle: ");
            scanf("%lf", &width);
            printf("Enter the height of the rectangle: ");
            scanf("%lf", &height);
            result = calculate_rectangle_perimeter(width, height);
            printf("The perimeter of the rectangle is %.2lf\n", result);
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}