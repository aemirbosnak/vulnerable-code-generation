//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GET_GREY(r,g,b) (0.2126 * (double)(r) + 0.7152 * (double)(g) + 0.0722 * (double)(b))

unsigned char **readImage(const char *filename, int *width, int *height) {
    FILE *fptr = fopen(filename, "rb");
    if (fptr == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    if (fscanf(fptr, "P3\n%d %d\n255\n", width, height) != 3) {
        fprintf(stderr, "Error: could not read header of file %s\n", filename);
        fclose(fptr);
        return NULL;
    }

    unsigned char **image = (unsigned char **) malloc(*height * sizeof(unsigned char *));
    for (int i = 0; i < *height; i++) {
        image[i] = (unsigned char *) malloc(*width * sizeof(unsigned char));
        for (int j = 0; j < *width; j++) {
            if (fscanf(fptr, "%hhu %hhu %hhu\n", &image[i][j], &image[i][j+1], &image[i][j+2]) != 3) {
                fprintf(stderr, "Error: could not read pixel at (%d, %d) of file %s\n", i, j, filename);
                for (int k = 0; k <= i; k++) {
                    free(image[k]);
                }
                free(image);
                fclose(fptr);
                return NULL;
            }
            j += 2;
        }
    }

    fclose(fptr);
    return image;
}

void writeImage(const char *filename, unsigned char **image, int width, int height) {
    FILE *fptr = fopen(filename, "wb");
    if (fptr == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    fprintf(fptr, "P3\n%d %d\n255\n", width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(fptr, "%hhu %hhu %hhu ", image[i][j], image[i][j], image[i][j]);
        }
        fprintf(fptr, "\n");
    }

    fclose(fptr);
}

void flipImage(unsigned char **image, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char temp = image[i][j];
            image[i][j] = image[height - i - 1][j];
            image[height - i - 1][j] = temp;
        }
    }
}

void changeBrightness(unsigned char **image, int width, int height, double factor) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = (unsigned char) (image[i][j] * factor);
        }
    }
}

void changeContrast(unsigned char **image, int width, int height, double factor) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = (unsigned char) (128 + (image[i][j] - 128) * factor);
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input image> <output image> <operation> <factor>\n", argv[0]);
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    const char *operation = argv[3];
    double factor = atof(argv[4]);

    int width, height;
    unsigned char **image = readImage(input_filename, &width, &height);
    if (image == NULL) {
        return 1;
    }

    if (strcmp(operation, "flip") == 0) {
        flipImage(image, width, height);
    } else if (strcmp(operation, "brightness") == 0) {
        changeBrightness(image, width, height, factor);
    } else if (strcmp(operation, "contrast") == 0) {
        changeContrast(image, width, height, factor);
    } else {
        fprintf(stderr, "Error: unknown operation %s\n", operation);
        free(image);
        return 1;
    }

    writeImage(output_filename, image, width, height);
    free(image);
    return 0;
}