//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 100
#define MAX_PIXEL_VALUE 255

void print_ascii_art(int pixel_array[][WIDTH], int height, int width);
char get_ascii_char(int pixel_value);

int main() {
    FILE *image_file;
    char file_name[50];
    int pixel_val, pixel_array[HEIGHT][WIDTH];
    int width, height, max_pixel_val;
    char image_type[3];

    printf("Enter the file name of the input image: ");
    scanf("%s", file_name);

    image_file = fopen(file_name, "r");

    if (image_file == NULL) {
        fprintf(stderr, "Error opening image file!\n");
        exit(1);
    }

    // Read header of image file
    fscanf(image_file, "%s\n", image_type);
    fscanf(image_file, "# This is a comment line\n");
    fscanf(image_file, "%d %d\n%d\n", &width, &height, &max_pixel_val);

    if (strcmp(image_type, "P2") != 0) {
        fprintf(stderr, "Input image file is not in P2 format!\n");
        exit(1);
    }

    if (max_pixel_val != MAX_PIXEL_VALUE) {
        fprintf(stderr, "Input image is not a 8-bit grayscale image!\n");
        exit(1);
    }

    // Read pixel values from image file
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(image_file, "%d", &pixel_val);
            if (pixel_val > MAX_PIXEL_VALUE) {
                fprintf(stderr, "Pixel value in image file exceeds maximum value!\n");
                exit(1);
            }
            pixel_array[i][j] = pixel_val;
        }
    }

    print_ascii_art(pixel_array, height, width);

    return 0;
}

void print_ascii_art(int pixel_array[][WIDTH], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char ascii_char = get_ascii_char(pixel_array[i][j]);
            printf("%c", ascii_char);
        }
        printf("\n");
    }
}

char get_ascii_char(int pixel_value) {
    char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    int num_chars = sizeof(ascii_chars) / sizeof(ascii_chars[0]);
    int step = MAX_PIXEL_VALUE / num_chars;
    int index = pixel_value / step;
    return ascii_chars[index];
}