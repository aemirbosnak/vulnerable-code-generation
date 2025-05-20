//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 512
#define MAX_HEIGHT 512
#define WATERMARK_TEXT "Happy Watermark!"

typedef struct {
    int width;
    int height;
    unsigned char pixels[MAX_HEIGHT][MAX_WIDTH];
} PGMImage;

void readPGM(const char *filename, PGMImage *image) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }
    
    char format[3];
    fscanf(file, "%s", format);
    fscanf(file, "%d %d", &image->width, &image->height);
    int maxVal;
    fscanf(file, "%d", &maxVal);
    
    fread(image->pixels, sizeof(unsigned char), image->width * image->height, file);
    
    fclose(file);
}

void writePGM(const char *filename, const PGMImage *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file for writing");
        exit(EXIT_FAILURE);
    }
    
    fprintf(file, "P5\n%d %d\n255\n", image->width, image->height);
    fwrite(image->pixels, sizeof(unsigned char), image->width * image->height, file);
    
    fclose(file);
}

void embedWatermark(PGMImage *image) {
    int textLength = strlen(WATERMARK_TEXT);
    for (int i = 0; i < textLength && i < image->height; ++i) {
        for (int j = 0; j < textLength && j < image->width; ++j) {
            if (image->pixels[i][j] < 255) {
                image->pixels[i][j] += (WATERMARK_TEXT[j] % 2) * 10; // Modify pixels to embed watermark
            }
        }
    }
}

void printImageInfo(const PGMImage *image) {
    printf("Image Width: %d\n", image->width);
    printf("Image Height: %d\n", image->height);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input.pgm> <output.pgm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    PGMImage image;
    readPGM(argv[1], &image);
    printImageInfo(&image);
    
    embedWatermark(&image);
    writePGM(argv[2], &image);
    
    printf("Watermark added successfully! Enjoy your new image with a happy watermark!\n");
    
    return EXIT_SUCCESS;
}