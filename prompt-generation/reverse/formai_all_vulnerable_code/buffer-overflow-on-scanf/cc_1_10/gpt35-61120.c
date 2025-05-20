//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int playAgain, turnCount = 0;
char player1Choice, player2Choice;
char gameBoard[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
};

void drawBoard() {
    printf("\n\t");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c | ", gameBoard[i][j]);
        }
        printf("\n\t");
        if (i != 2) printf("---------\n\t");
    }
}

void takeInput(char currentPlayer) {
    int row, col;
    printf("It is %c's turn. Pick a row (1, 2, or 3): \n", currentPlayer);
    scanf("%d", &row);
    printf("Pick a column (1, 2, or 3): \n");
    scanf("%d", &col);
    if (gameBoard[row-1][col-1] != ' ') {
        printf("That spot is already taken. Pick again.\n");
        takeInput(currentPlayer);
    } else {
        gameBoard[row-1][col-1] = currentPlayer;
        turnCount++;
    }
}

char checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]) {
            return gameBoard[i][0];
        }
        if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i]) {
            return gameBoard[0][i];
        }
    }
    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) {
        return gameBoard[0][0];
    }
    if (gameBoard[2][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[0][2]) {
        return gameBoard[2][0];
    }
    return ' ';
}

void computerTurn(char currentPlayer) {
    int row, col;
    printf("\nIt is %c's turn (computer).\n", currentPlayer);
    row = rand() % 3;
    col = rand() % 3;
    if (gameBoard[row][col] == ' ') {
        printf("The computer chose row %d and column %d.\n", row+1, col+1);
        gameBoard[row][col] = currentPlayer;
        turnCount++;
    } else {
        computerTurn(currentPlayer);
    } 
}

void playGame() {
    printf("Player 1, choose X or O: \n");
    scanf(" %c", &player1Choice);
    if (player1Choice == 'X') player2Choice = 'O';
    else player2Choice = 'X';

    while (checkWinner() == ' ' && turnCount < 9) {
        drawBoard();
        takeInput(player1Choice);
        if (checkWinner() != ' ' || turnCount == 9) break;
        computerTurn(player2Choice);
    }

    drawBoard();
    char winner = checkWinner();
    printf("\nThe winner is %c!\n", winner);
}

int main() {
    do {
        playGame();
        printf("\nWould you like to play again? (y/n)\n");
        char playAgainChoice;
        scanf(" %c", &playAgainChoice);
        if (playAgainChoice != 'y') playAgain = 0;
        else {
            playAgain = 1;
            turnCount = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    gameBoard[i][j] = ' ';
                }
            }
        }
    } while (playAgain);

    return 0;
}