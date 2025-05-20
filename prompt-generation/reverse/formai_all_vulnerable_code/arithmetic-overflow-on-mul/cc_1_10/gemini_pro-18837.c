//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

Image *read_image(const char *filename) {
    Image *image = malloc(sizeof(Image));
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;
    fseek(file, 18, SEEK_SET);
    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);
    fseek(file, 54, SEEK_SET);
    image->data = malloc(image->width * image->height * 3);
    fread(image->data, image->width * image->height * 3, 1, file);
    fclose(file);
    return image;
}

void write_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) return;
    fprintf(file, "BM");
    int filesize = 54 + image->width * image->height * 3;
    fprintf(file, "%c%c%c%c", filesize & 0xFF, (filesize >> 8) & 0xFF, (filesize >> 16) & 0xFF, filesize >> 24);
    fprintf(file, "%c%c%c%c", 0, 0, 0, 0); // reserved
    fprintf(file, "%c%c%c%c", 54, 0, 0, 0); // offset to image data
    fprintf(file, "%c%c%c%c", 40, 0, 0, 0); // header size
    fprintf(file, "%c%c%c%c", image->width & 0xFF, (image->width >> 8) & 0xFF, (image->width >> 16) & 0xFF, image->width >> 24);
    fprintf(file, "%c%c%c%c", image->height & 0xFF, (image->height >> 8) & 0xFF, (image->height >> 16) & 0xFF, image->height >> 24);
    fprintf(file, "%c%c", 1, 0); // planes
    fprintf(file, "%c%c", 24, 0); // bits per pixel
    fprintf(file, "%c%c%c%c", 0, 0, 0, 0); // compression
    fprintf(file, "%c%c%c%c", image->width * image->height * 3, 0, 0, 0); // image size
    fprintf(file, "%c%c%c%c", 0, 0, 0, 0); // x pixels per meter
    fprintf(file, "%c%c%c%c", 0, 0, 0, 0); // y pixels per meter
    fprintf(file, "%c%c%c%c", 0, 0, 0, 0); // number of colors
    fprintf(file, "%c%c%c%c", 0, 0, 0, 0); // important color count
    fwrite(image->data, image->width * image->height * 3, 1, file);
    fclose(file);
}

void flip_image(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < 3; k++) {
                unsigned char temp = image->data[i * image->width * 3 + j * 3 + k];
                image->data[i * image->width * 3 + j * 3 + k] = image->data[(image->height - i - 1) * image->width * 3 + j * 3 + k];
                image->data[(image->height - i - 1) * image->width * 3 + j * 3 + k] = temp;
            }
        }
    }
}

void change_brightness(Image *image, int value) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < 3; k++) {
                int new_value = image->data[i * image->width * 3 + j * 3 + k] + value;
                if (new_value < 0) new_value = 0;
                if (new_value > 255) new_value = 255;
                image->data[i * image->width * 3 + j * 3 + k] = new_value;
            }
        }
    }
}

void change_contrast(Image *image, float value) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < 3; k++) {
                int new_value = image->data[i * image->width * 3 + j * 3 + k] * value;
                if (new_value < 0) new_value = 0;
                if (new_value > 255) new_value = 255;
                image->data[i * image->width * 3 + j * 3 + k] = new_value;
            }
        }
    }
}

int main() {
    Image *image = read_image("image.bmp");
    if (!image) return 1;

    flip_image(image);
    change_brightness(image, 50);
    change_contrast(image, 1.5);

    write_image(image, "new_image.bmp");

    free(image->data);
    free(image);

    return 0;
}