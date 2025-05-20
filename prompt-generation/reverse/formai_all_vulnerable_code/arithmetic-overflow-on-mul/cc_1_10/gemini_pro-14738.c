//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

Image *loadImage(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);

    image->pixels = malloc(image->width * image->height * sizeof(Pixel));
    if (!image->pixels) {
        perror("malloc");
        fclose(fp);
        free(image);
        return NULL;
    }

    fread(image->pixels, sizeof(Pixel), image->width * image->height, fp);

    fclose(fp);

    return image;
}

void saveImage(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        return;
    }

    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);

    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, fp);

    fclose(fp);
}

void hideMessage(Image *image, const char *message) {
    int messageLength = strlen(message);
    for (int i = 0; i < messageLength; i++) {
        int byte = message[i];
        for (int j = 0; j < 8; j++) {
            int bit = (byte >> j) & 1;
            image->pixels[i * 8 + j].red = (image->pixels[i * 8 + j].red & ~1) | bit;
        }
    }
}

char *revealMessage(const Image *image) {
    int messageLength = 0;
    for (int i = 0; i < image->width * image->height; i++) {
        if (image->pixels[i].red & 1) {
            messageLength++;
        }
    }

    char *message = malloc(messageLength + 1);
    if (!message) {
        perror("malloc");
        return NULL;
    }

    int index = 0;
    for (int i = 0; i < image->width * image->height; i++) {
        if (image->pixels[i].red & 1) {
            message[index++] = (i / 8) + 32;
        }
    }
    message[index] = '\0';

    return message;
}

int main() {
    Image *image = loadImage("image.bmp");
    if (!image) {
        return 1;
    }

    hideMessage(image, "Hello, world!");

    saveImage(image, "output.bmp");

    free(image->pixels);
    free(image);

    Image *outputImage = loadImage("output.bmp");
    if (!outputImage) {
        return 1;
    }

    char *message = revealMessage(outputImage);
    if (!message) {
        return 1;
    }

    printf("Message: %s\n", message);

    free(message);
    free(outputImage->pixels);
    free(outputImage);

    return 0;
}