//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24

void print_ascii_art(char* ascii_art) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", ascii_art[i * WIDTH + j]);
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    long input_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    char* input_buffer = malloc(input_size);
    if (input_buffer == NULL) {
        printf("Error: could not allocate memory for input buffer.\n");
        return 1;
    }

    fread(input_buffer, input_size, 1, input_file);
    fclose(input_file);

    int ascii_art_size = input_size * 3;
    char* ascii_art = malloc(ascii_art_size);
    if (ascii_art == NULL) {
        printf("Error: could not allocate memory for ASCII art buffer.\n");
        return 1;
    }

    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int pixel_value = (int) input_buffer[i * WIDTH + j];
            int ascii_code = 33 + (pixel_value / 51) * 58;
            ascii_art[i * WIDTH * 3 + j * 3] = ascii_code;
            ascii_art[i * WIDTH * 3 + j * 3 + 1] = ascii_code;
            ascii_art[i * WIDTH * 3 + j * 3 + 2] = ascii_code;
        }
    }

    fwrite(ascii_art, ascii_art_size, 1, output_file);
    fclose(output_file);

    printf("ASCII art generated successfully.\n");

    free(input_buffer);
    free(ascii_art);

    return 0;
}