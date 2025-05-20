//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200

// Function to convert image to ASCII art
void imageToAscii(char image[MAX_WIDTH][MAX_HEIGHT], int width, int height, char ascii[MAX_WIDTH][MAX_HEIGHT], bool invert) {
    char gradient[] = " .:-=+*#%@";
    int levels = strlen(gradient);

    // Calculate pixel range
    int max_pixel = 0, min_pixel = 255;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel = image[x][y];
            if (pixel > max_pixel) {
                max_pixel = pixel;
            }
            if (pixel < min_pixel) {
                min_pixel = pixel;
            }
        }
    }

    // Convert pixel values to ASCII characters
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel = image[x][y];
            int level = (int) round((pixel - min_pixel) * (levels - 1) / (max_pixel - min_pixel));
            if (invert) {
                level = levels - 1 - level;
            }
            ascii[x][y] = gradient[level];
        }
    }
}

int main() {
    // Set up input file and output file names
    char input_file[] = "image.bmp";
    char output_file[] = "image.txt";

    // Read image file header
    FILE *fp_in = fopen(input_file, "rb");
    if (fp_in == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    char signature[2];
    fread(signature, sizeof(signature), 1, fp_in);
    if (signature[0] != 'B' || signature[1] != 'M') {
        printf("Invalid file format\n");
        exit(EXIT_FAILURE);
    }
    int file_size;
    fread(&file_size, sizeof(file_size), 1, fp_in);
    fseek(fp_in, 10, SEEK_SET);
    int data_offset;
    fread(&data_offset, sizeof(data_offset), 1, fp_in);
    fseek(fp_in, 18, SEEK_SET);
    int width, height;
    fread(&width, sizeof(width), 1, fp_in);
    fread(&height, sizeof(height), 1, fp_in);
    fseek(fp_in, data_offset, SEEK_SET);

    // Read image data
    char image[MAX_WIDTH][MAX_HEIGHT];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int b, g, r;
            fread(&b, sizeof(b), 1, fp_in);
            fread(&g, sizeof(g), 1, fp_in);
            fread(&r, sizeof(r), 1, fp_in);
            int gray = (int) round(0.299 * r + 0.587 * g + 0.114 * b);
            image[x][y] = (char) gray;
        }
        fseek(fp_in, (width * 3) % 4, SEEK_CUR);
    }
    fclose(fp_in);

    char ascii[MAX_WIDTH][MAX_HEIGHT];
    // Convert image to ASCII art and print to console
    imageToAscii(image, width, height, ascii, false);
    printf("Image converted to ASCII art:\n");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", ascii[x][y]);
        }
        printf("\n");
    }

    // Write ASCII art to file
    FILE *fp_out = fopen(output_file, "w");
    if (fp_out == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }
    imageToAscii(image, width, height, ascii, true);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fprintf(fp_out, "%c", ascii[x][y]);
        }
        fprintf(fp_out, "\n");
    }
    printf("ASCII art saved to %s\n", output_file);

    fclose(fp_out);

    return 0;
}