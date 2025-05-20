//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 640
#define HEIGHT 480
#define MAX_COLORS 256

typedef unsigned char uchar;

unsigned char palette[MAX_COLORS][3];
unsigned char framebuffer[WIDTH * HEIGHT];

int main() {
    // Load palette from file
    FILE *palette_file = fopen("palette.txt", "r");
    if (palette_file == NULL) {
        fprintf(stderr, "Error opening palette file\n");
        return 1;
    }

    int num_colors;
    fscanf(palette_file, "%d", &num_colors);

    for (int i = 0; i < num_colors; i++) {
        fscanf(palette_file, "%hhu %hhu %hhu", &palette[i][0], &palette[i][1], &palette[i][2]);
    }

    fclose(palette_file);

    // Create framebuffer
    memset(framebuffer, 0, WIDTH * HEIGHT);

    // Draw pixel art
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Get pixel color
            unsigned char color_index = (x + y) % num_colors;
            unsigned char *color = palette[color_index];

            // Set pixel in framebuffer
            int index = y * WIDTH + x;
            framebuffer[index] = color_index;
        }
    }

    // Write framebuffer to file
    FILE *framebuffer_file = fopen("framebuffer.pbm", "wb");
    if (framebuffer_file == NULL) {
        fprintf(stderr, "Error opening framebuffer file\n");
        return 1;
    }

    fprintf(framebuffer_file, "P4\n%d %d\n", WIDTH, HEIGHT);
    fwrite(framebuffer, WIDTH * HEIGHT, 1, framebuffer_file);

    fclose(framebuffer_file);

    return 0;
}