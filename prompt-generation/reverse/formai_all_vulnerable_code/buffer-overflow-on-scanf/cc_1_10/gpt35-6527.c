//FormAI DATASET v1.0 Category: Table Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

char board[3][3]; // the Tic Tac Toe board array
char player; // the current player, initialized as 'X'
int row, col; // variables to hold the row and column input by the user

void drawBoard(); // function to draw the Tic Tac Toe board
int checkWin(); // function to check if a player has won
void play(); // function to handle the player's turn

int main() {
    // initialize the Tic Tac Toe board
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
    
    player = 'X'; // start with player 'X' first
    
    printf("Welcome to Tic Tac Toe!\n\n");
    drawBoard();
    printf("Player 'X': Enter row and column (1-3) to place 'X':\n\n");
    
    // game loop
    int gameOver = 0;
    while (!gameOver) {
        play();
        drawBoard();
        if (checkWin()) {
            printf("Player '%c' has won!\n", player);
            gameOver = 1;
        } else if (board[0][0] != '-' && board[0][1] != '-' && board[0][2] != '-' && 
                   board[1][0] != '-' && board[1][1] != '-' && board[1][2] != '-' && 
                   board[2][0] != '-' && board[2][1] != '-' && board[2][2] != '-') {
            printf("It's a tie!\n");
            gameOver = 1;
        } else {
            player = (player == 'X') ? 'O' : 'X';
            printf("Player '%c': Enter row and column (1-3) to place '%c':\n\n", player, player);
        }
    }
    
    return 0;
}

void drawBoard() {
    printf("  1 2 3\n");
    int i, j;
    for (i = 0; i < 3; i++) {
        printf("%d", i + 1);
        for (j = 0; j < 3; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int checkWin() {
    int i;
    for (i = 0; i < 3; i++) {
        // check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            return 1;
        }
        
        // check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') {
            return 1;
        }
    }
    
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') {
        return 1;
    }
    
    return 0;
}

void play() {
    // prompt user for row and column input
    printf("Row: ");
    scanf("%d", &row);
    printf("Column: ");
    scanf("%d", &col);
    
    // subtract 1 from row and column to make indices zero-indexed
    row--;
    col--;
    
    // keep prompting user for input until the input is valid
    while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '-') {
        printf("Invalid input. Enter row and column (1-3) again:\n");
        printf("Row: ");
        scanf("%d", &row);
        printf("Column: ");
        scanf("%d", &col);
        row--;
        col--;
    }
    
    // update the board with the player's move
    board[row][col] = player;
}