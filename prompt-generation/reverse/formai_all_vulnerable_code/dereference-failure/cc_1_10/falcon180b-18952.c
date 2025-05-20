//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 30
#define CHAR_SET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?/~`"

// Convert pixel value to corresponding ASCII character
char pixel_to_ascii(int pixel) {
    return CHAR_SET[pixel % strlen(CHAR_SET)];
}

// Read image file and store pixel values in buffer
void read_image(char *filename, int *buffer) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 18, SEEK_SET); // Skip header

    int width, height, bytes_per_pixel;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    fread(&bytes_per_pixel, sizeof(int), 1, fp);

    if (bytes_per_pixel!= 3) {
        printf("Error: Image must have 3 channels (RGB)\n");
        exit(1);
    }

    int size = width * height * bytes_per_pixel;
    buffer = (int *) malloc(size);

    fread(buffer, sizeof(int), size, fp);

    fclose(fp);
}

// Print ASCII art representation of image
void print_ascii_art(int *buffer, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", pixel_to_ascii(buffer[(y * width + x) * 3]));
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    int *buffer;
    read_image(argv[1], &buffer);

    print_ascii_art(buffer, WIDTH, HEIGHT);

    free(buffer);

    return 0;
}