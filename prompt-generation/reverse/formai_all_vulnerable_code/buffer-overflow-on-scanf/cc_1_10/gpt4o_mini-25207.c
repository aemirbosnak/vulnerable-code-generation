//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

void draw_line(int x1, int y1, int x2, int y2);
void draw_circle(int xc, int yc, int radius);
void draw_rectangle(int x1, int y1, int width, int height);
void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3);

void plot_point(int x, int y);
void delay(unsigned int mseconds);
void draw_shapes();

int main() {
    printf("Welcome to the Retro Geometric Shapes Drawer!\n");
    draw_shapes();
    return 0;
}

void draw_shapes() {
    int choice = 0;

    while (1) {
        printf("\nChoose a shape to draw:\n");
        printf("1. Line\n");
        printf("2. Circle\n");
        printf("3. Rectangle\n");
        printf("4. Triangle\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int x1, y1, x2, y2;
                printf("Enter starting point (x1 y1): ");
                scanf("%d %d", &x1, &y1);
                printf("Enter ending point (x2 y2): ");
                scanf("%d %d", &x2, &y2);
                draw_line(x1, y1, x2, y2);
                break;
            }
            case 2: {
                int xc, yc, radius;
                printf("Enter center of circle (xc yc) and radius: ");
                scanf("%d %d %d", &xc, &yc, &radius);
                draw_circle(xc, yc, radius);
                break;
            }
            case 3: {
                int x1, y1, width, height;
                printf("Enter top-left corner (x1 y1) and width, height: ");
                scanf("%d %d %d %d", &x1, &y1, &width, &height);
                draw_rectangle(x1, y1, width, height);
                break;
            }
            case 4: {
                int x1, y1, x2, y2, x3, y3;
                printf("Enter vertices (x1 y1 x2 y2 x3 y3): ");
                scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
                draw_triangle(x1, y1, x2, y2, x3, y3);
                break;
            }
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
        delay(3000);
    }
}

void draw_line(int x1, int y1, int x2, int y2) {
    printf("Drawing line from (%d, %d) to (%d, %d)...\n", x1, y1, x2, y2);
    // Here would be the line drawing algorithm, e.g., Bresenham's line algorithm
}

void draw_circle(int xc, int yc, int radius) {
    printf("Drawing circle with center (%d, %d) and radius %d...\n", xc, yc, radius);
    // Here would be the circle drawing algorithm, e.g., Midpoint circle algorithm
}

void draw_rectangle(int x1, int y1, int width, int height) {
    printf("Drawing rectangle at (%d, %d) with width %d and height %d...\n", x1, y1, width, height);
    // Simple rectangle drawing (just four lines)
    draw_line(x1, y1, x1 + width, y1);
    draw_line(x1 + width, y1, x1 + width, y1 + height);
    draw_line(x1 + width, y1 + height, x1, y1 + height);
    draw_line(x1, y1 + height, x1, y1);
}

void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    printf("Drawing triangle with vertices (%d, %d), (%d, %d), (%d, %d)...\n", x1, y1, x2, y2, x3, y3);
    draw_line(x1, y1, x2, y2);
    draw_line(x2, y2, x3, y3);
    draw_line(x3, y3, x1, y1);
}

void plot_point(int x, int y) {
    // Mock function to 'plot' a point on a console (not implemented here)
    printf("Plotting point at (%d, %d)\n", x, y);
}

void delay(unsigned int mseconds) {
    usleep(mseconds * 1000);  // Convert to microseconds
}