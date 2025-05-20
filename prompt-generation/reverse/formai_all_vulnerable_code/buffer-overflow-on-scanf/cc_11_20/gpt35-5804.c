//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare necessary variables
    int width, height, color;
    char pixel;

    // Prompt user to enter values
    printf("Enter the Width of the image: ");
    scanf("%d", &width);
    printf("Enter the Height of the image: ");
    scanf("%d", &height);

    // Create a 2D array to store pixel colors
    int image[height][width];

    // Generate random pixel colors for each position in the array
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            color = rand() % 256;
            image[i][j] = color;
        }
    }

    // Convert the pixel colors to ASCII characters for display
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(image[i][j] <= 25) {
                pixel = '#';
            } else if(image[i][j] <= 50) {
                pixel = '&';
            } else if(image[i][j] <= 75) {
                pixel = '$';
            } else if(image[i][j] <= 100) {
                pixel = '%';
            } else if(image[i][j] <= 125) {
                pixel = '*';
            } else if(image[i][j] <= 150) {
                pixel = 'o';
            } else if(image[i][j] <= 175) {
                pixel = '|';
            } else if(image[i][j] <= 200) {
                pixel = '=';
            } else if(image[i][j] <= 225) {
                pixel = ':';
            } else {
                pixel = ' ';
            }
            printf("%c", pixel);
        }
        printf("\n");
    }

    return 0;
}