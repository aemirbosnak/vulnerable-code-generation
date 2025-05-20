//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define ASCII_CHARS ".,-~:+*#%@"

struct pixel {
    int x;
    int y;
    int value;
};

void read_image(char *filename, struct pixel *pixels, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 18, SEEK_SET); // skip header
    fread(pixels, sizeof(struct pixel), *width * *height, fp);

    fclose(fp);
}

void print_ascii_art(struct pixel *pixels, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int value = pixels[i * width + j].value;
            printf("%c", ASCII_CHARS[value % strlen(ASCII_CHARS)]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];

    struct pixel *pixels;
    int width, height;
    read_image(input_filename, pixels, &width, &height);

    print_ascii_art(pixels, width, height);

    FILE *fp = fopen(output_filename, "w");
    if (fp == NULL) {
        printf("Error: could not open file '%s' for writing\n", output_filename);
        return 1;
    }

    fwrite(pixels, sizeof(struct pixel), width * height, fp);
    fclose(fp);

    printf("ASCII art saved to '%s'\n", output_filename);

    return 0;
}