//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define PIXEL_SIZE 3

char screen[WIDTH][HEIGHT];

void init_screen() {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            screen[i][j] = ' ';
        }
    }
}

void draw_pixel(int x, int y) {
    int i, j;
    for (i = x*PIXEL_SIZE; i < (x+1)*PIXEL_SIZE; i++) {
        for (j = y*PIXEL_SIZE; j < (y+1)*PIXEL_SIZE; j++) {
            screen[i][j] = '*';
        }
    }
}

void print_screen() {
    int i, j;
    for (j = 0; j < HEIGHT*PIXEL_SIZE; j++) {
        for (i = 0; i < WIDTH*PIXEL_SIZE; i++) {
            printf("%c ", screen[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int n = WIDTH*HEIGHT/5; // number of pixels
    int i;
    for (i = 0; i < n; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        draw_pixel(x, y);
    }
    print_screen();
    return 0;
}