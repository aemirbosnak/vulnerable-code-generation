//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// function to flip image horizontally
void flip_horizontal(int **image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// function to change image brightness
void change_brightness(int **image, int width, int height, int factor) {
    int adjusted_factor = (factor >= 0) ? factor + 1 : 1.0 / (-factor + 1);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_value = image[i][j] * adjusted_factor;
            if (new_value > 255) {
                image[i][j] = 255;
            } else {
                image[i][j] = new_value;
            }
        }
    }
}

int main() {
    printf("Enter image width: ");
    int width;
    scanf("%d", &width);

    printf("Enter image height: ");
    int height;
    scanf("%d", &height);

    // allocate memory for image
    int **image = (int **) malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        image[i] = (int *) malloc(sizeof(int) * width);
    }

    printf("Enter image data:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    printf("Enter brightness factor (positive or negative integer): ");
    int factor;
    scanf("%d", &factor);

    printf("Original image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    flip_horizontal(image, width, height);
    printf("Horizontally flipped image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    change_brightness(image, width, height, factor);
    printf("Brightness adjusted image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // free memory
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}