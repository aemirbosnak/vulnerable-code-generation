#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 5
#define COL 5
#define BUFFER_SIZE 10

char grid[ROW][COL];
int x = 0, y = 0;

void print_grid() {
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j)
            printf("%c ", grid[i][j]);
        printf("\n");
    }
}

void set_position(char dir) {
    switch (dir) {
        case 'w': --y; break;
        case 'a': --x; break;
        case 's': ++y; break;
        case 'd': ++x; break;
        default: printf("Invalid direction.\n");
    }

    if (x < 0 || x >= COL || y < 0 || y >= ROW)
        printf("Out of bounds.\n");
    else
        grid[y][x] = 'X';
}

int main() {
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)
            grid[i][j] = '.';

    char buffer[BUFFER_SIZE];
    while (1) {
        printf("\nCurrent position: (%d, %d)\n", x, y);
        print_grid();
        printf("Enter direction: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        set_position(buffer[0]);
    }

    return 0;
}
