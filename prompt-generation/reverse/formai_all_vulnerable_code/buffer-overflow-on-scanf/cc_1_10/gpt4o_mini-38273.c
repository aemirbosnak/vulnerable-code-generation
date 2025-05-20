//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

void draw_triangle(int row, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < (1 << height) - 1; j++) {
            if (j >= (1 << (height - i - 1)) - 1 && j <= (1 << (height - i)) - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void draw_sierpinski(int x1, int y1, int x2, int y2, int x3, int y3, int height) {
    if (height == 0) {
        // Base case: Draw a filled triangle
        printf("Drawing triangle with vertices: (%d, %d), (%d, %d), (%d, %d)\n", x1, y1, x2, y2, x3, y3);
        // The precise drawing has been abstracted for simplicity.
        return;
    }

    int mid_x1 = (x1 + x2) / 2;
    int mid_y1 = (y1 + y2) / 2;
    int mid_x2 = (x2 + x3) / 2;
    int mid_y2 = (y2 + y3) / 2;
    int mid_x3 = (x1 + x3) / 2;
    int mid_y3 = (y1 + y3) / 2;

    draw_sierpinski(x1, y1, mid_x1, mid_y1, mid_x3, mid_y3, height - 1);
    draw_sierpinski(mid_x1, mid_y1, x2, y2, mid_x2, mid_y2, height - 1);
    draw_sierpinski(mid_x3, mid_y3, mid_x2, mid_y2, x3, y3, height - 1);
}

int main() {
    int height;

    printf("Enter the height of the Sierpinski triangle (Recommended 1-6): ");
    scanf("%d", &height);

    if (height < 0 || height > 6) {
        printf("Height must be between 0 and 6!\n");
        return 1;
    }

    int base_width = (1 << height) - 1;
    int x1 = base_width / 2;
    int y1 = 0;
    int x2 = 0;
    int y2 = height;
    int x3 = base_width;
    int y3 = height;

    printf("Sierpinski Triangle of height %d:\n", height);
    draw_triangle(height, height);
    draw_sierpinski(x1, y1, x2, y2, x3, y3, height);

    return 0;
}