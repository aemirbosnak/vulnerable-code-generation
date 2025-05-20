//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)
typedef struct {
    unsigned char bfType[2];
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BITMAPFILEHEADER;

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
    unsigned int biClrImportant;
    unsigned int biClrUsed;
    int biRedMask;
    int biGreenMask;
    int biBlueMask;
} BITMAPINFOHEADER;

void flip_image(unsigned char* image, int width, int height, int padding) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width * 3; j++) {
            unsigned char temp = image[(i * width * 3) + j];
            image[(i * width * 3) + j] = image[((height - 1 - i) * width * 3) + j];
            image[((height - 1 - i) * width * 3) + j] = temp;
        }
    }
}

void change_brightness(unsigned char* image, int size, int change) {
    for (int i = 0; i < size; i++) {
        int new_value = image[i] + change;
        image[i] = new_value < 0 ? 0 : (new_value > 255 ? 255 : new_value);
    }
}

void change_contrast(unsigned char* image, int size, float factor) {
    float f = (factor + 1) / (1 + 255 * factor);
    for (int i = 0; i < size; i++) {
        int new_value = (int)(f * (image[i] - 128) + 128);
        image[i] = new_value < 0 ? 0 : (new_value > 255 ? 255 : new_value);
    }
}

void read_bmp(const char* filename, unsigned char** image, BITMAPFILEHEADER* bmfHeader, BITMAPINFOHEADER* bmInfoHeader) {
    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        perror("Failed to open file");
        exit(1);
    }
    
    fread(bmfHeader, sizeof(BITMAPFILEHEADER), 1, f);
    fread(bmInfoHeader, sizeof(BITMAPINFOHEADER), 1, f);
    
    int width = bmInfoHeader->biWidth;
    int height = bmInfoHeader->biHeight;
    int padding = (4 - (width * 3) % 4) % 4;
    
    *image = (unsigned char*)malloc(height * (width * 3 + padding));
    fseek(f, bmfHeader->bfOffBits, SEEK_SET);
    
    for (int i = 0; i < height; i++) {
        fread(*image + (i * (width * 3 + padding)), sizeof(unsigned char), width * 3, f);
        fread(*image + (i * (width * 3 + padding)) + (width * 3), sizeof(unsigned char), padding, f);
    }
    
    fclose(f);
}

void write_bmp(const char* filename, unsigned char* image, BITMAPFILEHEADER* bmfHeader, BITMAPINFOHEADER* bmInfoHeader) {
    FILE* f = fopen(filename, "wb");
    if (f == NULL) {
        perror("Failed to write file");
        exit(1);
    }
    
    fwrite(bmfHeader, sizeof(BITMAPFILEHEADER), 1, f);
    fwrite(bmInfoHeader, sizeof(BITMAPINFOHEADER), 1, f);

    int width = bmInfoHeader->biWidth;
    int height = bmInfoHeader->biHeight;
    int padding = (4 - (width * 3) % 4) % 4;

    for (int i = 0; i < height; i++) {
        fwrite(image + (i * (width * 3 + padding)), sizeof(unsigned char), width * 3 + padding, f);
    }
    
    fclose(f);
}

int main() {
    const char* input_filename = "input.bmp";
    const char* output_filename = "output.bmp";
    
    BITMAPFILEHEADER bmfHeader;
    BITMAPINFOHEADER bmInfoHeader;
    unsigned char* image = NULL;
    
    // Step 1: Read image
    read_bmp(input_filename, &image, &bmfHeader, &bmInfoHeader);
    
    // Step 2: Flip the image
    int width = bmInfoHeader.biWidth;
    int height = bmInfoHeader.biHeight;
    int padding = (4 - (width * 3) % 4) % 4;
    
    flip_image(image, width, height, padding);

    // Step 3: Change brightness
    change_brightness(image, width * height * 3 + padding * height, 50);

    // Step 4: Change contrast
    change_contrast(image, width * height * 3 + padding * height, 1.5);

    // Step 5: Write updated image
    write_bmp(output_filename, image, &bmfHeader, &bmInfoHeader);

    // Step 6: Clean up
    free(image);

    printf("Image processing completed successfully!\n");
    
    return 0;
}