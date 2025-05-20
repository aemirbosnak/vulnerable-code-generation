//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 10

void print_heart(int x, int y) {
    char heart[HEIGHT][WIDTH + 2];

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH + 2; j++) {
            if (j == 0 || j == WIDTH + 1 || i == 0 || i == HEIGHT - 1) {
                heart[i][j] = '*';
            } else if (i < HEIGHT / 2 && j < WIDTH / 2 + 1 || i > HEIGHT / 2 && j > WIDTH / 2 - 1) {
                heart[i][j] = 'x';
            } else {
                heart[i][j] = ' ';
            }
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH + 2; j++) {
            putchar(heart[i][j]);
            if (j == WIDTH) {
                putchar('\n');
            }
        }
    }

    for (int i = 0; i < HEIGHT / 2 + 1; i++) {
        sleep(1);
        printf("\033[%d;%dH", y + i, x);
        for (int j = 0; j < WIDTH + 2; j++) {
            putchar(heart[HEIGHT - i - 1][j]);
        }
    }
}

int main() {
    int x, y;
    printf("Enter the x and y coordinates: ");
    scanf("%d%d", &x, &y);

    printf("\033[%d;%dH", y, x);
    puts("Press Ctrl+C to exit...");

    while (1) {
        print_heart(x, y);
        sleep(5);
    }

    return 0;
}