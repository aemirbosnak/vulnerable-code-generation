//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image
void flip_image(int *image, int width, int height) {
    int temp;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            temp = *(image + i * width + j);
            *(image + i * width + j) = *(image + i * width + width - j - 1);
            *(image + i * width + width - j - 1) = temp;
        }
    }
}

// Function to adjust brightness and contrast of an image
void adjust_image(int *image, int width, int height, float brightness, float contrast) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            float pixel = *(image + i * width + j);
            pixel = (pixel - 128.0) * contrast + 128.0 + brightness;
            if (pixel < 0) {
                pixel = 0;
            } else if (pixel > 255) {
                pixel = 255;
            }
            *(image + i * width + j) = (int)pixel;
        }
    }
}

int main() {
    // Read image file
    FILE *file = fopen("image.txt", "r");
    if (file == NULL) {
        printf("Error reading file\n");
        return 1;
    }
    int width, height;
    fscanf(file, "%d %d", &width, &height);
    int *image = (int*)malloc(width * height * sizeof(int));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(file, "%d", image + i * width + j);
        }
    }
    fclose(file);

    // Flip image horizontally
    flip_image(image, width, height);

    // Adjust brightness and contrast of image
    adjust_image(image, width, height, 25.0, 1.5);

    // Save image to file
    FILE *outfile = fopen("new_image.txt", "w");
    fprintf(outfile, "%d %d\n", width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(outfile, "%d ", *(image + i * width + j));
        }
        fprintf(outfile, "\n");
    }
    fclose(outfile);

    free(image);
    return 0;
}