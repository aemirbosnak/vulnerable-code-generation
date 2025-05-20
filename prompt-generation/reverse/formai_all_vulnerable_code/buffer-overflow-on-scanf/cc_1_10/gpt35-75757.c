//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 22
#define COLS 19

char gameBoard[ROWS][COLS] = {
    "###################",
    "#.................#",
    "#.###.###.###.###.#",
    "#.###.###.###.###.#",
    "#................#",
    "#.###.#.#####.#.###",
    "#.....#...#...#...#",
    "#####.#.#.#.#.#.#.#",
    "......#...#...#.#.#",
    "#####.#.#.#.#.#.#.#",
    "#.................#",
    "#.###.#.#.#.#.#.###",
    "#.....#...#...#...#",
    "#.###.#.#.#.#.#.#.#",
    "#.###.#.#####.#.#.#",
    "#.................#",
    "#.###.###.###.#.###",
    "#.###.###.###.#.###",
    "#................#",
    "###################"
};

int pacmanX, pacmanY;
int ghostX, ghostY;

bool gameWon = false;
bool gameLost = false;

void handleInput() {
    char input;
    scanf("%c", &input);
    switch (input) {
        case 'w':
            pacmanX--;
            break;
        case 'a':
            pacmanY++;
            break;
        case 's':
            pacmanX++;
            break;
        case 'd':
            pacmanY--;
            break;
        default:
            break;
    }
}

void moveGhosts() {
    int direction = rand() % 4;
    switch (direction) {
        case 0:
            ghostX--;
            break;
        case 1:
            ghostY++;
            break;
        case 2:
            ghostX++;
            break;
        case 3:
            ghostY--;
            break;
        default:
            break;
    }
}

void checkCollisions() {
    if (gameBoard[pacmanX][pacmanY] == '.') {
        gameBoard[pacmanX][pacmanY] = ' ';
    } else if (gameBoard[pacmanX][pacmanY] == '#') {
        pacmanX++;
    } else if (pacmanX == ghostX && pacmanY == ghostY) {
        gameLost = true;
    }

    if (gameBoard[ghostX][ghostY] == '.') {
        gameBoard[ghostX][ghostY] = ' ';
    }
}

void printBoard() {
    printf("\033c"); // clear the terminal
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == pacmanX && j == pacmanY) {
                printf("C");
            } else if (i == ghostX && j == ghostY) {
                printf("G");
            } else {
                printf("%c", gameBoard[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    pacmanX = 1;
    pacmanY = 1;
    ghostX = 10;
    ghostY = 10;

    while (!gameWon && !gameLost) {
        handleInput();
        moveGhosts();
        checkCollisions();
        printBoard();
    }

    if (gameWon) {
        printf("Congratulations, you won!\n");
    } else {
        printf("Game over. You lost!\n");
    }

    return 0;
}