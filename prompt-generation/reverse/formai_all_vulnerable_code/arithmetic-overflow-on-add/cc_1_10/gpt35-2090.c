//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FILE_NAME "image.bmp"

typedef unsigned char BYTE;
typedef unsigned short int WORD;
typedef unsigned int DWORD;
typedef int LONG;

#pragma pack(push, 1)

typedef struct tagBITMAPFILEHEADER {
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} BITMAPINFOHEADER;

typedef struct tagRGBQUAD {
    BYTE rgbBlue;
    BYTE rgbGreen;
    BYTE rgbRed;
    BYTE rgbReserved;
} RGBQUAD;

#pragma pack(pop)

void flip_horizontal(BYTE* data, LONG width, LONG height, WORD bit_count) {
    LONG row_size = (width * bit_count + 31) / 32 * 4;
    BYTE* row_data = (BYTE*) malloc(row_size);
    for (LONG y = 0; y < height; ++y) {
        memcpy(row_data, data + y * row_size, row_size);
        for (LONG x = 0; x < width / 2; ++x) {
            BYTE tmp[row_size / 2];
            memcpy(tmp, row_data + x * bit_count / 8, bit_count / 8);
            memcpy(row_data + x * bit_count / 8, row_data + (width - x - 1) * bit_count / 8, bit_count / 8);
            memcpy(row_data + (width - x - 1) * bit_count / 8, tmp, bit_count / 8);
        }
        memcpy(data + y * row_size, row_data, row_size);
    }
    free(row_data);
}

void change_brightness(BYTE* data, LONG width, LONG height, WORD bit_count, float brightness) {
    for (LONG y = 0; y < height; ++y) {
        for (LONG x = 0; x < width; ++x) {
            BYTE* color = data + y * ((width * bit_count + 31) / 32 * 4) + x * bit_count / 8;
            color[0] = fmax(0, fmin(255, color[0] * brightness));
            color[1] = fmax(0, fmin(255, color[1] * brightness));
            color[2] = fmax(0, fmin(255, color[2] * brightness));
        }
    }
}

void change_contrast(BYTE* data, LONG width, LONG height, WORD bit_count, float contrast) {
    for (LONG y = 0; y < height; ++y) {
        for (LONG x = 0; x < width; ++x) {
            BYTE* color = data + y * ((width * bit_count + 31) / 32 * 4) + x * bit_count / 8;
            color[0] = fmax(0, fmin(255, (color[0] - 127.5) * contrast + 127.5));
            color[1] = fmax(0, fmin(255, (color[1] - 127.5) * contrast + 127.5));
            color[2] = fmax(0, fmin(255, (color[2] - 127.5) * contrast + 127.5));
        }
    }
}

int main() {
    FILE* f = fopen(FILE_NAME, "rb");
    if (!f) {
        perror("Failed to open file");
        exit(1);
    }

    BITMAPFILEHEADER file_header;
    BITMAPINFOHEADER info_header;

    fread(&file_header, sizeof(BITMAPFILEHEADER), 1, f);
    fread(&info_header, sizeof(BITMAPINFOHEADER), 1, f);

    BYTE* data = (BYTE*) malloc(info_header.biSizeImage);

    fseek(f, file_header.bfOffBits, SEEK_SET);
    fread(data, info_header.biSizeImage, 1, f);

    fclose(f);

    flip_horizontal(data, info_header.biWidth, info_header.biHeight, info_header.biBitCount);
    change_brightness(data, info_header.biWidth, info_header.biHeight, info_header.biBitCount, 1.25);
    change_contrast(data, info_header.biWidth, info_header.biHeight, info_header.biBitCount, 1.5);

    f = fopen(FILE_NAME, "wb");
    if (!f) {
        perror("Failed to open file");
        exit(1);
    }

    fwrite(&file_header, sizeof(BITMAPFILEHEADER), 1, f);
    fwrite(&info_header, sizeof(BITMAPINFOHEADER), 1, f);
    fwrite(data, info_header.biSizeImage, 1, f);

    fclose(f);

    free(data);

    return 0;
}