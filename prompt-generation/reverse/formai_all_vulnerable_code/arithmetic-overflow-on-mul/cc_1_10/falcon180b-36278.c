//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define colors
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

// Define escape character for reset color
#define RESET "\033[0m"

// Function to generate fractal
void fractal(int x, int y, int depth) {
    if (depth == 0) {
        // Base case: draw a pixel
        printf("%c", '*');
        return;
    }

    // Recursive case: draw a fractal
    int size = (int) pow(2, depth);
    int half_size = size / 2;

    // Draw top half of fractal
    for (int i = 0; i < half_size; i++) {
        fractal(x - half_size + i, y - half_size, depth - 1);
    }

    // Draw bottom half of fractal
    for (int i = 0; i < half_size; i++) {
        fractal(x - half_size + i, y + half_size, depth - 1);
    }

    // Draw left half of fractal
    for (int i = 0; i < half_size; i++) {
        fractal(x - half_size, y - half_size + i, depth - 1);
    }

    // Draw right half of fractal
    for (int i = 0; i < half_size; i++) {
        fractal(x + half_size, y - half_size + i, depth - 1);
    }
}

int main() {
    int width, height, max_depth;

    // Get user input
    printf(YELLOW "Enter the width of the fractal image: " RESET);
    scanf("%d", &width);

    printf(YELLOW "Enter the height of the fractal image: " RESET);
    scanf("%d", &height);

    printf(YELLOW "Enter the maximum depth of the fractal: " RESET);
    scanf("%d", &max_depth);

    // Calculate number of pixels
    int num_pixels = width * height;

    // Print fractal image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fractal(x, y, max_depth);
        }
        printf("\n");
    }

    return 0;
}