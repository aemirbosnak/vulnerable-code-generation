//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 10
#define PATTERN_SIZE 11
#define PATTERN "*0123456789#"

void print_pattern(int x, int y) {
    int i, j;
    char pattern[PATTERN_SIZE];

    for (i = 0; i < PATTERN_SIZE; i++) {
        pattern[i] = PATTERN[i];
    }

    pattern[PATTERN_SIZE] = '\0';

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if ((i == 0 || i == HEIGHT - 1) || (j == 0 || j == WIDTH - 1)) {
                printf("%s", pattern);
            } else {
                printf("%c", pattern[rand() % PATTERN_SIZE]);
            }
        }
        printf("\n");
    }

    usleep(100000); // Delay between each pattern print
}

int main() {
    int x, y;
    int i, j;

    srand(time(NULL));

    for (i = 0; i < 10; i++) {
        x = rand() % (WIDTH / 2) * 2 + WIDTH / 4;
        y = rand() % (HEIGHT / 2) * 2 + HEIGHT / 4;

        print_pattern(x, y);
    }

    return 0;
}