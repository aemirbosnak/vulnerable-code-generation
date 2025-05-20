//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 80
#define HEIGHT 60
#define CHAR_SET ".,-~:;=!*#@"

void print_image(char *image, int width, int height) {
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            printf("%c", image[y * width + x]);
        }
        printf("\n");
    }
}

void image_to_ascii(char *filename, int width, int height) {
    FILE *fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 54, SEEK_SET); // Skip header
    unsigned char *data = malloc(3 * width * height);
    fread(data, sizeof(unsigned char), 3 * width * height, fp);
    fclose(fp);

    int max_value = 0;
    for(int i = 0; i < 3 * width * height; i++) {
        if(data[i] > max_value) {
            max_value = data[i];
        }
    }

    char *ascii_image = malloc(3 * width * height + 1);
    for(int i = 0; i < 3 * width * height; i++) {
        int value = data[i] * HEIGHT / max_value;
        ascii_image[i] = CHAR_SET[value];
    }
    ascii_image[3 * width * height] = '\0';

    print_image(ascii_image, width, height);
}

int main(int argc, char *argv[]) {
    if(argc!= 4) {
        printf("Usage: %s <width> <height> <filename>\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);

    image_to_ascii(argv[3], width, height);

    return 0;
}