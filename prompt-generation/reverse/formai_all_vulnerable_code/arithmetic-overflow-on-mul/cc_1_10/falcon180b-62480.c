//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>

#define MAX_SIZE 1000000
#define HIDDEN_SIZE 1000
#define BIT_SIZE 8
#define BIT_MASK 0xff
#define BIT_SHIFT 24
#define BIT_SCALE (1 << BIT_SHIFT)

typedef struct {
    int width;
    int height;
    char *data;
} Image;

void read_image(Image *image, FILE *fp) {
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    image->data = malloc(size);
    fread(image->data, size, 1, fp);
    image->width = atoi(strtok(NULL, " "));
    image->height = atoi(strtok(NULL, " "));
}

void write_image(Image *image, FILE *fp) {
    fprintf(fp, "%d %d\n", image->width, image->height);
    fwrite(image->data, image->width * image->height, 1, fp);
}

int get_pixel_value(Image *image, int x, int y) {
    return (int)image->data[y * image->width + x];
}

void set_pixel_value(Image *image, int x, int y, int value) {
    image->data[y * image->width + x] = value;
}

void hide_data(Image *image, char *data, int size) {
    int index = 0;
    int value = 0;
    for (int i = 0; i < image->width * image->height; i++) {
        if (index < size) {
            value = (int)data[index] & BIT_MASK;
            set_pixel_value(image, i % image->width, i / image->width, value << BIT_SHIFT);
            index++;
        } else {
            set_pixel_value(image, i % image->width, i / image->width, 0);
        }
    }
}

char *extract_data(Image *image, int size) {
    char *data = malloc(size);
    int index = 0;
    for (int i = 0; i < image->width * image->height; i++) {
        int value = get_pixel_value(image, i % image->width, i / image->width);
        if (value!= 0) {
            data[index] = value >> BIT_SHIFT;
            index++;
        }
    }
    return data;
}

int main() {
    srand(time(NULL));
    Image cover, stego;
    char *message = "Hello, world!";
    int message_size = strlen(message);
    cover.data = malloc(MAX_SIZE);
    stego.data = malloc(MAX_SIZE);
    read_image(&cover, stdin);
    hide_data(&stego, message, message_size);
    write_image(&stego, stdout);
    return 0;
}