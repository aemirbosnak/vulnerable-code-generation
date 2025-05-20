//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 50
#define MAX_VALUE 255

int main() {
    int width, height, max_value;
    FILE *fp;
    char filename[50];
    int **image;
    int *ascii_art;
    int i, j, k, value;

    // Get input from user
    printf("Enter the image filename: ");
    scanf("%s", filename);
    printf("Enter the image width: ");
    scanf("%d", &width);
    printf("Enter the image height: ");
    scanf("%d", &height);
    printf("Enter the maximum value: ");
    scanf("%d", &max_value);

    // Open the image file
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open image file.\n");
        exit(1);
    }

    // Read the image data
    image = (int **)malloc(height * sizeof(int *));
    for (i = 0; i < height; i++) {
        image[i] = (int *)malloc(width * sizeof(int));
        fread(image[i], sizeof(int), width, fp);
    }
    fclose(fp);

    // Convert the image to ASCII art
    ascii_art = (int *)malloc(height * WIDTH * sizeof(int));
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            value = image[i][j] * MAX_VALUE / max_value;
            ascii_art[i * WIDTH + j] = value;
        }
    }

    // Print the ASCII art
    for (i = 0; i < height; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (ascii_art[i * WIDTH + j] == 0) {
                printf(" ");
            } else {
                printf("%c", 219 - ascii_art[i * WIDTH + j]);
            }
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);
    free(ascii_art);

    return 0;
}