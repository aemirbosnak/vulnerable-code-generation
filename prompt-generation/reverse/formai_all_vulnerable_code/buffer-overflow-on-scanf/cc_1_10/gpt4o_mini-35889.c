//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 16
#define HEIGHT 16

// Define the color palette
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

char canvas[HEIGHT][WIDTH];

// Initializes the canvas with spaces
void init_canvas() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            canvas[y][x] = ' ';
        }
    }
}

// Fills a pixel at (x, y) with a given character
void set_pixel(int x, int y, char pixel) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        canvas[y][x] = pixel;
    }
}

// Displays the canvas with colors
void display_canvas() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            char pixel = canvas[y][x];

            // Color the pixels based on their character
            switch (pixel) {
                case 'R':
                    printf(RED "%c" RESET, pixel);
                    break;
                case 'G':
                    printf(GREEN "%c" RESET, pixel);
                    break;
                case 'B':
                    printf(BLUE "%c" RESET, pixel);
                    break;
                case 'Y':
                    printf(YELLOW "%c" RESET, pixel);
                    break;
                case 'M':
                    printf(MAGENTA "%c" RESET, pixel);
                    break;
                case 'C':
                    printf(CYAN "%c" RESET, pixel);
                    break;
                default:
                    printf(" " RESET);
                    break;
            }
        }
        printf("\n");
    }
}

// Generate a random pixel pattern
void generate_random_pixel_pattern() {
    const char colors[] = {'R', 'G', 'B', 'Y', 'M', 'C', ' '};
    srand(time(NULL));  // Seed for randomness

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int random_index = rand() % (sizeof(colors) - 1); // Exclude space character
            set_pixel(x, y, colors[random_index]);
        }
    }
}

// Draw a simple pattern (a smiley face)
void draw_smiley_face() {
    init_canvas();
    
    // Drawing eyes
    set_pixel(4, 4, 'B');
    set_pixel(11, 4, 'B');
    
    // Drawing mouth
    set_pixel(6, 10, 'Y');
    set_pixel(7, 9, 'Y');
    set_pixel(8, 8, 'Y');
    set_pixel(9, 9, 'Y');
    set_pixel(10, 10, 'Y');

    // Display the canvas
    display_canvas();
}

int main() {
    printf("Welcome to the C Pixel Art Generator!\n");

    char choice;
    printf("Choose an option:\n");
    printf("1. Generate Random Pixel Art\n");
    printf("2. Draw Smiley Face\n");
    printf("Enter your choice (1/2): ");
    scanf(" %c", &choice);

    if (choice == '1') {
        init_canvas();
        generate_random_pixel_pattern();
        display_canvas();
    } else if (choice == '2') {
        draw_smiley_face();
    } else {
        printf("Invalid choice. Please restart and choose 1 or 2.\n");
    }

    return 0;
}