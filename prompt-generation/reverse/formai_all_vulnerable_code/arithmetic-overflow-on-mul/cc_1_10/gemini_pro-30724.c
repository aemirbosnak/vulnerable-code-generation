//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1024

typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

Image *read_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(file);
        return NULL;
    }

    // Read the header
    unsigned char header[14];
    if (fread(header, 1, 14, file) != 14) {
        fprintf(stderr, "Error reading header\n");
        fclose(file);
        free(image);
        return NULL;
    }

    // Check the header
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Invalid header\n");
        fclose(file);
        free(image);
        return NULL;
    }

    // Read the dimensions
    image->width = *(int *)&header[18];
    image->height = *(int *)&header[22];

    // Allocate memory for the data
    image->data = malloc(image->width * image->height * 3);
    if (image->data == NULL) {
        fprintf(stderr, "Error allocating memory for data\n");
        fclose(file);
        free(image);
        return NULL;
    }

    // Read the data
    if (fread(image->data, 1, image->width * image->height * 3, file) != image->width * image->height * 3) {
        fprintf(stderr, "Error reading data\n");
        fclose(file);
        free(image->data);
        free(image);
        return NULL;
    }

    fclose(file);

    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Write the header
    unsigned char header[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;
    if (fwrite(header, 1, 14, file) != 14) {
        fprintf(stderr, "Error writing header\n");
        fclose(file);
        return;
    }

    // Write the data
    if (fwrite(image->data, 1, image->width * image->height * 3, file) != image->width * image->height * 3) {
        fprintf(stderr, "Error writing data\n");
        fclose(file);
        return;
    }

    fclose(file);
}

void embed_watermark(Image *image, const char *watermark) {
    int len = strlen(watermark);
    if (len > image->width * image->height / 8) {
        fprintf(stderr, "Watermark is too long\n");
        return;
    }

    for (int i = 0; i < len; i++) {
        int bit = watermark[i] & 1;
        int r = i / (image->width / 8);
        int c = i % (image->width / 8);
        int offset = r * image->width * 3 + c * 3;
        image->data[offset] = (image->data[offset] & 0xFE) | bit;
    }
}

char *extract_watermark(const Image *image) {
    int len = image->width * image->height / 8;
    char *watermark = malloc(len + 1);
    if (watermark == NULL) {
        fprintf(stderr, "Error allocating memory for watermark\n");
        return NULL;
    }

    for (int i = 0; i < len; i++) {
        int bit = image->data[i * 8 * 3] & 1;
        watermark[i] = bit << 7;
        for (int j = 1; j < 8; j++) {
            bit = image->data[(i * 8 + j) * 3] & 1;
            watermark[i] |= bit << (7 - j);
        }
    }

    watermark[len] = '\0';

    return watermark;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <watermark> <output image>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    embed_watermark(image, argv[2]);

    write_image(image, argv[3]);

    free(image->data);
    free(image);

    return 0;
}