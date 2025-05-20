//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: beginner-friendly
#include <stdio.h>

#define PI 3.14159265358979323846

void main() {
    int choice;
    float side, radius, length, width, base, height;

    printf("Welcome to the Shape Area Calculator!\n");
    printf("Please choose the shape you want to calculate the area for:\n");
    printf("1. Square\n");
    printf("2. Circle\n");
    printf("3. Rectangle\n");
    printf("4. Triangle\n");
    printf("5. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the length of a side: ");
            scanf("%f", &side);
            printf("The area of the square is: %f\n", side * side);
            break;

        case 2:
            printf("Enter the radius of the circle: ");
            scanf("%f", &radius);
            printf("The area of the circle is: %f\n", PI * radius * radius);
            break;

        case 3:
            printf("Enter the length of the rectangle: ");
            scanf("%f", &length);
            printf("Enter the width of the rectangle: ");
            scanf("%f", &width);
            printf("The area of the rectangle is: %f\n", length * width);
            break;

        case 4:
            printf("Enter the base of the triangle: ");
            scanf("%f", &base);
            printf("Enter the height of the triangle: ");
            scanf("%f", &height);
            printf("The area of the triangle is: %f\n", 0.5 * base * height);
            break;

        case 5:
            printf("Exiting the program...\n");
            break;

        default:
            printf("Invalid choice! Please choose a valid shape.\n");
            break;
    }
}