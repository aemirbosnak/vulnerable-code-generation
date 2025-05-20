//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
/* C Terminal Based Game: The Maze Runner */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ROW 10
#define COL 10

/* Function to print game board */
void printBoard(char maze[][COL]) {
    int i, j;
    printf("\n");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

/* Function to generate maze */
void generateMaze(char maze[][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (i == 0 || i == ROW - 1 || j == 0 || j == COL - 1) {
                maze[i][j] = '#';      // adding walls to the board
            }
            else {
                maze[i][j] = ' ';      // adding empty spaces to the board
            }
        }
    }
    // place starting point and ending point
    maze[1][1] = 'S';
    maze[ROW - 2][COL - 2] = 'E';
}

/* Function to move player */
void movePlayer(char maze[][COL], int *row, int *col, char move) {
    switch (move) {
        case 'W':
        case 'w':
            if (*row > 1 && maze[*row - 1][*col] != '#') {
                *row -= 1;
            }
            break;
        case 'S':
        case 's':
            if (*row < ROW - 2 && maze[*row + 1][*col] != '#') {
                *row += 1;
            }
            break;
        case 'A':
        case 'a':
            if (*col > 1 && maze[*row][*col - 1] != '#') {
                *col -= 1;
            }
            break;
        case 'D':
        case 'd':
            if (*col < COL - 2 && maze[*row][*col + 1] != '#') {
                *col += 1;
            }
            break;
    }
}

/* Function to check if the player has reached the end */
int checkEnd(int row, int col) {
    if (row == ROW - 2 && col == COL - 2) {
        return 1;
    }
    return 0;
}

/* Main function */
int main() {
    srand(time(NULL));
    int row = 1, col = 1, end = 0, i, j;
    char maze[ROW][COL], move;

    // generate maze
    generateMaze(maze);

    // print instructions
    printf("\nInstructions:");
    printf("\nUse W-A-S-D keys to move the player.");
    printf("\nReach to 'E' to win.\n");

    // print board
    printBoard(maze);

    // game loop
    do {
        printf("\nEnter your move: ");
        scanf(" %c", &move);
        movePlayer(maze, &row, &col, move);
        end = checkEnd(row, col);
        system("clear");
        printBoard(maze);
    } while (!end);

    // end of game
    printf("\nCongratulations! You have won the game.\n");
    return 0;
}