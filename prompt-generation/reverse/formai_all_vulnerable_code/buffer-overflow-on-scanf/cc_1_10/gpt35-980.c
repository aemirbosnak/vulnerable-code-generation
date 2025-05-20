//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

void flip_image(char *filename) {
    FILE *fptr1, *fptr2;
    char new_filename[MAX];
    char buffer;
    int width, height, max_value;

    // Open original image file
    fptr1 = fopen(filename, "rb");
    if (fptr1 == NULL) {
        printf("Error: could not open file.\n");
        return;
    }

    // Read PPM header (first line)
    if (fgets(new_filename, MAX, fptr1) == NULL) {
        printf("Invalid PPM file format.\n");
        return;
    }

    // Check PPM file format (must start with "P6")
    if (new_filename[0] != 'P' || new_filename[1] != '6') {
        printf("Invalid PPM file format.\n");
        return;
    }

    // Read PPM image dimensions (second line)
    if (fgets(new_filename, MAX, fptr1) == NULL) {
        printf("Invalid PPM file format.\n");
        return;
    }

    // Parse image dimensions
    sscanf(new_filename, "%d %d", &width, &height);

    // Read PPM max value (third line)
    if (fgets(new_filename, MAX, fptr1) == NULL) {
        printf("Invalid PPM file format.\n");
        return;
    }

    // Parse max value
    sscanf(new_filename, "%d", &max_value);

    // Create new image file with "_flipped" suffix
    strcpy(new_filename, filename);
    strcat(new_filename, "_flipped");

    // Open new image file for writing
    fptr2 = fopen(new_filename, "wb");
    if (fptr2 == NULL) {
        printf("Error: could not create file.\n");
        return;
    }

    // Write PPM header to new file
    fprintf(fptr2, "P6\n%d %d\n%d\n", width, height, max_value);

    // Read and write PPM pixels to new file in reverse order
    for (int i = height-1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {

            // Read pixel from original file
            fread(&buffer, sizeof(char), 1, fptr1);
            fwrite(&buffer, sizeof(char), 1, fptr2);

            fread(&buffer, sizeof(char), 1, fptr1);
            fwrite(&buffer, sizeof(char), 1, fptr2);

            fread(&buffer, sizeof(char), 1, fptr1);
            fwrite(&buffer, sizeof(char), 1, fptr2);
        }
    }

    // Close files
    fclose(fptr1);
    fclose(fptr2);

    printf("Image flipped successfully.\n");
}

void adjust_brightness(char *filename, int brightness) {
    FILE *fptr1, *fptr2;
    char new_filename[MAX];
    char buffer;
    int width, height, max_value, pixel_r, pixel_g, pixel_b;

    // Open original image file
    fptr1 = fopen(filename, "rb");
    if (fptr1 == NULL) {
        printf("Error: could not open file.\n");
        return;
    }

    // Read PPM header (first line)
    if (fgets(new_filename, MAX, fptr1) == NULL) {
        printf("Invalid PPM file format.\n");
        return;
    }

    // Check PPM file format (must start with "P6")
    if (new_filename[0] != 'P' || new_filename[1] != '6') {
        printf("Invalid PPM file format.\n");
        return;
    }

    // Read PPM image dimensions (second line)
    if (fgets(new_filename, MAX, fptr1) == NULL) {
        printf("Invalid PPM file format.\n");
        return;
    }

    // Parse image dimensions
    sscanf(new_filename, "%d %d", &width, &height);

    // Read PPM max value (third line)
    if (fgets(new_filename, MAX, fptr1) == NULL) {
        printf("Invalid PPM file format.\n");
        return;
    }

    // Parse max value
    sscanf(new_filename, "%d", &max_value);

    // Create new image file with "_brightened" suffix
    strcpy(new_filename, filename);
    strcat(new_filename, "_brightened");

    // Open new image file for writing
    fptr2 = fopen(new_filename, "wb");
    if (fptr2 == NULL) {
        printf("Error: could not create file.\n");
        return;
    }

    // Write PPM header to new file
    fprintf(fptr2, "P6\n%d %d\n%d\n", width, height, max_value);

    // Adjust brightness of each pixel and write to new file
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            // Read pixel from original file
            fread(&buffer, sizeof(char), 1, fptr1);
            pixel_r = buffer;

            fread(&buffer, sizeof(char), 1, fptr1);
            pixel_g = buffer;

            fread(&buffer, sizeof(char), 1, fptr1);
            pixel_b = buffer;

            // Adjust pixel brightness by adding the brightness value
            pixel_r += brightness;
            pixel_g += brightness;
            pixel_b += brightness;

            // Make sure pixel values are within 0-255 range
            if (pixel_r > 255) pixel_r = 255;
            if (pixel_g > 255) pixel_g = 255;
            if (pixel_b > 255) pixel_b = 255;
            if (pixel_r < 0) pixel_r = 0;
            if (pixel_g < 0) pixel_g = 0;
            if (pixel_b < 0) pixel_b = 0;

            // Write adjusted pixel to new file
            fwrite(&pixel_r, sizeof(char), 1, fptr2);
            fwrite(&pixel_g, sizeof(char), 1, fptr2);
            fwrite(&pixel_b, sizeof(char), 1, fptr2);
        }
    }

    // Close files
    fclose(fptr1);
    fclose(fptr2);

    printf("Image brightness adjusted successfully.\n");
}

int main() {
    char filename[MAX];
    int choice = 0, brightness = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    printf("\nChoose an image processing task:\n");
    printf("1. Flip image\n");
    printf("2. Adjust brightness\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            flip_image(filename);
            break;
        case 2:
            printf("Enter brightness level (-255 to 255): ");
            scanf("%d", &brightness);
            adjust_brightness(filename, brightness);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}