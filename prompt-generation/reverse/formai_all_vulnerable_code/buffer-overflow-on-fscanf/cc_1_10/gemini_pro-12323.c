//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Image {
    unsigned int width;
    unsigned int height;
    unsigned char *data;
} Image;

Image *read_image(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    unsigned int width, height;
    if (fscanf(f, "P3\n%u %u\n255\n", &width, &height) != 2) {
        fprintf(stderr, "Error reading header from file %s\n", filename);
        fclose(f);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * 3);

    fread(image->data, 1, width * height * 3, f);
    fclose(f);

    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    fprintf(f, "P3\n%u %u\n255\n", image->width, image->height);
    fwrite(image->data, 1, image->width * image->height * 3, f);
    fclose(f);
}

void embed_message(Image *image, const char *message) {
    unsigned int message_length = strlen(message);
    if (message_length > image->width * image->height * 3) {
        fprintf(stderr, "Error: Message is too long\n");
        return;
    }

    for (unsigned int i = 0; i < message_length; i++) {
        unsigned char byte = message[i];
        for (unsigned int j = 0; j < 8; j++) {
            unsigned char bit = (byte >> j) & 1;
            image->data[i * 8 + j] = (image->data[i * 8 + j] & 0xFE) | bit;
        }
    }
}

char *extract_message(const Image *image) {
    unsigned int message_length = 0;
    for (unsigned int i = 0; i < image->width * image->height * 3; i++) {
        if ((image->data[i] & 1) == 1) {
            message_length++;
        }
    }

    char *message = malloc(message_length + 1);
    for (unsigned int i = 0, j = 0; i < message_length; i++, j += 8) {
        unsigned char byte = 0;
        for (unsigned int k = 0; k < 8; k++) {
            byte |= ((image->data[j + k] & 1) << k);
        }
        message[i] = byte;
    }
    message[message_length] = '\0';

    return message;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> <message>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    embed_message(image, argv[3]);

    write_image(image, argv[2]);
    free(image->data);
    free(image);

    printf("Message embedded successfully\n");

    return 0;
}