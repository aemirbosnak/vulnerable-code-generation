//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

Image* loadPGM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    char header[3];
    fscanf(file, "%s", header); // Read the PGM header
    if (strcmp(header, "P5") != 0) {
        fclose(file);
        fprintf(stderr, "Unsupported format\n");
        return NULL;
    }

    int width, height, maxval;
    fscanf(file, "%d %d", &width, &height);
    fscanf(file, "%d", &maxval);
    fgetc(file); // Read the newline character after maxval

    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height);

    fread(img->data, 1, width * height, file);
    fclose(file);
    return img;
}

void savePGM(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }
    
    fprintf(file, "P5\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, 1, img->width * img->height, file);
    fclose(file);
}

void watermarkImage(Image *img, const char *watermark, int xOffset, int yOffset) {
    int wLen = strlen(watermark);
    for (int y = 0; y < img->height && (y + yOffset) < img->height; y++) {
        for (int x = 0; x < wLen && (x + xOffset) < img->width; x++) {
            // Embed watermark into the image by modifying the pixel values
            img->data[(y + yOffset) * img->width + (x + xOffset)] = 
                (img->data[(y + yOffset) * img->width + (x + xOffset)] + watermark[x]) % 256;
        }
    }
}

void freeImage(Image *img) {
    free(img->data);
    free(img);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.pgm> <output.pgm> <watermark>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    const char *watermark = argv[3];

    Image *img = loadPGM(inputFile);
    if (!img) {
        return EXIT_FAILURE;
    }

    watermarkImage(img, watermark, 10, 10); // Embed watermark at (10, 10)

    savePGM(outputFile, img);
    printf("Watermarked image saved as %s\n", outputFile);

    freeImage(img);
    return EXIT_SUCCESS;
}