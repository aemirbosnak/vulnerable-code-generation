//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: recursive
#include <stdio.h>

// Function to calculate the area of a triangle using recursion
double triangleArea(double base, double height) {
    // Base case: If the base or height is zero, area is zero
    if (base == 0 || height == 0) {
        return 0;
    }
    // If height is greater than 1, we proceed recursively decreasing height by 1
    if (height > 1) {
        // The area of the triangle is 1/2 * base * height
        return (0.5 * base + triangleArea(base, height - 1));
    }
    // When height is 1, it calculates the area for the last unit height
    return 0.5 * base;
}

// Function to calculate the area of a rectangle recursively
double rectangleArea(double length, double breadth) {
    // Base case: If either length or breadth is zero, area is zero
    if (length == 0 || breadth == 0) {
        return 0;
    }
    // Recursive case: Decrease the breadth and accumulate area
    return length + rectangleArea(length, breadth - 1);
}

int main() {
    int choice;
    double area, base, height, length, breadth;

    printf("Geometric Area Calculator\n");
    printf("Choose an option:\n");
    printf("1. Calculate the area of a triangle\n");
    printf("2. Calculate the area of a rectangle\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the base of the triangle: ");
            scanf("%lf", &base);
            printf("Enter the height of the triangle: ");
            scanf("%lf", &height);
            area = triangleArea(base, height);
            printf("The area of the triangle is: %.2lf\n", area);
            break;
        case 2:
            printf("Enter the length of the rectangle: ");
            scanf("%lf", &length);
            printf("Enter the breadth of the rectangle: ");
            scanf("%lf", &breadth);
            area = rectangleArea(length, breadth);
            printf("The area of the rectangle is: %.2lf\n", area);
            break;
        default:
            printf("Invalid choice! Please select either 1 or 2.\n");
    }

    return 0;
}