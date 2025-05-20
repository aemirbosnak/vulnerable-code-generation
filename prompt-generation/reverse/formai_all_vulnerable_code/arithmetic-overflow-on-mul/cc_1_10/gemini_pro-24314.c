//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);

    image->pixels = malloc(sizeof(Pixel) * image->width * image->height);
    if (!image->pixels) {
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
    if (!fp) {
        return;
    }

    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, fp);
    fclose(fp);
}

void hide_message(Image *image, const char *message) {
    int i = 0;
    int j = 0;
    while (message[i] != '\0') {
        image->pixels[j].red &= 0xFE;
        image->pixels[j].red |= (message[i] >> 7) & 0x01;
        image->pixels[j].green &= 0xFE;
        image->pixels[j].green |= (message[i] >> 6) & 0x01;
        image->pixels[j].blue &= 0xFE;
        image->pixels[j].blue |= (message[i] >> 5) & 0x01;
        j++;
        i++;
    }
}

char *extract_message(const Image *image) {
    int i = 0;
    int j = 0;
    char *message = malloc(sizeof(char) * image->width * image->height);
    if (!message) {
        return NULL;
    }

    while (image->pixels[j].red != 0xFF) {
        message[i] = ((image->pixels[j].red & 0x01) << 7) | ((image->pixels[j].green & 0x01) << 6) | ((image->pixels[j].blue & 0x01) << 5);
        j++;
        i++;
    }

    message[i] = '\0';
    return message;
}

int main() {
    Image *image = load_image("image.bmp");
    if (!image) {
        printf("Error loading image.\n");
        return 1;
    }

    hide_message(image, "Hello, world!");

    save_image(image, "image_with_message.bmp");

    free(image);

    Image *image_with_message = load_image("image_with_message.bmp");
    if (!image_with_message) {
        printf("Error loading image with message.\n");
        return 1;
    }

    char *message = extract_message(image_with_message);
    if (!message) {
        printf("Error extracting message.\n");
        return 1;
    }

    printf("Message: %s\n", message);

    free(message);
    free(image_with_message);

    return 0;
}