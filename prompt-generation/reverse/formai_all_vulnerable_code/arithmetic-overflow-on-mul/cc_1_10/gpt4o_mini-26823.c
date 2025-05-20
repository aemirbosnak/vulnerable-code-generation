//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: dynamic
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

void flip_image(RGB *image, int width, int height, int flip_vertical) {
    RGB temp;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            if (flip_vertical) {
                temp = image[i * width + j];
                image[i * width + j] = image[i * width + (width - 1 - j)];
                image[i * width + (width - 1 - j)] = temp;
            } else {
                temp = image[j * width + i];
                image[j * width + i] = image[(width - 1 - j) * width + i];
                image[(width - 1 - j) * width + i] = temp;
            }
        }
    }
}

void change_brightness(RGB *image, int size, int brightness) {
    for (int i = 0; i < size; i++) {
        image[i].red = (image[i].red + brightness > 255) ? 255 : (image[i].red + brightness < 0) ? 0 : image[i].red + brightness;
        image[i].green = (image[i].green + brightness > 255) ? 255 : (image[i].green + brightness < 0) ? 0 : image[i].green + brightness;
        image[i].blue = (image[i].blue + brightness > 255) ? 255 : (image[i].blue + brightness < 0) ? 0 : image[i].blue + brightness;
    }
}

void change_contrast(RGB *image, int size, float contrast) {
    for (int i = 0; i < size; i++) {
        image[i].red = (int)(((image[i].red / 255.0 - 0.5) * contrast + 0.5) * 255);
        image[i].green = (int)(((image[i].green / 255.0 - 0.5) * contrast + 0.5) * 255);
        image[i].blue = (int)(((image[i].blue / 255.0 - 0.5) * contrast + 0.5) * 255);
        
        image[i].red = image[i].red > 255 ? 255 : (image[i].red < 0 ? 0 : image[i].red);
        image[i].green = image[i].green > 255 ? 255 : (image[i].green < 0 ? 0 : image[i].green);
        image[i].blue = image[i].blue > 255 ? 255 : (image[i].blue < 0 ? 0 : image[i].blue);
    }
}

int main() {
    FILE *file = fopen("input.bmp", "rb");
    if (!file) {
        printf("Error opening file!\n");
        return 1;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, file);

    if (bfh.bfType != 0x4D42 || bih.biBitCount != 24) {
        printf("Unsupported file format!\n");
        fclose(file);
        return 1;
    }

    int width = bih.biWidth;
    int height = abs(bih.biHeight);
    int size = width * height;
    RGB *image = (RGB *)malloc(size * sizeof(RGB));

    fseek(file, bfh.bfOffBits, SEEK_SET);
    fread(image, sizeof(RGB), size, file);
    fclose(file);

    int choice;
    printf("Image Processing Options:\n");
    printf("1. Flip Image Vertically\n");
    printf("2. Flip Image Horizontally\n");
    printf("3. Change Brightness\n");
    printf("4. Change Contrast\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            flip_image(image, width, height, 1);
            break;
        case 2:
            flip_image(image, width, height, 0);
            break;
        case 3: {
            int brightness;
            printf("Enter brightness adjustment (-255 to 255): ");
            scanf("%d", &brightness);
            change_brightness(image, size, brightness);
            break;
        }
        case 4: {
            float contrast;
            printf("Enter contrast adjustment (0.0 for grayscale): ");
            scanf("%f", &contrast);
            change_contrast(image, size, contrast);
            break;
        }
        default:
            printf("Invalid option!\n");
            free(image);
            return 0;
    }

    file = fopen("output.bmp", "wb");
    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, file);
    fwrite(image, sizeof(RGB), size, file);
    fclose(file);

    free(image);
    printf("Processing complete. Output saved as output.bmp\n");
    return 0;
}