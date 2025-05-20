//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert RGB image to grayscale
void rgb2gray(int *img, int width, int height)
{
    // Convert RGB image to grayscale by averaging R, G, B values
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++) {
            int r = img[x * width + y * 3 + 2];
            int g = img[x * width + y * 3 + 1];
            int b = img[x * width + y * 3 + 0];
            int gray = (r + g + b) / 3;
            img[x * width + y * 3 + 2] = gray;
        }
}

int main()
{
    // Read image file
    FILE *input = fopen("input.png", "rb");
    if (!input) {
        perror("Error opening input file");
        return 1;
    }

    // Allocate memory for image data
    int width, height;
    fread(&width, sizeof(int), 1, input);
    fread(&height, sizeof(int), 1, input);
    int *img = (int *)malloc(width * height * 3 * sizeof(int));
    if (!img) {
        perror("Error allocating memory");
        fclose(input);
        return 1;
    }

    // Read image data
    fread(img, sizeof(int), width * height * 3, input);
    fclose(input);

    // Convert RGB image to grayscale
    rgb2gray(img, width, height);

    // Write grayscale image to file
    FILE *output = fopen("output.png", "wb");
    if (!output) {
        perror("Error opening output file");
        return 1;
    }
    fwrite(img, sizeof(int), width * height * 3, output);
    fclose(output);

    // Free memory
    free(img);

    printf("Image converted successfully.\n");
    return 0;
}