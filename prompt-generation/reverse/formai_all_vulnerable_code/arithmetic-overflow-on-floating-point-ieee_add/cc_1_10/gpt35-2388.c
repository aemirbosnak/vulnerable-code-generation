//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: real-life
#include <stdio.h>
#include <math.h>

int main() {

    int choice;
    float radius, length, width, base, height, area, perimeter;

    do {
        printf("Welcome to the Geometric Algorithm Program!\n");
        printf("Please select a shape:\n");
        printf("1. Circle\n");
        printf("2. Rectangle\n");
        printf("3. Triangle\n");
        printf("4. Quit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the radius of the circle: ");
                scanf("%f", &radius);
                area = M_PI * radius * radius;
                perimeter = 2 * M_PI * radius;
                printf("\nArea of the circle is: %.2f\n", area);
                printf("Circumference of the circle is: %.2f\n", perimeter);
                break;
            case 2:
                printf("\nEnter the length and width of the rectangle: ");
                scanf("%f %f", &length, &width);
                area = length * width;
                perimeter = 2 * (length + width);
                printf("\nArea of the rectangle is: %.2f\n", area);
                printf("Perimeter of the rectangle is: %.2f\n", perimeter);
                break;
            case 3:
                printf("\nEnter the base and height of the triangle: ");
                scanf("%f %f", &base, &height);
                area = 0.5 * base * height;
                perimeter = base + height + sqrt(base * base + height * height);
                printf("\nArea of the triangle is: %.2f\n", area);
                printf("Perimeter of the triangle is: %.2f\n", perimeter);
                break;
            case 4:
                printf("\nThank you for using the Geometric Algorithm Program!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}