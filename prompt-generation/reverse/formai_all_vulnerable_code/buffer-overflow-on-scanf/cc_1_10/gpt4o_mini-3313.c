//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL_VALUE 255
#define HEADER_SIZE 54  // BMP header size
#define WIDTH_IDX 18
#define HEIGHT_IDX 22

typedef unsigned char BYTE;

#pragma pack(push, 1)
typedef struct {
    BYTE header[HEADER_SIZE];
} BMPHeader;
#pragma pack(pop)

void loadBMP(const char *filename, BMPHeader *header, BYTE **data, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    fread(header->header, sizeof(BYTE), HEADER_SIZE, file);

    *width = *(int *)&header->header[WIDTH_IDX];
    *height = *(int *)&header->header[HEIGHT_IDX];
    int padding = (4 - (*width * 3) % 4) % 4;

    *data = (BYTE *)malloc((*height) * (*width) * 3 + padding * (*height));
    fseek(file, HEADER_SIZE, SEEK_SET);
    fread(*data, sizeof(BYTE), (*height) * (*width) * 3 + padding * (*height), file);
    fclose(file);
}

void saveBMP(const char *filename, BMPHeader *header, BYTE *data, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to save file");
        exit(EXIT_FAILURE);
    }
    fwrite(header->header, sizeof(BYTE), HEADER_SIZE, file);
    fwrite(data, sizeof(BYTE), height * (width * 3 + (4 - (width * 3) % 4) % 4), file);
    fclose(file);
}

void flipImage(BYTE *data, int width, int height) {
    int rowSize = width * 3;
    int padding = (4 - rowSize % 4) % 4;
    for (int i = 0; i < height / 2; i++) {
        // Swap rows
        for (int j = 0; j < rowSize + padding; j++) {
            BYTE temp = data[i * (rowSize + padding) + j];
            data[i * (rowSize + padding) + j] = data[(height - 1 - i) * (rowSize + padding) + j];
            data[(height - 1 - i) * (rowSize + padding) + j] = temp;
        }
    }
}

void changeBrightness(BYTE *data, int width, int height, int brightness) {
    int totalPixels = width * height;
    for (int i = 0; i < totalPixels * 3; i++) {
        int newVal = data[i] + brightness;
        data[i] = (newVal > MAX_PIXEL_VALUE) ? MAX_PIXEL_VALUE : (newVal < 0) ? 0 : newVal;
    }
}

void adjustContrast(BYTE *data, int width, int height, float factor) {
    int totalPixels = width * height;
    for (int i = 0; i < totalPixels * 3; i++) {
        int newVal = (int)((data[i] - 128) * factor + 128);
        data[i] = (newVal > MAX_PIXEL_VALUE) ? MAX_PIXEL_VALUE : (newVal < 0) ? 0 : newVal;
    }
}

void displayMenu() {
    printf("Image Processing Menu:\n");
    printf("1. Flip Image Vertically\n");
    printf("2. Change Brightness\n");
    printf("3. Adjust Contrast\n");
    printf("4. Exit\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_image.bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    BMPHeader header;
    BYTE *data;
    int width, height;

    loadBMP(argv[1], &header, &data, &width, &height);
    int choice, brightness;
    float contrast;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                flipImage(data, width, height);
                printf("Image flipped vertically.\n");
                break;
            case 2:
                printf("Enter brightness adjustment (-255 to 255): ");
                scanf("%d", &brightness);
                changeBrightness(data, width, height, brightness);
                printf("Brightness adjusted by %d.\n", brightness);
                break;
            case 3:
                printf("Enter contrast factor (0.0 to 3.0): ");
                scanf("%f", &contrast);
                adjustContrast(data, width, height, contrast);
                printf("Contrast adjusted by a factor of %.2f.\n", contrast);
                break;
            case 4:
                free(data);
                printf("Exiting program.\n");
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    free(data);
    return EXIT_SUCCESS;
}