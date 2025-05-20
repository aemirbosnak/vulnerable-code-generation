//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

/* Function to flip the image horizontally. 
   Takes the image width and height as input. */
void flip_horizontal(int width, int height, unsigned char *image) {
    int i, j;
    unsigned char temp;

    for (i = 0; i < height; i++) {
        for (j = 0; j < (width / 2); j++) {
            temp = image[(i * width) + j];
            image[(i * width) + j] = image[(i * width) + (width - j - 1)];
            image[(i * width) + (width - j - 1)] = temp;
        }
    }
}

/* Function to adjust the brightness of the image. 
   Takes the image width, height, and a brightness value (-255 to 255) as input. */
void adjust_brightness(int width, int height, unsigned char *image, int brightness) {
    int i, j;
    int pixel_value;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            pixel_value = (int) image[(i * width) + j] + brightness;
            if (pixel_value < 0) {
                pixel_value = 0;
            } else if (pixel_value > 255) {
                pixel_value = 255;
            }
            image[(i * width) + j] = (unsigned char) pixel_value;
        }
    }
}

/* Function to adjust the contrast of the image. 
   Takes the image width, height, and a contrast value (-100 to 100) as input. */
void adjust_contrast(int width, int height, unsigned char *image, int contrast) {
    int i, j;
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            image[(i * width) + j] = (unsigned char) (factor * (image[(i * width) + j] - 128) + 128);
        }
    }
}

/* Main function to run the program. */
int main() {
    int width, height;
    int brightness, contrast;
    char filename[20];
    FILE *file;
    unsigned char *image;

    /* Ask for the image file and read it in to memory. */
    printf("Enter the filename of the image: ");
    scanf("%s", filename);
    file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    fseek(file, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);
    fseek(file, 54, SEEK_SET);
    image = (unsigned char*) malloc(width * height * 3);
    fread(image, sizeof(unsigned char), width * height * 3, file);
    fclose(file);

    /* Ask for the desired adjustments and apply them to the image. */
    printf("Enter the desired brightness adjustment (-255 to 255): ");
    scanf("%d", &brightness);
    adjust_brightness(width, height, image, brightness);

    printf("Enter the desired contrast adjustment (-100 to 100): ");
    scanf("%d", &contrast);
    adjust_contrast(width, height, image, contrast);

    flip_horizontal(width, height, image);

    /* Write the adjusted image to a new file. */
    file = fopen("output.bmp", "wb");
    fseek(file, 18, SEEK_SET);
    fwrite(&width, sizeof(int), 1, file);
    fwrite(&height, sizeof(int), 1, file);
    fseek(file, 54, SEEK_SET);
    fwrite(image, sizeof(unsigned char), width * height * 3, file);
    fclose(file);
    free(image);

    printf("Done! Check the file 'output.bmp' for the adjusted image.\n");
    return 0;
}