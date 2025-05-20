//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BMP header structure
#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;       // Filetype
    unsigned int bfSize;        // File size in bytes
    unsigned short bfReserved1;  // Reserved
    unsigned short bfReserved2;  // Reserved
    unsigned int bfOffBits;      // Offset to start of pixel data
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;        // Size of this header
    int biWidth;                // Width of image
    int biHeight;               // Height of image
    unsigned short biPlanes;     // Number of color planes
    unsigned short biBitCount;   // Bits per pixel
    unsigned int biCompression;   // Compression type
    unsigned int biSizeImage;    // Image size (can be 0 for uncompressed images)
    int biXPelsPerMeter;         // Pixels per meter in X
    int biYPelsPerMeter;         // Pixels per meter in Y
    unsigned int biClrUsed;      // Number of colors in the palette
    unsigned int biClrImportant;  // Important colors
} BITMAPINFOHEADER;
#pragma pack(pop)

// Function prototypes
void loadBMP(const char *filename, unsigned char **imageData, int *width, int *height);
void saveBMP(const char *filename, unsigned char *imageData, int width, int height);
void convertToGrayscale(unsigned char *imageData, int width, int height);
void flipImage(unsigned char *imageData, int width, int height);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    unsigned char *imageData;
    int width, height;

    loadBMP(argv[1], &imageData, &width, &height);
    convertToGrayscale(imageData, width, height);
    flipImage(imageData, width, height);
    saveBMP(argv[2], imageData, width, height);

    free(imageData);
    printf("Image processed successfully!\n");
    return 0;
}

void loadBMP(const char *filename, unsigned char **imageData, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    BITMAPFILEHEADER fileHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);

    BITMAPINFOHEADER infoHeader;
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    *width = infoHeader.biWidth;
    *height = infoHeader.biHeight;

    // Calculate the size of BMP data
    size_t imageSize = (*width) * (*height) * 3; // BMP stores pixel data in BGR
    *imageData = (unsigned char *)malloc(imageSize);
    fseek(file, fileHeader.bfOffBits, SEEK_SET);
    fread(*imageData, imageSize, 1, file);

    fclose(file);
}

void saveBMP(const char *filename, unsigned char *imageData, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error creating file");
        exit(1);
    }

    BITMAPFILEHEADER fileHeader = {0x4D42, 0, 0, 0, sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)};
    BITMAPINFOHEADER infoHeader = {sizeof(BITMAPINFOHEADER), width, height, 1, 24, 0, 0, 0, 0, 0, 0};

    // Set file size
    fileHeader.bfSize = fileHeader.bfOffBits + (width * height * 3);
    
    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    size_t imageSize = width * height * 3;
    fwrite(imageData, imageSize, 1, file);
    
    fclose(file);
}

void convertToGrayscale(unsigned char *imageData, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        unsigned char b = imageData[i * 3];
        unsigned char g = imageData[i * 3 + 1];
        unsigned char r = imageData[i * 3 + 2];
        unsigned char gray = (b + g + r) / 3; // Simple averaging
        
        imageData[i * 3] = gray;       // Blue channel
        imageData[i * 3 + 1] = gray;   // Green channel
        imageData[i * 3 + 2] = gray;   // Red channel
    }
}

void flipImage(unsigned char *imageData, int width, int height) {
    int rowSize = width * 3;
    unsigned char *tempRow = (unsigned char *)malloc(rowSize);
    
    for (int i = 0; i < height / 2; i++) {
        memcpy(tempRow, imageData + i * rowSize, rowSize);
        memcpy(imageData + i * rowSize, imageData + (height - i - 1) * rowSize, rowSize);
        memcpy(imageData + (height - i - 1) * rowSize, tempRow, rowSize);
    }
    
    free(tempRow);
}