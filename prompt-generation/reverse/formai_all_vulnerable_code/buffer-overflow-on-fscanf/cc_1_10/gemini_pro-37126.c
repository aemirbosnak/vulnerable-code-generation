//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    int width, height;
    if (fscanf(fp, "P6\n%d %d\n255\n", &width, &height) != 3) {
        fprintf(stderr, "Error: invalid PPM file format\n");
        fclose(fp);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(Pixel));

    if (fread(image->data, sizeof(Pixel), width * height, fp) != width * height) {
        fprintf(stderr, "Error: could not read image data\n");
        free(image->data);
        free(image);
        fclose(fp);
        return NULL;
    }

    fclose(fp);
    return image;
}

void save_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s for writing\n", filename);
        return;
    }

    fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, sizeof(Pixel), image->width * image->height, fp);

    fclose(fp);
}

void hide_message(Image *image, const char *message) {
    int message_length = strlen(message);
    int bit_index = 0;

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            Pixel *pixel = &image->data[i * image->width + j];

            if (bit_index < message_length) {
                unsigned char bit = (message[bit_index] >> (7 - bit_index % 8)) & 1;
                pixel->r = (pixel->r & ~1) | bit;
                bit_index++;
            }

            if (bit_index < message_length) {
                unsigned char bit = (message[bit_index] >> (7 - bit_index % 8)) & 1;
                pixel->g = (pixel->g & ~1) | bit;
                bit_index++;
            }

            if (bit_index < message_length) {
                unsigned char bit = (message[bit_index] >> (7 - bit_index % 8)) & 1;
                pixel->b = (pixel->b & ~1) | bit;
                bit_index++;
            }
        }
    }
}

char *extract_message(const Image *image) {
    int bit_index = 0;
    char *message = malloc(1);
    message[0] = '\0';

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            const Pixel *pixel = &image->data[i * image->width + j];

            unsigned char bit = pixel->r & 1;
            message = realloc(message, strlen(message) + 1);
            message[strlen(message) - 1] = (message[strlen(message) - 1] << 1) | bit;
            bit_index++;

            if (bit_index % 8 == 0) {
                message = realloc(message, strlen(message) + 1);
                message[strlen(message) - 1] = '\0';
            }

            if (bit == 0 && strlen(message) > 0) {
                return message;
            }

            bit = pixel->g & 1;
            message = realloc(message, strlen(message) + 1);
            message[strlen(message) - 1] = (message[strlen(message) - 1] << 1) | bit;
            bit_index++;

            if (bit_index % 8 == 0) {
                message = realloc(message, strlen(message) + 1);
                message[strlen(message) - 1] = '\0';
            }

            if (bit == 0 && strlen(message) > 0) {
                return message;
            }

            bit = pixel->b & 1;
            message = realloc(message, strlen(message) + 1);
            message[strlen(message) - 1] = (message[strlen(message) - 1] << 1) | bit;
            bit_index++;

            if (bit_index % 8 == 0) {
                message = realloc(message, strlen(message) + 1);
                message[strlen(message) - 1] = '\0';
            }

            if (bit == 0 && strlen(message) > 0) {
                return message;
            }
        }
    }

    return message;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <message> <output image>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    hide_message(image, argv[2]);

    save_image(image, argv[3]);

    free(image->data);
    free(image);

    return 0;
}