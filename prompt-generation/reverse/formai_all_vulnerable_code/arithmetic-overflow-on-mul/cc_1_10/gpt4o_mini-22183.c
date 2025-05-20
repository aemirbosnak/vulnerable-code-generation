//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_VALUE 255
#define HEADER_SIZE 3

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    char format[3]; // PPM format
    int width;
    int height;
    int max_color;
    Pixel* pixels;
} PPMImage;

void readPPM(const char* filename, PPMImage* image) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    fscanf(file, "%s", image->format);
    fscanf(file, "%d %d", &image->width, &image->height);
    fscanf(file, "%d", &image->max_color);

    image->pixels = malloc(image->width * image->height * sizeof(Pixel));
    fread(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

void writePPM(const char* filename, PPMImage* image) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s\n%d %d\n%d\n", image->format, image->width, image->height, image->max_color);
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

void encodeMessage(PPMImage* image, const char* message) {
    size_t message_length = strlen(message);
    size_t total_bits = message_length * 8;
    if (total_bits > (image->width * image->height * 3)) {
        fprintf(stderr, "Message is too long to encode in the image.\n");
        exit(EXIT_FAILURE);
    }

    for(size_t i = 0; i < total_bits; i++) {
        int pixel_index = i / 3;
        int color_index = i % 3;
        Pixel* pixel = &image->pixels[pixel_index];
        unsigned char bit = (message[i / 8] >> (7 - (i % 8))) & 1;

        if (color_index == 0) {
            pixel->r = (pixel->r & ~1) | bit;
        } else if (color_index == 1) {
            pixel->g = (pixel->g & ~1) | bit;
        } else {
            pixel->b = (pixel->b & ~1) | bit;
        }
    }
}

void decodeMessage(PPMImage* image, char* message, size_t message_size) {
    memset(message, 0, message_size);
    size_t total_bits = message_size * 8;

    for(size_t i = 0; i < total_bits; i++) {
        int pixel_index = i / 3;
        int color_index = i % 3;
        Pixel* pixel = &image->pixels[pixel_index];

        unsigned char bit;
        if (color_index == 0) {
            bit = pixel->r & 1;
        } else if (color_index == 1) {
            bit = pixel->g & 1;
        } else {
            bit = pixel->b & 1;
        }

        message[i / 8] |= (bit << (7 - (i % 8)));
    }
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <encode|decode> <image.ppm> <message|output.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    PPMImage image;
    readPPM(argv[2], &image);

    if (strcmp(argv[1], "encode") == 0) {
        encodeMessage(&image, argv[3]);
        writePPM("output.ppm", &image);
        printf("Message encoded and saved to output.ppm.\n");
    } else if (strcmp(argv[1], "decode") == 0) {
        char message[256];
        decodeMessage(&image, message, sizeof(message));
        printf("Decoded message: %s\n", message);
    } else {
        fprintf(stderr, "Invalid option. Use 'encode' or 'decode'.\n");
        return EXIT_FAILURE;
    }

    free(image.pixels);
    return EXIT_SUCCESS;
}