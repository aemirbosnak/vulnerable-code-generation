//MISTRAL-7B DATASET v1.0 Category: Image Steganography ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_IMAGE_SIZE 512000
#define MSG_SIZE 32
#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512

typedef struct {
    unsigned char *data;
    int width, height;
} Image;

void read_pgm(const char *filename, Image *image) {
    FILE *fp;
    char magic_number[3];
    int width, height, max_value;

    fp = fopen(filename, "rb");
    fgets(magic_number, sizeof(magic_number), fp);
    magic_number[strlen(magic_number) - 1] = '\0';
    sscanf(magic_number, "PGM %d %d %d", &width, &height, &max_value);
    image->data = malloc(width * height);
    fread(image->data, width * height, 1, fp);
    fclose(fp);
    image->width = width;
    image->height = height;
}

void write_pgm(const char *filename, const Image *image) {
    FILE *fp;

    fp = fopen(filename, "wb");
    fprintf(fp, "PGM %d %d 255\n", image->width, image->height);
    fwrite(image->data, image->width * image->height, 1, fp);
    fclose(fp);
}

void steganography(Image *image, const char *message) {
    unsigned char bit;
    int x, y, index;
    for (int i = 0; i < MSG_SIZE; i++) {
        bit = message[i] & 0x01;
        for (y = 0; y < IMAGE_HEIGHT; y++) {
            for (x = 0; x < IMAGE_WIDTH; x++) {
                index = y * IMAGE_WIDTH + x;
                if (index >= image->width * image->height ||
                    image->data[index] + bit > 255) {
                    continue;
                }
                image->data[index] += bit;
                break;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    Image image;
    char message[MSG_SIZE];

    if (argc != 2) {
        printf("Usage: %s <image.pgm>\n", argv[0]);
        return 1;
    }

    read_pgm(argv[1], &image);
    strcpy(message, "This is a retro-style C Image Steganography example!");
    steganography(&image, message);
    write_pgm("output.pgm", &image);

    printf("Message embedded successfully!\n");
    free(image.data);

    return 0;
}