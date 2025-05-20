//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

// Function to generate random numbers between 0 and 1
double rand01() {
    return (double) rand() / RAND_MAX;
}

// Function to generate random colors
int randColor() {
    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;
    return (r << 16) | (g << 8) | b;
}

// Function to generate random fractal patterns
void fractal(int x, int y, int depth) {
    if (depth == 0) {
        printf(".");
        return;
    }

    // Choose a random direction
    int dx = rand() % 3 - 1;
    int dy = rand() % 3 - 1;

    // Choose a random color
    int color = randColor();

    // Print the fractal pattern
    printf("\033[38;2;%06x;%06x;%06xm", (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
    printf("║");
    fractal(x + dx, y + dy, depth - 1);
}

// Function to generate a random surrealist image
void surrealist(int width, int height) {
    srand(time(NULL));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fractal(x, y, rand() % 10);
        }
        printf("\n");
    }
}

int main() {
    int width, height;

    // Get the width and height of the image from the user
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);

    // Generate the surrealist image
    surrealist(width, height);

    return 0;
}