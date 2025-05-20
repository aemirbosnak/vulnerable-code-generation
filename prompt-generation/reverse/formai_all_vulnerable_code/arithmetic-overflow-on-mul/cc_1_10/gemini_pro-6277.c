//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fclose(fp);
        return NULL;
    }

    // Read the header
    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);

    // Allocate memory for the pixels
    image->pixels = malloc(sizeof(Pixel) * image->width * image->height);
    if (image->pixels == NULL) {
        fclose(fp);
        free(image);
        return NULL;
    }

    // Read the pixels
    fread(image->pixels, sizeof(Pixel), image->width * image->height, fp);

    fclose(fp);
    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }

    // Write the header
    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);

    // Write the pixels
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, fp);

    fclose(fp);
}

void hide_message(Image *image, const char *message) {
    int message_length = strlen(message);
    int message_index = 0;

    for (int i = 0; i < image->width * image->height; i++) {
        if (message_index >= message_length) {
            break;
        }

        // Get the pixel
        Pixel *pixel = &image->pixels[i];

        // Hide the message in the pixel's least significant bit
        pixel->r = (pixel->r & 0xfe) | ((message[message_index] >> 7) & 0x01);
        pixel->g = (pixel->g & 0xfe) | ((message[message_index] >> 6) & 0x01);
        pixel->b = (pixel->b & 0xfe) | ((message[message_index] >> 5) & 0x01);

        message_index++;
    }
}

char *extract_message(const Image *image) {
    int message_length = 0;

    for (int i = 0; i < image->width * image->height; i++) {
        // Get the pixel
        const Pixel *pixel = &image->pixels[i];

        // Extract the message from the pixel's least significant bit
        message_length |= ((pixel->r & 0x01) << 7) | ((pixel->g & 0x01) << 6) | ((pixel->b & 0x01) << 5);

        if (message_length == 0) {
            break;
        }
    }

    char *message = malloc(message_length + 1);
    if (message == NULL) {
        return NULL;
    }

    int message_index = 0;

    for (int i = 0; i < image->width * image->height; i++) {
        // Get the pixel
        const Pixel *pixel = &image->pixels[i];

        // Extract the message from the pixel's least significant bit
        message[message_index] = ((pixel->r & 0x01) << 7) | ((pixel->g & 0x01) << 6) | ((pixel->b & 0x01) << 5);

        message_index++;

        if (message_index >= message_length) {
            break;
        }
    }

    message[message_length] = '\0';

    return message;
}

int main(void) {
    // Read the image
    const char *filename = "image.bmp";
    Image *image = read_image(filename);
    if (image == NULL) {
        fprintf(stderr, "Error: could not read image '%s'\n", filename);
        return 1;
    }

    // Hide the message in the image
    const char *message = "Hello, world!";
    hide_message(image, message);

    // Write the image
    const char *output_filename = "encoded_image.bmp";
    write_image(image, output_filename);

    // Extract the message from the image
    Image *decoded_image = read_image(output_filename);
    if (decoded_image == NULL) {
        fprintf(stderr, "Error: could not read image '%s'\n", output_filename);
        return 1;
    }

    char *extracted_message = extract_message(decoded_image);
    if (extracted_message == NULL) {
        fprintf(stderr, "Error: could not extract message from image '%s'\n", output_filename);
        return 1;
    }

    // Print the extracted message
    printf("Extracted message: %s\n", extracted_message);

    // Free memory
    free(image->pixels);
    free(image);
    free(decoded_image->pixels);
    free(decoded_image);
    free(extracted_message);

    return 0;
}