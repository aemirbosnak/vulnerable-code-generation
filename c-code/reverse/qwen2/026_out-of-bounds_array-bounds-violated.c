#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define MAP_SIZE 5

void explore(int x, int y) {
    static int map[MAP_SIZE][MAP_SIZE] = {0};
    if (x >= 0 && x < MAP_SIZE && y >= 0 && y < MAP_SIZE) {
        map[x][y]++;
        printf("Exploring (%d, %d)\n", x, y);
    } else {
        printf("Out of bounds!\n");
    }
}

int main() {
    int x, y;
    while (1) {
        printf("Enter coordinates to explore (-1 -1 to quit): ");
        scanf("%d %d", &x, &y);
        if (x == -1 && y == -1) break;
        explore(x, y);
    }
    return 0;
}
