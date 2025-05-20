//Falcon2-11B DATASET v1.0 Category: Geometric algorithms ; Style: configurable
#include <stdio.h>

int main() {
    int choice;
    float radius, sideLength, base, height;
    float area;

    do {
        printf("Enter 1 to calculate the area of a circle, 2 for a square, or 3 for a triangle: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the radius of the circle: ");
                scanf("%f", &radius);
                area = 3.14159 * radius * radius;
                printf("The area of the circle is: %.2f\n", area);
                break;
            case 2:
                printf("Enter the length of the side of the square: ");
                scanf("%f", &sideLength);
                area = sideLength * sideLength;
                printf("The area of the square is: %.2f\n", area);
                break;
            case 3:
                printf("Enter the base of the triangle: ");
                scanf("%f", &base);
                printf("Enter the height of the triangle: ");
                scanf("%f", &height);
                area = 0.5 * base * height;
                printf("The area of the triangle is: %.2f\n", area);
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    } while (choice!= 4);

    printf("Do you want to calculate the area of another shape? (Enter 1 for yes, 2 for no): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter 1 to calculate the area of a circle, 2 for a square, or 3 for a triangle: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the radius of the circle: ");
                scanf("%f", &radius);
                area = 3.14159 * radius * radius;
                printf("The area of the circle is: %.2f\n", area);
                break;
            case 2:
                printf("Enter the length of the side of the square: ");
                scanf("%f", &sideLength);
                area = sideLength * sideLength;
                printf("The area of the square is: %.2f\n", area);
                break;
            case 3:
                printf("Enter the base of the triangle: ");
                scanf("%f", &base);
                printf("Enter the height of the triangle: ");
                scanf("%f", &height);
                area = 0.5 * base * height;
                printf("The area of the triangle is: %.2f\n", area);
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    } else if (choice == 2) {
        printf("Thank you for using this program!\n");
    } else {
        printf("Invalid input. Please try again.\n");
    }

    return 0;
}