//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1024 // maximum size of image
#define IMAGE_SIZE 512 // size of image
#define PIXEL_SIZE 3 // size of each pixel
#define CHANNEL_SIZE (IMAGE_SIZE * IMAGE_SIZE * PIXEL_SIZE) // size of each channel
#define DATA_SIZE (CHANNEL_SIZE - 1) // maximum size of data that can be hidden

typedef struct {
    char *filename;
    unsigned char *data;
    int size;
} Image;

Image *loadImage(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error loading image.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *data = malloc(size);
    fread(data, size, 1, fp);
    fclose(fp);

    Image *image = malloc(sizeof(Image));
    image->filename = strdup(filename);
    image->data = data;
    image->size = size;

    return image;
}

void saveImage(Image *image) {
    FILE *fp = fopen(image->filename, "wb");
    if (!fp) {
        printf("Error saving image.\n");
        exit(1);
    }

    fwrite(image->data, image->size, 1, fp);
    fclose(fp);
}

void hideData(Image *image, unsigned char *data, int size) {
    int index = 0;
    for (int i = 0; i < CHANNEL_SIZE; i += PIXEL_SIZE) {
        if (index >= size) {
            break;
        }
        int value = data[index++];
        int channel = i / PIXEL_SIZE;
        int pixel = i % PIXEL_SIZE;
        int offset = pixel * PIXEL_SIZE;
        image->data[channel * IMAGE_SIZE * PIXEL_SIZE + i] ^= value;
    }
}

unsigned char *extractData(Image *image, int *size) {
    unsigned char *data = malloc(DATA_SIZE);
    int index = 0;
    for (int i = 0; i < CHANNEL_SIZE; i += PIXEL_SIZE) {
        int channel = i / PIXEL_SIZE;
        int pixel = i % PIXEL_SIZE;
        int offset = pixel * PIXEL_SIZE;
        data[index++] = image->data[channel * IMAGE_SIZE * PIXEL_SIZE + i] ^ 0xff;
        if (index >= DATA_SIZE) {
            break;
        }
    }
    *size = index;
    return data;
}

int main() {
    srand(time(NULL));

    Image *cover = loadImage("cover.bmp");
    Image *data = loadImage("data.bmp");

    int dataSize = data->size;
    if (dataSize > DATA_SIZE) {
        printf("Data is too large to hide.\n");
        exit(1);
    }

    unsigned char *dataBuffer = malloc(dataSize);
    memcpy(dataBuffer, data->data, dataSize);

    hideData(cover, dataBuffer, dataSize);

    saveImage(cover);

    free(dataBuffer);
    free(data->data);
    free(data);

    return 0;
}