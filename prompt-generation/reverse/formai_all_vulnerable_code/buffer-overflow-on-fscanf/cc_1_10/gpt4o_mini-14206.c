//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define WATERMARK_SIZE 4

void apply_watermark(int *image, int width, int height, const int *watermark) {
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        // Embed the watermark into the image with slight modification
        int posX = i % width;
        int posY = i / width;
        if (posY < height) {
            image[posY * width + posX] = (image[posY * width + posX] + watermark[i]) / 2;
        }
    }
}

void print_image(int *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[i * width + j]);
        }
        printf("\n");
    }
}

void load_image(const char *filename, int **image, int *width, int *height) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    *width = 0;
    *height = 0;
    int pixel;
    int size = 0;
    
    // Calculate width and height by counting pixels
    while (fscanf(file, "%d", &pixel) != EOF) {
        size++;
        if (*width == 0) {
            *width = 1; // Assuming at least one pixel
        }
        if (size > *width) {
            *width = size;
        }
    }
    *height = size / (*width);
    
    // Allocate space for image
    *image = malloc(size * sizeof(int));
    rewind(file);
    
    // Load pixel values
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &(*image)[i]);
    }
    
    fclose(file);
}

int main() {
    int *image = NULL;
    int width, height;

    const int watermark[WATERMARK_SIZE] = {10, 20, 30, 40}; // Example watermark values

    load_image("image.txt", &image, &width, &height);
    printf("Original Image:\n");
    print_image(image, width, height);
    
    apply_watermark(image, width, height, watermark);
    printf("\nWatermarked Image:\n");
    print_image(image, width, height);

    free(image);
    return 0;
}