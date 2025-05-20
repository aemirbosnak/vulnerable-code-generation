//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265359

int main() {
    float radius, area, perimeter;
    char choice;

    printf("Enter the shape you want to calculate for:\n");
    printf("1. Circle\n2. Rectangle\n3. Triangle\n");
    scanf("%c", &choice);

    switch(choice) {
        case '1':
            printf("Enter the radius of the circle: ");
            scanf("%f", &radius);

            area = PI * radius * radius;
            perimeter = 2 * PI * radius;

            printf("\nFor the circle:\n");
            printf("Area = %.2f\n", area);
            printf("Perimeter = %.2f\n", perimeter);

            break;

        case '2':
            printf("Enter the length of the rectangle: ");
            scanf("%f", &radius);
            printf("Enter the width of the rectangle: ");
            scanf("%f", &radius);

            area = radius * radius;
            perimeter = 2 * (radius + radius);

            printf("\nFor the rectangle:\n");
            printf("Area = %.2f\n", area);
            printf("Perimeter = %.2f\n", perimeter);

            break;

        case '3':
            printf("Enter the length of the base of the triangle: ");
            scanf("%f", &radius);
            printf("Enter the height of the triangle: ");
            scanf("%f", &radius);

            area = 0.5 * radius * radius;
            perimeter = 2 * (radius + radius);

            printf("\nFor the triangle:\n");
            printf("Area = %.2f\n", area);
            printf("Perimeter = %.2f\n", perimeter);

            break;

        default:
            printf("\nInvalid choice!\n");
            exit(0);
    }

    return 0;
}