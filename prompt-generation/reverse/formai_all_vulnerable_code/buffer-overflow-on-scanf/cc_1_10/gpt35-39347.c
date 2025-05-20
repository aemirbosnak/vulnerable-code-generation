//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: cheerful
#include <stdio.h>

int main() {

    printf("Welcome to C Geometric Algorithms program!\n");

    float base, height, radius, side, apothem, perimeter, area;
    int choice;

    printf("\nEnter your choice of shape: \n");
    printf("1. Triangle\n");
    printf("2. Circle\n");
    printf("3. Square\n");
    printf("4. Regular Pentagon\n");
    printf("5. Exit\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEnter the base and height of triangle: ");
            scanf("%f %f", &base, &height);
            area = 0.5 * base * height;
            perimeter = 3 * base;
            printf("\nTriangle area: %.2f", area);
            printf("\nTriangle perimeter: %.2f", perimeter);
            break;
        case 2:
            printf("\nEnter the radius of circle: ");
            scanf("%f", &radius);
            area = 3.14 * radius * radius;
            perimeter = 2 * 3.14 * radius;
            printf("\nCircle area: %.2f", area);
            printf("\nCircle circumference: %.2f", perimeter);
            break;
        case 3:
            printf("\nEnter the side of square: ");
            scanf("%f", &side);
            area = side * side;
            perimeter = 4 * side;
            printf("\nSquare area: %.2f", area);
            printf("\nSquare perimeter: %.2f", perimeter);
            break;
        case 4:
            printf("\nEnter the side and apothem of regular pentagon: ");
            scanf("%f %f", &side, &apothem);
            area = 0.5 * 5 * side * apothem;
            perimeter = 5 * side;
            printf("\nRegular pentagon area: %.2f", area);
            printf("\nRegular pentagon perimeter: %.2f", perimeter);
            break;
        case 5:
            printf("\nThanks for using the program!");
            return 0;
        default:
            printf("\nInvalid choice, try again!");
    }

    return 0;
}