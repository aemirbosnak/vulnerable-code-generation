//FormAI DATASET v1.0 Category: Image Editor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define HEADER_SIZE 54
#define BYTES_PER_PIXEL 3

void invertColors(unsigned char *image, int width, int height) {
    for(int i = 0; i < width * height * BYTES_PER_PIXEL; i++) {
        image[i] = 255 - image[i]; // Invert color
    }
}

void grayscale(unsigned char *image, int width, int height) {
    for(int i = 0; i < width * height * BYTES_PER_PIXEL; i += BYTES_PER_PIXEL) {
        unsigned char grayscale = 0.2989 * image[i + 2] + 0.5870 * image[i + 1] + 0.1140 * image[i]; // Calculate grayscale value using ITU-R Recommendation BT.601
        image[i + 2] = grayscale; // Assign grayscale value to red channel
        image[i + 1] = grayscale; // Assign grayscale value to green channel
        image[i] = grayscale; // Assign grayscale value to blue channel
    }
}

int main() {
    FILE *f = fopen("image.bmp", "rb"); // Open image file in read mode
    if(f == NULL) {
        perror("Error opening image");
        exit(1);
    }

    unsigned char header[HEADER_SIZE]; // Read header of BMP file
    fread(header, sizeof(unsigned char), HEADER_SIZE, f);

    int width = *(int*) &header[18]; // Read width from BMP file header
    int height = *(int*) &header[22]; // Read height from BMP file header

    printf("Image dimensions: %dx%d\n", width, height);

    unsigned char *image = (unsigned char*) malloc(width * height * BYTES_PER_PIXEL); // Allocate memory for image data
    fread(image, sizeof(unsigned char), width * height * BYTES_PER_PIXEL, f); // Read image data from file
    fclose(f); // Close file

    printf("Choose an option:\n");
    printf("1. Invert colors\n");
    printf("2. Convert to grayscale\n");
    printf("Option: ");

    int option;
    scanf("%d", &option);

    switch(option) {
        case 1:
            invertColors(image, width, height);
            break;
        case 2:
            grayscale(image, width, height);
            break;
        default:
            printf("Invalid option\n");
            free(image);
            exit(1);
    }

    FILE *output = fopen("output.bmp", "wb"); // Open output file in write mode
    if(output == NULL) {
        perror("Error opening output file");
        free(image);
        exit(1);
    }

    fwrite(header, sizeof(unsigned char), HEADER_SIZE, output); // Write header to output file
    fwrite(image, sizeof(unsigned char), width * height * BYTES_PER_PIXEL, output); // Write modified image data to output file
    fclose(output); // Close file

    free(image); // Free memory
    printf("Image processed successfully\n");
    return 0;
}