//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int width;
    int height;
    int channels;
    unsigned char *data;
} Image;

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'.\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for image.\n");
        fclose(file);
        return NULL;
    }

    int width, height, channels;
    if (fscanf(file, "P3 %d %d %d\n", &width, &height, &channels) != 3) {
        fprintf(stderr, "Error: Invalid PPM file header.\n");
        fclose(file);
        free(image);
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->channels = channels;
    image->data = malloc(width * height * channels);
    if (image->data == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for image data.\n");
        fclose(file);
        free(image);
        return NULL;
    }

    for (int i = 0; i < width * height * channels; i++) {
        int value;
        if (fscanf(file, "%d", &value) != 1) {
            fprintf(stderr, "Error: Invalid PPM file data.\n");
            fclose(file);
            free(image->data);
            free(image);
            return NULL;
        }
        image->data[i] = value;
    }

    fclose(file);
    return image;
}

void free_image(Image *image) {
    if (image != NULL) {
        if (image->data != NULL) {
            free(image->data);
        }
        free(image);
    }
}

int main() {
    Image *image = load_image("image.ppm");
    if (image == NULL) {
        return EXIT_FAILURE;
    }

    // Your image classification code here...

    free_image(image);
    return EXIT_SUCCESS;
}