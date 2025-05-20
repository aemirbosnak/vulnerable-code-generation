//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: Donald Knuth
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 41
#define HEIGHT 11

int main() {
    char pattern[WIDTH][HEIGHT];
    int i, j, k, l, m, n, o;

    // Initialize pattern with zeros
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            pattern[i][j] = '0';
        }
    }

    // Generate pattern using Knuth's algorithm
    srand(time(NULL));

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                pattern[i][j] = '*';
                continue;
            }

            if (i % 2 == 0 && j % 2 == 0) {
                pattern[i][j] = 'o';
                continue;
            }

            k = i / 2;
            l = j / 2;

            if (k * k + l * l < (HEIGHT / 2) * (WIDTH / 2)) {
                pattern[i][j] = 'x';
                continue;
            }

            m = rand() % 2;
            n = rand() % 3;
            o = rand() % 4;

            switch (n) {
                case 0:
                    pattern[i][j] = '+';
                    break;
                case 1:
                    pattern[i][j] = '-';
                    break;
                case 2:
                    pattern[i][j] = '|';
                    break;
            }

            switch (m) {
                case 0:
                    pattern[i][j] += 'a' + (o % 4);
                    break;
                case 1:
                    pattern[i][j] += 'A' + (o % 4);
                    break;
            }
        }
    }

    // Print pattern
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", pattern[i][j]);
        }
        printf("\n");
    }

    return 0;
}