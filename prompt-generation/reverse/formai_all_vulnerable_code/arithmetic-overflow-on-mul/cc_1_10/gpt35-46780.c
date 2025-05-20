//FormAI DATASET v1.0 Category: Image Steganography ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define SECRET_MESSAGE "My secret message is hidden in this image!"

typedef struct Pixel {
    unsigned char red, green, blue;
}Pixel;

void hideMessage(Pixel* pixels, int messageLength);
void decodeMessage(Pixel* pixels);

int main(void) {
    FILE* inputFile = fopen("input.bmp", "rb");
    FILE* outputFile = fopen("output.bmp", "wb");

    int i, j, width, height, messageLength;
    unsigned char header[54];

    // read header from input file
    fread(header, sizeof(unsigned char), 54, inputFile);

    // get image dimensions from header
    width = *(int*)(header + 18);
    height = *(int*)(header + 22);

    // calculate total number of pixels
    int numPixels = width * height;

    // allocate memory for pixel data
    Pixel* pixels = (Pixel*)malloc(numPixels * sizeof(Pixel));
    
    // read pixel data from input file
    for(i = 0; i < numPixels; i++) {
        fread(&pixels[i].blue, sizeof(unsigned char), 1, inputFile);
        fread(&pixels[i].green, sizeof(unsigned char), 1, inputFile);
        fread(&pixels[i].red, sizeof(unsigned char), 1, inputFile);
    }

    // hide secret message in image
    messageLength = strlen(SECRET_MESSAGE);
    hideMessage(pixels, messageLength);

    // write modified pixel data to output file
    fwrite(header, sizeof(unsigned char), 54, outputFile);
    for(i = 0; i < numPixels; i++) {
        fwrite(&pixels[i].blue, sizeof(unsigned char), 1, outputFile);
        fwrite(&pixels[i].green, sizeof(unsigned char), 1, outputFile);
        fwrite(&pixels[i].red, sizeof(unsigned char), 1, outputFile);
    }

    // decode secret message from image
    decodeMessage(pixels);

    // free allocated memory
    free(pixels);

    // close input and output files
    fclose(inputFile);
    fclose(outputFile);

    printf("Program executed successfully.\n");

    return 0;
}

void hideMessage(Pixel* pixels, int messageLength) {
    int i, j, bitCount = 0;
    unsigned char currentByte = 0, bitMask = 1;
    for(i = 0; i < messageLength; i++) {
        for(j = 0; j < 8; j++) {
            // get current bit of message
            currentByte = (SECRET_MESSAGE[i] & bitMask) << bitCount;
            // set least significant bit of blue component of pixel to current bit of message
            pixels[i].blue = (pixels[i].blue & (~bitMask)) | currentByte;
            // shift bit mask
            bitMask <<= 1;
            // increment bit count
            bitCount++;
            // if all 8 bits have been encoded, reset bit mask and bit count, and move on to next pixel
            if(bitCount == 8) {
                bitMask = 1;
                bitCount = 0;
                i++;
            }
        }
    }
}

void decodeMessage(Pixel* pixels) {
    int i, j, bitCount = 0;
    unsigned char currentByte = 0, bitMask = 1;
    printf("Decoded message: ");
    for(i = 0; i < strlen(SECRET_MESSAGE); i++) {
        for(j = 0; j < 8; j++) {
            // get least significant bit of blue component of pixel
            currentByte |= (pixels[i].blue & bitMask) >> bitCount;
            // shift bit mask
            bitMask <<= 1;
            // increment bit count
            bitCount++;
            // if all 8 bits have been read, print current byte and reset bit mask and bit count
            if(bitCount == 8) {
                printf("%c", currentByte);
                currentByte = 0;
                bitMask = 1;
                bitCount = 0;
                i++;
            }
        }
    }
    printf("\n");
}