//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int width = 256;
    int height = 256;
    int watermark_size = 64;
    int watermark_intensity = 20;
    int watermark_pos_x = rand() % (width - watermark_size);
    int watermark_pos_y = rand() % (height - watermark_size);

    int **image = malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        image[i] = malloc(width * sizeof(int));
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = rand() % 256;
        }
    }

    for (int i = 0; i < watermark_size; i++) {
        for (int j = 0; j < watermark_size; j++) {
            int x = watermark_pos_x + i;
            int y = watermark_pos_y + j;
            if (x >= 0 && x < width && y >= 0 && y < height) {
                image[y][x] += watermark_intensity;
            }
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}