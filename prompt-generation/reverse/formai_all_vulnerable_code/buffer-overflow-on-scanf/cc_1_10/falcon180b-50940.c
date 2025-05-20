//Falcon-180B DATASET v1.0 Category: Educational ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

void createMaze(char maze[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }
}

void printMaze(char maze[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int checkExit(int playerRow, int playerCol, char maze[ROW][COL]) {
    if (playerRow == 0 && playerCol == COL - 1) {
        return 1;
    } else if (playerRow == ROW - 1 && playerCol == 0) {
        return 1;
    }
    return 0;
}

void movePlayer(int *playerRow, int *playerCol, char direction, char maze[ROW][COL]) {
    switch (direction) {
        case 'w':
            (*playerRow)--;
            break;
        case 'a':
            (*playerCol)--;
            break;
        case's':
            (*playerRow)++;
            break;
        case 'd':
            (*playerCol)++;
            break;
    }

    if (*playerRow < 0) {
        (*playerRow) = ROW - 1;
    } else if (*playerRow >= ROW) {
        (*playerRow) = 0;
    }

    if (*playerCol < 0) {
        (*playerCol) = COL - 1;
    } else if (*playerCol >= COL) {
        (*playerCol) = 0;
    }

    if (maze[*playerRow][*playerCol]!= '.' && maze[*playerRow][*playerCol]!= 'E') {
        (*playerRow)--;
        (*playerCol)--;
    }
}

int main() {
    srand(time(NULL));

    char maze[ROW][COL];
    createMaze(maze);

    int playerRow = 0;
    int playerCol = 0;

    while (1) {
        system("clear");
        printMaze(maze);

        char input;
        scanf("%c", &input);

        movePlayer(&playerRow, &playerCol, input, maze);

        if (checkExit(playerRow, playerCol, maze)) {
            printf("You escaped the maze!\n");
            break;
        }
    }

    return 0;
}