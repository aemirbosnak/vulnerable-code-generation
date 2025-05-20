//FormAI DATASET v1.0 Category: Image Editor ; Style: energetic
// Welcome to the Energized Image Editor!

#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1000

int main()
{
    int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], n, m, i, j, brightness;

    printf("Enter the height and width of the image (n x m): ");
    scanf("%d %d", &n, &m);

    // Populate the image with random brightness values
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            image[i][j] = rand() % 256;
        }
    }

    printf("\nOriginal Image:\n");

    // Display the original image
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Increase the brightness of the image by a factor of 2
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            brightness = image[i][j] * 2;
            if (brightness > 255) {
                brightness = 255;
            }
            image[i][j] = brightness;
        }
    }

    printf("\nBrightened Image:\n");

    // Display the modified image
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}