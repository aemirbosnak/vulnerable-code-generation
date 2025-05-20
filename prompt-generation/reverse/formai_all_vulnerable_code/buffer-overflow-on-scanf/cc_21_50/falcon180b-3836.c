//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {
    srand(time(NULL));
    int maze[ROWS][COLS];
    int playerRow = 0;
    int playerCol = 0;

    // Generate maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ((i == 0 && j == 0) || (i == ROWS - 1 && j == COLS - 1) || (i == 0 && j == COLS - 1) || (i == ROWS - 1 && j == 0)) {
                maze[i][j] = 1;
            } else {
                maze[i][j] = rand() % 2;
            }
        }
    }

    // Print maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf("# ");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Move player
    while (1) {
        system("clear");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (maze[i][j] == 1) {
                    printf("# ");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("Player: %d, %d\n", playerRow, playerCol);

        char move;
        scanf("%c", &move);
        switch (move) {
            case 'w':
                if (playerRow > 0 && maze[playerRow - 1][playerCol] == 0) {
                    playerRow--;
                }
                break;
            case's':
                if (playerRow < ROWS - 1 && maze[playerRow + 1][playerCol] == 0) {
                    playerRow++;
                }
                break;
            case 'a':
                if (playerCol > 0 && maze[playerRow][playerCol - 1] == 0) {
                    playerCol--;
                }
                break;
            case 'd':
                if (playerCol < COLS - 1 && maze[playerRow][playerCol + 1] == 0) {
                    playerCol++;
                }
                break;
            default:
                printf("Invalid move\n");
        }
    }

    return 0;
}