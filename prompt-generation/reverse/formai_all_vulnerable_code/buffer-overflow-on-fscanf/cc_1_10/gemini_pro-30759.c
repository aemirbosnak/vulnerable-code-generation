//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMG_WIDTH 28
#define IMG_HEIGHT 28

typedef struct {
    double data[IMG_WIDTH * IMG_HEIGHT];
    int label;
} Image;

Image* load_image(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    Image* image = malloc(sizeof(Image));
    if (image == NULL) {
        fclose(fp);
        return NULL;
    }

    for (int i = 0; i < IMG_WIDTH * IMG_HEIGHT; i++) {
        fscanf(fp, "%lf", &image->data[i]);
    }
    fscanf(fp, "%d", &image->label);

    fclose(fp);

    return image;
}

void free_image(Image* image) {
    free(image);
}

int main() {
    Image* image = load_image("image.txt");
    if (image == NULL) {
        printf("Error loading image.\n");
        return EXIT_FAILURE;
    }

    // Perform image classification here

    free_image(image);

    return EXIT_SUCCESS;
}