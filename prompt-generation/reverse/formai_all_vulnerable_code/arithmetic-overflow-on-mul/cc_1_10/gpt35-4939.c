//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 10000

/* Function to flip an image horizontally */
void flipImageHorizontally(int width, int height, unsigned char *image) {
    unsigned char temp;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width/2; col++) {
            // Swap pixels on either side of the midpoint
            temp = image[row*width + col];
            image[row*width + col] = image[row*width + (width-col-1)];
            image[row*width + (width-col-1)] = temp;
        }
    }
}

/* Function to adjust the brightness of an image */
void adjustBrightness(int width, int height, unsigned char *image, float brightness) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            // Adjust the brightness of each pixel
            int new_intensity = (int)(brightness * image[row*width + col]);
            if (new_intensity > 255) {
                new_intensity = 255;
            }
            image[row*width + col] = new_intensity;
        }
    }
}

/* Function to adjust the contrast of an image */
void adjustContrast(int width, int height, unsigned char *image, float contrast) {
    // Compute the mean intensity of the image
    float mean_intensity = 0;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            mean_intensity += image[row*width + col];
        }
    }
    mean_intensity = mean_intensity / ((float)width * height);

    // Adjust the contrast of each pixel
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int new_intensity = (int)(mean_intensity + contrast * (image[row*width + col] - mean_intensity));
            if (new_intensity > 255) {
                new_intensity = 255;
            } else if (new_intensity < 0) {
                new_intensity = 0;
            }
            image[row*width + col] = new_intensity;
        }
    }
}

/* Main function for image processing */
int main(int argc, char* argv[]) {
    char* input_file = argv[1];
    char* output_file = argv[2];
    float brightness = atof(argv[3]);
    float contrast = atof(argv[4]);

    FILE* infile = fopen(input_file, "rb");
    if (infile == NULL) {
        printf("ERROR: could not open file.\n");
        return 1;
    }

    // Read in the image dimensions from the header
    char header[256];
    fgets(header, 256, infile);
    int width, height, max_intensity;
    fscanf(infile, "%d %d %d\n", &width, &height, &max_intensity);
    printf("Processing image with dimensions %d x %d\n", width, height);

    // Read in the image data
    unsigned char* image = malloc(sizeof(unsigned char) * width * height);
    int num_pixels = fread(image, sizeof(unsigned char), width * height, infile);
    if (num_pixels != width * height) {
        printf("ERROR: unexpected end of file.\n");
        return 1;
    }

    // Flip the image horizontally
    flipImageHorizontally(width, height, image);

    // Adjust the brightness and contrast of the image
    adjustBrightness(width, height, image, brightness);
    adjustContrast(width, height, image, contrast);

    // Write out the processed image
    FILE* outfile = fopen(output_file, "wb");
    fprintf(outfile, "%s\n", header);
    fprintf(outfile, "%d %d\n%d\n", width, height, max_intensity);
    fwrite(image, sizeof(unsigned char), width * height, outfile);
    fclose(outfile);

    free(image);

    return 0;
}