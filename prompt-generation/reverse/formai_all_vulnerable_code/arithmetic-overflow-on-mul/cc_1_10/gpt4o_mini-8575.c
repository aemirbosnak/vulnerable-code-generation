//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;
#pragma pack(pop)

void flipImage(RGB **image, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            RGB temp = image[i][j];
            image[i][j] = image[height - 1 - i][j];
            image[height - 1 - i][j] = temp;
        }
    }
}

void adjustBrightness(RGB **image, int width, int height, int value) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j].red = (image[i][j].red + value > 255) ? 255 : (image[i][j].red + value < 0 ? 0 : image[i][j].red + value);
            image[i][j].green = (image[i][j].green + value > 255) ? 255 : (image[i][j].green + value < 0 ? 0 : image[i][j].green + value);
            image[i][j].blue = (image[i][j].blue + value > 255) ? 255 : (image[i][j].blue + value < 0 ? 0 : image[i][j].blue + value);
        }
    }
}

void adjustContrast(RGB **image, int width, int height, float factor) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j].red = (int)(factor * (image[i][j].red - 128) + 128);
            image[i][j].green = (int)(factor * (image[i][j].green - 128) + 128);
            image[i][j].blue = (int)(factor * (image[i][j].blue - 128) + 128);
            // Clamping values
            image[i][j].red = (image[i][j].red > 255) ? 255 : (image[i][j].red < 0 ? 0 : image[i][j].red);
            image[i][j].green = (image[i][j].green > 255) ? 255 : (image[i][j].green < 0 ? 0 : image[i][j].green);
            image[i][j].blue = (image[i][j].blue > 255) ? 255 : (image[i][j].blue < 0 ? 0 : image[i][j].blue);
        }
    }
}

void loadBMP(const char *filename, RGB ***image, int *width, int *height) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("Could not open file");
        exit(1);
    }

    BITMAPFILEHEADER bfh;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, f);
    BITMAPINFOHEADER bih;
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, f);

    *width = bih.biWidth;
    *height = bih.biHeight;

    *image = (RGB **)malloc(sizeof(RGB *) * (*height));
    for (int i = 0; i < (*height); i++) {
        (*image)[i] = (RGB *)malloc(sizeof(RGB) * (*width));
        fread((*image)[i], sizeof(RGB), *width, f);
    }
    fclose(f);
}

void saveBMP(const char *filename, RGB **image, int width, int height) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        perror("Could not open file");
        exit(1);
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    bfh.bfType = 0x4D42;
    bfh.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + (width * height * sizeof(RGB));
    bfh.bfReserved1 = 0;
    bfh.bfReserved2 = 0;
    bfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    bih.biSize = sizeof(BITMAPINFOHEADER);
    bih.biWidth = width;
    bih.biHeight = height;
    bih.biPlanes = 1;
    bih.biBitCount = 24;
    bih.biCompression = 0;
    bih.biSizeImage = 0;
    bih.biXPelsPerMeter = 2835; // DPI 72
    bih.biYPelsPerMeter = 2835; // DPI 72
    bih.biClrUsed = 0;
    bih.biClrImportant = 0;

    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, f);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, f);

    for (int i = 0; i < height; i++) {
        fwrite(image[i], sizeof(RGB), width, f);
    }
    fclose(f);
}

int main() {
    RGB **image;
    int width, height;
    const char *inputFile = "input.bmp";
    const char *outputFile = "output.bmp";

    loadBMP(inputFile, &image, &width, &height);
    
    int choice;
    do {
        printf("Choose an option:\n");
        printf("1. Flip Image\n");
        printf("2. Adjust Brightness\n");
        printf("3. Adjust Contrast\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                flipImage(image, width, height);
                printf("Image flipped successfully!\n");
                break;
            case 2: {
                int brightnessValue;
                printf("Enter brightness adjustment value (-255 to +255): ");
                scanf("%d", &brightnessValue);
                adjustBrightness(image, width, height, brightnessValue);
                printf("Brightness adjusted successfully!\n");
                break;
            }
            case 3: {
                float contrastFactor;
                printf("Enter contrast adjustment factor (e.g., 1.0 for no change): ");
                scanf("%f", &contrastFactor);
                adjustContrast(image, width, height, contrastFactor);
                printf("Contrast adjusted successfully!\n");
                break;
            }
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
        
        if (choice != 4) {
            saveBMP(outputFile, image, width, height);
            printf("Processed image saved as 'output.bmp'!\n");
        }
    } while (choice != 4);

    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}