//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define CHAR_SET "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Unable to open output file.\n");
        fclose(input_file);
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    size_t input_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    unsigned char *input_buffer = malloc(input_size);
    if (input_buffer == NULL) {
        printf("Error: Unable to allocate memory.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    fread(input_buffer, input_size, 1, input_file);
    fclose(input_file);

    int output_width = WIDTH;
    int output_height = (int) ceil((float) HEIGHT / (float) input_size);

    for (int y = 0; y < HEIGHT; y++) {
        int input_row = (int) ceil((float) y / (float) output_height) * input_size / HEIGHT;
        for (int x = 0; x < WIDTH; x++) {
            int value = input_buffer[input_row * WIDTH + x] / 32;
            fprintf(output_file, "%c", CHAR_SET[value]);
        }
        fprintf(output_file, "\n");
    }

    fclose(output_file);
    free(input_buffer);

    return 0;
}