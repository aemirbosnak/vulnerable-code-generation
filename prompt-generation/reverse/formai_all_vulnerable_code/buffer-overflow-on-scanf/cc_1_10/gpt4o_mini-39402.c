//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define COLOR_COUNT 7

const char *COLOR_NAMES[] = {
    "Red", "Green", "Blue", "Yellow", "Magenta", "Cyan", "White"
};

const char *COLOR_CODES[] = {
    "\033[31m", "\033[32m", "\033[34m", "\033[33m", "\033[35m", "\033[36m", "\033[37m"
};

void print_pixel(char *color) {
    printf("%s⬛ ", color);
}

void print_row(int width, const char *color_code) {
    for (int i = 0; i < width; i++) {
        print_pixel(color_code);
    }
    printf("\033[0m\n"); // Reset color
}

void generate_pixel_art(int pattern[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            print_row(1, COLOR_CODES[pattern[i][j]]);
        }
    }
}

void initialize_random_pattern(int pattern[HEIGHT][WIDTH]) {
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pattern[i][j] = rand() % COLOR_COUNT;
        }
    }
}

void print_color_menu() {
    printf("Choose Colors for Pixel Art:\n");
    for (int i = 0; i < COLOR_COUNT; i++) {
        printf("%d: %s\n", i, COLOR_NAMES[i]);
    }
    printf("Enter -1 to generate a random pattern.\n");
}

void fill_custom_pattern(int pattern[HEIGHT][WIDTH]) {
    int color_choice;
    printf("Enter your pixel pattern (0 to %d):\n", COLOR_COUNT - 1);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("Pixel[%d][%d]: ", i, j);
            scanf("%d", &color_choice);
            if (color_choice >= 0 && color_choice < COLOR_COUNT) {
                pattern[i][j] = color_choice;
            } else {
                printf("Invalid input, defaulting to White.\n");
                pattern[i][j] = 6; // Default to White
            }
        }
    }
}

int main() {
    int pixel_pattern[HEIGHT][WIDTH];
    
    printf("Welcome to the C Pixel Art Generator!\n\n");
    
    print_color_menu();
    
    int custom_choice;
    printf("Would you like to create a custom pixel art pattern? (1 for Yes, 0 for No): ");
    scanf("%d", &custom_choice);
    
    if (custom_choice == 1) {
        fill_custom_pattern(pixel_pattern);
    } else {
        initialize_random_pattern(pixel_pattern);
    }
    
    printf("\nGenerated Pixel Art:\n\n");
    generate_pixel_art(pixel_pattern);

    return 0;
}