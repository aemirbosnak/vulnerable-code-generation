//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int width, height, max_iterations;
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    int *image = (int *)malloc(width * height * sizeof(int));

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int iterations = rand() % max_iterations;
            int c = 0;

            for (int i = 0; i < iterations; ++i) {
                int dx = rand() % 3 - 1;
                int dy = rand() % 3 - 1;
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0) {
                    nx = -nx;
                }
                if (ny < 0) {
                    ny = -ny;
                }

                if (nx >= width) {
                    nx = 2 * width - nx - 1;
                }
                if (ny >= height) {
                    ny = 2 * height - ny - 1;
                }

                int r = rand() % 2;
                if (r == 0) {
                    c += image[ny * width + nx];
                } else {
                    c -= image[ny * width + nx];
                }
            }

            image[y * width + x] = c;
        }
    }

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int value = image[y * width + x];

            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }

            printf("%d ", value);
        }
        printf("\n");
    }

    free(image);
    return 0;
}