//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_width 80
#define max_height 60
#define max_pixels 4800

void convert_to_ascii(int pixels[], int width, int height, char ascii[]) {
    char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    int ascii_range = 10;
    int pixel_range = 256/ascii_range;
    int pixel_index, ascii_index;
    for (int i = 0; i < width*height; i++) {
        pixel_index = pixels[i]/pixel_range;
        ascii_index = pixel_index >= ascii_range ? ascii_range : pixel_index;
        ascii[i] = ascii_chars[ascii_index];
    }
    ascii[width*height] = '\0';
}

int main() {
    // Load Image
    FILE *image_file;
    char image_name[20];
    int width, height;
    int pixels[max_pixels];

    printf("Enter image name (Max 20 characters): ");
    scanf("%s", image_name);

    image_file = fopen(image_name, "r");
    if (!image_file) {
        printf("Error opening image file.\n");
        exit(1);
    }

    fscanf(image_file, "%d %d", &width, &height);
    if (width > max_width || height > max_height) {
        printf("Error: Image too large.\n");
        exit(1);
    }

    for (int i = 0; i < width*height; i++) {
        fscanf(image_file, "%d", &pixels[i]);
    }

    fclose(image_file);

    // Generate ASCII Art
    char ascii[max_pixels+1];
    convert_to_ascii(pixels, width, height, ascii);

    // Print ASCII Art
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            printf("%c", ascii[row*width+col]);
        }
        printf("\n");
    }
    return 0;
}