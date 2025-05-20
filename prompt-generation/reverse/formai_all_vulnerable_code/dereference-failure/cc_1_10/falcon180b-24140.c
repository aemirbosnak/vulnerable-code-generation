//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    char* data;
    int size;
} image_t;

image_t* read_image(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* data = malloc(size);
    if (fread(data, size, 1, fp)!= 1) {
        printf("Error: could not read file '%s'\n", filename);
        exit(1);
    }

    fclose(fp);

    image_t* img = malloc(sizeof(image_t));
    img->data = data;
    img->size = size;

    return img;
}

void write_image(image_t* img, char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fwrite(img->data, img->size, 1, fp);

    fclose(fp);
}

void free_image(image_t* img) {
    free(img->data);
    free(img);
}

int get_pixel(image_t* img, int x, int y) {
    return (int)img->data[y * img->size + x];
}

void set_pixel(image_t* img, int x, int y, int value) {
    img->data[y * img->size + x] = value;
}

int main() {
    image_t* img = read_image("image.png");

    int message_size = strlen("Hello, world!");
    char* message = malloc(message_size + 1);
    strcpy(message, "Hello, world!");

    int i = 0;
    while (i < message_size) {
        int x = i % img->size;
        int y = i / img->size;

        int pixel_value = get_pixel(img, x, y);
        int bit_value = (pixel_value >> 7) & 1;

        if (bit_value == 0) {
            set_pixel(img, x, y, pixel_value | 128);
        }

        i++;
    }

    write_image(img, "stego.png");

    free_image(img);
    free(message);

    return 0;
}