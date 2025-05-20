//FormAI DATASET v1.0 Category: Image Editor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 512
#define MAX_HEIGHT 512

// Structure to hold the image data
typedef struct {
    int width;
    int height;
    int pixels[MAX_WIDTH][MAX_HEIGHT][3]; // RGB values for each pixel
} Image;

// Function to invert the colors of an image
void invert_colors(Image *img) {
    for (int i = 0; i < img->width; i++) {
        for (int j = 0; j < img->height; j++) {
            img->pixels[i][j][0] = 255 - img->pixels[i][j][0]; // Red
            img->pixels[i][j][1] = 255 - img->pixels[i][j][1]; // Green
            img->pixels[i][j][2] = 255 - img->pixels[i][j][2]; // Blue
        }
    }
}

// Function to flip an image horizontally
void flip_horizontally(Image *img) {
    for (int i = 0; i < img->width / 2; i++) {
        for (int j = 0; j < img->height; j++) {
            // Swap pixels
            int temp = img->pixels[i][j][0];
            img->pixels[i][j][0] = img->pixels[img->width - 1 - i][j][0];
            img->pixels[img->width - 1 - i][j][0] = temp;

            temp = img->pixels[i][j][1];
            img->pixels[i][j][1] = img->pixels[img->width - 1 - i][j][1];
            img->pixels[img->width - 1 - i][j][1] = temp;

            temp = img->pixels[i][j][2];
            img->pixels[i][j][2] = img->pixels[img->width - 1 - i][j][2];
            img->pixels[img->width - 1 - i][j][2] = temp;
        }
    }
}

// Function to read an image from a file
void read_image(Image *img, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char buffer[1024];
    fgets(buffer, 1024, file); // Read the file type (P3)
    fgets(buffer, 1024, file); // Read the comment (if any)
    fscanf(file, "%d %d", &img->width, &img->height); // Read the image dimensions
    int max_color_value;
    fscanf(file, "%d\n", &max_color_value); // Read the maximum color value

    for (int j = 0; j < img->height; j++) {
        for (int i = 0; i < img->width; i++) {
            fscanf(file, "%d %d %d", &img->pixels[i][j][0], &img->pixels[i][j][1], &img->pixels[i][j][2]);
        }
    }

    fclose(file);
}

// Function to write an image to a file
void write_image(const Image *img, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fprintf(file, "P3\n");
    fprintf(file, "# Created by Innovative Image Editor\n");
    fprintf(file, "%d %d\n", img->width, img->height);
    fprintf(file, "%d\n", 255);

    for (int j = 0; j < img->height; j++) {
        for (int i = 0; i < img->width; i++) {
            fprintf(file, "%d %d %d ", img->pixels[i][j][0], img->pixels[i][j][1], img->pixels[i][j][2]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int main() {
    Image img;
    read_image(&img, "input.ppm"); // Read the input image from a file

    invert_colors(&img); // Apply the invert colors effect
    write_image(&img, "output_invert.ppm"); // Write the output image to a file

    flip_horizontally(&img); // Apply the flip horizontally effect
    write_image(&img, "output_flip.ppm"); // Write the output image to a file

    return 0;
}