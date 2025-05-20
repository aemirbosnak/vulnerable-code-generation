//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Romeo and Juliet
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    unsigned char *data;
    int width, height;
} Image;

typedef struct {
    unsigned char *data;
    int length;
} Message;

Image *read_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening image file");
        return NULL;
    }

    Image *image = (Image *)malloc(sizeof(Image));

    // Read header
    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);

    // Allocate memory for data
    image->data = (unsigned char *)malloc(image->width * image->height);

    // Read data
    fread(image->data, sizeof(unsigned char), image->width * image->height, fp);

    fclose(fp);

    return image;
}

void write_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error writing image file");
        return;
    }

    // Write header
    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);

    // Write data
    fwrite(image->data, sizeof(unsigned char), image->width * image->height, fp);

    fclose(fp);
}

Message *read_message(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening message file");
        return NULL;
    }

    Message *message = (Message *)malloc(sizeof(Message));

    // Read length
    fread(&message->length, sizeof(int), 1, fp);

    // Allocate memory for data
    message->data = (unsigned char *)malloc(message->length);

    // Read data
    fread(message->data, sizeof(unsigned char), message->length, fp);

    fclose(fp);

    return message;
}

void write_message(Message *message, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error writing message file");
        return;
    }

    // Write length
    fwrite(&message->length, sizeof(int), 1, fp);

    // Write data
    fwrite(message->data, sizeof(unsigned char), message->length, fp);

    fclose(fp);
}

void hide_message(Image *image, Message *message) {
    int i, j;
    unsigned char mask = 0x01;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            image->data[i * image->width + j] ^= (message->data[i * image->width + j] & mask);
            mask <<= 1;
            if (mask == 0x00) {
                mask = 0x01;
            }
        }
    }
}

void extract_message(Image *image, Message *message) {
    int i, j;
    unsigned char mask = 0x01;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            message->data[i * image->width + j] |= (image->data[i * image->width + j] & mask);
            mask <<= 1;
            if (mask == 0x00) {
                mask = 0x01;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <image> <message> <output> <extract>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    Message *message = read_message(argv[2]);
    if (message == NULL) {
        return 1;
    }

    if (strcmp(argv[4], "hide") == 0) {
        hide_message(image, message);
    } else if (strcmp(argv[4], "extract") == 0) {
        extract_message(image, message);
    } else {
        fprintf(stderr, "Error: invalid operation\n");
        return 1;
    }

    write_image(image, argv[3]);

    free(image->data);
    free(image);
    free(message->data);
    free(message);

    return 0;
}