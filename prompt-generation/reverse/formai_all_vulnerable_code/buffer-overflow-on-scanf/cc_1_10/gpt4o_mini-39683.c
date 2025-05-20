//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // for sleep
#include <time.h>   // for random seed

#define WIDTH 32
#define HEIGHT 16

const char *colors[] = {
    "  ",   // Black
    "░░",   // Dark Gray
    "▒▒",   // Gray
    "▓▓",   // Light Gray
    "██",   // White
    "██",   // Red
    "██",   // Green
    "██",   // Blue
    "██",   // Yellow
    "██",   // Cyan
    "██",   // Magenta
};

unsigned char canvas[HEIGHT][WIDTH]; // The art canvas

void clear_canvas() {
    memset(canvas, 0, sizeof(canvas)); // Clear all pixels
}

void draw_pixel(int x, int y, unsigned char color) {
    if(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        canvas[y][x] = color; // Set the pixel to the designated color
    }
}

void display_canvas() {
    printf("\033[H\033[J"); // Clear screen and move cursor to top-left corner
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%s", colors[canvas[y][x]]); // Print each pixel
        }
        printf("\n");
    }
}

void generate_pattern1() {
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            if ((x + y) % 2 == 0) {
                draw_pixel(x, y, 1); // Dark Gray
            } else {
                draw_pixel(x, y, 2); // Gray
            }
        }
    }
}

void generate_pattern2() {
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            if (x < WIDTH / 2 && y < HEIGHT / 2) {
                draw_pixel(x, y, 5); // Red
            } else if (x >= WIDTH / 2 && y < HEIGHT / 2) {
                draw_pixel(x, y, 6); // Green
            } else if (x < WIDTH / 2 && y >= HEIGHT / 2) {
                draw_pixel(x, y, 7); // Blue
            } else {
                draw_pixel(x, y, 8); // Yellow
            }
        }
    }
}

void random_fill() {
    srand(time(NULL));
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            draw_pixel(x, y, rand() % 10); // Random color
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("Welcome to the Pixel Art Generator!\n");
        printf("Choose an option:\n");
        printf("1. Generate Pattern 1\n");
        printf("2. Generate Pattern 2\n");
        printf("3. Random Fill\n");
        printf("4. Clear Canvas\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                clear_canvas();        
                generate_pattern1();
                display_canvas();
                break;

            case 2:
                clear_canvas();        
                generate_pattern2();
                display_canvas();
                break;

            case 3:
                clear_canvas();
                random_fill();
                display_canvas();
                break;

            case 4:
                clear_canvas();
                display_canvas();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid option! Please select again.\n");
        }

        sleep(2); // Pause for 2 seconds before returning to the menu
    }

    return 0;
}