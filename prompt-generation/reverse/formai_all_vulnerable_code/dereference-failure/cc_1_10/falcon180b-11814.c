//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512
#define IMAGE_SIZE (IMAGE_WIDTH * IMAGE_HEIGHT)
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    unsigned char *pixels;
    int width;
    int height;
} Image;

// Load an image from a file
Image load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open image file '%s'\n", filename);
        exit(1);
    }

    Image image;
    image.pixels = (unsigned char *)malloc(IMAGE_SIZE * sizeof(unsigned char));
    if (image.pixels == NULL) {
        printf("Error: out of memory\n");
        exit(1);
    }

    fread(image.pixels, IMAGE_SIZE, 1, fp);
    fclose(fp);

    image.width = IMAGE_WIDTH;
    image.height = IMAGE_HEIGHT;

    return image;
}

// Save an image to a file
void save_image(const char *filename, Image image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open image file '%s' for writing\n", filename);
        exit(1);
    }

    fwrite(image.pixels, IMAGE_SIZE, 1, fp);
    fclose(fp);
}

// Encode a message into an image
void encode(Image image, const char *message) {
    int message_length = strlen(message);
    if (message_length > MAX_MESSAGE_LENGTH) {
        printf("Error: message is too long (maximum length is %d characters)\n", MAX_MESSAGE_LENGTH);
        exit(1);
    }

    int pixel_index = 0;
    for (int i = 0; i < message_length; i++) {
        char c = message[i];
        unsigned int value = (unsigned int)c;
        int shift = value % 8;
        image.pixels[pixel_index] += shift;
        pixel_index++;
        if (pixel_index >= IMAGE_SIZE) {
            pixel_index = 0;
        }
    }
}

// Decode a message from an image
char *decode(Image image) {
    char *message = (char *)malloc(MAX_MESSAGE_LENGTH * sizeof(char));
    int message_length = 0;

    int pixel_index = 0;
    while (message_length < MAX_MESSAGE_LENGTH) {
        unsigned int value = image.pixels[pixel_index] & 0x7;
        char c = (char)value;
        message[message_length++] = c;
        pixel_index++;
        if (pixel_index >= IMAGE_SIZE) {
            pixel_index = 0;
        }
    }

    message[message_length] = '\0';
    return message;
}

int main() {
    Image image = load_image("image.png");

    char *message = "This is a secret message!";
    encode(image, message);

    save_image("encoded_image.png", image);

    char *decoded_message = decode(image);
    printf("Decoded message: %s\n", decoded_message);

    return 0;
}