//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: complex
#include <stdio.h>

char board[3][3];
int moveCount = 0;

void printBoard() {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        printf("     ");
        for(int j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
            if(j < 2) printf(" | ");
        }
        printf("\n");
        if(i < 2) printf("     --+---+--\n");
    }
    printf("\n");
}

char checkWin() {
    //Check rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) return board[i][0];
    }

    //Check columns
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) return board[0][i];
    }

    //Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[0][0];
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[0][2];

    //Check for a tie
    if(moveCount == 9) return 'T';

    //No winner yet
    return 'N';
}

void playerMove(char symbol) {
    int row, col;
    printf("Enter the row and column to place %c (1-3): ", symbol);
    scanf("%d %d", &row, &col);
    row--;
    col--;

    if(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
        printf("Invalid move. Try again.\n");
        playerMove(symbol);
    } else {
        board[row][col] = symbol;
        moveCount++;
    }
}

void computerMove(char symbol) {
    //Implement AI move algorithm here
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while(board[row][col] != ' ');

    printf("Computer places %c on (%d, %d).\n", symbol, row + 1, col + 1);
    board[row][col] = symbol;
    moveCount++;
}

int main() {
    char winner = 'N';
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    printf("Welcome to Tic-Tac-Toe!\n\n");
    printBoard();

    //Main game loop
    while(winner == 'N') {
        playerMove('X');
        printBoard();
        winner = checkWin();
        if(winner != 'N') break;

        computerMove('O');
        printBoard();
        winner = checkWin();
    }

    //End of game
    if(winner == 'T') {
        printf("It's a tie!\n");
    } else if(winner == 'X') {
        printf("Congratulations! You win!\n");
    } else {
        printf("Sorry, you lose. Try again!\n");
    }

    return 0;
}