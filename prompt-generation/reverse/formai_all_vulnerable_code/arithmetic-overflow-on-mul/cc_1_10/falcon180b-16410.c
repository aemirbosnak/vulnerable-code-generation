//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

void draw_circle(int x, int y, int r) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < r; j++) {
            if (i * i + j * j <= r * r) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void draw_rectangle(int x, int y, int w, int h) {
    int i, j;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void draw_triangle(int x, int y, int s) {
    int i, j;
    for (i = 0; i < s; i++) {
        for (j = 0; j < s; j++) {
            if (i == j || i + j == s - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int x = 0, y = 0, r = 0, s = 0;
    printf("Enter the coordinates of the center of the shape (x y): ");
    scanf("%d %d", &x, &y);
    printf("Enter the radius of the circle: ");
    scanf("%d", &r);
    printf("Enter the side length of the triangle: ");
    scanf("%d", &s);
    draw_circle(x, y, r);
    draw_rectangle(x, y, r, r);
    draw_triangle(x, y, s);
    return 0;
}