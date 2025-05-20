//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {

    srand(time(NULL));

    int width, height, max_iterations;

    printf("Enter the width of the fractal: ");
    scanf("%d", &width);

    printf("Enter the height of the fractal: ");
    scanf("%d", &height);

    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    int **fractal = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        fractal[i] = (int *)malloc(width * sizeof(int));
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fractal[i][j] = rand() % 2;
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < max_iterations; k++) {
                int count = 0;
                int x = j - 1;
                int y = i - 1;

                while (x >= 0 && y >= 0 && x < width && y < height) {
                    if (fractal[y][x] == 1) {
                        count++;
                    }
                    x++;
                    y++;
                }

                if (count == 2 || count == 3) {
                    fractal[i][j] = 1;
                } else {
                    fractal[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (fractal[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < height; i++) {
        free(fractal[i]);
    }
    free(fractal);

    return 0;
}