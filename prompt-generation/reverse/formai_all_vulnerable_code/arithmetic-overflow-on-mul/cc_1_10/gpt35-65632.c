//FormAI DATASET v1.0 Category: Image Editor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel* data;
} Image;

typedef struct {
    uint8_t* buffer;
    int size;
} InputData;

typedef struct {
    Image* image;
    bool success;
} OutputData;

// Helper function to read a BMP file
InputData* readBmp(const char* filename) {
    FILE* fp = fopen(filename, "rb");

    if (!fp) {
        perror("File opening failed");
        return NULL;
    }

    uint8_t header[54];
    fread(header, sizeof(header), 1, fp);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    int padding = 0;
    while ((width * 3 + padding) % 4 != 0) {
        padding++;
    }

    int size = (width * 3 + padding) * height;
    uint8_t* buffer = (uint8_t*)malloc(size);

    fseek(fp, *(int*)&header[10], SEEK_SET);
    fread(buffer, size, 1, fp);

    fclose(fp);

    InputData* inputData = (InputData*)malloc(sizeof(InputData));
    inputData->buffer = buffer;
    inputData->size = size;

    return inputData;
}

// Helper function to write a BMP file
void writeBmp(const char* filename, Image* image) {
    FILE* fp = fopen(filename, "wb");

    int padding = 0;
    while ((image->width * 3 + padding) % 4 != 0) {
        padding++;
    }

    uint8_t header[54] = {
        0x42, 0x4d, 0x36, 0x3c, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x01, 0x00,
        0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6c, 0x3c, 0x0e, 0x00,
        0x13, 0x0b, 0x00, 0x00, 0x13, 0x0b, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00
    };

    *(int*)&header[18] = image->width;
    *(int*)&header[22] = image->height;
    *(int*)&header[34] = image->width * image->height * 3 + image->height * padding;

    fwrite(header, sizeof(header), 1, fp);

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            uint32_t index = i * image->width + j;
            uint32_t pixelIndex = index * 3;
            fwrite(&image->data[pixelIndex].blue, 1, 1, fp);
            fwrite(&image->data[pixelIndex].green, 1, 1, fp);
            fwrite(&image->data[pixelIndex].red, 1, 1, fp);
        }

        for (int j = 0; j < padding; j++) {
            fputc(0x00, fp);
        }
    }

    fclose(fp);
}

// Helper function to convert 1-dimensional index to 2-dimensional coordinates
void indexToCoords(int index, int width, int* x, int* y) {
    *x = index % width;
    *y = index / width;
}

// Helper function to get the index of a pixel from its 2-dimensional coordinates
int coordsToIndex(int x, int y, int width) {
    return y * width + x;
}

// Function to apply a grayscale filter to an image
void grayscaleFilter(Image* image) {
    for (int i = 0; i < image->width * image->height * 3; i += 3) {
        uint8_t r = image->data[i].red;
        uint8_t g = image->data[i].green;
        uint8_t b = image->data[i].blue;

        uint8_t grayscale = (r + g + b) / 3;

        image->data[i].red = grayscale;
        image->data[i].green = grayscale;
        image->data[i].blue = grayscale;
    }
}

// Function to filter an image asynchronously using the given filter function
void filterImageAsync(Image* image, void (*filterFunction)(Image*), OutputData* outputData) {
    filterFunction(image);
    outputData->image = image;
    outputData->success = true;
}

// Main function to demonstrate usage
int main() {
    InputData* inputData = readBmp("input.bmp");

    if (!inputData) {
        return 1;
    }

    Image image = {
        .width = 2,
        .height = inputData->size / (2 * 3),
        .data = (Pixel*)inputData->buffer
    };

    OutputData outputData = {
        .image = NULL,
        .success = false
    };

    filterImageAsync(&image, grayscaleFilter, &outputData);

    while (!outputData.success) {}

    writeBmp("output.bmp", outputData.image);

    free(outputData.image->data);
    free(outputData.image);
    free(inputData->buffer);
    free(inputData);

    return 0;
}