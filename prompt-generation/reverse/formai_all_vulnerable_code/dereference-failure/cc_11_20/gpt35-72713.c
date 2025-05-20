//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int width, height, max;
    char type[4];
    FILE *input_file = fopen("input.pgm", "rb");
    FILE *output_file = fopen("output.pgm", "wb");

    if (!input_file) {
        printf("Could not open input file.\n");
        return 1;
    }

    if (!output_file) {
        printf("Could not create output file.\n");
        return 1;
    }

    fscanf(input_file, "%s %d %d %d", type, &width, &height, &max);
    unsigned char **image = (unsigned char **) malloc(height * sizeof(unsigned char *));
    for (int i = 0; i < height; i++) {
        image[i] = (unsigned char *) malloc(width * sizeof(unsigned char));
        fread(image[i], sizeof(unsigned char), width, input_file);
    }

    // Flip the image vertically
    for (int i = 0; i < height/2; i++) {
        unsigned char *temp = image[i];
        image[i] = image[height-i-1];
        image[height-i-1] = temp;
    }

    // Adjust the image's brightness and contrast
    float brightness = 50;
    float contrast = 1.5;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            float pixel = (float) image[i][j];
            pixel = (pixel - 127.5) * contrast + 127.5 + brightness;
            if (pixel < 0) {
                pixel = 0;
            }
            if (pixel > 255) {
                pixel = 255;
            }
            image[i][j] = (unsigned char) round(pixel);
        }
    }

    fprintf(output_file, "%s\n%d %d\n%d\n", type, width, height, max);
    for (int i = 0; i < height; i++) {
        fwrite(image[i], sizeof(unsigned char), width, output_file);
    }

    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    fclose(input_file);
    fclose(output_file);
    printf("Image processing complete.\n");
    return 0;
}