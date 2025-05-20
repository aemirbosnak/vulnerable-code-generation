//FormAI DATASET v1.0 Category: Table Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get a random number between min and max
int getRandomNumber(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

// Function to display the game board
void printBoard(char board[][3]) {
    printf("\nCurrent Position:\n\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// Function to check if the game has ended
int isGameOver(char board[][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
            return 1;
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))
        return 1;

    // Check if game is tied
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 2;
}

int main() {
    char board[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int row, col, position, player = 1;
    int gameStatus, validatedPosition;
    char symbol;

    printf("~~~~ BRAVE TIC-TAC-TOE GAME ~~~~\n");
    printf("Instructions: This game is for two players. Each player will take turns to place their symbol (X or O) on the board. The player who succeeds in placing three of their symbols in a horizontal, vertical, or diagonal row wins the game.\n");

    while (1) {
        // Get the symbol for the current player
        if (player % 2 == 1) {
            symbol = 'X';
        } else {
            symbol = 'O';
        }

        // Display the current game board
        printBoard(board);

        // Get the position from the player
        validatedPosition = 0;
        while (!validatedPosition) {
            printf("Player %d (%c), enter a position (1-9): ", player, symbol);
            scanf("%d", &position);

            if (position < 1 || position > 9 || board[(position - 1) / 3][(position - 1) % 3] != ' ') {
                printf("Invalid position. Please enter a valid position.\n");
            } else {
                row = (position - 1) / 3;
                col = (position - 1) % 3;
                board[row][col] = symbol;
                validatedPosition = 1;
            }
        }

        // Check if the game has ended
        gameStatus = isGameOver(board);

        // If the game has ended display the final board and exit
        if (gameStatus == 1) {
            printBoard(board);
            printf("Player %d (%c) wins the game!\n", player, symbol);
            break;
        } else if (gameStatus == 2) {
            printBoard(board);
            printf("The game ended in a tie.\n");
            break;
        }

        // Switch to the next player
        player++;
    }

    return 0;
}