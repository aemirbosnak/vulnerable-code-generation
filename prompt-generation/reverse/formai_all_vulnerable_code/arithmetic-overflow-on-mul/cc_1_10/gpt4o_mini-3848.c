//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define CHARSET "@%#*+=-:. "  // Characters used for ASCII representation
#define WIDTH 100             // ASCII Art Width
#define HEIGHT 100            // ASCII Art Height

typedef unsigned char uchar;

void load_pgm(const char *filename, uchar **image, int *width, int *height);
void convert_to_ascii(uchar *image, int width, int height);
void free_image(uchar *image);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input.pgm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    uchar *image = NULL;
    int width, height;

    load_pgm(argv[1], &image, &width, &height);
    convert_to_ascii(image, width, height);
    free_image(image);

    return EXIT_SUCCESS;
}

void load_pgm(const char *filename, uchar **image, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char header[3];
    fscanf(fp, "%2s", header);
    if (header[1] != '5') {
        fprintf(stderr, "Unsupported PGM format\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d %d", width, height);
    int max_value;
    fscanf(fp, "%d", &max_value);

    *image = (uchar *)malloc((*width) * (*height));
    fread(*image, sizeof(uchar), (*width) * (*height), fp);
    fclose(fp);
}

void convert_to_ascii(uchar *image, int width, int height) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            uchar pixel = image[y * width + x];
            int index = pixel * (sizeof(CHARSET) - 2) / 255;
            putchar(CHARSET[index]);
        }
        putchar('\n');
    }
}

void free_image(uchar *image) {
    free(image);
}