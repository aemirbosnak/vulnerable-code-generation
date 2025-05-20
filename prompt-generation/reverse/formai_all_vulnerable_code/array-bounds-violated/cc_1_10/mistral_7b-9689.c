//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 30
#define HEIGHT 10
#define ASCII_ART_CHARS " .:!*oe%$#@"

typedef struct {
    int x;
    int y;
} point;

void convert_image_to_ascii(unsigned char image[WIDTH][HEIGHT]) {
    int i, j;
    point current_point;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            current_point.x = j;
            current_point.y = i;

            if (image[current_point.x][current_point.y] > 128) {
                printf("%c", ASCII_ART_CHARS[image[current_point.x][current_point.y] % 32]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void read_image_from_file(unsigned char image[WIDTH][HEIGHT], const char *filename) {
    FILE *file;
    int i, j;

    file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Error: Unable to open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    fread(image, sizeof(unsigned char), WIDTH * HEIGHT, file);

    fclose(file);
}

int main(int argc, char *argv[]) {
    unsigned char image[WIDTH][HEIGHT];

    if (argc != 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_image_from_file(image, argv[1]);
    convert_image_to_ascii(image);

    return EXIT_SUCCESS;
}