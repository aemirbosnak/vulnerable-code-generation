//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

// A function to calculate the area of a circle
double circleArea(double radius)
{
    double area = M_PI * radius * radius;
    return area;
}

// A function to calculate the area of a triangle
double triangleArea(double base, double height)
{
    double area = 0.5 * base * height;
    return area;
}

// A function to calculate the area of a rectangle
double rectangleArea(double length, double width)
{
    double area = length * width;
    return area;
}

int main() {
    int option; // To store the user's option
    double radius, base, height, length, width; // To store the inputs for calculations

    // Displaying the options to the user
    printf("Please enter the shape you want to calculate the area of:\n");
    printf("1. Circle\n");
    printf("2. Triangle\n");
    printf("3. Rectangle\n");

    // Getting the user's option
    scanf("%d", &option);

    // Performing calculations based on the user's option
    switch(option) {
        case 1:
            printf("Please enter the radius of the circle: ");
            scanf("%lf", &radius);
            printf("The area of the circle is: %.2lf", circleArea(radius));
            break;
        case 2:
            printf("Please enter the base of the triangle: ");
            scanf("%lf", &base);
            printf("Please enter the height of the triangle: ");
            scanf("%lf", &height);
            printf("The area of the triangle is: %.2lf", triangleArea(base, height));
            break;
        case 3:
            printf("Please enter the length of the rectangle: ");
            scanf("%lf", &length);
            printf("Please enter the width of the rectangle: ");
            scanf("%lf", &width);
            printf("The area of the rectangle is: %.2lf", rectangleArea(length, width));
            break;
        default:
            printf("Invalid option!");
    }

    return 0;
}