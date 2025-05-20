//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: calm
#include <stdio.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

int main() {
    int width, height, i, j;

    // Ask user for image dimensions
    printf("Enter image width: ");
    scanf("%d", &width);
    printf("Enter image height: ");
    scanf("%d", &height);

    // Check if dimensions are within limits
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: Image dimensions are too large\n");
        return 1;
    }

    // Declare and initialize image array
    int image[MAX_HEIGHT][MAX_WIDTH];
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            image[i][j] = 0;
        }
    }

    // Ask user for input image
    printf("Enter image data (0 or 1): \n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    // Flip image horizontally
    printf("\nFlipped image:\n");
    for (i = 0; i < height; i++) {
        for (j = width - 1; j >= 0; j--) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Adjust image brightness and contrast
    int brightness, contrast, adjusted;
    printf("\nEnter brightness adjustment (-255 to 255): ");
    scanf("%d", &brightness);
    printf("Enter contrast adjustment (-255 to 255): ");
    scanf("%d", &contrast);

    printf("\nAdjusted image:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            adjusted = (image[i][j] + brightness) * contrast;
            adjusted = adjusted < 0 ? 0 : adjusted > 255 ? 255 : adjusted;
            printf("%d ", adjusted);
        }
        printf("\n");
    }

    return 0;
}