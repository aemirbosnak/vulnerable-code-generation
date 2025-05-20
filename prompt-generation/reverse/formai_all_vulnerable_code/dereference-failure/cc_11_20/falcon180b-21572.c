//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 100

int main() {
    int width, height;
    FILE *file;
    char filename[100];
    int **image, **result;
    int x, y, i, j, k, l;
    float brightness, contrast;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    width = ftell(file) / (3 * sizeof(int));
    rewind(file);

    height = 0;
    while (fgetc(file)!= EOF) {
        height++;
    }

    image = (int **)malloc(height * sizeof(int *));
    for (i = 0; i < height; i++) {
        image[i] = (int *)malloc(width * sizeof(int));
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fread(&image[i][j], sizeof(int), 1, file);
        }
    }

    printf("Enter the brightness (0-100): ");
    scanf("%d", &brightness);
    printf("Enter the contrast (0-100): ");
    scanf("%d", &contrast);

    result = (int **)malloc(height * sizeof(int *));
    for (i = 0; i < height; i++) {
        result[i] = (int *)malloc(width * sizeof(int));
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            k = image[i][j] * contrast / 100 + brightness;
            if (k < 0) {
                k = 0;
            } else if (k > 255) {
                k = 255;
            }
            result[i][j] = k;
        }
    }

    printf("Enter the output filename: ");
    scanf("%s", filename);

    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: File could not be created.\n");
        return 1;
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fwrite(&result[i][j], sizeof(int), 1, file);
        }
    }

    fclose(file);
    return 0;
}