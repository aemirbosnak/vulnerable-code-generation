//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

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

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fclose(file);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);

    image->pixels = malloc(sizeof(Pixel) * image->width * image->height);
    if (!image->pixels) {
        free(image);
        fclose(file);
        return NULL;
    }

    fread(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);

    return image;
}

void save_image(const Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return;
    }

    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

void hide_message(Image *image, const char *message) {
    int message_length = strlen(message);

    int pixel_index = 0;
    int bit_index = 0;

    for (int i = 0; i < message_length; i++) {
        unsigned char byte = message[i];

        for (int j = 0; j < 8; j++) {
            unsigned char bit = (byte >> j) & 1;

            if (bit_index == 3) {
                bit_index = 0;
                pixel_index++;
            }

            unsigned char pixel_value = image->pixels[pixel_index].red;

            pixel_value = (pixel_value & 0xFE) | bit;

            image->pixels[pixel_index].red = pixel_value;

            bit_index++;
        }
    }
}

char *extract_message(const Image *image) {
    int pixel_index = 0;
    int bit_index = 0;

    char *message = malloc(100);
    int message_length = 0;

    while (1) {
        unsigned char pixel_value = image->pixels[pixel_index].red;

        unsigned char bit = pixel_value & 1;

        message[message_length] = (message[message_length] << 1) | bit;

        bit_index++;

        if (bit_index == 8) {
            bit_index = 0;
            pixel_index++;

            if (message[message_length] == '\0') {
                break;
            }

            message_length++;
        }
    }

    return message;
}

int main() {
    Image *image = load_image("image.bmp");
    if (!image) {
        printf("Error loading image.\n");
        return 1;
    }

    const char *message = "Hello world!";
    hide_message(image, message);

    save_image(image, "image_with_message.bmp");

    free(image->pixels);
    free(image);

    Image *new_image = load_image("image_with_message.bmp");
    if (!new_image) {
        printf("Error loading image.\n");
        return 1;
    }

    char *extracted_message = extract_message(new_image);

    printf("Extracted message: %s\n", extracted_message);

    free(new_image->pixels);
    free(new_image);

    free(extracted_message);

    return 0;
}