//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);
    image->data = malloc(image->width * image->height * sizeof(unsigned char));
    if (!image->data) {
        perror("malloc");
        fclose(fp);
        free(image);
        return NULL;
    }

    fread(image->data, sizeof(unsigned char), image->width * image->height, fp);
    fclose(fp);

    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        return;
    }

    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);
    fwrite(image->data, sizeof(unsigned char), image->width * image->height, fp);
    fclose(fp);
}

void embed_watermark(Image *image, const char *watermark) {
    int i, j;
    int watermark_length = strlen(watermark);

    for (i = 0; i < watermark_length; i++) {
        int bit = (watermark[i] >> 0) & 1;
        int least_significant_bit = image->data[i % image->width + (i / image->width) * image->width] & 1;
        if (bit != least_significant_bit) {
            image->data[i % image->width + (i / image->width) * image->width] ^= 1;
        }
    }
}

char *extract_watermark(const Image *image) {
    int i, j;
    int watermark_length = 0;
    char *watermark = NULL;

    for (i = 0; i < image->width * image->height; i++) {
        if (i % image->width + (i / image->width) * image->width < watermark_length) {
            continue;
        }

        int bit = image->data[i % image->width + (i / image->width) * image->width] & 1;
        watermark = realloc(watermark, watermark_length + 1);
        watermark[watermark_length++] = (bit << 0) | watermark[watermark_length];
    }

    return watermark;
}

int main() {
    Image *image = read_image("image.bmp");
    if (!image) {
        return EXIT_FAILURE;
    }

    embed_watermark(image, "Peaceful");

    write_image(image, "watermarked_image.bmp");

    char *watermark = extract_watermark(image);
    if (!watermark) {
        return EXIT_FAILURE;
    }

    printf("Watermark: %s\n", watermark);

    free(image->data);
    free(image);
    free(watermark);

    return EXIT_SUCCESS;
}