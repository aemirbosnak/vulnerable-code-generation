//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define ROOM_EMPTY '.'
#define ROOM_HAUNTED 'H'
#define ROOM_VISITED 'V'
#define ROOM_WIN 'W'

char hauntedHouse[ROWS][COLS];
int playerRow, playerCol;
int score = 0;

void generateHauntedHouse() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            hauntedHouse[i][j] = ROOM_EMPTY;
        }
    }
    hauntedHouse[0][0] = ROOM_WIN;
    hauntedHouse[ROWS-1][COLS-1] = ROOM_HAUNTED;
}

void printHauntedHouse() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", hauntedHouse[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(int rowOffset, int colOffset) {
    playerRow += rowOffset;
    playerCol += colOffset;
    if (playerRow < 0 || playerRow >= ROWS || playerCol < 0 || playerCol >= COLS) {
        printf("You've fallen off the edge of the haunted house!\n");
        exit(1);
    }
}

int main() {
    int i, j;
    srand(time(NULL));
    generateHauntedHouse();
    printHauntedHouse();
    playerRow = 0;
    playerCol = 0;
    while (1) {
        printf("Score: %d\n", score);
        printf("You are at room (%d,%d)\n", playerRow, playerCol);
        printf("Enter your move (w/a/s/d): ");
        char move;
        scanf("%c", &move);
        switch (move) {
            case 'w':
                movePlayer(0, -1);
                break;
            case 'a':
                movePlayer(-1, 0);
                break;
            case's':
                movePlayer(0, 1);
                break;
            case 'd':
                movePlayer(1, 0);
                break;
            default:
                printf("Invalid move!\n");
        }
        if (hauntedHouse[playerRow][playerCol] == ROOM_HAUNTED) {
            printf("You've been caught by the ghost! Game over.\n");
            exit(0);
        } else if (hauntedHouse[playerRow][playerCol] == ROOM_WIN) {
            printf("Congratulations! You've escaped the haunted house!\n");
            exit(0);
        }
        hauntedHouse[playerRow][playerCol] = ROOM_VISITED;
    }
    return 0;
}