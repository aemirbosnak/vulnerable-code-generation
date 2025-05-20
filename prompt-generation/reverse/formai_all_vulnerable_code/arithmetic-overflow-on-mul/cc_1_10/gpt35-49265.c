//FormAI DATASET v1.0 Category: Image Editor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to read the image file
void readImage(char *filename, unsigned char **data, int *width, int *height, int *channels) {
    FILE *file = fopen(filename, "rb");

    // read the header of the file
    unsigned char header[18];
    fread(header, sizeof(unsigned char), 18, file);

    // get the dimensions of the image
    *width = header[13] * 256 + header[12];
    *height = header[15] * 256 + header[14];

    // get the number of channels
    *channels = header[16];

    // allocate memory for the image data
    *data = (unsigned char*)malloc(*width * *height * *channels);

    // read the image data
    fread(*data, sizeof(unsigned char), *width * *height * *channels, file);

    // close the file
    fclose(file);
}

// function to write the modified image to a new file
void writeImage(char *filename, unsigned char *data, int width, int height, int channels) {
    FILE *file = fopen(filename, "wb");

    // write the header of the file
    unsigned char header[18] = { 0 };
    header[2] = 2; // uncompressed
    header[12] = width % 256;
    header[13] = width / 256;
    header[14] = height % 256;
    header[15] = height / 256;
    header[16] = channels;
    header[17] = 8; // bit depth
    fwrite(header, sizeof(unsigned char), 18, file);

    // write the image data
    fwrite(data, sizeof(unsigned char), width * height * channels, file);

    //close the file
    fclose(file);
}

int main() {
    // read the image file
    char *filename = "input.bmp";
    unsigned char *data;
    int width, height, channels;
    readImage(filename, &data, &width, &height, &channels);

    // apply filter to the image
    for (int i = 0; i < width * height * channels; i++) {
        data[i] = 255 - data[i]; // invert colors
    }

    // write the modified image to a new file
    char *newFilename = "output.bmp";
    writeImage(newFilename, data, width, height, channels);

    // free memory allocated for the image data
    free(data);

    return 0;
}