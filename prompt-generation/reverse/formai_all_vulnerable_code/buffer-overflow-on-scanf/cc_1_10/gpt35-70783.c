//FormAI DATASET v1.0 Category: Table Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate random number */
int generateRandomNumber(int lower, int upper) {
    srand(time(NULL));
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

/* Function to initialize the game board */
void initializeBoard(char board[][3]) {
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            board[row][col] = ' ';
        }
    }
}

/* Function to display the game board */
void displayBoard(char board[][3]) {
    printf("\n");

    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);

    printf("\n");
}

/* Function to check if any row is filled with a single symbol */
int checkRows(char board[][3], char symbol) {
    for(int row = 0; row < 3; row++) {
        if(board[row][0] == symbol && board[row][1] == symbol && board[row][2] == symbol) {
            return 1;
        }
    }
    return 0;
}

/* Function to check if any column is filled with a single symbol */
int checkColumns(char board[][3], char symbol) {
    for(int col = 0; col < 3; col++) {
        if(board[0][col] == symbol && board[1][col] == symbol && board[2][col] == symbol) {
            return 1;
        }
    }
    return 0;
}

/* Function to check if any of the diagonals is filled with a single symbol */
int checkDiagonals(char board[][3], char symbol) {
    if(board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }
    if(board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }
    return 0;
}

/* Function to check if the game is over */
int isGameOver(char board[][3], char symbol) {
    /* Check rows */
    if(checkRows(board, symbol)) {
        return 1;
    }

    /* Check columns */
    if(checkColumns(board, symbol)) {
        return 1;
    }

    /* Check diagonals */
    if(checkDiagonals(board, symbol)) {
        return 1;
    }

    /* Check if the board is full */
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            if(board[row][col] == ' '){
                return 0;
            }
        }
    }

    /* Return 1 if the game is over and nobody has won */
    return 1;
}

/* Function to get the user's move */
void takeUserInput(char board[][3], char symbol) {
    int row, col;
    printf("\n%s's turn (%c):\n", symbol == 'X' ? "Player 1" : "Player 2", symbol);
    printf("Enter the row number (0 - 2): ");
    scanf("%d", &row);
    printf("Enter the column number (0 - 2): ");
    scanf("%d", &col);

    /* Check if the cell is empty */
    if(board[row][col] == ' ') {
        board[row][col] = symbol;
    } else {
        printf("\nInvalid input! Please enter again.\n");
        takeUserInput(board, symbol);
    }
}

/* Function to get the computer's move */
void takeComputerInput(char board[][3], char symbol) {
    int row, col;
    printf("\nComputer turns (%c):\n", symbol);
    row = generateRandomNumber(0, 2);
    col = generateRandomNumber(0, 2);

    /* Check if the cell is empty */
    if(board[row][col] == ' ') {
        board[row][col] = symbol;
    } else {
        takeComputerInput(board, symbol);
    }
}

/* Function to play the game */
void playGame() {
    char board[3][3];
    int gameOver = 0;
    char currentPlayer = 'X';

    initializeBoard(board);
    displayBoard(board);

    /* Loop until the game is over */
    while(!gameOver) {
        /* Take input from the current player */
        if(currentPlayer == 'X') {
            takeUserInput(board, currentPlayer);
        } else {
            takeComputerInput(board, currentPlayer);
        }

        /* Display the updated board */
        displayBoard(board);

        /* Check if the game is over */
        gameOver = isGameOver(board, currentPlayer);

        /* Switch the player */
        if(currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }

    /* Print the winner */
    if(checkRows(board, 'X') || checkColumns(board, 'X') || checkDiagonals(board, 'X')) {
        printf("Player 1 wins!\n");
    } else if(checkRows(board, 'O') || checkColumns(board, 'O') || checkDiagonals(board, 'O')) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}

/* Main Function */
int main() {
    int choice;

    /* Loop until the user wants to quit */
    do {
        printf("Welcome to Tic Tac Toe!\n");
        printf("1. Play game\n");
        printf("2. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                playGame();
                break;

            case 2:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 2);

    return 0;
}