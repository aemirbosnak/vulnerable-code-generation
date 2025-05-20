//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define ASCII_CHARS "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file '%s'.\n", argv[1]);
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file '%s'.\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    size_t file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    unsigned char *input_buffer = (unsigned char *)malloc(file_size);
    if (input_buffer == NULL) {
        printf("Error: Could not allocate memory for input buffer.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    size_t bytes_read = fread(input_buffer, 1, file_size, input_file);
    if (bytes_read!= file_size) {
        printf("Error: Could not read entire input file.\n");
        free(input_buffer);
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    fclose(input_file);

    int width = 0;
    int height = 0;
    int max_value = 0;
    int pixel_count = 0;

    for (int y = 0; y < MAX_HEIGHT; y++) {
        for (int x = 0; x < MAX_WIDTH; x++) {
            int value = input_buffer[(y * MAX_WIDTH + x) * 3];
            if (value > max_value) {
                max_value = value;
            }
            pixel_count++;
        }
    }

    double brightness = 1.0;
    if (max_value > 255) {
        brightness = 255.0 / max_value;
    }

    rewind(input_file);

    for (int y = 0; y < MAX_HEIGHT; y++) {
        for (int x = 0; x < MAX_WIDTH; x++) {
            int value = input_buffer[(y * MAX_WIDTH + x) * 3];
            int ascii_char_index = (int)(value * brightness);

            fprintf(output_file, "%c", ASCII_CHARS[ascii_char_index]);
        }
        fprintf(output_file, "\n");
    }

    free(input_buffer);
    fclose(output_file);

    return 0;
}