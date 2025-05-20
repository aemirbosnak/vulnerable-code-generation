//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100
#define PI 3.14159265358979323846

int main() {

    int image[MAX][MAX], new_image[MAX][MAX], width, height, x, y, choice;
    float contrast, brightness;

    printf("Enter the width of the image: ");
    scanf("%d", &width);

    printf("Enter the height of the image: ");
    scanf("%d", &height);

    printf("Enter the contrast value (between 0 and 2): ");
    scanf("%f", &contrast);

    printf("Enter the brightness value (between -1 and 1): ");
    scanf("%f", &brightness);

    printf("Enter 1 to enter image values manually or 2 to read from a file: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter image values:\n");
        for (x = 0; x < width; x++) {
            for (y = 0; y < height; y++) {
                scanf("%d", &image[x][y]);
            }
        }
    } else if (choice == 2) {
        // read image from file
    }

    // apply contrast
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            new_image[x][y] = (int) (255 * ((image[x][y] - 127) * contrast + 127));
        }
    }

    // apply brightness
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            new_image[x][y] += (int) (brightness * (new_image[x][y] - 127));
        }
    }

    // flip image horizontally
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            new_image[x][y] = image[width - x - 1][y];
        }
    }

    printf("Original image:\n");
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            printf("%d ", image[x][y]);
        }
        printf("\n");
    }

    printf("New image:\n");
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            printf("%d ", new_image[x][y]);
        }
        printf("\n");
    }

    return 0;
}