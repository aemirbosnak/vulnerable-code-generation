//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random color
void random_color(int* r, int* g, int* b) {
    *r = rand() % 256;
    *g = rand() % 256;
    *b = rand() % 256;
}

// Function to print a pixel
void print_pixel(int x, int y, int r, int g, int b) {
    printf("\033[48;2;%d;%d;%dm ", r, g, b);
    printf("\033[H");
}

// Recursive function to generate fractal pattern
void fractal(int x1, int y1, int x2, int y2, int depth) {
    if (depth == 0) {
        print_pixel(x1, y1, 0, 0, 0);
        return;
    }

    // Divide the line into two parts
    int x3 = (x1 + x2) / 2;
    int y3 = (y1 + y2) / 2;

    // Recursively draw the left part
    fractal(x1, y1, x3, y3, depth - 1);

    // Recursively draw the right part
    fractal(x3, y3, x2, y2, depth - 1);
}

int main() {
    srand(time(NULL));

    int width, height;
    printf("Enter the width and height of the image: ");
    scanf("%d %d", &width, &height);

    // Clear the console
    system("clear");

    // Loop through each pixel and generate fractal pattern
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r, g, b;
            random_color(&r, &g, &b);
            fractal(0, y, width - 1, y, 10);
            printf("\n");
        }
    }

    return 0;
}