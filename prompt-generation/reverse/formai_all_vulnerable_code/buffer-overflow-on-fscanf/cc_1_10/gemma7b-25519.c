//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

void convert_image_to_ascii(FILE *fp) {
    int r, g, b, pixel_value;
    char ascii_character;

    fscanf(fp, "%d", &pixel_value);
    r = pixel_value / 3;
    g = (pixel_value - r * 3) / 3;
    b = pixel_value - r * 3 - g * 3;

    switch (r) {
        case 0:
            ascii_character = ' ';
            break;
        case 1:
            ascii_character = '.';
            break;
        case 2:
            ascii_character = ',';
            break;
        case 3:
            ascii_character = '#';
            break;
    }

    switch (g) {
        case 0:
            ascii_character = ' ';
            break;
        case 1:
            ascii_character = '.';
            break;
        case 2:
            ascii_character = ',';
            break;
        case 3:
            ascii_character = '#';
            break;
    }

    switch (b) {
        case 0:
            ascii_character = ' ';
            break;
        case 1:
            ascii_character = '.';
            break;
        case 2:
            ascii_character = ',';
            break;
        case 3:
            ascii_character = '#';
            break;
    }

    fprintf(stdout, "%c", ascii_character);
}

int main() {
    FILE *fp;

    fp = fopen("image.ppm", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    convert_image_to_ascii(fp);

    fclose(fp);

    return 0;
}