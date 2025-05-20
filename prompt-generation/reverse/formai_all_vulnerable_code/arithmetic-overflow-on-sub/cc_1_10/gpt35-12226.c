//FormAI DATASET v1.0 Category: Image Editor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 50

#pragma pack(push, 1)
typedef struct {
    uint16_t type;
    uint32_t fileSize;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t dataOffset;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitsPerPixel;
    uint32_t compression;
    uint32_t imageSize;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
} BMPInfoHeader;
#pragma pack(pop)

int getInputOption() {
    int option;
    printf("Enter an option:\n");
    printf("1. Convert to grayscale\n");
    printf("2. Rotate by 90 degrees clockwise\n");
    printf("3. Flip horizontally\n");
    printf("4. Flip vertically\n");
    printf("5. Exit\n");

    scanf("%d", &option);
    return option;
}

void convertToGrayscale(unsigned char *data, int size) {
    int i;
    for (i = 0; i < size; i += 3) {
        unsigned char gray = (data[i] * 0.21) + (data[i + 1] * 0.72) + (data[i + 2] * 0.07);
        data[i] = gray;
        data[i + 1] = gray;
        data[i + 2] = gray;
    }
}

void rotate90Clockwise(unsigned char *data, int width, int height) {
    unsigned char *temp = malloc(width * height * 3 * sizeof(unsigned char));

    int i, j, k = 0;
    for (i = width - 1; i >= 0; i--) {
        for (j = 0; j < height; j++) {
            temp[k++] = data[(j * width + i) * 3];
            temp[k++] = data[(j * width + i) * 3 + 1];
            temp[k++] = data[(j * width + i) * 3 + 2];
        }
    }

    memcpy(data, temp, width * height * 3 * sizeof(unsigned char));

    free(temp);
}

void flipHorizontally(unsigned char *data, int width, int height) {
    int i, j;
    unsigned char temp[3];
    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            memcpy(temp, &data[(i * width + j) * 3], 3 * sizeof(unsigned char));
            memcpy(&data[(i * width + j) * 3], &data[(i * width + width - 1 - j) * 3], 3 * sizeof(unsigned char));
            memcpy(&data[(i * width + width - 1 - j) * 3], temp, 3 * sizeof(unsigned char));
        }
    }
}

void flipVertically(unsigned char *data, int width, int height) {
    int i, j;
    unsigned char temp[3];
    for (i = 0; i < height / 2; i++) {
        for (j = 0; j < width; j++) {
            memcpy(temp, &data[(i * width + j) * 3], 3 * sizeof(unsigned char));
            memcpy(&data[(i * width + j) * 3], &data[((height - 1 - i) * width + j) * 3], 3 * sizeof(unsigned char));
            memcpy(&data[((height - 1 - i) * width + j) * 3], temp, 3 * sizeof(unsigned char));
        }
    }
}

void processImage(char *fileName) {
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", fileName);
        return;
    }

    BMPHeader header;
    BMPInfoHeader infoHeader;

    fread(&header, sizeof(BMPHeader), 1, file);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, file);

    if (header.type != 0x4D42) {
        printf("Invalid BMP file\n");
        fclose(file);
        return;
    }

    if (infoHeader.width * infoHeader.height * 3 != infoHeader.imageSize) {
        printf("Invalid BMP file\n");
        fclose(file);
        return;
    }

    if (infoHeader.width % 4 != 0) {
        printf("Invalid BMP file\n");
        fclose(file);
        return;
    }

    unsigned char *data = malloc(infoHeader.imageSize * sizeof(unsigned char));
    fread(data, sizeof(unsigned char), infoHeader.imageSize, file);

    int option = -1;
    while (option != 5) {
        option = getInputOption();

        switch (option) {
            case 1:
                convertToGrayscale(data, infoHeader.imageSize);
                break;
            case 2:
                rotate90Clockwise(data, infoHeader.width, infoHeader.height);
                int temp = infoHeader.width;
                infoHeader.width = infoHeader.height;
                infoHeader.height = temp;
                break;
            case 3:
                flipHorizontally(data, infoHeader.width, infoHeader.height);
                break;
            case 4:
                flipVertically(data, infoHeader.width, infoHeader.height);
                break;
            case 5:
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    }

    fclose(file);

    strcat(fileName, ".out.bmp");

    FILE *outFile = fopen(fileName, "wb");
    if (outFile == NULL) {
        printf("Error opening file %s\n", fileName);
        return;
    }

    fwrite(&header, sizeof(BMPHeader), 1, outFile);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, outFile);
    fwrite(data, sizeof(unsigned char), infoHeader.imageSize, outFile);

    fclose(outFile);

    printf("Saved modified image to %s\n", fileName);

    free(data);
}

int main() {
    char fileName[MAX_FILE_NAME_LENGTH];

    printf("Enter BMP file name: ");
    scanf("%s", fileName);

    processImage(fileName);

    return 0;
}