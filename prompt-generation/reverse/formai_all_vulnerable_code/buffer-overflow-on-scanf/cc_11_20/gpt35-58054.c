//FormAI DATASET v1.0 Category: Game ; Style: high level of detail
#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

int main() {
    int width = 10;
    int height = 10;
    char grid[height][width];
    Point playerPos = {0, 0};
    Point treasurePos = {9, 9};

    // initialize the grid
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x] = '-';
        }
    }
    // place the player and treasure
    grid[playerPos.y][playerPos.x] = 'P';
    grid[treasurePos.y][treasurePos.x] = '$';

    while (playerPos.x != treasurePos.x || playerPos.y != treasurePos.y) {
        // display the grid
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                printf("%c ", grid[y][x]);
            }
            printf("\n");
        }

        // get input from user
        char input;
        printf("Enter direction (W/A/S/D): ");
        scanf(" %c", &input);

        // move the player
        if (input == 'W' && playerPos.y > 0) {
            grid[playerPos.y][playerPos.x] = '-';
            playerPos.y--;
            grid[playerPos.y][playerPos.x] = 'P';
        } else if (input == 'A' && playerPos.x > 0) {
            grid[playerPos.y][playerPos.x] = '-';
            playerPos.x--;
            grid[playerPos.y][playerPos.x] = 'P';
        } else if (input == 'S' && playerPos.y < height - 1) {
            grid[playerPos.y][playerPos.x] = '-';
            playerPos.y++;
            grid[playerPos.y][playerPos.x] = 'P';
        } else if (input == 'D' && playerPos.x < width - 1) {
            grid[playerPos.y][playerPos.x] = '-';
            playerPos.x++;
            grid[playerPos.y][playerPos.x] = 'P';
        }
    }

    // player reached the treasure!
    printf("You found the treasure!\n");

    return 0;
}