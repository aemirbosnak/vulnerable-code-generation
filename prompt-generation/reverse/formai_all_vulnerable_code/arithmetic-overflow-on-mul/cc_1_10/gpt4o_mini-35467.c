//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)
typedef struct {
    unsigned char  signature[2]; // BMP signature
    unsigned int   fileSize;      // Size of the file (in bytes)
    unsigned short reserved1;      // Reserved. Should be 0
    unsigned short reserved2;      // Reserved. Should be 0
    unsigned int   dataOffset;     // Offset to start of pixel data
} BMPHeader;

typedef struct {
    unsigned int   headerSize;     // Size of this header
    int            width;          // Width of the bitmap
    int            height;         // Height of the bitmap
    unsigned short planes;         // Number of color planes
    unsigned short bitsPerPixel;   // Bits per pixel
    unsigned int   compression;     // Compression method
    unsigned int   imageSize;      // Image size (in bytes)
    int            xPixelsPerMeter; // Horizontal resolution
    int            yPixelsPerMeter; // Vertical resolution
    unsigned int   colorsUsed;      // Number of colors in palette
    unsigned int   importantColors; // Important colors
} DIBHeader;

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;
#pragma pack(pop)

void convertToGrayscale(Pixel *image, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        unsigned char gray = (image[i].r + image[i].g + image[i].b) / 3;
        image[i].r = gray;
        image[i].g = gray;
        image[i].b = gray;
    }
}

void readBMP(const char *filename, BMPHeader *bmpHeader, DIBHeader *dibHeader, Pixel **image) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(1);
    }

    fread(bmpHeader, sizeof(BMPHeader), 1, file);
    fread(dibHeader, sizeof(DIBHeader), 1, file);

    if (dibHeader->bitsPerPixel != 24) {
        fprintf(stderr, "Only 24-bit BMP files are supported.\n");
        fclose(file);
        exit(1);
    }

    *image = malloc(dibHeader->width * dibHeader->height * sizeof(Pixel));
    fseek(file, bmpHeader->dataOffset, SEEK_SET);
    fread(*image, sizeof(Pixel), dibHeader->width * dibHeader->height, file);

    fclose(file);
}

void writeBMP(const char *filename, BMPHeader bmpHeader, DIBHeader dibHeader, Pixel *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file %s for writing\n", filename);
        exit(1);
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, file);
    fwrite(&dibHeader, sizeof(DIBHeader), 1, file);
    fseek(file, bmpHeader.dataOffset, SEEK_SET);
    fwrite(image, sizeof(Pixel), dibHeader.width * dibHeader.height, file);

    fclose(file);
}

void displayMenu() {
    printf("Simple BMP Image Editor\n");
    printf("1. Load Image\n");
    printf("2. Convert to Grayscale\n");
    printf("3. Save Image\n");
    printf("4. Exit\n");
}

int main() {
    BMPHeader bmpHeader;
    DIBHeader dibHeader;
    Pixel *image = NULL;
    char filename[100];
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter image file name to load: ");
                scanf("%s", filename);
                readBMP(filename, &bmpHeader, &dibHeader, &image);
                printf("Image loaded successfully!\n");
                break;
            case 2:
                if (image == NULL) {
                    printf("No image loaded. Please load an image first.\n");
                } else {
                    convertToGrayscale(image, dibHeader.width, dibHeader.height);
                    printf("Image converted to grayscale!\n");
                }
                break;
            case 3:
                if (image == NULL) {
                    printf("No image loaded. Please load an image first.\n");
                } else {
                    char outputFilename[100];
                    printf("Enter file name to save the image: ");
                    scanf("%s", outputFilename);
                    writeBMP(outputFilename, bmpHeader, dibHeader, image);
                    printf("Image saved successfully!\n");
                }
                break;
            case 4:
                free(image);
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}