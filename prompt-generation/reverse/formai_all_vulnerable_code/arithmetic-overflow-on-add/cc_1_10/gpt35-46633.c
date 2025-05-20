//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef unsigned char byte;

byte *load_image(const char *filename, int *w, int *h) {
    FILE *fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Failed to open file %s: %s\n", filename, strerror(errno));
        return NULL;
    }

    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    byte *data = malloc(size);
    fread(data, size, 1, fp);

    fclose(fp);

    *w = *((int *) &data[0x12]);
    *h = *((int *) &data[0x16]);

    return data + *((int *) &data[0x0A]);
}

byte *flip_image(byte *data, int w, int h) {
    byte *result = malloc(w * h * 3);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int i = (y * w + x) * 3;
            int j = ((h - y - 1) * w + x) * 3;

            result[j + 0] = data[i + 0];
            result[j + 1] = data[i + 1];
            result[j + 2] = data[i + 2];
        }
    }

    free(data);
    return result;
}

byte clamp(int value) {
    if (value < 0) {
        return 0;
    } else if (value > 255) {
        return 255;
    } else {
        return value;
    }
}

byte *adjust_brightness(byte *data, int w, int h, int adjustment) {
    byte *result = malloc(w * h * 3);

    for (int i = 0; i < w * h * 3; i++) {
        result[i] = clamp(data[i] + adjustment);
    }

    free(data);
    return result;
}

byte *adjust_contrast(byte *data, int w, int h, float adjustment) {
    byte *result = malloc(w * h * 3);

    float factor = (259.0f * (adjustment + 255.0f)) / (255.0f * (259.0f - adjustment));

    for (int i = 0; i < w * h * 3; i++) {
        float value = data[i];
        value -= 128.0f;
        value *= factor;
        value += 128.0f;

        result[i] = clamp(value);
    }

    free(data);
    return result;
}

int main(int argc, char **argv) {
    int w, h;
    byte *data = load_image("input.bmp", &w, &h);

    if (data == NULL) {
        return 1;
    }

    byte *flipped = flip_image(data, w, h);
    byte *brightened = adjust_brightness(flipped, w, h, 50);
    byte *contrasted = adjust_contrast(brightened, w, h, 50.0f);

    FILE *fp = fopen("output.bmp", "wb");

    if (fp == NULL) {
        printf("Failed to open file output.bmp: %s\n", strerror(errno));
        return 1;
    }

    byte header[] = {
        0x42, 0x4D, 0x36, 0x7C, 0x0B, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00,
        0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x10, 0x7C, 0x0B, 0x00, 0x13, 0x0B,
        0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    *((int *) &header[0x12]) = w;
    *((int *) &header[0x16]) = h;

    fwrite(header, sizeof(header), 1, fp);
    fwrite(contrasted, w * h * 3, 1, fp);

    fclose(fp);

    free(contrasted);
    return 0;
}