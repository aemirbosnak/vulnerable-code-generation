//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: modular
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

double area_circle(double radius) {
    return PI * radius * radius;
}

double perimeter_circle(double radius) {
    return 2 * PI * radius;
}

double area_rectangle(double length, double width) {
    return length * width;
}

double perimeter_rectangle(double length, double width) {
    return 2 * (length + width);
}

double area_triangle(double base, double height) {
    return 0.5 * base * height;
}

double perimeter_triangle(double base, double side) {
    return base + 2 * side;
}

int main() {
    double radius, length, width, base, side, height;

    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    printf("The area of the circle is: %lf\n", area_circle(radius));
    printf("The perimeter of the circle is: %lf\n", perimeter_circle(radius));

    printf("\nEnter the length and width of the rectangle: ");
    scanf("%lf %lf", &length, &width);

    printf("The area of the rectangle is: %lf\n", area_rectangle(length, width));
    printf("The perimeter of the rectangle is: %lf\n", perimeter_rectangle(length, width));

    printf("\nEnter the base and height of the triangle: ");
    scanf("%lf %lf", &base, &height);

    printf("The area of the triangle is: %lf\n", area_triangle(base, height));
    printf("The perimeter of the triangle is: %lf\n", perimeter_triangle(base, height));

    return 0;
}