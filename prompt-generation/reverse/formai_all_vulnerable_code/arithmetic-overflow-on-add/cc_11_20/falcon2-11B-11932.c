//Falcon2-11B DATASET v1.0 Category: Pixel Art Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    char shape;
    int dim1, dim2, radius;

    printf("Welcome to the Pixel Art Generator!\n");
    printf("What shape would you like to draw? (S for square, T for triangle, C for circle)\n");
    scanf("%c", &shape);

    switch(shape) {
        case 'S':
            printf("Enter the dimensions of the square:\n");
            scanf("%d %d", &dim1, &dim2);
            break;
        case 'T':
            printf("Enter the dimensions of the triangle:\n");
            scanf("%d %d", &dim1, &dim2);
            break;
        case 'C':
            printf("Enter the radius of the circle:\n");
            scanf("%d", &radius);
            break;
        default:
            printf("Invalid shape!\n");
            return 0;
    }

    if (dim1 < 0 || dim2 < 0 || radius <= 0) {
        printf("Invalid dimensions!\n");
        return 0;
    }

    int width = (dim1 + 1) * 2;
    int height = (dim2 + 1) * 2;
    int radius_squared = radius * radius;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x >= dim1 && y >= dim2) {
                printf(" ");
            } else if (x >= dim1 && y >= dim2 && x <= width - dim1 && y <= height - dim2) {
                printf("#");
            } else if (x >= dim1 && y >= dim2 && x <= width - dim1 && y <= height - dim2 && x + y <= radius_squared) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}