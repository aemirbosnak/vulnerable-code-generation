//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char *data;
    int width, height;
} Image;

Image *load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(fp);
        return NULL;
    }

    fseek(fp, 18, SEEK_SET);
    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);

    image->data = malloc(image->width * image->height * 3);
    if (!image->data) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(fp);
        free(image);
        return NULL;
    }

    fseek(fp, 54, SEEK_SET);
    fread(image->data, image->width * image->height * 3, 1, fp);

    fclose(fp);

    return image;
}

void save_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    fwrite("BM", 2, 1, fp);
    int filesize = 54 + image->width * image->height * 3;
    fwrite(&filesize, 4, 1, fp);
    fwrite("\0\0\0\0", 4, 1, fp);
    fwrite("\0\0\0\0", 4, 1, fp);
    fwrite("\0\0\0\40", 4, 1, fp);
    int headersize = 40;
    fwrite(&headersize, 4, 1, fp);
    fwrite(&image->width, 4, 1, fp);
    fwrite(&image->height, 4, 1, fp);
    fwrite("\0\0\0\1", 4, 1, fp);
    fwrite("\0\0\0\24", 4, 1, fp);
    fwrite("\0\0\0\0", 4, 1, fp);
    fwrite("\0\0\0\0", 4, 1, fp);

    fwrite(image->data, image->width * image->height * 3, 1, fp);

    fclose(fp);
}

void flip_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int index = (i * image->width + j) * 3;
            char temp = image->data[index];
            image->data[index] = image->data[index + 2];
            image->data[index + 2] = temp;
        }
    }
}

void change_brightness_contrast(Image *image, int brightness, int contrast) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int index = (i * image->width + j) * 3;
            for (int k = 0; k < 3; k++) {
                int value = image->data[index + k] + brightness;
                value = (value - 128) * contrast + 128;
                if (value < 0) value = 0;
                if (value > 255) value = 255;
                image->data[index + k] = value;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input image> <output image> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    int brightness = atoi(argv[3]);
    int contrast = atoi(argv[4]);

    flip_image(image);
    change_brightness_contrast(image, brightness, contrast);

    save_image(image, argv[2]);

    free(image->data);
    free(image);

    return 0;
}