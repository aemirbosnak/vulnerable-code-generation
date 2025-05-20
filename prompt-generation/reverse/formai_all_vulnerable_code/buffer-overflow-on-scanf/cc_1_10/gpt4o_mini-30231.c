//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 5
#define HEIGHT 5

// Define colors using ANSI escape codes
const char* colors[] = {
    "\033[0;30m", // Black
    "\033[0;31m", // Red
    "\033[0;32m", // Green
    "\033[0;33m", // Yellow
    "\033[0;34m", // Blue
    "\033[0;35m", // Magenta
    "\033[0;36m", // Cyan
    "\033[0;37m", // White
    "\033[0m"     // Reset
};

void draw_pixel_art(int art[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int color = art[y][x];
            printf("%s  ", colors[color]);
        }
        printf("\033[0m\n"); // Reset color after each row
    }
}

void init_art(int art[HEIGHT][WIDTH]) {
    memset(art, 0, sizeof(int) * HEIGHT * WIDTH); // Initialize to black
}

void create_panda(int art[HEIGHT][WIDTH]) {
    // Simple panda pixel art
    int panda[HEIGHT][WIDTH] = {
        {0, 1, 1, 1, 0},
        {1, 0, 0, 0, 1},
        {1, 0, 2, 0, 1},
        {0, 1, 0, 1, 0},
        {0, 0, 3, 0, 0}
    };
    memcpy(art, panda, sizeof(panda));
}

void create_cat(int art[HEIGHT][WIDTH]) {
    // Simple cat face pixel art
    int cat[HEIGHT][WIDTH] = {
        {0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {1, 0, 2, 0, 1},
        {0, 3, 3, 3, 0},
        {0, 0, 0, 0, 0}
    };
    memcpy(art, cat, sizeof(cat));
}

int main() {
    int art[HEIGHT][WIDTH];
    char choice;

    printf("Welcome to the Pixel Art Generator!\n");
    printf("Choose your pixel art:\n");
    printf("1. Panda\n");
    printf("2. Cat\n");
    printf("Choose 1 or 2: ");
    scanf(" %c", &choice);
    
    init_art(art);

    if (choice == '1') {
        create_panda(art);
    } else if (choice == '2') {
        create_cat(art);
    } else {
        printf("Invalid choice! Defaulting to Panda.\n");
        create_panda(art);
    }

    printf("\nHere is your Pixel Art:\n");
    draw_pixel_art(art);

    printf("\033[0m"); // Final reset
    return 0;
}