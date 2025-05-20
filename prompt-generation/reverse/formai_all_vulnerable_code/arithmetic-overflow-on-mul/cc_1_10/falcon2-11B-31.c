//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: Cyberpunk
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 1000
#define PI 3.14159265358979323846
#define MIN_X -1.5
#define MIN_Y -1.5
#define MAX_X 1.5
#define MAX_Y 1.5
#define STEP 0.005
#define NUM_ITERATIONS 200
#define SCALE 1.5
#define COLOR_RED 0xFF0000
#define COLOR_GREEN 0x00FF00
#define COLOR_BLUE 0x0000FF
int main(int argc, char *argv[]) {
    int width, height, i, j, k;
    int red, green, blue;
    int x, y;
    char buffer[MAX_SIZE];
    srand(time(NULL));
    printf("Generating Fractal...\n");
    width = MAX_X - MIN_X;
    height = MAX_Y - MIN_Y;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            red = 0;
            green = 0;
            blue = 0;
            x = (double) i * SCALE + MIN_X;
            y = (double) j * SCALE + MIN_Y;
            for (k = 0; k < NUM_ITERATIONS; k++) {
                x = x * x - y * y + MIN_X;
                y = 2 * x * y + MIN_Y;
            }
            if (x >= MIN_X && x <= MAX_X && y >= MIN_Y && y <= MAX_Y) {
                red = 255;
                green = 0;
                blue = 0;
            } else {
                red = 0;
                green = 255;
                blue = 0;
            }
            printf("%d %d %d\n", red, green, blue);
        }
    }
    printf("Fractal generated!\n");
    return 0;
}