//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

unsigned char image[HEIGHT][WIDTH][3];
unsigned char palette[] = {
    0x00, 0x00, 0x00, // Black
    0x22, 0x33, 0x44, // Dark grey
    0x44, 0x66, 0x88, // Grey
    0x66, 0x99, 0xCC, // Light grey
    0x88, 0xCC, 0xFF, // Blue
    0x00, 0x88, 0x00, // Green
    0xFF, 0xFF, 0x00, // Yellow
    0xFF, 0x66, 0x00, // Orange
    0xFF, 0x00, 0x00, // Red
    0x88, 0x00, 0x88, // Purple
    0xFF, 0xFF, 0xFF, // White
};

void generate_image() {
    //srand(time(NULL));

    int r, g, b;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Get a random color from the palette
            r = palette[(rand() % (sizeof(palette) / sizeof(palette[0]))) * 3 + 0];
            g = palette[(rand() % (sizeof(palette) / sizeof(palette[0]))) * 3 + 1];
            b = palette[(rand() % (sizeof(palette) / sizeof(palette[0]))) * 3 + 2];

            // Set the pixel color
            image[y][x][0] = r;
            image[y][x][1] = g;
            image[y][x][2] = b;
        }
    }
}

void write_image() {
    FILE *fp = fopen("image.ppm", "wb");

    fprintf(fp, "P3\n");
    fprintf(fp, "%d %d\n", WIDTH, HEIGHT);
    fprintf(fp, "255\n");

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fprintf(fp, "%d %d %d ", image[y][x][0], image[y][x][1], image[y][x][2]);
        }
    }

    fclose(fp);
}

int main() {
    generate_image();
    write_image();

    return 0;
}