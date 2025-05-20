//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

char board[SIZE][SIZE];

void initializeBoard();
void displayBoard();
int isMoveValid(char *move);
void makeMove(char *move);
int isGameOver();

int main() {
    char move[5];

    initializeBoard();
    while (!isGameOver()) {
        displayBoard();
        printf("Enter your move (e.g., e2 e4): ");
        scanf("%s %s", move, move + 3);
        if (isMoveValid(move)) {
            makeMove(move);
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    printf("Game over!\n");
    return 0;
}

void initializeBoard() {
    const char *initial[] = {
        "rnbqkbnr",
        "pppppppp",
        "        ",
        "        ",
        "        ",
        "        ",
        "PPPPPPPP",
        "RNBQKBNR"
    };
    for (int i = 0; i < SIZE; i++) {
        strcpy(board[i], initial[i]);
    }
}

void displayBoard() {
    printf("\n  a b c d e f g h\n");
    printf(" +-----------------+\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d| ", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf(" +-----------------+\n");
}

int isMoveValid(char *move) {
    int fromCol = move[0] - 'a';
    int fromRow = SIZE - (move[1] - '0') - 1;
    int toCol = move[3] - 'a';
    int toRow = SIZE - (move[4] - '0') - 1;

    // Simple bounds and format check
    if (fromCol < 0 || fromCol >= SIZE || fromRow < 0 || fromRow >= SIZE ||
        toCol < 0 || toCol >= SIZE || toRow < 0 || toRow >= SIZE) {
        return 0; // Invalid move due to out-of-bounds
    }

    // Add further checks (like checking piece movement rules)
    return 1; // For now, we assume any input is valid
}

void makeMove(char *move) {
    int fromCol = move[0] - 'a';
    int fromRow = SIZE - (move[1] - '0') - 1;
    int toCol = move[3] - 'a';
    int toRow = SIZE - (move[4] - '0') - 1;

    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = ' ';
}

int isGameOver() {
    // Simple check for game over - can be expanded later
    return 0; // The game is never over in this simple version
}