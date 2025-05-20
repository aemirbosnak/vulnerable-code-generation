//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

struct PPMImage {
    int width;
    int height;
    unsigned char *data;
};

struct PPMImage *loadPPM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return NULL;
    }

    char format[3];
    fscanf(file, "%s\n", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported PPM format: %s\n", format);
        fclose(file);
        return NULL;
    }

    struct PPMImage *image = malloc(sizeof(struct PPMImage));
    fscanf(file, "%d %d\n255\n", &image->width, &image->height);

    image->data = (unsigned char *)malloc(image->width * image->height * 3);
    fread(image->data, 3, image->width * image->height, file);
    fclose(file);

    return image;
}

void savePPM(const char *filename, struct PPMImage *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, 3, image->width * image->height, file);
    fclose(file);
}

void invertColors(struct PPMImage *image) {
    for (int i = 0; i < image->width * image->height * 3; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

void freePPMImage(struct PPMImage *image) {
    if (image) {
        free(image->data);
        free(image);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        return 1;
    }

    struct PPMImage *image = loadPPM(argv[1]);
    if (!image) {
        return 1;
    }

    invertColors(image);
    
    savePPM(argv[2], image);
    printf("Inverted colors and saved to %s\n", argv[2]);

    freePPMImage(image);
    return 0;
}