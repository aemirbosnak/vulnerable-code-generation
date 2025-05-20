//FormAI DATASET v1.0 Category: Image Editor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define image properties */
#define WIDTH 200
#define HEIGHT 200
#define MAX_PIXEL_VALUE 255

/* Define image structure */
typedef struct {
    int width;
    int height;
    int max_pixel_value;
    int pixel_array[HEIGHT][WIDTH];
} Image;

/* Function to read image data from file */
void read_image(char *filename, Image *image) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    /* Read image properties */
    fscanf(file, "P2\n%d %d\n%d\n", &image->width, &image->height, &image->max_pixel_value);

    /* Read pixel values */
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fscanf(file, "%d", &image->pixel_array[i][j]);
        }
    }

    fclose(file);
}

/* Function to write image data to file */
void write_image(char *filename, Image *image) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    /* Write image properties */
    fprintf(file, "P2\n%d %d\n%d\n", image->width, image->height, image->max_pixel_value);

    /* Write pixel values */
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fprintf(file, "%d ", image->pixel_array[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

/* Function to flip an image horizontally */
void flip_horizontal(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width/2; j++) {
            /* Swap pixels from left and right columns */
            int temp = image->pixel_array[i][j];
            image->pixel_array[i][j] = image->pixel_array[i][image->width-1-j];
            image->pixel_array[i][image->width-1-j] = temp;
        }
    }
}

/* Function to invert pixel values in an image */
void invert(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            /* Invert pixel value */
            image->pixel_array[i][j] = image->max_pixel_value - image->pixel_array[i][j];
        }
    }
}

/* Main function */
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s input_filename output_filename\n", argv[0]);
        exit(1);
    }

    /* Read input image */
    Image image;
    read_image(argv[1], &image);

    /* Flip image horizontally */
    flip_horizontal(&image);

    /* Invert pixel values */
    invert(&image);

    /* Write output image */
    write_image(argv[2], &image);

    printf("Image processing complete!\n");

    return 0;
}