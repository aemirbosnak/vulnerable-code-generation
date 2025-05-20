//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: beginner-friendly
#include <stdio.h>

// function to calculate the perimeter of a rectangle
float rectanglePerimeter(float length, float width) {
    return 2 * (length + width);
}

// function to calculate the area of a rectangle
float rectangleArea(float length, float width) {
    return length * width;
}

// function to calculate the perimeter of a circle
float circlePerimeter(float radius) {
    return 2 * 3.141592 * radius;
}

// function to calculate the area of a circle
float circleArea(float radius) {
    return 3.141592 * radius * radius;
}

int main() {
    int choice;
    float result, length, width, radius;

    do {
        printf("Choose a shape to calculate its perimeter and area:\n");
        printf("1. Rectangle\n");
        printf("2. Circle\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the length of the rectangle: ");
                scanf("%f", &length);
                printf("Enter the width of the rectangle: ");
                scanf("%f", &width);

                result = rectanglePerimeter(length, width);
                printf("Perimeter of rectangle: %.2f\n", result);

                result = rectangleArea(length, width);
                printf("Area of rectangle: %.2f\n", result);
                break;
            case 2:
                printf("Enter the radius of the circle: ");
                scanf("%f", &radius);

                result = circlePerimeter(radius);
                printf("Perimeter of circle: %.2f\n", result);

                result = circleArea(radius);
                printf("Area of circle: %.2f\n", result);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 0);

    return 0;
}