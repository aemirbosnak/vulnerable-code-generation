//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: artistic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Function to generate fractal image
void fractal(int x1, int y1, int x2, int y2, int depth) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int s = (int) sqrt(dx*dx + dy*dy);

    if (depth == 0) {
        printf("*");
    }
    else {
        // Recursively divide the line segment into four parts
        int x3 = x1 + dx/2;
        int y3 = y1 + dy/2;
        int x4 = x2 - dx/2;
        int y4 = y2 - dy/2;
        fractal(x1, y1, x3, y3, depth-1);
        fractal(x3, y3, x4, y4, depth-1);
        fractal(x4, y4, x2, y2, depth-1);
        fractal(x3, y3, x2, y2, depth-1);
    }
}

int main() {
    srand(time(0));

    // Get user input for fractal depth and size
    int depth;
    printf("Enter fractal depth: ");
    scanf("%d", &depth);

    int size;
    printf("Enter fractal size: ");
    scanf("%d", &size);

    // Generate fractal image
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            int x1 = i*size/2 - size/2;
            int y1 = j*size/2 - size/2;
            int x2 = i*size/2 + size/2;
            int y2 = j*size/2 + size/2;
            fractal(x1, y1, x2, y2, depth);
        }
        printf("\n");
    }

    return 0;
}