//Falcon2-11B DATASET v1.0 Category: Pac-Man Game Clone ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 10
#define NUM_COLUMNS 10

typedef struct {
    int x;
    int y;
} Point;

void displayBoard(int board[][NUM_ROWS], int rows, int columns) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

void movePacMan(int board[][NUM_ROWS], int rows, int columns, Point pacMan) {
    int newX = pacMan.x + pacMan.y;
    int newY = pacMan.y;

    if (newX < 0 || newX >= NUM_COLUMNS || newY < 0 || newY >= NUM_ROWS) {
        printf("PacMan out of bounds!\n");
        return;
    }

    board[newY][newX] = pacMan.x + pacMan.y;
}

void moveEnemy(int board[][NUM_ROWS], int rows, int columns, Point enemy) {
    int newX = enemy.x + enemy.y;
    int newY = enemy.y;

    if (newX < 0 || newX >= NUM_COLUMNS || newY < 0 || newY >= NUM_ROWS) {
        printf("Enemy out of bounds!\n");
        return;
    }

    board[newY][newX] = enemy.x + enemy.y;
}

int main() {
    srand(time(NULL));

    int board[NUM_ROWS][NUM_COLUMNS];
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLUMNS; j++) {
            board[i][j] = rand() % 2? 1 : 0;
        }
    }

    Point pacMan = {0, 0};
    Point enemy = {0, 0};

    displayBoard(board, NUM_ROWS, NUM_COLUMNS);

    while (1) {
        int move = 0;

        printf("Enter '0' for no move, '1' for up, '2' for down, '3' for left, '4' for right:\n");
        scanf("%d", &move);

        switch (move) {
            case 0:
                break;
            case 1:
                movePacMan(board, NUM_ROWS, NUM_COLUMNS, pacMan);
                displayBoard(board, NUM_ROWS, NUM_COLUMNS);
                break;
            case 2:
                movePacMan(board, NUM_ROWS, NUM_COLUMNS, pacMan);
                displayBoard(board, NUM_ROWS, NUM_COLUMNS);
                break;
            case 3:
                movePacMan(board, NUM_ROWS, NUM_COLUMNS, pacMan);
                displayBoard(board, NUM_ROWS, NUM_COLUMNS);
                break;
            case 4:
                movePacMan(board, NUM_ROWS, NUM_COLUMNS, pacMan);
                displayBoard(board, NUM_ROWS, NUM_COLUMNS);
                break;
        }

        int enemyMove = rand() % 2? 0 : 1;

        switch (enemyMove) {
            case 0:
                moveEnemy(board, NUM_ROWS, NUM_COLUMNS, enemy);
                displayBoard(board, NUM_ROWS, NUM_COLUMNS);
                break;
            case 1:
                moveEnemy(board, NUM_ROWS, NUM_COLUMNS, enemy);
                displayBoard(board, NUM_ROWS, NUM_COLUMNS);
                break;
        }

        if (pacMan.x == enemy.x && pacMan.y == enemy.y) {
            printf("Game over!\n");
            break;
        }
    }

    return 0;
}