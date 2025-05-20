//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

Point maze[100][100];
int wall[100][100];
int start[2];
int end[2];

void generateMaze() {
    int i, j;
    int startX, startY, endX, endY;
    srand(time(NULL));

    startX = rand() % 10;
    startY = rand() % 10;
    endX = rand() % 10;
    endY = rand() % 10;

    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            maze[i][j].x = j;
            maze[i][j].y = i;
            wall[i][j] = 1;
        }
    }

    wall[startY][startX] = 0;
    wall[endY][endX] = 0;

    start[0] = startX;
    start[1] = startY;
    end[0] = endX;
    end[1] = endY;
}

void printMaze() {
    int i, j;

    printf("Maze:\n");
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            printf("%d ", wall[i][j]);
        }
        printf("\n");
    }
}

void printStartAndEnd() {
    int i, j;

    printf("Start: (%d, %d)\n", start[0], start[1]);
    printf("End: (%d, %d)\n", end[0], end[1]);
}

void printMove(int moveX, int moveY) {
    int i, j;

    printf("Move: (%d, %d)\n", moveX, moveY);
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            if (wall[i][j] == 0) {
                printf("  ");
            } else {
                printf("%d ", wall[i][j]);
            }
        }
        printf("\n");
    }
}

void movePlayer(int moveX, int moveY) {
    int i, j;

    if (moveX == -1 && moveY == 0) {
        if (wall[maze[start[1]][start[0]].x - 1][maze[start[1]][start[0]].y] == 1) {
            printf("You can't go that way!\n");
        } else {
            maze[start[1]][start[0]].x -= 1;
            printf("You moved one step to the left.\n");
        }
    } else if (moveX == 1 && moveY == 0) {
        if (wall[maze[start[1]][start[0]].x + 1][maze[start[1]][start[0]].y] == 1) {
            printf("You can't go that way!\n");
        } else {
            maze[start[1]][start[0]].x += 1;
            printf("You moved one step to the right.\n");
        }
    } else if (moveY == -1 && moveX == 0) {
        if (wall[maze[start[1]][start[0]].x][maze[start[1]][start[0]].y - 1] == 1) {
            printf("You can't go that way!\n");
        } else {
            maze[start[1]][start[0]].y -= 1;
            printf("You moved one step down.\n");
        }
    } else if (moveY == 1 && moveX == 0) {
        if (wall[maze[start[1]][start[0]].x][maze[start[1]][start[0]].y + 1] == 1) {
            printf("You can't go that way!\n");
        } else {
            maze[start[1]][start[0]].y += 1;
            printf("You moved one step up.\n");
        }
    } else if (moveX == 0 && moveY == 1) {
        if (wall[maze[start[1]][start[0]].x][maze[start[1]][start[0]].y + 1] == 1) {
            printf("You can't go that way!\n");
        } else {
            maze[start[1]][start[0]].y += 1;
            printf("You moved one step right.\n");
        }
    } else if (moveX == 0 && moveY == -1) {
        if (wall[maze[start[1]][start[0]].x][maze[start[1]][start[0]].y - 1] == 1) {
            printf("You can't go that way!\n");
        } else {
            maze[start[1]][start[0]].y -= 1;
            printf("You moved one step left.\n");
        }
    } else if (moveX == -1 && moveY == 1) {
        if (wall[maze[start[1]][start[0]].x - 1][maze[start[1]][start[0]].y + 1] == 1) {
            printf("You can't go that way!\n");
        } else {
            maze[start[1]][start[0]].y += 1;
            printf("You moved one step down.\n");
        }
    } else if (moveX == 1 && moveY == -1) {
        if (wall[maze[start[1]][start[0]].x + 1][maze[start[1]][start[0]].y - 1] == 1) {
            printf("You can't go that way!\n");
        } else {
            maze[start[1]][start[0]].y -= 1;
            printf("You moved one step up.\n");
        }
    } else if (moveX == 1 && moveY == 1) {
        if (wall[maze[start[1]][start[0]].x + 1][maze[start[1]][start[0]].y + 1] == 1) {
            printf("You can't go that way!\n");
        } else {
            maze[start[1]][start[0]].y += 1;
            printf("You moved one step right.\n");
        }
    } else if (moveX == -1 && moveY == -1) {
        if (wall[maze[start[1]][start[0]].x - 1][maze[start[1]][start[0]].y - 1] == 1) {
            printf("You can't go that way!\n");
        } else {
            maze[start[1]][start[0]].y -= 1;
            printf("You moved one step left.\n");
        }
    } else {
        printf("Invalid move!\n");
    }
}

void main() {
    int move;

    printf("Welcome to the Maze!\n");
    printf("You are at the starting point (%d, %d).\n", start[0], start[1]);

    while (1) {
        printf("Please enter a move (-1, 1, -1, 1, 0, 0): ");
        scanf("%d", &move);
        if (move == -1 || move == 1) {
            movePlayer(-1, move);
        } else if (move == -1 || move == 1) {
            movePlayer(move, -1);
        } else {
            break;
        }
    }

    printf("Congratulations! You made it to the end point (%d, %d)!\n", end[0], end[1]);
}