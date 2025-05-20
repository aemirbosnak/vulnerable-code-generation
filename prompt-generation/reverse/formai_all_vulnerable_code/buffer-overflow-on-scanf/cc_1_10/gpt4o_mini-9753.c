//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

char board[SIZE][SIZE]; // The sacred board of battles
char player = 'X'; // The valiant knight
char computer = 'O'; // The merciless dragon

// Initialize the board with empty spaces
void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Display the current state of the battleground
void displayBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("     |     |     \n");
        printf("  %c  |  %c  |  %c  \n", board[i][0], board[i][1], board[i][2]);
        printf("_____|_____|_____\n");
    }
    printf("     |     |     \n\n");
}

// Check for the brave champion
int checkWin(char symbol) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol))
            return 1;
    }
    // Check diagonals
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))
        return 1;
    
    return 0;
}

// Check for a draw, a tale of stalemate
int checkDraw() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ')
                return 0; // Not a draw yet
    return 1; // All fields filled
}

// The cunning dragon (AI) chooses its next move
void computerMove() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ') {
                board[i][j] = computer;
                if (checkWin(computer)) {
                    return; // If the dragon can win, it does
                }
                board[i][j] = ' '; // Backtrack
            }

    // Block the knight from winning
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ') {
                board[i][j] = player;
                if (checkWin(player)) {
                    board[i][j] = computer; // Block the knight from winning
                    return;
                }
                board[i][j] = ' '; // Backtrack
            }

    // Choose a random free space to strike
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ') {
                board[i][j] = computer;
                return; // The dragon strikes!
            }
}

// The courageous knight purveys the field
void playerMove() {
    int x, y;
    printf("Valiant knight, choose your position (row and column 0-2): ");
    scanf("%d %d", &x, &y);
    while (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != ' ') {
        printf("Alas! That position is taken or invalid. Choose again: ");
        scanf("%d %d", &x, &y);
    }
    board[x][y] = player; // The knight claims the position
}

int main() {
    initializeBoard();
    displayBoard();
    
    while (1) {
        playerMove();
        displayBoard();
        
        if (checkWin(player)) {
            printf("Huzzah! The valiant knight has claim’d victory!\n");
            break;
        }
        
        if (checkDraw()) {
            printf("A draw! The battle ends with no champions!\n");
            break;
        }
        
        computerMove();
        displayBoard();
        
        if (checkWin(computer)) {
            printf("Alas! The merciless dragon hath prevail'd!\n");
            break;
        }
        
        if (checkDraw()) {
            printf("A draw! The battle wends to a bitter end!\n");
            break;
        }
    }

    return 0;
}