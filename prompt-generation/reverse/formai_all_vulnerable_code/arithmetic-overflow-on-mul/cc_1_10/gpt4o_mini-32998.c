//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200
#define ASCII_CHARS "@%#*+=-:. "

void load_ppm(const char *filename, unsigned char image[MAX_HEIGHT][MAX_WIDTH][3], int *width, int *height);
void convert_to_ascii(unsigned char image[MAX_HEIGHT][MAX_WIDTH][3], int width, int height);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned char image[MAX_HEIGHT][MAX_WIDTH][3];
    int width, height;

    load_ppm(argv[1], image, &width, &height);
    convert_to_ascii(image, width, height);

    return EXIT_SUCCESS;
}

void load_ppm(const char *filename, unsigned char image[MAX_HEIGHT][MAX_WIDTH][3], int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    char header[3];
    fscanf(fp, "%s", header);
    if (header[0] != 'P' || header[1] != '6') {
        fprintf(stderr, "Unsupported file format (only P6 allowed)\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d %d", width, height);
    int max_val;
    fscanf(fp, "%d", &max_val);

    if (*width > MAX_WIDTH || *height > MAX_HEIGHT) {
        fprintf(stderr, "Image dimensions exceed maximum limits\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    fgetc(fp); // Read the newline character after max_val
    fread(image, 3, (*width) * (*height), fp);
    fclose(fp);
}

void convert_to_ascii(unsigned char image[MAX_HEIGHT][MAX_WIDTH][3], int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Compute the grayscale value
            unsigned char r = image[y][x][0];
            unsigned char g = image[y][x][1];
            unsigned char b = image[y][x][2];
            unsigned char gray = (r + g + b) / 3;

            // Map the grayscale value to an ASCII character
            int ascii_index = gray * (sizeof(ASCII_CHARS) - 1) / 255;
            putchar(ASCII_CHARS[ascii_index]);
        }
        putchar('\n');
    }
}