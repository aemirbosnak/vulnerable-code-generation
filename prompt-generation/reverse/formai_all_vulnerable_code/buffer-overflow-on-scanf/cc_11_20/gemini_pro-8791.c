//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 512

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

pixel image_data[MAX_SIZE][MAX_SIZE];

int main() {
    char filename[50];
    int width, height;
    FILE *file;

    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    // Read the header information
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    // Read the image data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(&image_data[i][j], sizeof(pixel), 1, file);
        }
    }

    fclose(file);

    // Flip the image horizontally
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            pixel temp = image_data[i][j];
            image_data[i][j] = image_data[i][width - j - 1];
            image_data[i][width - j - 1] = temp;
        }
    }

    // Change the brightness and contrast
    int brightness = 50;
    int contrast = 20;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int red = image_data[i][j].red + brightness;
            int green = image_data[i][j].green + brightness;
            int blue = image_data[i][j].blue + brightness;

            if (red > 255) {
                red = 255;
            }
            if (green > 255) {
                green = 255;
            }
            if (blue > 255) {
                blue = 255;
            }

            image_data[i][j].red = red * contrast / 100;
            image_data[i][j].green = green * contrast / 100;
            image_data[i][j].blue = blue * contrast / 100;
        }
    }

    // Save the modified image
    file = fopen("output.bmp", "wb");
    if (file == NULL) {
        printf("Error opening file output.bmp\n");
        return 1;
    }

    // Write the header information
    fwrite(&width, sizeof(int), 1, file);
    fwrite(&height, sizeof(int), 1, file);

    // Write the image data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fwrite(&image_data[i][j], sizeof(pixel), 1, file);
        }
    }

    fclose(file);

    return 0;
}