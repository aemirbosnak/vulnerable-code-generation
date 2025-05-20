//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check the winning condition
int checkWin(char[], char);

// Function to play a move for the computer
int computerPlay(char[], char);

// Function to print the Tic Tac Toe board
void printBoard(char[]);

int main() {
    char board[9];
    char player, computer, playAgain;
    int choice;

    // Randomly select the first player
    srand(time(0));
    int random = rand() % 2;

    // Take input for the players' symbols
    printf("** Welcome to Tic Tac Toe! **\n");
    printf("Choose your symbol (X/O): ");
    scanf(" %c", &player);

    // Assign symbols to the players
    if (player == 'X' || player == 'x') {
        player = 'X';
        computer = 'O';
    } else if (player == 'O' || player == 'o') {
        player = 'O';
        computer = 'X';
    } else {
        printf("Invalid input. Please try again.\n");
        return 0;
    }

    // Initialize the board
    for(int i=0; i<9; i++) {
        board[i] = '-';
    }

    do {  // Play again loop
        if (random == 0) {
            printf("\nYou are playing first.\n");
        } else {
            printf("\nComputer is playing first.\n");
            computerPlay(board, computer);  // Computer plays first
        }

        do {  // Game loop
            printBoard(board);

            // Player's turn
            printf("Enter your move (1-9): ");
            scanf("%d", &choice);

            if (board[choice-1] == '-'){
                board[choice-1] = player;
            } else {
                printf("Invalid move. Please try again.\n");
                continue;
            }

            // Check if player wins or not
            if (checkWin(board, player)) {
                printBoard(board);
                printf("** Congratulations! You won! **\n");
                break;
            }

            // Computer's turn
            computerPlay(board, computer);

            // Check if computer wins or not
            if (checkWin(board, computer)) {
                printBoard(board);
                printf("** Oops! Computer won! Better luck next time. **\n");
                break;
            }
        } while (1);

        printf("Do you want to play again? (y/n) ");
        scanf(" %c", &playAgain);
        if (playAgain == 'y' || playAgain == 'Y') {
            // Randomly select the first player
            random = rand() % 2;

            // Reset the board
            for(int i=0; i<9; i++) {
                board[i] = '-';
            }
        }
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thank you for playing! Have a nice day!\n");

    return 0;
}

int checkWin(char board[], char ch) {
    if ((board[0] == ch && board[1] == ch && board[2] == ch) ||
        (board[3] == ch && board[4] == ch && board[5] == ch) ||
        (board[6] == ch && board[7] == ch && board[8] == ch) ||
        (board[0] == ch && board[3] == ch && board[6] == ch) ||
        (board[1] == ch && board[4] == ch && board[7] == ch) ||
        (board[2] == ch && board[5] == ch && board[8] == ch) ||
        (board[0] == ch && board[4] == ch && board[8] == ch) ||
        (board[2] == ch && board[4] == ch && board[6] == ch)) {
        return 1;
    } else {
        return 0;
    }
}

int computerPlay(char board[], char computer) {
    int move;

    // Look for a winning move
    for(int i=0; i<9; i++) {
        if (board[i] == '-') {
            board[i] = computer;
            if (checkWin(board, computer)) {
                return 1;
            } else {
                board[i] = '-';
            }
        }
    }

    // Look for a move to block player's winning move
    for(int i=0; i<9; i++) {
        if (board[i] == '-') {
            board[i] = 'X' + 'O' - computer;
            if (checkWin(board, 'X' + 'O' - computer)) {
                board[i] = computer;
                return 1;
            } else {
                board[i] = '-';
            }
        }
    }

    // Look for a corner move
    if (board[0] == '-' || board[2] == '-' || board[6] == '-' || board[8] == '-') {
        do {
            move = rand() % 9;
        } while (board[move] != '-' || (move != 0 && move != 2 && move != 6 && move != 8));
        board[move] = computer;
        return 1;
    }

    // Look for a center move
    if (board[4] == '-') {
        board[4] = computer;
        return 1;
    }

    // Look for a side move
    if (board[1] == '-' || board[3] == '-' || board[5] == '-' || board[7] == '-') {
        do {
            move = rand() % 9;
        } while (board[move] != '-' || (move != 1 && move != 3 && move != 5 && move != 7));
        board[move] = computer;
        return 1;
    }

    // If none of the above moves is possible, return 0
    return 0;
}

void printBoard(char board[]) {
    printf("  %c | %c | %c \n", board[0], board[1], board[2]);
    printf("----|---|----\n");
    printf("  %c | %c | %c \n", board[3], board[4], board[5]);
    printf("----|---|----\n");
    printf("  %c | %c | %c \n", board[6], board[7], board[8]);
}