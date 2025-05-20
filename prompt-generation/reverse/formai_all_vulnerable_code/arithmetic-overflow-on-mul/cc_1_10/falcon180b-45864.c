//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define CHAR_SET ".,-+*0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

void print_usage(char *program_name) {
    printf("Usage: %s <input_file> <output_file>\n", program_name);
    exit(1);
}

void read_image(FILE *input_file, int **pixels, int *width, int *height) {
    int magic_number;
    fread(&magic_number, sizeof(int), 1, input_file);
    if (magic_number!= 0x46464952) {
        printf("Invalid image file.\n");
        exit(1);
    }

    fread(width, sizeof(int), 1, input_file);
    fread(height, sizeof(int), 1, input_file);

    *pixels = (int *) malloc(*width * *height * sizeof(int));
    fread(*pixels, sizeof(int), *width * *height, input_file);
}

void write_ascii_art(FILE *output_file, int *pixels, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fprintf(output_file, "%c", CHAR_SET[pixels[i * width + j] % 64]);
        }
        fprintf(output_file, "\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        print_usage(argv[0]);
    }

    FILE *input_file = fopen(argv[1], "rb");
    FILE *output_file = fopen(argv[2], "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int **pixels;
    int width, height;
    read_image(input_file, &pixels, &width, &height);

    write_ascii_art(output_file, pixels[0], width, height);

    fclose(input_file);
    fclose(output_file);

    free(pixels[0]);
    free(pixels);

    return 0;
}