//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printPixel(char pixel[3][3]) {
    printf("%c%c%c\n%c%c%c\n%c%c%c\n", pixel[0][0], pixel[0][1], pixel[0][2],
                                        pixel[1][0], pixel[1][1], pixel[1][2],
                                        pixel[2][0], pixel[2][1], pixel[2][2]);
}

void generatePixel(int color, char pixel[3][3]) {
    switch(color) {
        case 0: // Black pixel
            pixel[0][0] = ' ';
            pixel[0][1] = ' ';
            pixel[0][2] = ' ';
            pixel[1][0] = ' ';
            pixel[1][1] = 'X';
            pixel[1][2] = ' ';
            pixel[2][0] = ' ';
            pixel[2][1] = ' ';
            pixel[2][2] = ' ';
            break;
        case 1: // Red pixel
            pixel[0][0] = ' ';
            pixel[0][1] = '_';
            pixel[0][2] = ' ';
            pixel[1][0] = '|';
            pixel[1][1] = 'X';
            pixel[1][2] = '|';
            pixel[2][0] = '|';
            pixel[2][1] = '_';
            pixel[2][2] = '|';
            break;
        case 2: // Green pixel
            pixel[0][0] = ' ';
            pixel[0][1] = '_';
            pixel[0][2] = ' ';
            pixel[1][0] = '|';
            pixel[1][1] = ' ';
            pixel[1][2] = '|';
            pixel[2][0] = '|';
            pixel[2][1] = '_';
            pixel[2][2] = '|';
            break;
        case 3: // Blue pixel
            pixel[0][0] = 'X';
            pixel[0][1] = '_';
            pixel[0][2] = 'X';
            pixel[1][0] = '|';
            pixel[1][1] = 'X';
            pixel[1][2] = '|';
            pixel[2][0] = '|';
            pixel[2][1] = '_';
            pixel[2][2] = '|';
            break;
    }
}

int main() {
    srand(time(NULL)); // Seed the random generator with the current time
    int width, height;
    printf("Enter pixel art width: ");
    scanf("%d", &width);
    printf("Enter pixel art height: ");
    scanf("%d", &height);
    char pixel[3][3]; // 3x3 pixel grid
    int color;
    for(int h=0; h<height; h++) {
        for(int w=0; w<width; w++) {
            color = rand() % 4; // Generate random color between 0-3 (inclusive)
            generatePixel(color, pixel);
            printPixel(pixel);
        }
        printf("\n"); // New line after each row
    }
    return 0;
}