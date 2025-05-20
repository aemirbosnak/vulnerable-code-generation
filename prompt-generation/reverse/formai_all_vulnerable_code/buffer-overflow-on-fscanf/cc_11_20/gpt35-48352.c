//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mathematical
#include <stdio.h>

int main() {
    // Initialize variables
    int rows, columns, max_value;
    char magic_number[2];

    // Read input image
    FILE *input_image = fopen("input_image.pgm", "r");
    fscanf(input_image, "%s %d %d %d", magic_number, &columns, &rows, &max_value);
    int image[rows][columns];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            fscanf(input_image, "%d", &image[i][j]);
        }
    }
    fclose(input_image);

    // Flip image horizontally
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns/2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][columns-1-j];
            image[i][columns-1-j] = temp;
        }
    }

    // Change brightness of image
    int brightness = 50;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            image[i][j] += brightness;
            if(image[i][j] > max_value) {
                image[i][j] = max_value;
            }
        }
    }

    // Change contrast of image
    float contrast = 1.5;
    float factor = (259 * (contrast * 255 + 255)) / (255 * (259 - contrast * 255));
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            image[i][j] = factor * (image[i][j] - 128) + 128;
            if(image[i][j] < 0) {
                image[i][j] = 0;
            } else if(image[i][j] > max_value) {
                image[i][j] = max_value;
            }
        }
    }

    // Write output image
    FILE *output_image = fopen("output_image.pgm", "w");
    fprintf(output_image, "%s\n%d %d\n%d\n", magic_number, columns, rows, max_value);
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            fprintf(output_image, "%d ", image[i][j]);
        }
        fprintf(output_image, "\n");
    }
    fclose(output_image);

    return 0;
}