//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For usleep
#include <pthread.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

char pixel_art[HEIGHT][WIDTH];

// Function prototypes
void draw_pixel(int x, int y, char symbol);
void clear_screen();
void *generate_art(void *arg);
void print_art();

typedef struct {
    char symbol;
    int frequency;
} art_info;

int main() {
    pthread_t thread;

    // Define the pixel art symbols and their respective frequencies
    art_info symbols[] = {
        {'#', 3},
        {'*', 5},
        {'@', 7},
        {'o', 10},
        {' ', 1}
    };

    // Create a thread to generate pixel art
    if (pthread_create(&thread, NULL, generate_art, symbols) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // Join the thread to ensure it finishes execution
    pthread_join(thread, NULL);

    // Print the generated pixel art
    print_art();

    return 0;
}

// Function to randomly draw a pixel on the canvas
void draw_pixel(int x, int y, char symbol) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        pixel_art[y][x] = symbol;
    }
}

// Function to clear the screen
void clear_screen() {
    // ANSI escape code to clear the terminal
    printf("\033[H\033[J");
}

// Function to generate the pixel art asynchronously
void *generate_art(void *arg) {
    art_info *symbols = (art_info *)arg;
    srand(time(NULL));

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // Randomly select a symbol based on their frequency
            int total_frequency = 0;
            for (int k = 0; symbols[k].symbol != '\0'; k++) {
                total_frequency += symbols[k].frequency;
            }

            int random_value = rand() % total_frequency;
            char selected_symbol = ' ';
            for (int k = 0; symbols[k].symbol != '\0'; k++) {
                if (random_value < symbols[k].frequency) {
                    selected_symbol = symbols[k].symbol;
                    break;
                }
                random_value -= symbols[k].frequency;
            }

            draw_pixel(j, i, selected_symbol);
            usleep(100000); // Sleep for 100 milliseconds
        }
    }
    return NULL;
}

// Function to print the pixel art
void print_art() {
    clear_screen();
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", pixel_art[i][j]);
        }
        printf("\n");
    }
}