//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS];
int playerRow, playerCol;

void generateMaze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }
    playerRow = rand() % ROWS;
    playerCol = rand() % COLS;
    maze[playerRow][playerCol] = '@';
}

void printMaze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int move(int dir) {
    int newRow = playerRow, newCol = playerCol;

    switch (dir) {
        case 0: // up
            if (playerRow > 0 && maze[playerRow - 1][playerCol]!= '#') {
                newRow--;
            }
            break;
        case 1: // right
            if (playerCol < COLS - 1 && maze[playerRow][playerCol + 1]!= '#') {
                newCol++;
            }
            break;
        case 2: // down
            if (playerRow < ROWS - 1 && maze[playerRow + 1][playerCol]!= '#') {
                newRow++;
            }
            break;
        case 3: // left
            if (playerCol > 0 && maze[playerRow][playerCol - 1]!= '#') {
                newCol--;
            }
            break;
    }

    if (newRow!= playerRow || newCol!= playerCol) {
        maze[playerRow][playerCol] = '.';
        maze[newRow][newCol] = '@';
        playerRow = newRow;
        playerCol = newCol;
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    generateMaze();
    printMaze();

    int choice;
    while (1) {
        printf("Enter your move (0-3): ");
        scanf("%d", &choice);

        if (move(choice)) {
            printMaze();
        } else {
            printf("Invalid move!\n");
        }
    }

    return 0;
}