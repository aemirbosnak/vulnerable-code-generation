//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: funny
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} pixel_t;

int main() {
    // Get the image size from the user.
    int width, height;
    printf("Enter the image width: ");
    scanf("%d", &width);
    printf("Enter the image height: ");
    scanf("%d", &height);

    // Allocate memory for the image.
    pixel_t *image = malloc(width * height * sizeof(pixel_t));
    if (image == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for the image.\n");
        return 1;
    }

    // Read the image data from the user.
    printf("Enter the image data in row-major order, separated by spaces:\n");
    for (int i = 0; i < width * height; i++) {
        scanf("%hhu %hhu %hhu", &image[i].r, &image[i].g, &image[i].b);
    }

    // Apply a funny filter to the image.
    for (int i = 0; i < width * height; i++) {
        // Make the image look like a rainbow.
        image[i].r = (image[i].r + image[i].g + image[i].b) / 3;
        image[i].g = (image[i].r + image[i].g + image[i].b) / 3;
        image[i].b = (image[i].r + image[i].g + image[i].b) / 3;

        // Add some random noise to the image.
        image[i].r += rand() % 10;
        image[i].g += rand() % 10;
        image[i].b += rand() % 10;
    }

    // Write the filtered image to a file.
    FILE *fp = fopen("output.ppm", "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open the output file.\n");
        return 1;
    }

    fprintf(fp, "P3\n%d %d\n255\n", width, height);
    for (int i = 0; i < width * height; i++) {
        fprintf(fp, "%hhu %hhu %hhu\n", image[i].r, image[i].g, image[i].b);
    }

    fclose(fp);

    // Free the memory allocated for the image.
    free(image);

    printf("Your hilarious image has been saved to output.ppm.\n");

    return 0;
}