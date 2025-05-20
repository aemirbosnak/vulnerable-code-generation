//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Flip function
void flipImage(unsigned char* image, int width, int height) {
    unsigned char temp;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            temp = image[(y * width + x) * 3];
            image[(y * width + x) * 3] = image[(y * width + (width - x - 1)) * 3];
            image[(y * width + (width - x - 1)) * 3] = temp;

            temp = image[(y * width + x) * 3 + 1];
            image[(y * width + x) * 3 + 1] = image[(y * width + (width - x - 1)) * 3 + 1];
            image[(y * width + (width - x - 1)) * 3 + 1] = temp;

            temp = image[(y * width + x) * 3 + 2];
            image[(y * width + x) * 3 + 2] = image[(y * width + (width - x - 1)) * 3 + 2];
            image[(y * width + (width - x - 1)) * 3 + 2] = temp;
        }
    }
}

// Brightness and contrast function
void adjustImage(unsigned char* image, int width, int height, float brightness, float contrast) {
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < 3; c++) {
                int index = (y * width + x) * 3 + c;
                int value = (int)(factor * (image[index] - 128.0) + 128.0 + brightness);
                if (value < 0) {
                    image[index] = 0;
                }
                else if (value > 255) {
                    image[index] = 255;
                }
                else {
                    image[index] = (unsigned char)value;
                }
            }
        }
    }
}

// Main function
int main() {
    printf("Welcome to the Image Processor 2000! We're here to serve you right!\n");

    // Opening the image
    FILE* file = fopen("myimage.bmp", "rb");
    fseek(file, 54, SEEK_SET);

    // Reading image parameters
    int width, height;
    fread(&width, 4, 1, file);
    fread(&height, 4, 1, file);

    // Reading image data
    int size = width * height * 3;
    unsigned char* image = (unsigned char*)malloc(size * sizeof(unsigned char));
    fread(image, 1, size, file);
    fclose(file);

    // Flipping the image
    printf("Processing image... Flipping it horizontally...\n");
    flipImage(image, width, height);

    // Adjusting the image brightness and contrast
    printf("Also, let's adjust the brightness and contrast to give it an edge.\n");
    adjustImage(image, width, height, 50.0, 50.0);

    // Saving the image
    printf("All done! Image is saved.\n");
    file = fopen("processed.bmp", "wb");
    fwrite(image, 1, size, file);
    fclose(file);

    printf("Thank you for choosing Image Processor 2000! Have a nice day!\n");

    return 0;
}