//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512
#define IMAGE_SIZE (IMAGE_WIDTH * IMAGE_HEIGHT)

#define PIXEL_VALUE_MASK 0x00FF0000
#define PIXEL_VALUE_SHIFT 16

typedef struct {
    char *data;
    int size;
} Image;

Image *read_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error reading file %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);

    Image *image = malloc(sizeof(Image));
    image->data = malloc(size);
    image->size = size;

    fread(image->data, size, 1, file);
    fclose(file);

    return image;
}

void write_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error writing file %s\n", filename);
        exit(1);
    }

    fwrite(image->data, image->size, 1, file);
    fclose(file);
}

void encode_message(Image *image, const char *message) {
    int message_size = strlen(message);
    int pixel_index = 0;

    for (int i = 0; i < message_size; i++) {
        int pixel_value = image->data[pixel_index] & PIXEL_VALUE_MASK;
        pixel_value = (pixel_value >> PIXEL_VALUE_SHIFT) & 0x00FF;

        int message_value = message[i] & 0x00FF;
        message_value = (message_value << PIXEL_VALUE_SHIFT) | pixel_value;

        image->data[pixel_index] = message_value;
        pixel_index++;
    }
}

void decode_message(Image *image, char *message) {
    int message_size = strlen(message);
    int pixel_index = 0;

    for (int i = 0; i < message_size; i++) {
        int pixel_value = image->data[pixel_index] & PIXEL_VALUE_MASK;
        pixel_value = (pixel_value >> PIXEL_VALUE_SHIFT) & 0x00FF;

        int message_value = (image->data[pixel_index] & 0x00FF) ^ pixel_value;

        message[i] = message_value;
        pixel_index++;
    }
}

int main() {
    Image *image = read_image("image.bmp");

    const char *message = "Hello, world!";
    encode_message(image, message);

    write_image("encoded_image.bmp", image);

    Image *encoded_image = read_image("encoded_image.bmp");
    char decoded_message[strlen(message) + 1];

    decode_message(encoded_image, decoded_message);
    printf("%s\n", decoded_message);

    free(image->data);
    free(image);
    free(encoded_image->data);
    free(encoded_image);

    return 0;
}