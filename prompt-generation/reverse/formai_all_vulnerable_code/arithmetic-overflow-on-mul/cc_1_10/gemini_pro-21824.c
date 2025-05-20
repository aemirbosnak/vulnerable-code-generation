//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char *data;
    int width, height;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return NULL;
    }

    int width, height;
    if (fscanf(fp, "P5 %d %d\n", &width, &height) != 2) {
        fprintf(stderr, "Invalid image format\n");
        fclose(fp);
        return NULL;
    }

    if (fgetc(fp) != '\n') {
        fprintf(stderr, "Invalid image format\n");
        fclose(fp);
        return NULL;
    }

    unsigned char *data = malloc(width * height);
    if (!data) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    if (fread(data, width * height, 1, fp) != 1) {
        perror("fread");
        fclose(fp);
        free(data);
        return NULL;
    }

    fclose(fp);

    Image *image = malloc(sizeof(Image));
    if (!image) {
        perror("malloc");
        free(data);
        return NULL;
    }

    image->data = data;
    image->width = width;
    image->height = height;

    return image;
}

void write_image(const char *filename, const Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        return;
    }

    fprintf(fp, "P5 %d %d\n", image->width, image->height);
    fwrite(image->data, image->width * image->height, 1, fp);

    fclose(fp);
}

void flip_image(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - y - 1) * image->width + x];
            image->data[(image->height - y - 1) * image->width + x] = temp;
        }
    }
}

void change_brightness_contrast(Image *image, double brightness, double contrast) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int value = image->data[y * image->width + x] + brightness;
            value *= contrast;
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            image->data[y * image->width + x] = value;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    flip_image(image);
    change_brightness_contrast(image, 10.0, 1.5);

    write_image(argv[2], image);

    free(image->data);
    free(image);

    return 0;
}