//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to generate random color
void generateColor(int *r, int *g, int *b) {
    *r = rand() % 256;
    *g = rand() % 256;
    *b = rand() % 256;
}

// Function to generate fractal tree
void fractalTree(int x, int y, int depth, int angle, int branchLen, int *color) {
    if (depth == 0) {
        printf("*");
        return;
    }

    int newX = x + branchLen * cos(angle * PI / 180);
    int newY = y + branchLen * sin(angle * PI / 180);

    fractalTree(newX, newY, depth - 1, angle - 30, branchLen * 0.7, color);
    fractalTree(newX, newY, depth - 1, angle + 30, branchLen * 0.7, color);
}

int main() {
    srand(time(NULL));

    int width, height, maxDepth;
    printf("Enter the width of the image (in pixels): ");
    scanf("%d", &width);
    printf("Enter the height of the image (in pixels): ");
    scanf("%d", &height);
    printf("Enter the maximum depth of the tree: ");
    scanf("%d", &maxDepth);

    int *color = malloc(sizeof(int) * 3);
    generateColor(color, color + 1, color + 2);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fractalTree(j, i, maxDepth, rand() % 360, 100, color);
        }
    }

    free(color);

    return 0;
}