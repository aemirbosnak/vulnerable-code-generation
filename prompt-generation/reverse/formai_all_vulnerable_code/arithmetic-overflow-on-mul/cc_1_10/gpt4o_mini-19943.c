//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

void flipImage(uint8_t* imgData, int width, int height, int padding) {
    for(int i = 0; i < height / 2; i++) {
        for(int j = 0; j < width * 3; j++) {
            uint8_t temp = imgData[i * (width * 3 + padding) + j];
            imgData[i * (width * 3 + padding) + j] = imgData[(height - i - 1) * (width * 3 + padding) + j];
            imgData[(height - i - 1) * (width * 3 + padding) + j] = temp;
        }
    }
}

void adjustBrightness(uint8_t* imgData, int width, int height, int padding, int value) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width * 3; j++) {
            int newValue = imgData[i * (width * 3 + padding) + j] + value;
            imgData[i * (width * 3 + padding) + j] = (newValue > 255) ? 255 : (newValue < 0) ? 0 : newValue;
        }
    }
}

void adjustContrast(uint8_t* imgData, int width, int height, int padding, float factor) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width * 3; j++) {
            int newValue = (int)((imgData[i * (width * 3 + padding) + j] - 128) * factor + 128);
            imgData[i * (width * 3 + padding) + j] = (newValue > 255) ? 255 : (newValue < 0) ? 0 : newValue;
        }
    }
}

int main() {
    FILE *inputFile = fopen("input.bmp", "rb");
    FILE *outputFile = fopen("output.bmp", "wb");
    
    if(!inputFile || !outputFile) {
        fprintf(stderr, "Error opening files!\n");
        return 1;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, inputFile);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, inputFile);
    
    if(bfh.bfType != 0x4D42) {
        fprintf(stderr, "Not a BMP file!\n");
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }
    
    int width = bih.biWidth;
    int height = bih.biHeight;
    int padding = (4 - (width * 3) % 4) % 4;
    
    int imgSize = (width * 3 + padding) * height;
    uint8_t *imgData = (uint8_t*)malloc(imgSize);
    
    fseek(inputFile, bfh.bfOffBits, SEEK_SET);
    fread(imgData, 1, imgSize, inputFile);
    
    printf("Choose an operation:\n1. Flip Image\n2. Adjust Brightness\n3. Adjust Contrast\n");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            flipImage(imgData, width, height, padding);
            printf("Image flipped!\n");
            break;
        case 2:
            printf("Enter brightness value (-255 to 255): ");
            int brightnessValue;
            scanf("%d", &brightnessValue);
            adjustBrightness(imgData, width, height, padding, brightnessValue);
            printf("Brightness adjusted!\n");
            break;
        case 3:
            printf("Enter contrast factor (0.0 to 3.0): ");
            float contrastFactor;
            scanf("%f", &contrastFactor);
            adjustContrast(imgData, width, height, padding, contrastFactor);
            printf("Contrast adjusted!\n");
            break;
        default:
            fprintf(stderr, "Invalid choice!\n");
            free(imgData);
            fclose(inputFile);
            fclose(outputFile);
            return 1;
    }

    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, outputFile);
    fseek(outputFile, bfh.bfOffBits, SEEK_SET);
    fwrite(imgData, 1, imgSize, outputFile);

    printf("Image processing completed! Output saved as output.bmp\n");

    free(imgData);
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}