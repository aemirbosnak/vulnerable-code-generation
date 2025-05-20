//FormAI DATASET v1.0 Category: Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Exit Puzzle Game!\n");
    printf("Simply navigate through the maze to reach the exit point.\n");

    // Generate random maze
    srand(time(NULL));
    int maze[5][5];
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            maze[i][j] = rand() % 2;
        }
    }

    int x = 0, y = 0; // Start position
    int exitX = 4, exitY = 4; // Exit position
    int movesCount = 0;

    printf("Maze:\n");
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(i == x && j == y) {
                printf("S"); // Start position
            } else if(i == exitX && j == exitY) {
                printf("E"); // Exit position
            } else if(maze[i][j] == 1) {
                printf("#"); // Wall
            } else {
                printf(" "); // Empty path
            }
        }
        printf("\n");
    }

    while(x != exitX || y != exitY) {
        printf("Enter your move (u=up, d=down, l=left, r=right): ");
        char move;
        scanf(" %c", &move);

        switch(move) {
            case 'u':
                if(x > 0 && maze[x-1][y] != 1) { // Check if there is no wall
                    x--;
                } else {
                    printf("Invalid move!\n");
                    continue;
                }
                break;
            case 'd':
                if(x < 4 && maze[x+1][y] != 1) { // Check if there is no wall
                    x++;
                } else {
                    printf("Invalid move!\n");
                    continue;
                }
                break;
            case 'l':
                if(y > 0 && maze[x][y-1] != 1) { // Check if there is no wall
                    y--;
                } else {
                    printf("Invalid move!\n");
                    continue;
                }
                break;
            case 'r':
                if(y < 4 && maze[x][y+1] != 1) { // Check if there is no wall
                    y++;
                } else {
                    printf("Invalid move!\n");
                    continue;
                }
                break;
            default:
                printf("Invalid move!\n");
                continue;
        }

        movesCount++;
        printf("Moves made: %d\n", movesCount);

        printf("Maze:\n");
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                if(i == x && j == y) {
                    printf("S"); // Start position
                } else if(i == exitX && j == exitY) {
                    printf("E"); // Exit position
                } else if(maze[i][j] == 1) {
                    printf("#"); // Wall
                } else {
                    printf(" "); // Empty path
                }
            }
            printf("\n");
        }
    }

    printf("Congratulations! You reached the exit with %d moves.\n", movesCount);

    return 0;
}