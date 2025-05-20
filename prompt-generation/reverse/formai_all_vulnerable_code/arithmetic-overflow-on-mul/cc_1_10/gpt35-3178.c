//FormAI DATASET v1.0 Category: Image Editor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Declare global variables for width and height
int WIDTH = 0;
int HEIGHT = 0;

// Function to read the image data from a file
unsigned char* readImageData(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read the header data
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    // Extract width and height from header
    WIDTH = *(int*)&header[18];
    HEIGHT = *(int*)&header[22];

    // Allocate memory for image data
    unsigned char *imgData = (unsigned char*)malloc(WIDTH * HEIGHT * 3);

    // Read the image data
    fread(imgData, sizeof(unsigned char), WIDTH * HEIGHT * 3, file);

    fclose(file);
    return imgData;
}

// Function to write the image data to a file
void writeImageData(char *filename, unsigned char *imgData) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Write the header data
    unsigned char header[54];
    for (int i = 0; i < 54; i++) {
        header[i] = 0;
    }
    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = 54 + WIDTH * HEIGHT * 3;
    *(int*)&header[10] = 54;
    *(int*)&header[14] = 40;
    *(int*)&header[18] = WIDTH;
    *(int*)&header[22] = HEIGHT;
    *(short*)&header[26] = 1;
    *(short*)&header[28] = 24;
    fwrite(header, sizeof(unsigned char), 54, file);

    // Write the image data
    fwrite(imgData, sizeof(unsigned char), WIDTH * HEIGHT * 3, file);

    fclose(file);
}

// Function to flip an image horizontally
void flipHorizontal(unsigned char *imgData) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH / 2; x++) {
            int offset1 = (y * WIDTH + x) * 3;
            int offset2 = (y * WIDTH + WIDTH - 1 - x) * 3;
            unsigned char tmp1 = imgData[offset1];
            unsigned char tmp2 = imgData[offset1 + 1];
            unsigned char tmp3 = imgData[offset1 + 2];
            imgData[offset1] = imgData[offset2];
            imgData[offset1 + 1] = imgData[offset2 + 1];
            imgData[offset1 + 2] = imgData[offset2 + 2];
            imgData[offset2] = tmp1;
            imgData[offset2 + 1] = tmp2;
            imgData[offset2 + 2] = tmp3;
        }
    }
}

// Function to tint an image with a specified color
void tintImage(unsigned char *imgData, unsigned char r, unsigned char g, unsigned char b) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int offset = (y * WIDTH + x) * 3;
            // Add specified color to each pixel
            imgData[offset] += r;
            imgData[offset + 1] += g;
            imgData[offset + 2] += b;
        }
    }
}

// Main function to run the program
int main(int argc, char **argv) {
    // Check for arguments
    if (argc < 3) {
        printf("Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    // Read image data from file
    unsigned char *imgData = readImageData(argv[1]);

    // Flip image horizontally
    flipHorizontal(imgData);

    // Tint image with red color
    tintImage(imgData, 50, 0, 0);

    // Write image data to file
    writeImageData(argv[2], imgData);

    // Free dynamically allocated memory
    free(imgData);

    return 0;
}