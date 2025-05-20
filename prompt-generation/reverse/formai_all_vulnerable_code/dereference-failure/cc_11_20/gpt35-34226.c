//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IMAGE_SIZE 1024

int main() {

    // Declare variables
    int i, j, k, temp;
    int height, width, maxval;
    int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];

    // Read in the image data
    FILE *fp = fopen("image.pgm", "rb");
    if (!fp) {
        printf("Could not open image file\n");
        return 0;
    }
    char magic_number[2];
    fscanf(fp, "%s", magic_number);
    fscanf(fp, "%d", &width);
    fscanf(fp, "%d", &height);
    fscanf(fp, "%d", &maxval);

    // Check for invalid image format
    if (strcmp(magic_number, "P2") != 0) {
        printf("Invalid image format\n");
        return 0;
    }

    // Read in the image data
    for (i=0; i<height; i++) {
        for (j=0; j<width; j++) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }

    // Close the file
    fclose(fp);

    // Declare variables for processing
    int brightness, contrast, flip;

    // Ask user for processing options
    printf("Enter brightness value (-255 to 255): ");
    scanf("%d", &brightness);
    printf("Enter contrast value (-255 to 255): ");
    scanf("%d", &contrast);
    printf("Flip image horizontally? (0 or 1): ");
    scanf("%d", &flip);

    // Adjust brightness and contrast
    for (i=0; i<height; i++) {
        for (j=0; j<width; j++) {
            temp = (int)((image[i][j] + brightness) * (contrast / 255.0));
            image[i][j] = fmin(fmax(temp, 0), maxval);
        }
    }

    // Flip image horizontally if option selected
    if (flip) {
        for (i=0; i<height; i++) {
            for (j=0, k=width-1; j<k; j++, k--) {
                temp = image[i][j];
                image[i][j] = image[i][k];
                image[i][k] = temp;
            }
        }
    }

    // Write the processed image data to file
    fp = fopen("processed_image.pgm", "wb");
    fprintf(fp, "P2 %d %d %d\n", width, height, maxval);
    for (i=0; i<height; i++) {
        for (j=0; j<width; j++) {
            fprintf(fp, "%d ", image[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    printf("Done!\n");

    return 0;
}