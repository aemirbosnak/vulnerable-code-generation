//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

/* This program takes an image file as input and converts it into ASCII art */

typedef struct {
    int width;
    int height;
    char** pixels;
} Image;

/* Function to read the image file */
Image* read_image(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening image file.\n");
        exit(1);
    }

    int width, height;
    fscanf(file, "%d %d\n", &width, &height);

    Image* img = (Image*) malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = (char**) malloc(sizeof(char*) * height);

    for (int i = 0; i < height; i++) {
        img->pixels[i] = (char*) malloc(sizeof(char) * (width + 1));
        fgets(img->pixels[i], width + 1, file);
    }

    fclose(file);

    return img;
}

/* Function to free memory allocated to image */
void free_image(Image* img) {
    for (int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
}

/* Function to convert image to ASCII art */
void image_to_ascii(Image* img) {
    char ascii[] = { '.', ',', '-', '~', ':', ';', '=', '!', '*', '#', '$', '@' };
    int ascii_len = sizeof(ascii) / sizeof(ascii[0]);
    int scale = 255 / (ascii_len - 1);

    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int pixel = img->pixels[i][j];
            int index = pixel / scale;
            printf("%c", ascii[index]);
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        exit(1);
    }

    Image* img = read_image(argv[1]);
    image_to_ascii(img);
    free_image(img);

    return 0;
}