//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    unsigned char *data;
    int width, height;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening file");
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    unsigned char header[18];
    fread(header, 1, 18, fp);

    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: not a BMP file\n");
        fclose(fp);
        return NULL;
    }

    unsigned int offset = *(unsigned int *)&header[10];
    unsigned int width = *(unsigned int *)&header[18];
    unsigned int height = *(unsigned int *)&header[22];

    Image *image = malloc(sizeof(Image));
    image->data = malloc(size - offset);
    fread(image->data, 1, size - offset, fp);

    image->width = width;
    image->height = height;

    fclose(fp);
    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    unsigned char header[18] = {
        'B', 'M',
        0, 0, 0, 0,
        0, 0,
        0, 0,
        54, 0, 0, 0,
        0, 0,
        0, 0
    };

    *(unsigned int *)&header[2] = image->width * image->height * 3 + 54;
    *(unsigned int *)&header[10] = 54;
    *(unsigned int *)&header[18] = image->width;
    *(unsigned int *)&header[22] = image->height;

    fwrite(header, 1, 18, fp);
    fwrite(image->data, 1, image->width * image->height * 3, fp);

    fclose(fp);
}

void invert_colors(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i * 3] = 255 - image->data[i * 3];
        image->data[i * 3 + 1] = 255 - image->data[i * 3 + 1];
        image->data[i * 3 + 2] = 255 - image->data[i * 3 + 2];
    }
}

void blur(Image *image, int radius) {
    if (radius <= 0) {
        return;
    }

    int width = image->width;
    int height = image->height;

    unsigned char *data = malloc(width * height * 3);
    memcpy(data, image->data, width * height * 3);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int sum[3] = {0, 0, 0};
            int count = 0;

            for (int k = -radius; k <= radius; k++) {
                for (int l = -radius; l <= radius; l++) {
                    int x = j + l;
                    int y = i + k;

                    if (x >= 0 && x < width && y >= 0 && y < height) {
                        sum[0] += data[(y * width + x) * 3];
                        sum[1] += data[(y * width + x) * 3 + 1];
                        sum[2] += data[(y * width + x) * 3 + 2];
                        count++;
                    }
                }
            }

            image->data[(i * width + j) * 3] = sum[0] / count;
            image->data[(i * width + j) * 3 + 1] = sum[1] / count;
            image->data[(i * width + j) * 3 + 2] = sum[2] / count;
        }
    }

    free(data);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    invert_colors(image);
    blur(image, 2);

    write_image(image, argv[2]);

    free(image->data);
    free(image);

    return 0;
}