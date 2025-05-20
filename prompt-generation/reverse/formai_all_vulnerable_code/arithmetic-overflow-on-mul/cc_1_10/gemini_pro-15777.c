//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);
    image->data = malloc(image->width * image->height);
    if (image->data == NULL) {
        free(image);
        fclose(fp);
        return NULL;
    }

    fread(image->data, 1, image->width * image->height, fp);
    fclose(fp);

    return image;
}

void save_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }

    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);
    fwrite(image->data, 1, image->width * image->height, fp);
    fclose(fp);
}

void embed_watermark(Image *image, const char *watermark) {
    int watermark_length = strlen(watermark);
    int watermark_index = 0;

    for (int i = 0; i < image->width * image->height; i++) {
        if (watermark_index < watermark_length) {
            image->data[i] = image->data[i] & 0x7F | (watermark[watermark_index] & 0x1) << 7;
            watermark_index++;
        }
    }
}

char *extract_watermark(Image *image) {
    int watermark_length = 0;
    while (watermark_length < image->width * image->height && (image->data[watermark_length] & 0x80) != 0) {
        watermark_length++;
    }

    char *watermark = malloc(watermark_length + 1);
    if (watermark == NULL) {
        return NULL;
    }

    int watermark_index = 0;
    for (int i = 0; i < image->width * image->height; i++) {
        if ((image->data[i] & 0x80) != 0) {
            watermark[watermark_index] = (image->data[i] & 0x7F) >> 7;
            watermark_index++;
        }
    }

    watermark[watermark_length] = '\0';
    return watermark;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <input image> <watermark> <output image>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (image == NULL) {
        printf("Error loading image: %s\n", argv[1]);
        return 1;
    }

    embed_watermark(image, argv[2]);

    save_image(argv[3], image);
    free(image->data);
    free(image);

    image = load_image(argv[3]);
    if (image == NULL) {
        printf("Error loading image: %s\n", argv[3]);
        return 1;
    }

    char *watermark = extract_watermark(image);
    if (watermark == NULL) {
        printf("Error extracting watermark from image: %s\n", argv[3]);
        return 1;
    }

    printf("Extracted watermark: %s\n", watermark);
    free(watermark);
    free(image->data);
    free(image);

    return 0;
}