//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Set pixel color
void setPixel(int x, int y, int color) {
    printf("\x1B[48;2;%d;%d;%dm ", color, color, color);
}

// Generate random color
int getRandomColor() {
    return rand() % 6 + 1;
}

// Generate fractal pattern
void fractal(int x, int y, int size, int depth) {
    if(depth == 0) {
        setPixel(x, y, getRandomColor());
        return;
    }
    int newSize = size / 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            fractal(x + i * newSize, y + j * newSize, newSize, depth - 1);
        }
    }
}

// Generate random pattern
void randomPattern(int x, int y, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            setPixel(x + i, y + j, getRandomColor());
        }
    }
}

int main() {
    srand(time(NULL));
    int width, height, patternType;
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    printf("Enter the type of pattern (1 for fractal, 2 for random): ");
    scanf("%d", &patternType);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(patternType == 1) {
                fractal(j, i, width, 5);
            } else if(patternType == 2) {
                randomPattern(j, i, width);
            }
        }
    }
    return 0;
}