//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *data;
    int width;
    int height;
    int max_val;
} PGMImage;

PGMImage *loadPGM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    PGMImage *img = (PGMImage *)malloc(sizeof(PGMImage));
    if (!img) {
        perror("Unable to allocate memory for image");
        fclose(file);
        return NULL;
    }

    char buffer[16];
    fscanf(file, "%s", buffer);

    if (strcmp(buffer, "P5") != 0) {
        perror("Not a valid PGM file");
        fclose(file);
        free(img);
        return NULL;
    }

    fscanf(file, "%d %d", &img->width, &img->height);
    fscanf(file, "%d", &img->max_val);
    fgetc(file); // Read one extra character for the newline

    img->data = (unsigned char *)malloc(img->width * img->height);
    if (!img->data) {
        perror("Unable to allocate memory for image data");
        fclose(file);
        free(img);
        return NULL;
    }

    fread(img->data, 1, img->width * img->height, file);
    fclose(file);
    return img;
}

void savePGM(const char *filename, PGMImage *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    fprintf(file, "P5\n%d %d\n%d\n", img->width, img->height, img->max_val);
    fwrite(img->data, 1, img->width * img->height, file);
    fclose(file);
}

void embedWatermark(PGMImage *image, const char *watermark, int wm_len) {
    for (int i = 0; i < wm_len; i++) {
        for (int j = 0; j < 8; j++) {
            int index = i * 8 + j;
            if (index < image->width * image->height) {
                if (watermark[i] & (1 << j)) {
                    image->data[index] |= 1; // Set LSB to 1
                } else {
                    image->data[index] &= 0xFE; // Set LSB to 0
                }
            } else {
                break; // Prevent out-of-bounds access
            }
        }
    }
}

void freePGMImage(PGMImage *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

void printUsage(const char *programName) {
    printf("Usage: %s <input_image.pgm> <watermark_string> <output_image.pgm>\n", programName);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    PGMImage *image = loadPGM(argv[1]);
    if (!image) {
        return EXIT_FAILURE;
    }

    const char *watermark = argv[2];
    int wm_len = strlen(watermark);

    embedWatermark(image, watermark, wm_len);

    savePGM(argv[3], image);
    printf("Watermark embedded successfully!\n");

    freePGMImage(image);
    return EXIT_SUCCESS;
}