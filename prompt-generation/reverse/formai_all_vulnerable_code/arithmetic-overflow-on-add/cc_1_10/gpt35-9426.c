//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define HEADER_SIZE 54

void flip_image(uint8_t* image, int width, int height, int channels) {
    int row_size = width * channels;
    uint8_t temp[row_size];
    for(int i = 0; i < height/2; i++) {
        int j = height - i - 1;
        int index1 = i * row_size;
        int index2 = j * row_size;
        for(int k = 0; k < row_size; k++) {
            temp[k] = image[index1 + k];
            image[index1 + k] = image[index2 + k];
            image[index2 + k] = temp[k];
        }
    }
}

void adjust_brightness_contrast(uint8_t* image, int width, int height, int channels, int brightness, int contrast) {
    float factor = (float)(259 * (contrast + 255)) / (float)(255 * (259 - contrast));
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int index = (i * width + j) * channels;
            for(int k = 0; k < channels; k++) {
                int value = image[index + k];
                value = (int)(factor * (value - 128) + 128 + brightness);
                image[index + k] = (uint8_t) (value < 0 ? 0 : (value > 255 ? 255 : value));
            }
        }
    }
}

int main(int argc, char** argv) {
    if(argc < 6) {
        printf("Usage: %s <input_file> <output_file> <flip> <brightness> <contrast>\n", argv[0]);
        return -1;
    }

    char* input_file = argv[1];
    char* output_file = argv[2];
    int flip = atoi(argv[3]);
    int brightness = atoi(argv[4]);
    int contrast = atoi(argv[5]);

    FILE* fp = fopen(input_file, "rb");
    if(fp == NULL) {
        printf("Error opening input file.\n");
        return -1;
    }

    FILE* out_fp = fopen(output_file, "wb");
    if(out_fp == NULL) {
        printf("Error creating output file.\n");
        fclose(fp);
        return -1;
    }

    uint8_t header[HEADER_SIZE];
    fread(header, sizeof(uint8_t), HEADER_SIZE, fp);
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, out_fp);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int channels = *(int*)&header[28];
    int padding = (4 - (width * channels) % 4) % 4;

    uint8_t* image = (uint8_t*)malloc(sizeof(uint8_t) * (width * channels + padding) * height);
    fread(image, sizeof(uint8_t), (width * channels + padding) * height, fp);

    if(flip) {
        flip_image(image, width, height, channels);
    }

    adjust_brightness_contrast(image, width, height, channels, brightness, contrast);

    fwrite(image, sizeof(uint8_t), (width * channels + padding) * height, out_fp);

    fclose(fp);
    fclose(out_fp);
    free(image);

    return 0;
}