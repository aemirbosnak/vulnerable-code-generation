//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

void pgm_read_header(FILE *fp, int *width, int *height, int *max_gray) {
    char magic_number[3];
    fgets(magic_number, 3, fp);
    sscanf(magic_number, "P5%d %d", width, height);
    fscanf(fp, "%d\n", max_gray);
}

void pgm_read_image(FILE *fp, uint8_t *buffer, int width, int height) {
    int i;
    for (i = 0; i < width * height; i++) {
        fread(&buffer[i], 1, 1, fp);
    }
}

void ascii_art_conversion(uint8_t *image, int width, int height, FILE *output) {
    int i, j, pixel_value, bar;
    char symbol = '*';

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            pixel_value = image[i * width + j];
            bar = pixel_value / 10;
            if (bar > 0) {
                for (; bar > 0; bar--) {
                    fprintf(output, "%c", symbol);
                }
            }
            if (pixel_value % 10 == 0) {
                fprintf(output, "\n");
            }
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *input, *output;
    int width, height, max_gray;
    uint8_t *image_buffer;

    if (argc != 3) {
        printf("Usage: %s <input_pgm_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    input = fopen(argv[1], "rb");
    if (input == NULL) {
        perror("Error opening input file");
        return 1;
    }

    pgm_read_header(input, &width, &height, &max_gray);

    image_buffer = (uint8_t *)malloc(width * height);
    pgm_read_image(input, image_buffer, width, height);
    fclose(input);

    output = fopen(argv[2], "w");
    if (output == NULL) {
        perror("Error opening output file");
        free(image_buffer);
        return 1;
    }

    ascii_art_conversion(image_buffer, width, height, output);
    fclose(output);
    free(image_buffer);

    printf("Image converted to ASCII art successfully.\n");

    return 0;
}