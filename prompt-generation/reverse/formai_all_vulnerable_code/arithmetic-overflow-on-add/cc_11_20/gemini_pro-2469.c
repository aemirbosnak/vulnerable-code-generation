//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: surprised
#include <stdlib.h>
#include <stdio.h>

typedef unsigned char uchar;
#define uchar_max 255

int main() {
    // Load the image
    FILE *input_file = fopen("input.bmp", "rb");
    if (input_file == NULL) {
        printf("Failed to open input file!");
        return 1;
    }
    int width, height;
    fscanf(input_file, "BM%*[^\n]\n%*[^\n]\n%*[^\n]\n%d %d\n", &width, &height);
    uchar *input_data = malloc(width * height * 3);
    fread(input_data, 1, width * height * 3, input_file);
    fclose(input_file);

    // Flip the image vertically
    uchar *output_data = malloc(width * height * 3);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            output_data[y * width * 3 + x * 3 + 0] = input_data[(height - y - 1) * width * 3 + x * 3 + 0];
            output_data[y * width * 3 + x * 3 + 1] = input_data[(height - y - 1) * width * 3 + x * 3 + 1];
            output_data[y * width * 3 + x * 3 + 2] = input_data[(height - y - 1) * width * 3 + x * 3 + 2];
        }
    }

    // Change the brightness and contrast
    float brightness = 1.2;
    float contrast = 1.5;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            float r = (float)input_data[y * width * 3 + x * 3 + 0] / uchar_max;
            float g = (float)input_data[y * width * 3 + x * 3 + 1] / uchar_max;
            float b = (float)input_data[y * width * 3 + x * 3 + 2] / uchar_max;

            r = r * contrast + brightness;
            if (r > 1.0) r = 1.0;
            if (r < 0.0) r = 0.0;

            g = g * contrast + brightness;
            if (g > 1.0) g = 1.0;
            if (g < 0.0) g = 0.0;

            b = b * contrast + brightness;
            if (b > 1.0) b = 1.0;
            if (b < 0.0) b = 0.0;

            output_data[y * width * 3 + x * 3 + 0] = (uchar)(r * uchar_max);
            output_data[y * width * 3 + x * 3 + 1] = (uchar)(g * uchar_max);
            output_data[y * width * 3 + x * 3 + 2] = (uchar)(b * uchar_max);
        }
    }

    // Save the output image
    FILE *output_file = fopen("output.bmp", "wb");
    if (output_file == NULL) {
        printf("Failed to open output file!");
        return 1;
    }
    fwrite("BM", 1, 2, output_file);
    fprintf(output_file, "%*[^\n]\n%*[^\n]\n%*[^\n]\n%d %d\n", 18, 18);
    fwrite(output_data, 1, width * height * 3, output_file);
    fclose(output_file);

    // Free the allocated memory
    free(input_data);
    free(output_data);

    return 0;
}