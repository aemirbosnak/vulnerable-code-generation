//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *image_file, *ascii_file;
    char image_data[1000000];
    char ascii_data[1000000];
    int width, height, pixel_count, index, r, g, b, i, j;

    image_file = fopen("image.png", "rb");
    if (!image_file) {
        printf("Error opening image file\n");
        return 1;
    }

    fseek(image_file, 0, SEEK_END);
    pixel_count = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);

    fread(image_data, 1, pixel_count, image_file);
    fclose(image_file);

    ascii_file = fopen("ascii_art.txt", "w");
    if (!ascii_file) {
        printf("Error opening ascii file\n");
        return 1;
    }

    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            r = image_data[pixel_count * j + i * 3 + 0];
            g = image_data[pixel_count * j + i * 3 + 1];
            b = image_data[pixel_count * j + i * 3 + 2];

            index = (r << 16) | (g << 8) | b;

            if (index >= 16) {
                printf("\e[38;5;1m"); // Set text color to green
            } else if (index >= 8) {
                printf("\e[38;5;2m"); // Set text color to yellow
            } else if (index >= 4) {
                printf("\e[38;5;3m"); // Set text color to red
            } else if (index >= 2) {
                printf("\e[38;5;4m"); // Set text color to cyan
            } else if (index >= 1) {
                printf("\e[38;5;5m"); // Set text color to magenta
            } else {
                printf("\e[38;5;6m"); // Set text color to white
            }

            printf("  "); // Add a space
            if (r >= 16) {
                printf("\e[38;5;1m  "); // Add green pixel
            } else if (r >= 8) {
                printf("\e[38;5;2m  "); // Add yellow pixel
            } else if (r >= 4) {
                printf("\e[38;5;3m  "); // Add red pixel
            } else if (r >= 2) {
                printf("\e[38;5;4m  "); // Add cyan pixel
            } else if (r >= 1) {
                printf("\e[38;5;5m  "); // Add magenta pixel
            } else {
                printf("\e[38;5;6m  "); // Add white pixel
            }

            if (g >= 16) {
                printf("\e[38;5;1m  "); // Add green pixel
            } else if (g >= 8) {
                printf("\e[38;5;2m  "); // Add yellow pixel
            } else if (g >= 4) {
                printf("\e[38;5;3m  "); // Add red pixel
            } else if (g >= 2) {
                printf("\e[38;5;4m  "); // Add cyan pixel
            } else if (g >= 1) {
                printf("\e[38;5;5m  "); // Add magenta pixel
            } else {
                printf("\e[38;5;6m  "); // Add white pixel
            }

            if (b >= 16) {
                printf("\e[38;5;1m  "); // Add green pixel
            } else if (b >= 8) {
                printf("\e[38;5;2m  "); // Add yellow pixel
            } else if (b >= 4) {
                printf("\e[38;5;3m  "); // Add red pixel
            } else if (b >= 2) {
                printf("\e[38;5;4m  "); // Add cyan pixel
            } else if (b >= 1) {
                printf("\e[38;5;5m  "); // Add magenta pixel
            } else {
                printf("\e[38;5;6m  "); // Add white pixel
            }

            printf("\e[0m"); // Reset text color
        }

        printf("\n");
    }

    fclose(ascii_file);

    return 0;
}