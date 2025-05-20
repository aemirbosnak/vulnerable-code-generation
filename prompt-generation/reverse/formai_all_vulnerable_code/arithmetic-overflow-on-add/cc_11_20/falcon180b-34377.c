//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 1000
#define HEIGHT 1000

int main() {
    int image[HEIGHT][WIDTH];
    int x, y, r, g, b;
    FILE* inputFile = fopen("input.bmp", "rb");

    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Read in BMP file header
    fseek(inputFile, 54, SEEK_SET); // Skip to start of image data
    fread(&r, 1, 2, inputFile);
    fread(&g, 1, 2, inputFile);
    fread(&b, 1, 2, inputFile);

    // Convert RGB values to grayscale
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            fread(&r, 1, 1, inputFile);
            fread(&g, 1, 1, inputFile);
            fread(&b, 1, 1, inputFile);

            int gray = (r + g + b) / 3;
            image[y][x] = gray;
        }
    }

    // Apply blur filter
    for (y = 1; y < HEIGHT - 1; y++) {
        for (x = 1; x < WIDTH - 1; x++) {
            int sum = 0;
            int count = 0;

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) {
                        continue;
                    }

                    int x1 = x + i;
                    int y1 = y + j;

                    if (x1 >= 0 && x1 < WIDTH && y1 >= 0 && y1 < HEIGHT) {
                        sum += image[y1][x1];
                        count++;
                    }
                }
            }

            int avg = sum / count;
            image[y][x] = avg;
        }
    }

    // Save edited image to output file
    FILE* outputFile = fopen("output.bmp", "wb");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    fwrite(&r, 1, 2, outputFile);
    fwrite(&g, 1, 2, outputFile);
    fwrite(&b, 1, 2, outputFile);

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            fwrite(&image[y][x], 1, 1, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}