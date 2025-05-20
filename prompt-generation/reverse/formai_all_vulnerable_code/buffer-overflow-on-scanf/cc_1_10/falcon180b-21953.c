//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print the ASCII art
void print_ascii_art(int width, int height, char image[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (image[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int width, height;
    char image[100][100];

    // Get the dimensions of the image
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);

    // Get the pixel values of the image
    printf("Enter the pixel values of the image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%c", &image[i][j]);
        }
    }

    // Convert the image to ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (image[i][j] == '0' || image[i][j] == '1' || image[i][j] == '2' || image[i][j] == '3' || image[i][j] == '4' || image[i][j] == '5' || image[i][j] == '6' || image[i][j] == '7' || image[i][j] == '8' || image[i][j] == '9') {
                image[i][j] = '0';
            }
        }
    }

    // Print the ASCII art
    print_ascii_art(width, height, image);

    return 0;
}