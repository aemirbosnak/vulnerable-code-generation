//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: retro
/* Retr0Style - A Basic Image Processing Program in C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IMAGE_SIZE 1000

/* Function to flip an image vertically */
void flipVertically(char inputImage[], char outputImage[]) {
    FILE* fptr1 = fopen(inputImage, "rb");
    FILE* fptr2 = fopen(outputImage, "wb");
    unsigned char header[54], colorTable[1024];
    int i;
    
    for (i = 0; i < 54; i++) {
        header[i] = getc(fptr1);
    }
    fwrite(header, sizeof(unsigned char), 54, fptr2);
    
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bitDepth = *(int*)&header[28];
    
    if (bitDepth <= 8) {
        fread(colorTable, sizeof(unsigned char), 1024, fptr1);
        fwrite(colorTable, sizeof(unsigned char), 1024, fptr2);
    }
    
    int rowSize = (width * bitDepth) / 8;
    unsigned char buffer[rowSize];
    
    for (int y = height - 1; y >= 0; y--) {
        fread(buffer, sizeof(unsigned char), rowSize, fptr1);
        fwrite(buffer, sizeof(unsigned char), rowSize, fptr2);
    }
    
    fclose(fptr1);
    fclose(fptr2);
}

/* Function to adjust brightness and contrast of an image */
void adjustBrightnessContrast(char inputImage[], char outputImage[], float brightness, float contrast) {
    FILE* fptr1 = fopen(inputImage, "rb");
    FILE* fptr2 = fopen(outputImage, "wb");
    unsigned char header[54], colorTable[1024];
    int i;
    
    for (i = 0; i < 54; i++) {
        header[i] = getc(fptr1);
    }
    fwrite(header, sizeof(unsigned char), 54, fptr2);
    
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bitDepth = *(int*)&header[28];
    
    if (bitDepth <= 8) {
        fread(colorTable, sizeof(unsigned char), 1024, fptr1);
        fwrite(colorTable, sizeof(unsigned char), 1024, fptr2);
    }
    
    int rowSize = (width * bitDepth) / 8;
    unsigned char buffer[rowSize];
    float pixelValue;
    
    for (int y = 0; y < height; y++) {
        fread(buffer, sizeof(unsigned char), rowSize, fptr1);
        for (int x = 0; x < rowSize; x += bitDepth / 8) {
            for (int c = 0; c < bitDepth / 8; c++) {
                pixelValue = buffer[x + c];
                pixelValue = (pixelValue - 128.0) * contrast + 128.0 + brightness;
                if (pixelValue < 0) {
                    pixelValue = 0;
                }
                if (pixelValue > 255) {
                    pixelValue = 255;
                }
                buffer[x + c] = (unsigned char)pixelValue;
            }
        }
        fwrite(buffer, sizeof(unsigned char), rowSize, fptr2);
    }
    
    fclose(fptr1);
    fclose(fptr2);
}

/* Main function */
int main() {
    char inputImage[MAX_IMAGE_SIZE], outputImage[MAX_IMAGE_SIZE];
    float brightness, contrast;
    int choice;
    
    printf("-------------------- Retr0Style --------------------\n");
    printf("Menu:\n");
    printf("1. Flip Image Vertically\n");
    printf("2. Adjust Brightness and Contrast\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("Enter path to input image file (e.g. input.bmp): ");
        scanf("%s", inputImage);
        printf("Enter path to output image file (e.g. output.bmp): ");
        scanf("%s", outputImage);
        flipVertically(inputImage, outputImage);
        printf("Image flipped vertically and saved as %s\n", outputImage);
    } else if (choice == 2) {
        printf("Enter path to input image file (e.g. input.bmp): ");
        scanf("%s", inputImage);
        printf("Enter path to output image file (e.g. output.bmp): ");
        scanf("%s", outputImage);
        printf("Enter brightness adjustment (e.g. -50 to 50): ");
        scanf("%f", &brightness);
        printf("Enter contrast adjustment (e.g. 0.5 to 1.5): ");
        scanf("%f", &contrast);
        adjustBrightnessContrast(inputImage, outputImage, brightness, contrast);
        printf("Image brightness and contrast adjusted and saved as %s\n", outputImage);
    } else {
        printf("Invalid choice!\n");
    }
    
    return 0;
}