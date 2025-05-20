//FormAI DATASET v1.0 Category: Image Editor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct to store pixel data
typedef struct pixel {
    unsigned char r, g, b; // Red, green, blue values (0-255)
} pixel;

// Function to load PPM image file
pixel** loadPPM(char* filename, int* width, int* height) {
    FILE* fp = fopen(filename, "rb"); // Open file in binary mode

    // Check the file open status
    if (!fp) {
        printf("Error: cannot open file %s\n", filename);
        exit(1);
    }

    char magic_number[3];
    fscanf(fp, "%s", magic_number);
    int max_color;
    fscanf(fp, "%d %d %d", width, height, &max_color);

    // Allocate memory to store image data
    pixel** image = (pixel**) malloc(sizeof(pixel*) * (*height));
    for (int i = 0; i < *height; i++) {
        image[i] = (pixel*) malloc(sizeof(pixel) * (*width));
    }

    // Read pixel data from file
    for (int j = 0; j < *height; j++) {
        for (int i = 0; i < *width; i++) {
            fscanf(fp, "%hhu %hhu %hhu", &image[j][i].r, &image[j][i].g, &image[j][i].b);
        }
    }

    fclose(fp);
    return image;
}

// Function to save PPM image file
void savePPM(char* filename, int width, int height, pixel** image) {
    FILE* fp = fopen(filename, "wb"); // Open file in binary mode

    // Check the file open status
    if (!fp) {
        printf("Error: cannot create file %s\n", filename);
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n255\n", width, height);

    // Write pixel data to file
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            fprintf(fp, "%c%c%c", image[j][i].r, image[j][i].g, image[j][i].b);
        }
    }

    fclose(fp);
}

// Function to perform artistic effect on image
void artisticEffect(int width, int height, pixel** image) {
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            // Invert colors
            image[j][i].r = 255 - image[j][i].r;
            image[j][i].g = 255 - image[j][i].g;
            image[j][i].b = 255 - image[j][i].b;
        }
    }
}

int main() {
    int width, height;
    pixel** image = loadPPM("input.ppm", &width, &height);

    // Perform artistic effect
    artisticEffect(width, height, image);

    // Save image file
    savePPM("output.ppm", width, height, image);

    // Free memory
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}