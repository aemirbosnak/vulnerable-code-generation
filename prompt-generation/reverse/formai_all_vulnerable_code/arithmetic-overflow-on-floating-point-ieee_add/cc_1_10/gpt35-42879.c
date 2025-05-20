//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: shape shifting
#include <stdio.h>

int main() {
    int shape = 0;
    float r, l, w, b, h, area = 0, perimeter = 0, volume = 0, pi = 3.14;
    printf("Welcome to the Geometric Shape Shifter!\n");
    printf("Choose the shape you want to transform:\n");
    printf("1. Circle\n");
    printf("2. Square\n");
    printf("3. Rectangle\n");
    printf("4. Triangle\n");
    printf("5. Sphere\n");
    printf("Enter your choice: ");
    scanf("%d", &shape);
    switch(shape) {
        case 1: 
            printf("Enter the radius of the circle: ");
            scanf("%f", &r);
            area = pi * r * r;
            perimeter = 2 * pi * r;
            printf("The circle with radius %.2f has an area of %.2f and a perimeter of %.2f.\n", r, area, perimeter);
            break;
        case 2:
            printf("Enter the length of the side of the square: ");
            scanf("%f", &l);
            area = l * l;
            perimeter = 4 * l;
            printf("The square with side length %.2f has an area of %.2f and a perimeter of %.2f.\n", l, area, perimeter);
            break;
        case 3:
            printf("Enter the length and width of the rectangle: ");
            scanf("%f %f", &l, &w);
            area = l * w;
            perimeter = 2 * (l + w);
            printf("The rectangle with length %.2f and width %.2f has an area of %.2f and a perimeter of %.2f.\n", l, w, area, perimeter);
            break;
        case 4:
            printf("Enter the base and height of the triangle: ");
            scanf("%f %f", &b, &h);
            area = 0.5 * b * h;
            printf("The triangle with base %.2f and height %.2f has an area of %.2f.\n", b, h, area);
            break;
        case 5:
            printf("Enter the radius of the sphere: ");
            scanf("%f", &r);
            area = 4 * pi * r * r;
            volume = (4.0 / 3.0) * pi * r * r * r;
            printf("The sphere with radius %.2f has an area of %.2f and a volume of %.2f.\n", r, area, volume);
            break;
        default:
            printf("Invalid input. Please choose a number between 1 and 5.\n");
            break;
    }
    return 0;
}