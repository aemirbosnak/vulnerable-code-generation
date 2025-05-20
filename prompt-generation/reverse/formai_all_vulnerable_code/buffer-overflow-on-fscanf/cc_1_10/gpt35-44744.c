//FormAI DATASET v1.0 Category: Image Editor ; Style: statistical
/* Statistical Image Editor */
/* Program to apply statistical operations on an image */

#include <stdio.h>
#include <stdlib.h>

/* Define image struct */
typedef struct {
    int width;
    int height;
    int **pixels;
} Image;

/* Function to allocate memory for image */
Image* create_image(int width, int height) {
    Image *im = (Image *)malloc(sizeof(Image));
    im->width = width;
    im->height = height;
    im->pixels = (int **)malloc(height * sizeof(int *));
    for(int i = 0; i < height; i++)
        im->pixels[i] = (int *)malloc(width * sizeof(int));
    return im;
}

/* Function to free memory of image */
void free_image(Image *im) {
    for(int i = 0; i < im->height; i++)
        free(im->pixels[i]);
    free(im->pixels);
    free(im);
}

/* Function to read image from file */
Image* read_image(char *filename) {
    FILE *fp = fopen(filename, "r");
    if(!fp) {
        printf("Error opening file. Exiting the program.");
        exit(EXIT_FAILURE);
    }
    int width, height, depth;
    char format[3];
    fscanf(fp, "%s %d %d %d", format, &width, &height, &depth);
    if(depth > 255) {
        printf("Error: Only 8-bit images are supported. Exiting the program.");
        exit(EXIT_FAILURE);
    }
    Image *im = create_image(width, height);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int pixel_value;
            fscanf(fp, "%d", &pixel_value);
            im->pixels[i][j] = pixel_value;
        }
    }
    fclose(fp);
    return im;
}

/* Function to write image to file */
void write_image(Image *im, char *filename) {
    FILE *fp = fopen(filename, "w");
    if(!fp) {
        printf("Error opening file. Exiting the program.");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "P2\n%d %d\n255\n", im->width, im->height);
    for(int i = 0; i < im->height; i++) {
        for(int j = 0; j < im->width; j++)
            fprintf(fp, "%d ", im->pixels[i][j]);
        fprintf(fp, "\n");
    }
    fclose(fp);
}

/* Function to perform histogram equalization operation */
void histogram_equalization(Image *im) {
    int hist[256] = {0};
    float pr[256] = {0};
    int sk[256] = {0};
    int cumulative_sum = 0;
    for(int i = 0; i < im->height; i++) {
        for(int j = 0; j < im->width; j++) {
            hist[im->pixels[i][j]]++;
        }
    }
    for(int i = 0; i < 256; i++) {
        pr[i] = (float)hist[i] / (im->height * im->width);
        cumulative_sum += hist[i];
        sk[i] = (int)(255 * cumulative_sum / (im->height * im->width));
    }
    for(int i = 0; i < im->height; i++) {
        for(int j = 0; j < im->width; j++) {
            im->pixels[i][j] = sk[im->pixels[i][j]];
        }
    }
}

/* Main function */
int main() {
    Image *im = read_image("example_image.pgm");
    printf("Image size: %d x %d", im->width, im->height);
    histogram_equalization(im);
    write_image(im, "processed_image.pgm");
    free_image(im);
    return 0;
}