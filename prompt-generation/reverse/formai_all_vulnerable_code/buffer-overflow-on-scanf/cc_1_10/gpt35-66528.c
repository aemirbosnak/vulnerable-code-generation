//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

/* Function to generate random RGB values */
void generateRGB(int *r, int *g, int *b) {
    *r = rand() % 256;
    *g = rand() % 256;
    *b = rand() % 256;
}

/* Function to create pixel art image */
void createPixelArt(char pixelArt[][HEIGHT][3], int numColors) {
    int r, g, b;
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            int colorIndex = rand() % numColors;
            generateRGB(&r, &g, &b);
            for (int k = 0; k < 3; k++) {
                pixelArt[i][j][k] = (char) ((colorIndex == 0 ? r : (colorIndex == 1 ? g : b)) & 0xff);
            }
        }
    }
}

/* Function to print pixel art image */
void printPixelArt(char pixelArt[][HEIGHT][3]) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%c%c%c  ", pixelArt[i][j][0], pixelArt[i][j][1], pixelArt[i][j][2]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    
    int numColors;
    printf("Enter number of colors (1-3): ");
    scanf("%d", &numColors);
    
    char pixelArt[WIDTH][HEIGHT][3];
    createPixelArt(pixelArt, numColors);
    printPixelArt(pixelArt);
    
    return 0;
}