//Falcon-180B DATASET v1.0 Category: Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int maze[MAX_ROWS][MAX_COLS] = {0};
int startRow, startCol, endRow, endCol;

void generateMaze(int row, int col) {
    int randomRow, randomCol;
    int count = 0;
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    if (row < 0 || row >= MAX_ROWS || col < 0 || col >= MAX_COLS)
        return;

    if (maze[row][col]!= 0)
        return;

    maze[row][col] = 1;
    count++;

    while (count < 5) {
        srand(time(NULL));
        randomRow = rand() % MAX_ROWS;
        randomCol = rand() % MAX_COLS;

        if (maze[randomRow][randomCol] == 0) {
            maze[randomRow][randomCol] = 1;
            count++;
        }
    }
}

void printMaze() {
    int i, j;

    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (maze[i][j] == 1)
                printf("X ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

int main() {
    int i, j;

    printf("Enter start row and column: ");
    scanf("%d%d", &startRow, &startCol);
    printf("Enter end row and column: ");
    scanf("%d%d", &endRow, &endCol);

    generateMaze(startRow, startCol);
    generateMaze(endRow, endCol);

    printMaze();

    return 0;
}