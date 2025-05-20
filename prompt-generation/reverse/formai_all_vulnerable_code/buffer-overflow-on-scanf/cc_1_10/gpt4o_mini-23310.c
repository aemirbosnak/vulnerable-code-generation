//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define WIDTH 40
#define HEIGHT 20

void draw_pixel(int x, int y, char canvas[HEIGHT][WIDTH], char c) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        canvas[y][x] = c;
    }
}

void clear_canvas(char canvas[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            canvas[y][x] = ' ';
        }
    }
}

void display_canvas(char canvas[HEIGHT][WIDTH]) {
    system("clear"); // Clear the console for a better display
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", canvas[y][x]);
        }
        printf("\n");
    }
}

void draw_shape(char canvas[HEIGHT][WIDTH], int shape) {
    switch (shape) {
        case 0: // Draw a square
            for (int y = 5; y < 10; y++) {
                for (int x = 5; x < 10; x++) {
                    draw_pixel(x, y, canvas, '#');
                }
            }
            break;
        case 1: // Draw a triangle
            for (int y = 0; y < 5; y++) {
                for (int x = 5 - y; x <= 5 + y; x++) {
                    draw_pixel(x, y + 10, canvas, '*');
                }
            }
            break;
        case 2: // Draw a circle
            for (int y = 0; y < 10; y++) {
                for (int x = 0; x < 10; x++) {
                    if ((x - 5) * (x - 5) + (y - 5) * (y - 5) <= 16) {
                        draw_pixel(x + 20, y, canvas, '@');
                    }
                }
            }
            break;
    }
}

void input_shape() {
    printf("Choose a shape to draw:\n");
    printf("0: Square\n");
    printf("1: Triangle\n");
    printf("2: Circle\n");
    printf("Enter your choice (0-2): ");
}

int main() {
    char canvas[HEIGHT][WIDTH];
    int shape;

    clear_canvas(canvas);  
    input_shape();
    scanf("%d", &shape);

    if (shape < 0 || shape > 2) {
        printf("Invalid choice. Exiting program.\n");
        return 1;
    }

    clear_canvas(canvas);
    draw_shape(canvas, shape);
    display_canvas(canvas);
    return 0;
}