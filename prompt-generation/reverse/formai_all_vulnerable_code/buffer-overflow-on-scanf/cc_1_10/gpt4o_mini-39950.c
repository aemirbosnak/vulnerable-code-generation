//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: peaceful
#include <stdio.h>

char board[3][3];
char player = 'X';
char ai = 'O';

void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

int checkWin(char symbol) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol))
            return 1;
    }

    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))
        return 1;

    return 0;
}

int checkTie() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0; // Found an empty space
    return 1; // No empty squares left
}

void playerMove() {
    int row, col;
    printf("It's your turn! Where would you like to place '%c'? (row and column: 0, 1, or 2)\n", player);
    while (1) {
        printf("Row: ");
        scanf("%d", &row);
        printf("Column: ");
        scanf("%d", &col);
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            printf("This move is not valid. Try again.\n");
        }
    }
}

void aiMove() {
    printf("AI is making a move...\n");
    
    // Simple AI tries to win or block player
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = ai;
                if (checkWin(ai)) {
                    return;
                }
                board[i][j] = ' '; // Reset if it doesn't lead to a win
            }
        }
    }

    // Random move for AI
    while (1) {
        int randRow = rand() % 3;
        int randCol = rand() % 3;
        if (board[randRow][randCol] == ' ') {
            board[randRow][randCol] = ai;
            break;
        }
    }
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    initializeBoard();

    while (1) {
        printBoard();
        
        playerMove();
        if (checkWin(player)) {
            printBoard();
            printf("Congratulations! You have won the game!\n");
            break;
        }
        if (checkTie()) {
            printBoard();
            printf("It's a tie! Thanks for playing!\n");
            break;
        }
        
        aiMove();
        if (checkWin(ai)) {
            printBoard();
            printf("Oh no! The AI has won the game! Better luck next time!\n");
            break;
        }
        if (checkTie()) {
            printBoard();
            printf("It's a tie! Thanks for playing!\n");
            break;
        }
    }
    
    return 0;
}