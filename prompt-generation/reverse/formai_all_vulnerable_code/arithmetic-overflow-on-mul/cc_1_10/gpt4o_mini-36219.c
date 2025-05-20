//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define a simple bitmap structure
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

void apply_greyscale(RGB *pixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        uint8_t grey = (pixels[i].red + pixels[i].green + pixels[i].blue) / 3;
        pixels[i].red = grey;
        pixels[i].green = grey;
        pixels[i].blue = grey;
    }
}

void apply_invert(RGB *pixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        pixels[i].red = 255 - pixels[i].red;
        pixels[i].green = 255 - pixels[i].green;
        pixels[i].blue = 255 - pixels[i].blue;
    }
}

void save_bmp(const char *filename, RGB *pixels, BITMAPFILEHEADER bf, BITMAPINFOHEADER bi) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to save image");
        return;
    }
    
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, file);
    
    int padding_size = (4 - (bi.biWidth * sizeof(RGB)) % 4) % 4; // padding for 4-byte alignment
    for (int i = 0; i < bi.biHeight; i++) {
        fwrite(pixels + (bi.biWidth * (bi.biHeight - i - 1)), sizeof(RGB), bi.biWidth, file);
        for (int p = 0; p < padding_size; p++) {
            fputc(0, file); // padding
        }
    }
    
    fclose(file);
}

void load_bmp(const char *filename, RGB **pixels, BITMAPFILEHEADER *bf, BITMAPINFOHEADER *bi) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open image");
        return;
    }
    
    fread(bf, sizeof(BITMAPFILEHEADER), 1, file);
    fread(bi, sizeof(BITMAPINFOHEADER), 1, file);
    
    *pixels = (RGB *)malloc(bi->biWidth * bi->biHeight * sizeof(RGB));
    if (!*pixels) {
        fclose(file);
        perror("Memory allocation failed");
        return;
    }

    int padding_size = (4 - (bi->biWidth * sizeof(RGB)) % 4) % 4;
    for (int i = 0; i < bi->biHeight; i++) {
        fread(*pixels + (bi->biWidth * (bi->biHeight - i - 1)), sizeof(RGB), bi->biWidth, file);
        fseek(file, padding_size, SEEK_CUR); // skip padding
    }
    
    fclose(file);
}

void print_menu() {
    printf("Image Editor Menu:\n");
    printf("1. Load Image\n");
    printf("2. Apply Greyscale\n");
    printf("3. Invert Colors\n");
    printf("4. Save Image\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    RGB *pixels = NULL;
    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;
    char filename[256];
    int option = 0;

    while (1) {
        print_menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter filename to load: ");
                scanf("%s", filename);
                load_bmp(filename, &pixels, &bf, &bi);
                printf("Image loaded successfully.\n");
                break;
            case 2:
                if (pixels) {
                    apply_greyscale(pixels, bi.biWidth, bi.biHeight);
                    printf("Greyscale applied.\n");
                } else {
                    printf("No image loaded.\n");
                }
                break;
            case 3:
                if (pixels) {
                    apply_invert(pixels, bi.biWidth, bi.biHeight);
                    printf("Colors inverted.\n");
                } else {
                    printf("No image loaded.\n");
                }
                break;
            case 4:
                if (pixels) {
                    printf("Enter filename to save: ");
                    scanf("%s", filename);
                    save_bmp(filename, pixels, bf, bi);
                    printf("Image saved successfully.\n");
                } else {
                    printf("No image loaded.\n");
                }
                break;
            case 5:
                free(pixels);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}