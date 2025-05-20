//FormAI DATASET v1.0 Category: Image Editor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_PIXEL_VALUE 255

int main() {

    // Declare variables
    char filename[MAX_FILENAME_LENGTH];
    FILE* fp;
    unsigned char* image_data;
    int width, height, max_val;

    printf("Enter input image filename: ");
    scanf("%s", filename);

    // Open input image file
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Unable to open input image file.\n");
        return 1;
    }

    // Read header of input image file
    char magic_number[3];
    fscanf(fp, "%s", magic_number);
    fscanf(fp, "%d", &width);
    fscanf(fp, "%d", &height);
    fscanf(fp, "%d", &max_val);

    // Allocate memory for image data
    image_data = (unsigned char*)malloc(width * height * sizeof(unsigned char));

    // Read image data from input file
    fread(image_data, sizeof(unsigned char), width * height, fp);

    // Close input image file
    fclose(fp);

    // Output image statistics
    printf("\nInput image dimensions: %d x %d\n", width, height);
    printf("Maximum pixel value: %d\n\n", max_val);

    // Image editing operations
    unsigned char* temp_data = (unsigned char*)malloc(width * height * sizeof(unsigned char));

    // Negative image
    for (int i = 0; i < width * height; i++) {
        temp_data[i] = MAX_PIXEL_VALUE - image_data[i];
    }

    // Save negative image to output file
    fp = fopen("negative.pgm", "wb");
    fprintf(fp, "P5 %d %d %d\n", width, height, max_val);
    fwrite(temp_data, sizeof(unsigned char), width * height, fp);
    fclose(fp);

    // Grayscale image
    for (int i = 0; i < width * height; i++) {
        int gray = 0.3 * image_data[i] + 0.59 * image_data[i + 1] + 0.11 * image_data[i + 2];
        temp_data[i] = gray;
    }

    // Save grayscale image to output file
    fp = fopen("grayscale.pgm", "wb");
    fprintf(fp, "P5 %d %d %d\n", width, height, max_val);
    fwrite(temp_data, sizeof(unsigned char), width * height, fp);
    fclose(fp);

    // Free allocated memory
    free(image_data);
    free(temp_data);

    return 0;
}