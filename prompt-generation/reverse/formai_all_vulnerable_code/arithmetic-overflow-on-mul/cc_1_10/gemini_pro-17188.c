//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define BITS 3

typedef struct {
    char *data;
    int width;
    int height;
    int bits;
} Image;

Image *read_image(const char *filename) {
    FILE *fp;
    Image *image;
    int i, j;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    // Read the header
    image = malloc(sizeof(Image));
    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);
    fread(&image->bits, sizeof(int), 1, fp);

    // Read the data
    image->data = malloc(image->width * image->height * image->bits / 8);
    fread(image->data, 1, image->width * image->height * image->bits / 8, fp);

    fclose(fp);

    return image;
}

void write_image(const char *filename, const Image *image) {
    FILE *fp;
    int i, j;

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }

    // Write the header
    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);
    fwrite(&image->bits, sizeof(int), 1, fp);

    // Write the data
    fwrite(image->data, 1, image->width * image->height * image->bits / 8, fp);

    fclose(fp);
}

void embed_message(Image *image, const char *message) {
    int i, j, k;
    int bit;

    for (i = 0; i < strlen(message); i++) {
        for (j = 0; j < 8; j++) {
            bit = (message[i] >> j) & 1;

            for (k = 0; k < BITS; k++) {
                image->data[(i * 8 + j) * BITS + k] = (image->data[(i * 8 + j) * BITS + k] & ~(1 << k)) | (bit << k);
            }
        }
    }
}

char *extract_message(const Image *image) {
    int i, j, k;
    int bit;
    char *message;

    message = malloc(strlen(image->data) / 8);

    for (i = 0; i < strlen(image->data) / 8; i++) {
        for (j = 0; j < 8; j++) {
            for (k = 0; k < BITS; k++) {
                bit = (image->data[(i * 8 + j) * BITS + k] >> k) & 1;
            }
            message[i] |= (bit << j);
        }
    }

    return message;
}

int main() {
    Image *image;
    char *message;

    image = read_image("image.bmp");
    message = "Hello, world!";

    embed_message(image, message);
    write_image("image_out.bmp", image);

    image = read_image("image_out.bmp");
    message = extract_message(image);

    printf("%s\n", message);

    return 0;
}