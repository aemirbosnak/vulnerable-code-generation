//FormAI DATASET v1.0 Category: Image Classification system ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define the structure of an image */
struct Image {
    int height;
    int width;
    float **pixels;
};

/* Initialize a new image */
void init_image(struct Image *image, int height, int width) {
    image->height = height;
    image->width = width;
    image->pixels = (float **)malloc(height * sizeof(float *));
    for (int i = 0; i < height; i++) {
        image->pixels[i] = (float *)malloc(width * sizeof(float));
    }
}

/* Free the memory allocated to an image*/
void free_image(struct Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
}

/* Load an image from a file */
int read_image_from_file(struct Image *image, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        return 0;
    }

    /* Read the height and width of the image */
    fscanf(fp, "%d %d", &image->height, &image->width);
    init_image(image, image->height, image->width);

    /* Read the pixel values and store them in the image*/
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fscanf(fp, "%f", &image->pixels[i][j]);
        }
    }
    fclose(fp);
    return 1;
}

/* Save an image to a file */
int write_image_to_file(struct Image *image, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        return 0;
    }

    /* Write the height and width of the image */
    fprintf(fp, "%d %d\n", image->height, image->width);

    /* Write the pixel values to the file */
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fprintf(fp, "%f ", image->pixels[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    return 1;
}

/* Classify an image based on its pixel values */
int classify_image(struct Image *image) {
    float average = 0;
    int count = 0;

    /* Calculate the average of the pixel values */
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            average += image->pixels[i][j];
            count++;
        }
    }
    average /= count;

    /* Classify the image as "light" or "dark" */
    if (average > 0.5) {
        return 1; // "light"
    } else {
        return 0; // "dark"
    }
}

/* Main function */
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./classify_image <input_file> <output_file>\n");
        return 1;
    }

    struct Image image;
    int success = read_image_from_file(&image, argv[1]);
    if (!success) {
        printf("Error: Could not read file %s\n", argv[1]);
        return 1;
    }

    int label = classify_image(&image);

    printf("Classified %s as %s\n", argv[1], label ? "Light" : "Dark");
    success = write_image_to_file(&image, argv[2]);
    if (!success) {
        printf("Error: Could not write file %s\n", argv[2]);
        return 1;
    }

    free_image(&image);
    return 0;
}