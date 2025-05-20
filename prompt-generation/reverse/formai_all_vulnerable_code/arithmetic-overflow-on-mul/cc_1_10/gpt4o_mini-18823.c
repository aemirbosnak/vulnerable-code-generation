//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

Image* readImage(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    fseek(f, 18, SEEK_SET);
    int width, height;
    fread(&width, 4, 1, f);
    fread(&height, 4, 1, f);

    Image *img = (Image *)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = (Pixel *)malloc(width * height * sizeof(Pixel));

    fseek(f, 54, SEEK_SET); // Move to pixel data
    fread(img->pixels, sizeof(Pixel), width * height, f);
    fclose(f);

    return img;
}

void writeImage(const char *filename, Image *img) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    unsigned char header[54] = {
        'B', 'M',  /* BITMAP file header */
        0, 0, 0, 0, /* size in bytes (will be filled later) */
        0, 0, 0, 0, /* reserved1 */
        54, 0, 0, 0, /* start of pixel array */
        40, 0, 0, 0, /* header size */
        0, 0, 0, 0, /* width (will be filled later) */
        0, 0, 0, 0, /* height (will be filled later) */
        1, 0, 24, 0, /* 1 plane, 24 bits per pixel */
        0, 0, 0, 0, /* no compression */
        0, 0, 0, 0, /* image size (can be zero for uncompressed) */
        0x13, 0x0B, 0, 0, /* resolution (pixels per meter), dummy value */
        0x13, 0x0B, 0, 0, /* resolution (pixels per meter), dummy value */
        0, 0, 0, 0, /* colors in palette (0 = 2^24) */
        0, 0, 0, 0  /* important color count */
    };

    // Fill in the size and dimensions
    int size = 54 + (img->width * img->height * 3);
    header[2] = (unsigned char)(size);
    header[3] = (unsigned char)(size >> 8);
    header[4] = (unsigned char)(size >> 16);
    header[5] = (unsigned char)(size >> 24);
    
    header[18] = (unsigned char)(img->width);
    header[19] = (unsigned char)(img->width >> 8);
    header[20] = (unsigned char)(img->width >> 16);
    header[21] = (unsigned char)(img->width >> 24);

    header[22] = (unsigned char)(img->height);
    header[23] = (unsigned char)(img->height >> 8);
    header[24] = (unsigned char)(img->height >> 16);
    header[25] = (unsigned char)(img->height >> 24);

    fwrite(header, sizeof(unsigned char), 54, f);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, f);
    fclose(f);
}

void embedMessage(Image *img, const char *message) {
    int msg_len = strlen(message);
    if (msg_len > img->width * img->height) {
        fprintf(stderr, "Message is too long to be embedded in the image.\n");
        return;
    }

    for (int i = 0; i < msg_len; ++i) {
        // Embed one character per pixel
        img->pixels[i].r = (img->pixels[i].r & 0xFE) | ((message[i] >> 7) & 0x01);
        img->pixels[i].g = (img->pixels[i].g & 0xFE) | ((message[i] >> 6) & 0x01);
        img->pixels[i].b = (img->pixels[i].b & 0xFE) | ((message[i] >> 5) & 0x01);
        // More bits can be embedded if needed by manipulating other color channels.
    }
}

void extractMessage(Image *img, char *message, int max_length) {
    for (int i = 0; i < max_length; ++i) {
        message[i] = 0;
        message[i] |= (img->pixels[i].r & 0x01) << 7;
        message[i] |= (img->pixels[i].g & 0x01) << 6;
        message[i] |= (img->pixels[i].b & 0x01) << 5;

        // '00000000' is a termination signal.
        if (message[i] == '\0') break;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> <message>\n", argv[0]);
        return 1;
    }

    Image *img = readImage(argv[1]);
    if (!img) return 1;

    embedMessage(img, argv[3]);
    writeImage(argv[2], img);

    char extracted_message[256] = {0};
    extractMessage(img, extracted_message, sizeof(extracted_message));
    printf("Extracted Message: %s\n", extracted_message);

    free(img->pixels);
    free(img);
    return 0;
}