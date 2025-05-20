//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 50
#define CHAR_SET_SIZE 256

char char_set[CHAR_SET_SIZE];
int brightness_level;

void init_char_set() {
    int i;
    for (i = 0; i < CHAR_SET_SIZE; i++) {
        char_set[i] = '@';
    }
}

void set_brightness(int level) {
    brightness_level = level;
}

int get_brightness() {
    return brightness_level;
}

void generate_ascii_art(unsigned char *image_data, int width, int height) {
    int x, y;
    int index;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            index = y * width + x;

            int brightness = image_data[index] * get_brightness() / 255;

            int ascii_char = char_set[brightness];

            printf("%c", ascii_char);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <image_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *image_file = fopen(argv[1], "rb");
    if (image_file == NULL) {
        printf("Error: Could not open image file.\n");
        return 1;
    }

    fseek(image_file, 0, SEEK_END);
    long image_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);

    unsigned char *image_data = malloc(image_size);
    fread(image_data, 1, image_size, image_file);
    fclose(image_file);

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        free(image_data);
        return 1;
    }

    init_char_set();
    set_brightness(128);

    generate_ascii_art(image_data, WIDTH, HEIGHT);

    free(image_data);
    fclose(output_file);

    return 0;
}