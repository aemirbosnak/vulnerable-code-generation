//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)
typedef struct {
    unsigned char  bfType[2];
    unsigned int   bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int   bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;
    int          biWidth;
    int          biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int   biCompression;
    unsigned int   biSizeImage;
    int          biXPelsPerMeter;
    int          biYPelsPerMeter;
    unsigned int   biClrUsed;
    unsigned int   biClrImportant;
} BITMAPINFOHEADER;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} PIXEL;
#pragma pack(pop)

void invertColors(PIXEL *pixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        pixels[i].red = 255 - pixels[i].red;
        pixels[i].green = 255 - pixels[i].green;
        pixels[i].blue = 255 - pixels[i].blue;
    }
}

void readBMP(const char *filename, BITMAPFILEHEADER *bfh, BITMAPINFOHEADER *bih, PIXEL **pixels) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    fread(bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fread(bih, sizeof(BITMAPINFOHEADER), 1, file);

    *pixels = (PIXEL *)malloc(bih->biWidth * bih->biHeight * sizeof(PIXEL));
    fseek(file, bfh->bfOffBits, SEEK_SET);
    fread(*pixels, sizeof(PIXEL), bih->biWidth * bih->biHeight, file);
    fclose(file);
}

void writeBMP(const char *filename, BITMAPFILEHEADER bfh, BITMAPINFOHEADER bih, PIXEL *pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, file);
    fseek(file, bfh.bfOffBits, SEEK_SET);
    fwrite(pixels, sizeof(PIXEL), bih.biWidth * bih.biHeight, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    PIXEL *pixels;

    readBMP(argv[1], &bfh, &bih, &pixels);
    invertColors(pixels, bih.biWidth, bih.biHeight);
    writeBMP(argv[2], bfh, bih, pixels);

    free(pixels);
    printf("Image processed successfully, output saved to %s\n", argv[2]);
    return EXIT_SUCCESS;
}