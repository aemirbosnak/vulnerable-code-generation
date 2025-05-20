//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 50

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s image.ppm\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    // Read the header
    char header[256];
    if (!fgets(header, sizeof(header), fp)) {
        perror("fgets");
        return 1;
    }

    if (strncmp(header, "P6", 2) != 0) {
        fprintf(stderr, "Unsupported image format: %s\n", header);
        return 1;
    }

    int width, height;
    if (fscanf(fp, "%d %d\n", &width, &height) != 2) {
        perror("fscanf");
        return 1;
    }

    int maxval;
    if (fscanf(fp, "%d\n", &maxval) != 1) {
        perror("fscanf");
        return 1;
    }

    // Allocate memory for the image data
    unsigned char *data = malloc(width * height * 3);
    if (!data) {
        perror("malloc");
        return 1;
    }

    // Read the image data
    if (fread(data, 1, width * height * 3, fp) != width * height * 3) {
        perror("fread");
        return 1;
    }

    fclose(fp);

    // Convert the image data to ASCII art
    char *ascii = malloc(WIDTH * HEIGHT);
    if (!ascii) {
        perror("malloc");
        return 1;
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int i = (y * WIDTH + x) * 3;
            double r = data[i] / (double)maxval;
            double g = data[i + 1] / (double)maxval;
            double b = data[i + 2] / (double)maxval;

            double brightness = (r + g + b) / 3.0;

            char c;
            if (brightness < 0.25) {
                c = '#';
            } else if (brightness < 0.5) {
                c = '=';
            } else if (brightness < 0.75) {
                c = ':';
            } else {
                c = ' ';
            }

            ascii[y * WIDTH + x] = c;
        }
    }

    // Print the ASCII art
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", ascii[y * WIDTH + x]);
        }
        printf("\n");
    }

    free(ascii);
    free(data);

    return 0;
}