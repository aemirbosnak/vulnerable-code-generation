//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, c, i, j, pixel, color;
    char **image;

    // Allocate memory for the image
    image = (char**)malloc(10 * sizeof(char*));
    for (r = 0; r < 10; r++) {
        image[r] = (char*)malloc(20 * sizeof(char));
    }

    // Get the image data
    printf("Enter the number of rows and columns for the image: ");
    scanf("%d %d", &r, &c);

    printf("Enter the pixel values (separated by commas): ");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d ", &pixel);
            image[i][j] = pixel;
        }
    }

    // Convert the image to ASCII art
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            color = image[i][j];
            switch (color) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(". ");
                    break;
                case 2:
                    printf("* ");
                    break;
                case 3:
                    printf("# ");
                    break;
            }
        }
        printf("\n");
    }

    // Free the memory
    for (r = 0; r < 10; r++) {
        free(image[r]);
    }
    free(image);

    return 0;
}