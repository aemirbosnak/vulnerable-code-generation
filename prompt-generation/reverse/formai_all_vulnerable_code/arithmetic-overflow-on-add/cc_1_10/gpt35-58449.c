//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wait(int seconds) {
    int end_time = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end_time);
}

int main() {
    srand(time(NULL));

    printf("Enter width of pixel art: ");
    int width;
    scanf("%d", &width);
    printf("Enter height of pixel art: ");
    int height;
    scanf("%d", &height);

    int pixels[width][height];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // randomly generate pixel color
            pixels[j][i] = rand() % 2;
        }
    }

    while(1) {
        // print each pixel
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (pixels[j][i] == 1) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // randomly change a pixel's color
        int random_x = rand() % width;
        int random_y = rand() % height;
        pixels[random_x][random_y] = 1 - pixels[random_x][random_y];

        // wait for a bit before refreshing
        wait(1);
        system("cls"); // clear console
    }

    return 0;
}