//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 768

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    fseek(fp, 2, SEEK_SET);
    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);
    fseek(fp, 10, SEEK_SET);

    image->data = malloc(image->width * image->height * 3);
    if (!image->data) {
        perror("malloc");
        fclose(fp);
        free(image);
        return NULL;
    }

    fread(image->data, image->width * image->height * 3, 1, fp);
    fclose(fp);

    return image;
}

void write_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        return;
    }

    fwrite("BM", 2, 1, fp);
    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);
    fwrite("\0\0", 2, 1, fp);
    fwrite("\0\0\0", 3, 1, fp);
    fwrite("\0", 1, 1, fp);
    fwrite(&image->data, image->width * image->height * 3, 1, fp);
    fclose(fp);
}

void invert_image(Image *image) {
    for (int i = 0; i < image->width * image->height * 3; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

void grayscale_image(Image *image) {
    for (int i = 0; i < image->width * image->height * 3; i += 3) {
        unsigned char gray = (image->data[i] + image->data[i + 1] + image->data[i + 2]) / 3;
        image->data[i] = gray;
        image->data[i + 1] = gray;
        image->data[i + 2] = gray;
    }
}

void rotate_image(Image *image, double angle) {
    double radians = angle * M_PI / 180.0;
    double sin_theta = sin(radians);
    double cos_theta = cos(radians);

    Image *new_image = malloc(sizeof(Image));
    if (!new_image) {
        perror("malloc");
        return;
    }

    new_image->width = round(image->width * cos_theta + image->height * sin_theta);
    new_image->height = round(image->width * sin_theta + image->height * cos_theta);
    new_image->data = malloc(new_image->width * new_image->height * 3);
    if (!new_image->data) {
        perror("malloc");
        free(new_image);
        return;
    }

    for (int i = 0; i < new_image->width; i++) {
        for (int j = 0; j < new_image->height; j++) {
            double x = i * cos_theta - j * sin_theta;
            double y = i * sin_theta + j * cos_theta;

            int x0 = round(x);
            int y0 = round(y);

            if (x0 >= 0 && x0 < image->width && y0 >= 0 && y0 < image->height) {
                new_image->data[i + j * new_image->width * 3] = image->data[x0 + y0 * image->width * 3];
                new_image->data[i + j * new_image->width * 3 + 1] = image->data[x0 + y0 * image->width * 3 + 1];
                new_image->data[i + j * new_image->width * 3 + 2] = image->data[x0 + y0 * image->width * 3 + 2];
            } else {
                new_image->data[i + j * new_image->width * 3] = 0;
                new_image->data[i + j * new_image->width * 3 + 1] = 0;
                new_image->data[i + j * new_image->width * 3 + 2] = 0;
            }
        }
    }

    free(image->data);
    *image = *new_image;
    free(new_image);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    invert_image(image);
    grayscale_image(image);
    rotate_image(image, 45.0);

    write_image(argv[2], image);
    free(image->data);
    free(image);

    return 0;
}