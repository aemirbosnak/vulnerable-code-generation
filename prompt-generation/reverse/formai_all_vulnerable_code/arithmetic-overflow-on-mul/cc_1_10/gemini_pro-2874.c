//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LSB_MASK 0x01

typedef struct {
    int width;
    int height;
    int channels;
    unsigned char *data;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(fp);
        return NULL;
    }

    // Read the header
    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);
    fread(&image->channels, sizeof(int), 1, fp);

    // Allocate memory for the data
    image->data = malloc(image->width * image->height * image->channels);
    if (image->data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        fclose(fp);
        free(image);
        return NULL;
    }

    // Read the data
    fread(image->data, image->width * image->height * image->channels, 1, fp);

    fclose(fp);

    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Write the header
    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);
    fwrite(&image->channels, sizeof(int), 1, fp);

    // Write the data
    fwrite(image->data, image->width * image->height * image->channels, 1, fp);

    fclose(fp);
}

void hide_message(Image *image, const char *message) {
    int message_length = strlen(message);

    // Convert the message to binary
    unsigned char *binary_message = malloc(message_length * 8);
    for (int i = 0; i < message_length; i++) {
        for (int j = 0; j < 8; j++) {
            binary_message[i * 8 + j] = (message[i] >> j) & LSB_MASK;
        }
    }

    // Hide the message in the image
    int index = 0;
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            for (int k = 0; k < image->channels; k++) {
                image->data[i * image->width * image->channels + j * image->channels + k] &= ~LSB_MASK;
                image->data[i * image->width * image->channels + j * image->channels + k] |= binary_message[index++];
            }
        }
    }

    free(binary_message);
}

char *extract_message(const Image *image) {
    int message_length = (image->width * image->height * image->channels) / 8;

    // Extract the message from the image
    unsigned char *binary_message = malloc(message_length);
    int index = 0;
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            for (int k = 0; k < image->channels; k++) {
                binary_message[index++] = image->data[i * image->width * image->channels + j * image->channels + k] & LSB_MASK;
            }
        }
    }

    // Convert the binary message to a string
    char *message = malloc(message_length + 1);
    for (int i = 0; i < message_length; i++) {
        message[i] = 0;
        for (int j = 0; j < 8; j++) {
            message[i] |= binary_message[i * 8 + j] << j;
        }
    }
    message[message_length] = '\0';

    free(binary_message);

    return message;
}

int main() {
    // Read the image
    Image *image = read_image("image.bmp");
    if (image == NULL) {
        return 1;
    }

    // Hide the message in the image
    hide_message(image, "Hello world!");

    // Write the image to a file
    write_image(image, "image_stego.bmp");

    // Free the image
    free(image);

    // Read the image again
    image = read_image("image_stego.bmp");
    if (image == NULL) {
        return 1;
    }

    // Extract the message from the image
    char *message = extract_message(image);

    // Print the message
    printf("%s\n", message);

    // Free the message
    free(message);

    // Free the image
    free(image);

    return 0;
}