//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: curious
/*
 * This program converts an image to ASCII art.
 * It takes a grayscale image as input and outputs the corresponding ASCII art.
 * The program uses a curious style by utilizing a custom font and color scheme.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 80
#define HEIGHT 25
#define CHAR_SET_SIZE 95

/* Define the custom font and color scheme */
char font[] = "@%#*+=-:. ";
char colors[][3] = {{"\033[0m"}, {"\033[1m"}, {"\033[2m"}, {"\033[3m"}, {"\033[4m"}, {"\033[5m"}, {"\033[6m"}, {"\033[7m"}};

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    /* Open the input image file */
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    /* Read the image data into memory */
    unsigned char *image_data = malloc(WIDTH * HEIGHT);
    if (image_data == NULL) {
        printf("Error allocating memory.\n");
        fclose(fp);
        return 1;
    }
    fread(image_data, 1, WIDTH * HEIGHT, fp);
    fclose(fp);

    /* Convert the image to ASCII art */
    char ascii_art[WIDTH * HEIGHT];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = y * WIDTH + x;
            int value = image_data[index] * (CHAR_SET_SIZE - 1) / 255;
            ascii_art[index] = font[value];
        }
    }

    /* Write the ASCII art to the output file */
    FILE *out_fp = fopen(argv[2], "w");
    if (out_fp == NULL) {
        printf("Error opening output file.\n");
        free(image_data);
        return 1;
    }
    fprintf(out_fp, "%s", ascii_art);
    fclose(out_fp);
    free(image_data);

    return 0;
}