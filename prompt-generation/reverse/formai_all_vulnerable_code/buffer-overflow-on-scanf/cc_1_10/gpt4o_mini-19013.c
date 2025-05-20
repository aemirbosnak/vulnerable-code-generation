//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#pragma pack(push, 1)  // Ensures proper alignments for BMP headers
typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitsPerPixel;
    uint32_t compression;
    uint32_t imageSize;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t importantColors;
} DIBHeader;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;

#pragma pack(pop)

void loadBMP(const char *filename, BMPHeader *bmpHeader, DIBHeader *dibHeader, RGB **imageData) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fread(bmpHeader, sizeof(BMPHeader), 1, file);
    fread(dibHeader, sizeof(DIBHeader), 1, file);
    
    *imageData = (RGB *)malloc(dibHeader->width * dibHeader->height * sizeof(RGB));
    fseek(file, bmpHeader->offset, SEEK_SET);
    fread(*imageData, sizeof(RGB), dibHeader->width * dibHeader->height, file);

    fclose(file);
}

void saveBMP(const char *filename, BMPHeader *bmpHeader, DIBHeader *dibHeader, RGB *imageData) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error saving file");
        exit(EXIT_FAILURE);
    }

    fwrite(bmpHeader, sizeof(BMPHeader), 1, file);
    fwrite(dibHeader, sizeof(DIBHeader), 1, file);
    
    fseek(file, bmpHeader->offset, SEEK_SET);
    fwrite(imageData, sizeof(RGB), dibHeader->width * dibHeader->height, file);

    fclose(file);
}

void invertColors(RGB *imageData, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        imageData[i].red = 255 - imageData[i].red;
        imageData[i].green = 255 - imageData[i].green;
        imageData[i].blue = 255 - imageData[i].blue;
    }
}

void displayMenu() {
    printf("Simple BMP Image Editor\n");
    printf("1. Invert Colors\n");
    printf("2. Exit\n");
    printf("Choose an option (1-2): ");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input.bmp> <output.bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    BMPHeader bmpHeader;
    DIBHeader dibHeader;
    RGB *imageData = NULL;

    loadBMP(argv[1], &bmpHeader, &dibHeader, &imageData);

    int running = 1;

    while (running) {
        displayMenu();

        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                invertColors(imageData, dibHeader.width, dibHeader.height);
                printf("Colors inverted!\n");
                break;
            case 2:
                running = 0;
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    saveBMP(argv[2], &bmpHeader, &dibHeader, imageData);
    free(imageData);
    
    printf("Image saved to %s\n", argv[2]);
    return EXIT_SUCCESS;
}