//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS];

void generateMaze() {
    int x, y;
    for (y = 0; y < ROWS; y++) {
        for (x = 0; x < COLS; x++) {
            maze[y][x] = rand() % 2? '.' : '#';
        }
    }
}

void printMaze() {
    int x, y;
    for (y = 0; y < ROWS; y++) {
        for (x = 0; x < COLS; x++) {
            printf("%c", maze[y][x]);
        }
        printf("\n");
    }
}

bool move(int *x, int *y, char dir) {
    switch (dir) {
        case 'w':
            (*y)--;
            break;
        case 'a':
            (*x)--;
            break;
        case's':
            (*y)++;
            break;
        case 'd':
            (*x)++;
            break;
        default:
            return false;
    }
    return true;
}

int main() {
    srand(time(NULL));
    generateMaze();
    int playerX = 0, playerY = 0;
    printMaze();

    while (true) {
        char input;
        printf("> ");
        scanf(" %c", &input);

        switch (input) {
            case 'w':
            case 'a':
            case's':
            case 'd':
                move(&playerX, &playerY, input);
                break;
            case 'q':
                return 0;
            default:
                printf("Invalid input.\n");
        }

        if (maze[playerY][playerX] == '#') {
            printf("You hit a wall!\n");
        } else {
            printf("You moved to (%d,%d).\n", playerX, playerY);
        }

        printMaze();
    }

    return 0;
}