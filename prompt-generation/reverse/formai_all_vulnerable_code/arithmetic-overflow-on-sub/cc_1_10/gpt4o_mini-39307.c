//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: Dennis Ritchie
#include <stdio.h>

#define SIZE 3

char board[SIZE][SIZE];
char player = 'X';
char computer = 'O';

void initializeBoard();
void printBoard();
int checkWin(char mark);
void playerMove();
void computerMove();
int isBoardFull();

int main() {
    initializeBoard();
    printf("Welcome to Tic Tac Toe!\n");
    
    while (1) {
        printBoard();
        
        if (checkWin(computer)) {
            printf("Computer wins!\n");
            break;
        }
        if (isBoardFull()) {
            printf("It's a draw!\n");
            break;
        }
        playerMove();
        
        if (checkWin(player)) {
            printBoard();
            printf("You win!\n");
            break;
        }
        if (isBoardFull()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
        computerMove();
    }
    
    printBoard();
    return 0;
}

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            for (int k = 0; k < SIZE; k++) {
                printf("----");
                if (k < SIZE - 1) printf("-");
            }
            printf("\n");
        }
    }
    printf("\n");
}

int checkWin(char mark) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
            (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)) {
            return 1;
        }
    }
    
    // Check diagonals
    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
        return 1;
    }
    
    return 0;
}

void playerMove() {
    int x, y;
    do {
        printf("Enter your move (row and column): ");
        scanf("%d %d", &x, &y);
        x--; y--; // Adjust for zero indexing
    } while (x < 0 || x >= SIZE || y < 0 || y >= SIZE || board[x][y] != ' ');
    
    board[x][y] = player;
}

void computerMove() {
    int x, y;
    // Simple AI to pick the first empty spot
    for (x = 0; x < SIZE; x++) {
        for (y = 0; y < SIZE; y++) {
            if (board[x][y] == ' ') {
                board[x][y] = computer;
                return;
            }
        }
    }
}

int isBoardFull() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}