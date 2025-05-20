//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

void clear_screen() {
    printf("\033[H\033[J");
}

void set_color(int fg, int bg) {
    printf("\033[38;5;%dm\033[48;5;%dm", fg, bg);
}

void reset_color() {
    printf("\033[0m");
}

void draw_pixel(int fg, int bg) {
    set_color(fg, bg);
    printf("  "); // Representing a pixel with two spaces
    reset_color();
}

void draw_canvas(int width, int height, int fg_color[][MAX_WIDTH], int bg_color[][MAX_WIDTH]) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            draw_pixel(fg_color[y][x], bg_color[y][x]);
        }
        printf("\n");
    }
}

void generate_pixel_art(int width, int height) {
    int fg_color[MAX_HEIGHT][MAX_WIDTH];
    int bg_color[MAX_HEIGHT][MAX_WIDTH];

    // Initialize colors for some simple shapes
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fg_color[y][x] = 15; // Default foreground white
            bg_color[y][x] = 0;  // Default background black
        }
    }

    // A simple smiley face
    for (int x = 30; x < 70; x++) {
        fg_color[10][x] = 11; // Yellow for the face
        bg_color[10][x] = 0;
    }

    fg_color[12][40] = 0; // Left Eye
    bg_color[12][40] = 7; // White Background
    fg_color[12][60] = 0; // Right Eye
    bg_color[12][60] = 7; // White Background

    // Mouth
    fg_color[14][42] = 0; // Mouth left
    bg_color[14][42] = 7; // Background white
    fg_color[14][43] = 0; // Mouth middle
    bg_color[14][43] = 7; // Background white
    fg_color[14][44] = 0; // Mouth right
    bg_color[14][44] = 7; // Background white

    // Draw the canvas with the created pixel art
    draw_canvas(width, height, fg_color, bg_color);
}

int main() {
    int width, height;

    // Get canvas dimensions from the user
    printf("Enter canvas width (max %d): ", MAX_WIDTH);
    scanf("%d", &width);
    if (width > MAX_WIDTH) width = MAX_WIDTH;

    printf("Enter canvas height (max %d): ", MAX_HEIGHT);
    scanf("%d", &height);
    if (height > MAX_HEIGHT) height = MAX_HEIGHT;

    clear_screen();
    generate_pixel_art(width, height);

    return 0;
}