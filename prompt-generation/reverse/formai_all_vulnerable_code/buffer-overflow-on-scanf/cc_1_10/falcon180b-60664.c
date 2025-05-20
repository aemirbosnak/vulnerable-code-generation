//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: synchronous
// This program generates pixel art in the console using C
// It allows the user to input the dimensions of the canvas,
// as well as the colors and shapes to be used in the art.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print a pixel in the console
void print_pixel(int x, int y, int color) {
    printf("\033[0;%d;%dm ", x, color);
}

// Function to generate a random color
int random_color() {
    return rand() % 8 + 30;
}

// Function to clear the console
void clear_console() {
    printf("\033[H\033[2J");
}

// Function to generate pixel art
void generate_art(int width, int height, int shape, int color) {
    srand(time(NULL));

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (shape == 1) {
                print_pixel(i, j, color);
            } else if (shape == 2) {
                if (i % 2 == 0 && j % 2 == 0) {
                    print_pixel(i, j, color);
                }
            } else if (shape == 3) {
                if (i % 3 == 0 && j % 3 == 0) {
                    print_pixel(i, j, color);
                }
            }
        }
    }
}

int main() {
    int width, height, shape, color;

    // Get user input for canvas dimensions
    printf("Enter the width of the canvas: ");
    scanf("%d", &width);
    printf("Enter the height of the canvas: ");
    scanf("%d", &height);

    // Get user input for shape and color
    printf("Enter the shape of the pixels (1 for square, 2 for checkerboard, 3 for triangle): ");
    scanf("%d", &shape);
    printf("Enter the color of the pixels (0-7): ");
    scanf("%d", &color);

    // Clear the console
    clear_console();

    // Generate the pixel art
    generate_art(width, height, shape, color);

    return 0;
}