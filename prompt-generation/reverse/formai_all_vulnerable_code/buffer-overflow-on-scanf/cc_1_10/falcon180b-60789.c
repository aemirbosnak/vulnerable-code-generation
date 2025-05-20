//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: single-threaded
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

void draw_circle(int x, int y, int radius) {
    int i, j, x1, y1;
    for (i = 0; i <= radius; i++) {
        x1 = x + i;
        y1 = y + radius;
        printf("*");
        for (j = 0; j < 2*radius - i; j++) {
            if (i == 0 || i == radius || j == 0 || j == 2*radius - i - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void draw_square(int x, int y, int side) {
    int i, j;
    for (i = 0; i < side; i++) {
        for (j = 0; j < side; j++) {
            if (i == 0 || i == side - 1 || j == 0 || j == side - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void draw_triangle(int x, int y, int side) {
    int i, j;
    for (i = 0; i < side; i++) {
        for (j = 0; j < side; j++) {
            if (i == 0 || i == side - 1 || j == 0 || j == side - 1) {
                printf("*");
            } else if (i == side/2 && j == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, side;
    printf("Enter your choice:\n");
    printf("1. Draw a circle\n2. Draw a square\n3. Draw a triangle\n");
    scanf("%d", &choice);
    printf("Enter the side length: ");
    scanf("%d", &side);

    switch (choice) {
        case 1:
            draw_circle(0, 0, side);
            break;
        case 2:
            draw_square(0, 0, side);
            break;
        case 3:
            draw_triangle(0, 0, side);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}