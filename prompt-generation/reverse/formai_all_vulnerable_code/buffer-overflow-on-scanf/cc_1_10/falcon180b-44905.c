//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_COLORS 10

enum color {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    ORANGE,
    PURPLE,
    BLACK,
    WHITE,
    GREY,
    BROWN
};

void print_pattern(int pattern[MAX_SIZE][MAX_SIZE], int size, enum color foreground, enum color background) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("\e[38;5;%dm\e[48;5;%dm ", foreground, background);
        }
        printf("\n");
    }
}

int main() {
    int pattern[MAX_SIZE][MAX_SIZE] = {{0}};
    int size = 0;
    enum color foreground_color = RED;
    enum color background_color = WHITE;

    printf("Enter pattern size (1-100): ");
    scanf("%d", &size);

    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid pattern size!\n");
        return 1;
    }

    printf("Enter foreground color (RED, GREEN, BLUE, YELLOW, ORANGE, PURPLE, BLACK, WHITE, GREY, BROWN): ");
    scanf(" %s", &foreground_color);

    printf("Enter background color (RED, GREEN, BLUE, YELLOW, ORANGE, PURPLE, BLACK, WHITE, GREY, BROWN): ");
    scanf(" %s", &background_color);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            pattern[i][j] = rand() % 10;
        }
    }

    print_pattern(pattern, size, foreground_color, background_color);

    return 0;
}