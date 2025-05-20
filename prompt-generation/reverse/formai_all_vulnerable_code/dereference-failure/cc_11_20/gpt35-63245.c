//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

int main() {
    char filename[MAX];
    int rows, cols, maxval;
    int i, j, k;

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the image header information.
    fscanf(fp, "P3\n%d %d\n%d\n", &cols, &rows, &maxval);

    // Allocate memory to store the image pixels.
    int **image = (int **) malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        image[i] = (int *) malloc(cols * sizeof(int));
    }

    // Read the image pixels.
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            fscanf(fp, "%d %d %d ", &image[i][j], &image[i][j+1], &image[i][j+2]);
        }
    }

    // Flip the image horizontally.
    for (i = 0; i < rows; i++) {
        for (j = 0, k = cols-1; j < k; j++, k--) {
            int temp = image[i][j];
            image[i][j] = image[i][k];
            image[i][k] = temp;
        }
    }

    // Adjust the brightness and contrast.
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            int pixel = image[i][j];
            pixel = (pixel - 128) * 2 + 128;
            if (pixel > maxval) {
                pixel = maxval;
            }
            if (pixel < 0) {
                pixel = 0;
            }
            image[i][j] = pixel;
        }
    }

    // Write the output file.
    printf("Enter the name of the output file: ");
    scanf("%s", filename);

    FILE *out = fopen(filename, "w");
    fprintf(out, "P3\n%d %d\n%d\n", cols, rows, maxval);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            fprintf(out, "%d %d %d ", image[i][j], image[i][j], image[i][j]);
        }
        fprintf(out, "\n");
    }

    fclose(fp);
    fclose(out);
    return 0;
}