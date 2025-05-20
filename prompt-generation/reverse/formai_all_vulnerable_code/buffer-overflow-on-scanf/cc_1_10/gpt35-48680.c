//FormAI DATASET v1.0 Category: Table Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number
int generateRandomNumber(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

// Function to print the game board
void printGameBoard(char gameBoard[][3]) {
    printf("\n\n");
    printf("\t %c | %c | %c \n", gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]);
    printf("\n\n");
}

// Function to update the game board
void updateGameBoard(char gameBoard[][3], int position, char symbol) {
    int row = (position - 1) / 3;
    int column = (position - 1) % 3;
    gameBoard[row][column] = symbol;
}

// Function to check if the game is over
int isGameOver(char gameBoard[][3]) {
    int i, j;
    // Checking rows
    for (i = 0; i < 3; i++) {
        if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]) {
            if (gameBoard[i][0] == 'X') {
                return 1;
            } else if (gameBoard[i][0] == 'O') {
                return 2;
            }
        }
    }
    // Checking columns
    for (j = 0; j < 3; j++) {
        if (gameBoard[0][j] == gameBoard[1][j] && gameBoard[1][j] == gameBoard[2][j]) {
            if (gameBoard[0][j] == 'X') {
                return 1;
            } else if (gameBoard[0][j] == 'O') {
                return 2;
            }
        }
    }
    // Checking diagonals
    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) {
        if (gameBoard[0][0] == 'X') {
            return 1;
        } else if (gameBoard[0][0] == 'O') {
            return 2;
        }
    } else if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]) {
        if (gameBoard[0][2] == 'X') {
            return 1;
        } else if (gameBoard[0][2] == 'O') {
            return 2;
        }
    }
    // Checking for tie
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (gameBoard[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 3;
}

int main() {
    srand(time(0)); // Seed for random number generator
    char gameBoard[3][3] = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
    };
    int playerTurn = 1, position, gameResult = 0;
    char playerSymbol, computerSymbol;
    printf("********** Welcome to Tic Tac Toe Game **********\n\n");
    printf("Choose your symbol (X / O): ");
    scanf("%c", &playerSymbol);
    while (playerSymbol != 'X' && playerSymbol != 'O') {
        printf("Invalid symbol, choose again (X / O): ");
        scanf("%c", &playerSymbol);
    }
    if (playerSymbol == 'X') {
        computerSymbol = 'O';
    } else {
        computerSymbol = 'X';
    }
    printf("You have chosen symbol '%c', computer got symbol '%c'\n", playerSymbol, computerSymbol);
    printGameBoard(gameBoard);
    while (gameResult == 0) {
        if (playerTurn == 1) {
            printf("Your turn, choose a position (1-9): ");
            scanf("%d", &position);
            while (position < 1 || position > 9 || gameBoard[(position - 1) / 3][(position - 1) % 3] != ' ') {
                printf("Invalid position, choose again (1-9): ");
                scanf("%d", &position);
            }
            updateGameBoard(gameBoard, position, playerSymbol);
            playerTurn = 2;
        } else {
            printf("Computer's turn\n");
            position = generateRandomNumber(1, 9);
            while (gameBoard[(position - 1) / 3][(position - 1) % 3] != ' ') {
                position = generateRandomNumber(1, 9);
            }
            printf("Computer has chosen position %d\n", position);
            updateGameBoard(gameBoard, position, computerSymbol);
            playerTurn = 1;
        }
        printGameBoard(gameBoard);
        gameResult = isGameOver(gameBoard);
    }
    if (gameResult == 1) {
        printf("Congratulations, you won the game!\n");
    } else if (gameResult == 2) {
        printf("Sorry, you lost the game!\n");
    } else {
        printf("The game ended in a tie!\n");
    }
}