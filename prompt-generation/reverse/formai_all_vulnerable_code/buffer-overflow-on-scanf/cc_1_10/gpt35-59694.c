//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IMAGE_SIZE 1000000 // maximum size of image to process
#define WATERMARK_SIZE 1000 // maximum size of watermark text
#define BITS_IN_BYTE 8

// function to check if given file is an image file or not
bool isImageFile(char *filename) {
    char *extension = strrchr(filename, '.');
    if (strcmp(extension, ".jpg") == 0 || strcmp(extension, ".jpeg") == 0 || strcmp(extension, ".png") == 0) {
        return true;
    }
    return false;
}

// function to embed watermark in given image
void embedWatermark(char *imageFilename, char *watermarkText) {
    if (!isImageFile(imageFilename)) {
        printf("Error: %s is not a valid image file\n", imageFilename);
        return;
    }

    // read image file
    FILE *imageFile = fopen(imageFilename, "rb");
    if (imageFile == NULL) {
        printf("Error: Failed to open image file\n");
        return;
    }
    fseek(imageFile, 0, SEEK_END);
    long imageFileSize = ftell(imageFile);
    if (imageFileSize > MAX_IMAGE_SIZE) {
        printf("Error: Image file is too large to process\n");
        fclose(imageFile);
        return;
    }
    rewind(imageFile);
    unsigned char *imageData = (unsigned char*) malloc(imageFileSize);
    fread(imageData, 1, imageFileSize, imageFile);
    fclose(imageFile);

    // read watermark text
    int watermarkLength = strlen(watermarkText);
    char *watermarkBinary = (char*) malloc(watermarkLength * BITS_IN_BYTE + 1);
    int i, j;
    for (i = 0; i < watermarkLength; i++) {
        for (j = 0; j < BITS_IN_BYTE; j++) {
            watermarkBinary[i*BITS_IN_BYTE+j] = (watermarkText[i] & (1 << j)) ? '1' : '0'; 
        }
    }
    watermarkBinary[watermarkLength * BITS_IN_BYTE] = '\0';

    // embed watermark in image data
    int imageDataOffset = 54; // offset of image data in file
    int imageDataMaxSize = imageFileSize - imageDataOffset;
    int watermarkDataSize = watermarkLength * BITS_IN_BYTE;
    if (watermarkDataSize > imageDataMaxSize) {
        printf("Error: Watermark is too large to embed in image\n");
        free(imageData);
        free(watermarkBinary);
        return;
    }
    int watermarkOffset = 0;
    bool endOfWatermark = false;
    for (i = imageDataOffset; i < imageDataOffset + watermarkDataSize; i++) {
        if (watermarkBinary[watermarkOffset] == '1' && imageData[i] % 2 == 0) {
            imageData[i]++;
        } else if (watermarkBinary[watermarkOffset] == '0' && imageData[i] % 2 == 1) {
            imageData[i]--;
        }
        watermarkOffset++;
        if (watermarkOffset >= watermarkDataSize) {
            endOfWatermark = true;
            break; // end of watermark data, exit loop
        }
    }

    // write watermarked image to file
    if (!endOfWatermark) {
        printf("Error: Failed to embed watermark in image\n");
        free(imageData);
        free(watermarkBinary);
        return;
    }
    char *outputFilename = (char*) malloc(strlen(imageFilename) + strlen(".watermarked") + 1);
    sprintf(outputFilename, "%s.watermarked", imageFilename);
    FILE *outputFile = fopen(outputFilename, "wb");
    if (outputFile == NULL) {
        printf("Error: Failed to create watermarked image file\n");
        free(imageData);
        free(watermarkBinary);
        free(outputFilename);
        return;
    }
    fwrite(imageData, 1, imageFileSize, outputFile);
    fclose(outputFile);
    printf("Success: Watermark embedded in watermarked image file %s\n", outputFilename);

    // free memory
    free(imageData);
    free(watermarkBinary);
    free(outputFilename);
}

int main() {
    char imageFilename[100];
    printf("Enter image filename: ");
    scanf("%s", imageFilename);

    char watermarkText[WATERMARK_SIZE];
    printf("Enter watermark text: ");
    getchar();
    fgets(watermarkText, WATERMARK_SIZE, stdin);
    watermarkText[strcspn(watermarkText, "\n")] = '\0'; // remove newline character from end of string

    embedWatermark(imageFilename, watermarkText);

    return 0;
}