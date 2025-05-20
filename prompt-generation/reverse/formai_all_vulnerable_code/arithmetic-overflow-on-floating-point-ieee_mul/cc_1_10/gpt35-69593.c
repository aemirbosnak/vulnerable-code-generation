//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: authentic
/*
This program calculates the area and circumference of a circle,
the perimeter of a rectangle, and the area of a triangle.

To calculate the area of a circle with radius r:
A = pi * r^2
To calculate the circumference of a circle with radius r:
C = 2 * pi * r
To calculate the perimeter of a rectangle with width w and height h:
P = 2 * (w + h)
To calculate the area of a triangle with base b and height h:
A = 0.5 * b * h
*/

#include <stdio.h>
#define PI 3.14159

int main()
{
    int choice;
    float radius, width, height, base;

    printf("Geometry Calculator\n");
    printf("1. Calculate the Area of a Circle\n");
    printf("2. Calculate the Circumference of a Circle\n");
    printf("3. Calculate the Perimeter of a Rectangle\n");
    printf("4. Calculate the Area of a Triangle\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the radius of the circle: ");
            scanf("%f", &radius);
            printf("Area of the circle is: %f\n", PI * radius * radius);
            break;

        case 2:
            printf("Enter the radius of the circle: ");
            scanf("%f", &radius);
            printf("Circumference of the circle is: %f\n", 2 * PI * radius);
            break;

        case 3:
            printf("Enter the width of the rectangle: ");
            scanf("%f", &width);
            printf("Enter the height of the rectangle: ");
            scanf("%f", &height);
            printf("Perimeter of the rectangle is: %f\n", 2 * (width + height));
            break;

        case 4:
            printf("Enter the base of the triangle: ");
            scanf("%f", &base);
            printf("Enter the height of the triangle: ");
            scanf("%f", &height);
            printf("Area of the triangle is: %f\n", 0.5 * base * height);
            break;

        default:
            printf("Invalid Choice\n");
            break;
    }

    return 0;
}