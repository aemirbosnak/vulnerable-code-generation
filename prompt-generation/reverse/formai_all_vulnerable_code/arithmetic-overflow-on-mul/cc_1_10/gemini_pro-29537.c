//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);

    image->pixels = malloc(image->width * image->height * sizeof(Pixel));
    if (image->pixels == NULL) {
        free(image);
        fclose(fp);
        return NULL;
    }

    fread(image->pixels, sizeof(Pixel), image->width * image->height, fp);

    fclose(fp);

    return image;
}

void save_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }

    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);

    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, fp);

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (image == NULL) {
        printf("Error loading input image.\n");
        return 1;
    }

    // Embed a secret message in the image.
    const char *message = "Hello, world!";
    int message_length = strlen(message);
    for (int i = 0; i < message_length; i++) {
        uint8_t byte = message[i];

        // Embed the byte in the least significant bits of the red channel of a pixel.
        image->pixels[i].r = (image->pixels[i].r & ~0x07) | (byte & 0x07);
    }

    // Save the modified image.
    save_image(image, argv[2]);

    printf("Secret message embedded in image.\n");

    free(image->pixels);
    free(image);

    return 0;
}