//FormAI DATASET v1.0 Category: Game of Life ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

// function declarations
void initializeBoard(char board[][SIZE]);
void displayBoard(char board[][SIZE]);
int countNeighbors(char board[][SIZE], int x, int y);
void updateBoard(char board[][SIZE]);

int main() {
    char board[SIZE][SIZE];
    int numPlayers;

    // get number of players
    printf("Enter number of players (2-4): ");
    scanf("%d", &numPlayers);

    // initialize board
    initializeBoard(board);

    // display initial board
    printf("\nInitial board:\n");
    displayBoard(board);

    // simulate game
    int round = 1;
    while (1) {
        // ask each player to take a turn
        for (int i = 1; i <= numPlayers; i++) {
            printf("\nPlayer %d's turn (round %d):\n", i, round);

            // update board based on player's move
            updateBoard(board);

            // display updated board
            printf("\nBoard after move:\n");
            displayBoard(board);
        }

        // check for game over
        int alivePlayers = 0;
        for (int player = 1; player <= numPlayers; player++) {
            int countAliveCells = 0;
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (board[i][j] == player + '0') {
                        countAliveCells++;
                    }
                }
            }
            if (countAliveCells > 0) {
                alivePlayers++;
            }
        }
        if (alivePlayers <= 1) {
            printf("\nGame over! ");
            for (int player = 1; player <= numPlayers; player++) {
                int countAliveCells = 0;
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        if (board[i][j] == player + '0') {
                            countAliveCells++;
                        }
                    }
                }
                if (countAliveCells > 0) {
                    printf("Player %d wins!\n", player);
                }
            }
            break;
        }

        // increment round
        round++;
    }

    return 0;
}

// function definitions
void initializeBoard(char board[][SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
    for (int p = 1; p <= 4; p++) {
        for (int i = 0; i < SIZE/2; i++) {
            int randX = rand() % SIZE;
            int randY = rand() % SIZE;
            while (board[randX][randY] != '-') {
                randX = rand() % SIZE;
                randY = rand() % SIZE;
            }
            board[randX][randY] = p + '0';
        }
    }
}

void displayBoard(char board[][SIZE]) {
    printf("  ");
    for (int j = 0; j < SIZE; j++) {
        printf("%d ", j+1);
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%c ", i+'A');
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int countNeighbors(char board[][SIZE], int x, int y) {
    int count = 0;
    for (int i = x-1; i <= x+1; i++) {
        for (int j = y-1; j <= y+1; j++) {
            if (i >= 0 && i < SIZE && j >= 0 && j < SIZE && board[i][j] != '-') {
                count++;
            }
        }
    }
    if (board[x][y] != '-') {
        count--;
    }
    return count;
}

void updateBoard(char board[][SIZE]) {
    int x, y;
    printf("Enter coordinates (e.g., B3): ");
    scanf(" %c%d", &x, &y);
    x = x - 'A';
    y = y - 1;
    int neighbors = countNeighbors(board, x, y);
    if (board[x][y] == '-') {
        if (neighbors == 3) {
            int player;
            printf("Enter player number (1-4): ");
            scanf("%d", &player);
            board[x][y] = player + '0';
        }
    } else {
        if (neighbors < 2 || neighbors > 3) {
            board[x][y] = '-';
        }
    }
}