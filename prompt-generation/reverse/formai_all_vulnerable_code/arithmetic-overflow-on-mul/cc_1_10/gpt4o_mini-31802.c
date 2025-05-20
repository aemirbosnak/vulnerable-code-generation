//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)
typedef struct {
    unsigned char bfType[2];
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BMPHeader;

typedef struct {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BMPInfoHeader;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGB;

void flip_image(RGB *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            // Swap pixels
            RGB temp = image[y * width + x];
            image[y * width + x] = image[y * width + (width - x - 1)];
            image[y * width + (width - x - 1)] = temp;
        }
    }
}

void adjust_brightness(RGB *image, int width, int height, int value) {
    for (int i = 0; i < width * height; i++) {
        image[i].red = (image[i].red + value > 255) ? 255 : 
                      (image[i].red + value < 0) ? 0 : image[i].red + value;
        image[i].green = (image[i].green + value > 255) ? 255 : 
                        (image[i].green + value < 0) ? 0 : image[i].green + value;
        image[i].blue = (image[i].blue + value > 255) ? 255 : 
                       (image[i].blue + value < 0) ? 0 : image[i].blue + value;
    }
}

void adjust_contrast(RGB *image, int width, int height, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < width * height; i++) {
        image[i].red = (unsigned char)(factor * (image[i].red - 128) + 128);
        image[i].green = (unsigned char)(factor * (image[i].green - 128) + 128);
        image[i].blue = (unsigned char)(factor * (image[i].blue - 128) + 128);
    }
}

void read_bmp(const char *filename, RGB **image, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    BMPHeader header;
    fread(&header, sizeof(BMPHeader), 1, file);
    
    BMPInfoHeader infoHeader;
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, file);

    *width = infoHeader.biWidth;
    *height = infoHeader.biHeight;

    *image = (RGB *)malloc((*width) * (*height) * sizeof(RGB));
    fseek(file, header.bfOffBits, SEEK_SET);
    
    for (int i = 0; i < (*height); i++) {
        for (int j = 0; j < (*width); j++) {
            fread(&((*image)[(i * (*width)) + j]), sizeof(RGB), 1, file);
        }
    }

    fclose(file);
}

void write_bmp(const char *filename, RGB *image, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    BMPHeader header = {{ 'B', 'M' }, 0, 0, 0, 54};
    BMPInfoHeader infoHeader = { 40, width, height, 1, 24, 0, 0, 0, 0, 0, 0 };

    header.bfSize = sizeof(BMPHeader) + sizeof(BMPInfoHeader) + (width * height * sizeof(RGB));

    fwrite(&header, sizeof(BMPHeader), 1, file);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, file);
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fwrite(&(image[(i * width) + j]), sizeof(RGB), 1, file);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <input.bmp> <output.bmp> <brightness_value> <contrast_value>\n", argv[0]);
        return 1;
    }

    RGB *image;
    int width, height;
    read_bmp(argv[1], &image, &width, &height);

    int brightness_value = atoi(argv[3]);
    float contrast_value = atof(argv[4]);

    // Processing image
    flip_image(image, width, height);
    adjust_brightness(image, width, height, brightness_value);
    adjust_contrast(image, width, height, contrast_value);

    write_bmp(argv[2], image, width, height);
    free(image);
    return 0;
}