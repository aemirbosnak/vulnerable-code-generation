//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: imaginative
#include <stdio.h>
#include <math.h>

#define PI 3.14159

void draw_circle(int x, int y, int r) {
    int i, j;
    int x0 = 0, y0 = r;
    int d = 3 - 2 * r;
    while (x0 <= y0) {
        for (i = x0; i <= y0; i++) {
            printf("*");
        }
        for (j = x0 + 1; j < y0; j++) {
            printf(" ");
        }
        printf("\n");
        if (d < 0) {
            d += 4 * x0 + 6;
        } else {
            d += 4 * (x0 - y0) + 10;
            x0++;
        }
        y0--;
    }
}

void draw_rectangle(int x, int y, int w, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void draw_triangle(int x, int y, int w, int h) {
    int i;
    for (i = 0; i < h; i++) {
        printf("*");
        if (i < h / 2) {
            printf(" ");
        } else {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int choice, x, y, w, h, r;
    printf("Enter 1 to draw a circle\n");
    printf("Enter 2 to draw a rectangle\n");
    printf("Enter 3 to draw a triangle\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the center coordinates of the circle (x,y): ");
            scanf("%d %d", &x, &y);
            printf("Enter the radius of the circle: ");
            scanf("%d", &r);
            draw_circle(x, y, r);
            break;
        case 2:
            printf("Enter the top-left coordinates of the rectangle (x,y): ");
            scanf("%d %d", &x, &y);
            printf("Enter the width and height of the rectangle: ");
            scanf("%d %d", &w, &h);
            draw_rectangle(x, y, w, h);
            break;
        case 3:
            printf("Enter the top-left coordinates of the triangle (x,y): ");
            scanf("%d %d", &x, &y);
            printf("Enter the width and height of the triangle: ");
            scanf("%d %d", &w, &h);
            draw_triangle(x, y, w, h);
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}