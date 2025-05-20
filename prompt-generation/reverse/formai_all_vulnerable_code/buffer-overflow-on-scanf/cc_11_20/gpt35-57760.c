//FormAI DATASET v1.0 Category: Game ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    int x, y;
} Coordinate;

int main()
{
    // initialize variables
    int width = 10, height = 10, numBombs = 10, numUncovered = 0;
    bool gameOver = false;
    char display[height][width]; // display array for the UI
    memset(display, '*', sizeof(display[0][0]) * width * height); // fill with '*'
    bool bombs[height][width]; // bombs array to store locations of bombs
    memset(bombs, false, sizeof(bombs[0][0]) * width * height); // fill with false
    Coordinate neighbors[] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };
    
    // randomly place bombs
    srand(time(NULL)); // seed the random number generator
    int i = 0;
    while (i < numBombs) {
        int x = rand() % width;
        int y = rand() % height;
        if (!bombs[y][x]) {
            bombs[y][x] = true;
            i++;
        }
    }
    
    // game loop, runs until user either uncovers all non-bomb tiles or detonates a bomb
    while (!gameOver) {
        // print game board
        printf(" ");
        for (int x = 0; x < width; x++) {
            printf("%d", x);
        }
        printf("\n");
        for (int y = 0; y < height; y++) {
            printf("%d", y);
            for (int x = 0; x < width; x++) {
                printf("%c", display[y][x]);
            }
            printf("\n");
        }
        
        // get user input
        int x, y;
        printf("Enter coordinates: ");
        scanf("%d %d", &x, &y);
        if (x < 0 || x >= width || y < 0 || y >= height) {
            printf("Invalid input!\n");
            continue;
        }
        if (bombs[y][x]) {
            // user detonated a bomb, game over
            printf("BOOM! You lose!\n");
            gameOver = true;
        } else if (display[y][x] != '*') {
            // user already uncovered this tile, ignore
            printf("Tile already uncovered!\n");
        } else {
            // user uncovered a tile, update display and count uncovered tiles
            int numAdjacentBombs = 0;
            for (int i = 0; i < sizeof(neighbors)/sizeof(neighbors[0]); i++) {
                Coordinate neighbor = neighbors[i];
                if (x + neighbor.x >= 0 && x + neighbor.x < width &&
                    y + neighbor.y >= 0 && y + neighbor.y < height &&
                    bombs[y + neighbor.y][x + neighbor.x]) {
                    numAdjacentBombs++;
                }
            }
            display[y][x] = '0' + numAdjacentBombs; // convert int to char for display
            numUncovered++;
            if (numUncovered == width * height - numBombs) {
                // user uncovered all non-bomb tiles, game over
                printf("Congratulations, you win!\n");
                gameOver = true;
            }
        }
    }
    
    return 0;
}