//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Function to flip the image
void flipImage(unsigned char *image, int width, int height) {
    unsigned char temp;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            temp = image[i * width + j];
            image[i * width + j] = image[i * width + width - j - 1];
            image[i * width + width - j - 1] = temp;
        }
    }
}

// Function to adjust the brightness and contrast of the image
void adjustBrightnessContrast(unsigned char *image, int width, int height, int brightness, int contrast) {
    float factor = (float)(259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = i * width + j;
            // Adjust brightness
            int val = image[index] + brightness;
            if (val < 0) {
                val = 0;
            } else if (val > 255) {
                val = 255;
            }
            // Adjust contrast
            val = (int)(factor * (val - 128) + 128);
            if (val < 0) {
                val = 0;
            } else if (val > 255) {
                val = 255;
            }
            image[index] = val;
        }
    }
}

int main() {
    FILE *fp = fopen("sample.pgm", "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    // Read the PGM image
    char format[10];
    int width, height, maxval;
    fscanf(fp, "%s\n%d %d\n%d\n", format, &width, &height, &maxval);
    if (strcmp(format, "P5") != 0 || maxval != 255) {
        printf("Unsupported file format.\n");
        fclose(fp);
        return 0;
    }
    unsigned char *image = (unsigned char*)malloc(sizeof(unsigned char) * width * height);
    fread(image, sizeof(unsigned char), width * height, fp);
    fclose(fp);

    // Flip the image
    flipImage(image, width, height);

    // Adjust brightness and contrast
    int brightness = 50;
    int contrast = -50;
    adjustBrightnessContrast(image, width, height, brightness, contrast);

    // Write the processed image to file
    fp = fopen("processed.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n255\n", width, height);
    fwrite(image, sizeof(unsigned char), width * height, fp);
    fclose(fp);

    printf("Processing complete. Output file: processed.pgm\n");

    free(image);
    return 0;
}