//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: calm
#include <stdio.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

void read_image(char image[MAX_HEIGHT][MAX_WIDTH], int *height, int *width) {
    printf("Enter image height and width: ");
    scanf("%d %d", height, width);

    printf("Enter image pixels:\n");
    for (int i = 0; i < *height; ++i) {
        for (int j = 0; j < *width; ++j) {
            scanf(" %c", &image[i][j]);
        }
    }
}

void convert_image_to_ascii(char image[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    char ascii_art[10][10] = { 
        {' ', ' ', ' ', '_', '_', '_', '_', '_', ' ', ' '}, 
        {' ', ' ', '/', '_', '_', '_', '_', '_', '\\', ' '}, 
        {' ', '/', ' ', ' ', ' ', ' ', ' ', ' ', '\\', ' '}, 
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' '}, 
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' '}, 
        {'\\', '_', '_', '_', '_', '_', '_', '_', '/', ' '}, 
        {' ', '\\', ' ', '_', '_', '_', '_', '/', ' ', ' '}, 
        {' ', ' ', '\\', '_', '_', '_', '/', ' ', ' ', ' '}, 
        {' ', ' ', ' ', '\\', ' ', '/', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', '\\', '/', ' ', ' ', ' ', ' '}, 
    };

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int shading = (255 - (int)image[i][j]) / 26;
            printf("\033[48;5;%dm%c", shading + 232, ascii_art[i % 10][j % 10]);
        }
        printf("\033[0m\n");
    }
}

int main() {
    char image[MAX_HEIGHT][MAX_WIDTH];
    int height, width;

    read_image(image, &height, &width);

    convert_image_to_ascii(image, height, width);

    return 0;
}