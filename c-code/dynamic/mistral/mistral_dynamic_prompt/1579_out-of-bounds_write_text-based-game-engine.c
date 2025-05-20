#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 256

void print_map(char map[][MAX_INPUT]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char map[10][MAX_INPUT];
    char input[MAX_INPUT];
    int x, y;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < MAX_INPUT; ++j) {
            map[i][j] = '.';
        }
    }

    printf("Welcome to Dungeon Crawler!\n");
    printf("Enter your move (x y): ");
    fgets(input, MAX_INPUT, stdin);
    sscanf(input, "%d %d", &x, &y);

    map[x][y] = '@';
    print_map(map);

    return 0;
}
