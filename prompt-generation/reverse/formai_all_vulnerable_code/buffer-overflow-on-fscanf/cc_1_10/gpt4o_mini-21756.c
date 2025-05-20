//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 768
#define MAX_CHARS 70

// ASCII chars used for brightness levels
char ascii_chars[MAX_CHARS] = "@%#*+=-:. ";

void load_ppm(const char *filename, unsigned char image[MAX_HEIGHT][MAX_WIDTH][3], int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char format[3];
    fscanf(fp, "%s", format);
    if (format[1] != '3') {
        fprintf(stderr, "Unsupported PPM format, must be P3.\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d %d", width, height);
    int max_val;
    fscanf(fp, "%d", &max_val);
    
    for (int y = 0; y < *height; y++) {
        for (int x = 0; x < *width; x++) {
            for (int c = 0; c < 3; c++) {
                fscanf(fp, "%hhu", &image[y][x][c]);
            }
        }
    }

    fclose(fp);
}

void generate_ascii_art(unsigned char image[MAX_HEIGHT][MAX_WIDTH][3], int width, int height) {
    double scale = 1.0 / 255.0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int brightness = (int)((image[y][x][0] + image[y][x][1] + image[y][x][2]) / 3.0 * scale * (MAX_CHARS - 1));
            putchar(ascii_chars[brightness]);
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned char image[MAX_HEIGHT][MAX_WIDTH][3];
    int width, height;

    load_ppm(argv[1], image, &width, &height);
    
    generate_ascii_art(image, width, height);

    return EXIT_SUCCESS;
}