//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[100];
    FILE *file;
    unsigned char *image;
    int width, height, bit_depth, i, j, pixel_pos, temp;
    float brightness, contrast;

    // Asks for filename and reads the input
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Attempts to open the file and reads the header
    file = fopen(filename, "rb");
    if(file == NULL) {
        printf("Error: Could not open the file.\n");
        return 1;
    }
    char header[54];
    fread(header, sizeof(char), 54, file);

    // Extracts the width, height and bit_depth from the header
    width = *(int*)&header[18];
    height = *(int*)&header[22];
    bit_depth = *(int*)&header[28];

    // Calculates the length (or size) of the image (in bytes)
    int size = width * height * (bit_depth / 8);

    // Allocates memory for the image
    image = (unsigned char*)malloc(size * sizeof(unsigned char));

    // Reads the image data
    fread(image, sizeof(unsigned char), size, file);
    fclose(file);

    // Performs a flip (vertically)
    for(i = 0; i < height / 2; i++) {
        for(j = 0; j < width * (bit_depth / 8); j++) {
            pixel_pos = (i * width * (bit_depth / 8)) + j;
            temp = image[pixel_pos];
            image[pixel_pos] = image[((height - 1 - i) * width * (bit_depth / 8)) + j];
            image[((height - 1 - i) * width * (bit_depth / 8)) + j] = temp;
        }
    }

    // Asks for brightness and contrast values and reads the input
    printf("Enter the brightness (-255 to 255): ");
    scanf("%f", &brightness);
    printf("Enter the contrast (0 to 10): ");
    scanf("%f", &contrast);

    // Performs a brightness and contrast adjustment
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            pixel_pos = (i * width + j) * (bit_depth / 8);
            int val = image[pixel_pos] * factor + brightness;
            if(val < 0) {
                val = 0;
            } else if(val > 255) {
                val = 255;
            }
            image[pixel_pos] = val;
            image[pixel_pos + 1] = val;
            image[pixel_pos + 2] = val;
        }
    }

    // Saves the modified image to a new file
    char output_filename[100];
    printf("Enter the output filename: ");
    scanf("%s", output_filename);
    file = fopen(output_filename, "wb");
    fwrite(header, sizeof(char), 54, file);
    fwrite(image, sizeof(unsigned char), size, file);
    fclose(file);

    // Frees allocated memory
    free(image);

    return 0;
}