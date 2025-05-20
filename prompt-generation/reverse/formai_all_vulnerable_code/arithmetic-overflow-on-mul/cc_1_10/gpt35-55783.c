//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: happy
// This C program performs simple image processing tasks
// such as flipping an image, changing its brightness and contrast

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Happy Image Processing program!\n\n");

    // Opening the input file
    FILE *inputFile;
    inputFile = fopen("input_image.bmp", "rb");
    if (!inputFile) {
        printf("Error: cannot open the input file!\n");
        return -1;
    }

    // Reading the bitmap header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, inputFile);

    // Reading the width and height values from the header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Computing the image size and padding
    int imageSize = width * height * 3;
    int padding = 0;
    if ((imageSize % 4) != 0) {
        padding = 4 - (imageSize % 4);
    }

    // Reading the image data into memory
    unsigned char* data = (unsigned char*) malloc((imageSize + padding) * sizeof(unsigned char));
    fread(data, sizeof(unsigned char), imageSize, inputFile);
    fclose(inputFile);

    // Performing image processing tasks
    printf("Performing image processing tasks...\n\n");

    // Flipping the image horizontally
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width/2; j++) {
            int offset1 = (i * width * 3) + (j * 3);
            int offset2 = (i * width * 3) + ((width - j - 1) * 3);
            unsigned char tmpR = data[offset1];
            unsigned char tmpG = data[offset1+1];
            unsigned char tmpB = data[offset1+2];
            data[offset1] = data[offset2];
            data[offset1+1] = data[offset2+1];
            data[offset1+2] = data[offset2+2];
            data[offset2] = tmpR;
            data[offset2+1] = tmpG;
            data[offset2+2] = tmpB;
        }
    }

    // Changing the brightness and contrast of the image
    float brightness = 50.0;
    float contrast = 1.2;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int offset = (i * width * 3) + (j * 3);
            // Changing the brightness
            data[offset] += brightness;
            data[offset+1] += brightness;
            data[offset+2] += brightness;
            // Changing the contrast
            data[offset] = (unsigned char) ((data[offset] - 128) * contrast + 128);
            data[offset+1] = (unsigned char) ((data[offset+1] - 128) * contrast + 128);
            data[offset+2] = (unsigned char) ((data[offset+2] - 128) * contrast + 128);
        }
    }

    // Opening the output file
    FILE *outputFile;
    outputFile = fopen("output_image.bmp", "wb");
    if (!outputFile) {
        printf("Error: cannot create the output file!\n");
        return -1;
    }

    // Writing the bitmap header to the output file
    fwrite(header, sizeof(unsigned char), 54, outputFile);

    // Writing the image data to the output file
    fwrite(data, sizeof(unsigned char), (imageSize + padding), outputFile);
    fclose(outputFile);

    // Freeing the memory
    free(data);

    printf("Image processing complete!\n");
    return 0;
}