//Falcon2-11B DATASET v1.0 Category: Geometric algorithms ; Style: shape shifting
#include <stdio.h>

int main() {
    int x = 0, y = 0, r = 0;
    char shape;

    printf("Enter the shape of the circle: ");
    scanf("%c", &shape);

    switch(shape) {
        case 'C':
            printf("Circle is drawn.");
            break;
        case 'O':
            printf("Oval is drawn.");
            break;
        case 'R':
            printf("Rectangle is drawn.");
            break;
        case 'T':
            printf("Triangle is drawn.");
            break;
        default:
            printf("Invalid shape entered.");
            break;
    }

    printf("Enter the radius of the circle: ");
    scanf("%d", &r);

    switch(shape) {
        case 'C':
            printf("Circle with radius %d is drawn.", r);
            break;
        case 'O':
            printf("Oval with radius %d is drawn.", r);
            break;
        case 'R':
            printf("Rectangle with width %d and height %d is drawn.", r, r);
            break;
        case 'T':
            printf("Triangle with base %d and height %d is drawn.", r, r);
            break;
        default:
            printf("Invalid shape entered.");
            break;
    }

    return 0;
}