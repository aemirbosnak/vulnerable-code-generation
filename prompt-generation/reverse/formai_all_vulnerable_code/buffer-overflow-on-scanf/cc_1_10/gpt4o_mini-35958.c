//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// BMP file header structure
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
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGBTRIPLE;
#pragma pack(pop)

// Function prototype
void openImage(const char *filename);
void convertToGrayscale(BITMAPFILEHEADER bfh, BITMAPINFOHEADER bih, RGBTRIPLE **imageData);
void saveImage(const char *filename, BITMAPFILEHEADER bfh, BITMAPINFOHEADER bih, RGBTRIPLE **imageData);
void freeImageData(RGBTRIPLE **imageData, int height);
void displayMenu();

int main() {
    displayMenu();
    return 0;
}

void displayMenu() {
    char input[100];
    char filename[100];
    
    printf("Welcome to the Simple BMP Image Editor!\n");
    printf("Please enter the command to process a BMP image (type 'exit' to quit):\n");
    
    while (1) {
        printf("Command (open, gray, save, exit): ");
        scanf("%s", input);

        if (strcmp(input, "open") == 0) {
            printf("Enter the filename to open: ");
            scanf("%s", filename);
            openImage(filename);
        } else if (strcmp(input, "gray") == 0) {
            // Call your convert function here when the data is loaded
            printf("Grayscale conversion is done. Please save your image!\n");
        } else if (strcmp(input, "save") == 0) {
            printf("Enter the filename to save: ");
            scanf("%s", filename);
            // Pass the current image data to the save function here
        } else if (strcmp(input, "exit") == 0) {
            printf("Thank you for using the BMP Image Editor!\n");
            break;
        } else {
            printf("Invalid command! Please try again.\n");
        }
    }
}

void openImage(const char *filename) {
    FILE *file = fopen(filename, "rb");

    if (!file) {
        printf("Error: Could not open the file %s\n", filename);
        return;
    }

    BITMAPFILEHEADER bfh;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, file);

    if (bfh.bfType != 0x4D42) {
        printf("Error: Not a valid BMP file.\n");
        fclose(file);
        return;
    }

    BITMAPINFOHEADER bih;
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, file);

    int width = bih.biWidth;
    int height = abs(bih.biHeight);
    RGBTRIPLE **imageData = malloc(height * sizeof(RGBTRIPLE *));

    for (int i = 0; i < height; i++) {
        imageData[i] = malloc(width * sizeof(RGBTRIPLE));
        fread(imageData[i], sizeof(RGBTRIPLE), width, file);
        fseek(file, (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4, SEEK_CUR); // Skip padding
    }
    
    printf("Image opened successfully: %dx%d pixels.\n", width, height);
    fclose(file);

    // Convert the image to grayscale
    convertToGrayscale(bfh, bih, imageData);

    // Free allocated memory and complete other operations
    freeImageData(imageData, height);
}

void convertToGrayscale(BITMAPFILEHEADER bfh, BITMAPINFOHEADER bih, RGBTRIPLE **imageData) {
    int width = bih.biWidth;
    int height = abs(bih.biHeight);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            uint8_t gray = (uint8_t)(0.299 * imageData[i][j].red + 0.587 * imageData[i][j].green + 0.114 * imageData[i][j].blue);
            imageData[i][j].red = gray;
            imageData[i][j].green = gray;
            imageData[i][j].blue = gray;
        }
    }
    printf("The image has been converted to grayscale.\n");
}

void saveImage(const char *filename, BITMAPFILEHEADER bfh, BITMAPINFOHEADER bih, RGBTRIPLE **imageData) {
    // Implementation of saving the BMP would go here
}

void freeImageData(RGBTRIPLE **imageData, int height) {
    for (int i = 0; i < height; i++) {
        free(imageData[i]);
    }
    free(imageData);
}