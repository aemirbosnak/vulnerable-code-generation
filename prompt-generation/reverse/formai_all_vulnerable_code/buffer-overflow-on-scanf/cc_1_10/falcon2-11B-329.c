//Falcon2-11B DATASET v1.0 Category: Pixel Art Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int width;
    int height;
    int color;
    int pattern;
    int x_start;
    int y_start;
} Pixel;

int main() {
    Pixel pixels[1000];
    int i, j;

    printf("Enter the width of the image: ");
    scanf("%d", &pixels[0].width);
    printf("Enter the height of the image: ");
    scanf("%d", &pixels[0].height);

    printf("Enter the color palette: ");
    scanf("%d", &pixels[0].color);

    printf("Enter the pattern: ");
    scanf("%d", &pixels[0].pattern);

    printf("Enter the starting X coordinate: ");
    scanf("%d", &pixels[0].x_start);

    printf("Enter the starting Y coordinate: ");
    scanf("%d", &pixels[0].y_start);

    for (i = 1; i < 1000; i++) {
        pixels[i].width = pixels[i-1].width;
        pixels[i].height = pixels[i-1].height;
        pixels[i].color = pixels[i-1].color;
        pixels[i].pattern = pixels[i-1].pattern;
        pixels[i].x_start = pixels[i-1].x_start;
        pixels[i].y_start = pixels[i-1].y_start;
    }

    printf("Enter the starting X coordinate: ");
    scanf("%d", &pixels[0].x_start);

    printf("Enter the starting Y coordinate: ");
    scanf("%d", &pixels[0].y_start);

    for (i = 0; i < 1000; i++) {
        for (j = 0; j < 1000; j++) {
            if (i == pixels[0].x_start && j == pixels[0].y_start) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}