//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    fscanf(fp, "P6\n%d %d\n255\n", &image->width, &image->height);

    image->data = malloc(image->width * image->height * 3);
    if (image->data == NULL) {
        perror("malloc");
        fclose(fp);
        free(image);
        return NULL;
    }

    fread(image->data, image->width * image->height * 3, 1, fp);
    fclose(fp);

    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, image->width * image->height * 3, 1, fp);
    fclose(fp);
}

Image *watermark(const Image *image, const char *watermark) {
    int i, j;
    int watermark_length = strlen(watermark);
    Image *watermarked_image = malloc(sizeof(Image));
    if (watermarked_image == NULL) {
        perror("malloc");
        return NULL;
    }

    watermarked_image->width = image->width;
    watermarked_image->height = image->height;
    watermarked_image->data = malloc(image->width * image->height * 3);
    if (watermarked_image->data == NULL) {
        perror("malloc");
        free(watermarked_image);
        return NULL;
    }

    memcpy(watermarked_image->data, image->data, image->width * image->height * 3);

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            if (i % 10 == 0 && j % 10 == 0 && watermark_length > 0) {
                watermarked_image->data[i * image->width * 3 + j * 3 + 0] = watermark[watermark_length - 1];
                watermarked_image->data[i * image->width * 3 + j * 3 + 1] = watermark[watermark_length - 1];
                watermarked_image->data[i * image->width * 3 + j * 3 + 2] = watermark[watermark_length - 1];
                watermark_length--;
            }
        }
    }

    return watermarked_image;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image> <watermark> <output_image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *image = read_image(argv[1]);
    if (image == NULL) {
        return EXIT_FAILURE;
    }

    Image *watermarked_image = watermark(image, argv[2]);
    if (watermarked_image == NULL) {
        free(image);
        return EXIT_FAILURE;
    }

    write_image(watermarked_image, argv[3]);
    free(image);
    free(watermarked_image);
    return EXIT_SUCCESS;
}