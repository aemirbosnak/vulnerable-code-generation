//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: paranoid
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
    int32_t  biWidth;        
    int32_t  biHeight;       
    uint16_t biPlanes;       
    uint16_t biBitCount;     
    uint32_t biCompression;  
    uint32_t biSizeImage;    
    int32_t  biXPelsPerMeter; 
    int32_t  biYPelsPerMeter; 
    uint32_t biClrUsed;      
    uint32_t biClrImportant;  
} BITMAPINFOHEADER;

typedef struct {
    uint8_t Blue;
    uint8_t Green;
    uint8_t Red;
} RGBTRIPLE;

#pragma pack(pop)

void checkFile(FILE *file) {
    if (!file) {
        fprintf(stderr, "ERROR: Unable to open file!\n");
        exit(EXIT_FAILURE);
    }
}

void loadImage(const char *filename, BITMAPFILEHEADER *fileHeader, BITMAPINFOHEADER *infoHeader, RGBTRIPLE **imageData) {
    FILE *file = fopen(filename, "rb");
    checkFile(file);

    fread(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fread(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    if (fileHeader->bfType != 0x4D42) {
        fprintf(stderr, "ERROR: Not a valid BMP file!\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    
    long pixelDataSize = infoHeader->biWidth * infoHeader->biHeight * sizeof(RGBTRIPLE);
    *imageData = malloc(pixelDataSize);
    fseek(file, fileHeader->bfOffBits, SEEK_SET);
    fread(*imageData, pixelDataSize, 1, file);

    fclose(file);
}

void saveImage(const char *filename, BITMAPFILEHEADER *fileHeader, BITMAPINFOHEADER *infoHeader, RGBTRIPLE *imageData) {
    FILE *file = fopen(filename, "wb");
    checkFile(file);

    fwrite(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);
    
    long pixelDataSize = infoHeader->biWidth * infoHeader->biHeight * sizeof(RGBTRIPLE);
    fwrite(imageData, pixelDataSize, 1, file);

    fclose(file);
}

void invertColors(RGBTRIPLE *imageData, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        imageData[i].Red = 255 - imageData[i].Red;
        imageData[i].Green = 255 - imageData[i].Green;
        imageData[i].Blue = 255 - imageData[i].Blue;
    }
}

void grayscale(RGBTRIPLE *imageData, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        uint8_t gray = (imageData[i].Red + imageData[i].Green + imageData[i].Blue) / 3;
        imageData[i].Red = gray;
        imageData[i].Green = gray;
        imageData[i].Blue = gray;
    }
}

void printMenu() {
    printf("Image Editor Menu:\n");
    printf("1. Invert Colors\n");
    printf("2. Convert to Grayscale\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    RGBTRIPLE *imageData = NULL;

    char inputFile[256];
    char outputFile[256];

    printf("Enter the input BMP file name: ");
    scanf("%255s", inputFile);

    loadImage(inputFile, &fileHeader, &infoHeader, &imageData);

    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                invertColors(imageData, infoHeader.biWidth, infoHeader.biHeight);
                printf("Colors inverted.\n");
                break;
            case 2:
                grayscale(imageData, infoHeader.biWidth, infoHeader.biHeight);
                printf("Converted to grayscale.\n");
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    printf("Enter the output BMP file name: ");
    scanf("%255s", outputFile);
    saveImage(outputFile, &fileHeader, &infoHeader, imageData);

    free(imageData);
    return 0;
}