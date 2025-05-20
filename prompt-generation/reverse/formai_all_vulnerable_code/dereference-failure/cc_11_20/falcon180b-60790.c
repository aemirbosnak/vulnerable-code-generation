//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define HEIGHT 100
#define WIDTH 100

int main(int argc, char *argv[]) {
    int **image = malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        image[i] = malloc(WIDTH * sizeof(int));
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = rand() % 256;
        }
    }

    int **result = malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        result[i] = malloc(WIDTH * sizeof(int));
        for (int j = 0; j < WIDTH; j++) {
            result[i][j] = image[i][j];
        }
    }

    // Flip the image
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH / 2; j++) {
            int temp = result[i][j];
            result[i][j] = result[i][WIDTH - 1 - j];
            result[i][WIDTH - 1 - j] = temp;
        }
    }

    // Change brightness and contrast
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            result[i][j] += 50;
            result[i][j] *= 2;
        }
    }

    // Save the result
    FILE *output = fopen("result.txt", "w");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fprintf(output, "%d ", result[i][j]);
        }
        fprintf(output, "\n");
    }
    fclose(output);

    for (int i = 0; i < HEIGHT; i++) {
        free(image[i]);
        free(result[i]);
    }
    free(image);
    free(result);

    return 0;
}