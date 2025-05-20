//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to clear the screen
void clearScreen() {
    printf("\033[2J\033[1;1H");
}

// function to display the game board
void displayBoard(char board[]) {
    printf("**********\n");
    printf("%c | %c | %c\n", board[0], board[1], board[2]);
    printf("---------\n");
    printf("%c | %c | %c\n", board[3], board[4], board[5]);
    printf("---------\n");
    printf("%c | %c | %c\n", board[6], board[7], board[8]);
    printf("**********\n");
}

// function to check if game is over
int checkOver(char board[], char current) {
    // check for horizontal wins
    if (board[0] == current && board[1] == current && board[2] == current) {
        return 1;
    }
    else if (board[3] == current && board[4] == current && board[5] == current) {
        return 1;
    }
    else if (board[6] == current && board[7] == current && board[8] == current) {
        return 1;
    }
    // check for vertical wins
    else if (board[0] == current && board[3] == current && board[6] == current) {
        return 1;
    }
    else if (board[1] == current && board[4] == current && board[7] == current) {
        return 1;
    }
    else if (board[2] == current && board[5] == current && board[8] == current) {
        return 1;
    }
    // check for diagonal wins
    else if (board[0] == current && board[4] == current && board[8] == current) {
        return 1;
    }
    else if (board[2] == current && board[4] == current && board[6] == current) {
        return 1;
    }
    // check if board is full
    else if (board[0] != '1' && board[1] != '2' && board[2] != '3' &&
        board[3] != '4' && board[4] != '5' && board[5] != '6' &&
        board[6] != '7' && board[7] != '8' && board[8] != '9') {
        return 2;
    }
    else {
        return 0;
    }
}

int main() {
    // initialize the game board
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    // display welcome message
    printf("Welcome to Tic Tac Toe! You will be playing against the computer.\n");
    printf("You will be 'X' and the computer will be 'O'.\n");
    printf("The game board is as follows:\n");
    displayBoard(board);

    // set a random seed for the computer's moves
    srand(time(0));

    // play the game
    int over = 0;
    int currentPlayer = 0; // 0 for player, 1 for computer
    while (!over) {
        if (currentPlayer == 0) {
            // get the player's move
            printf("Enter a number between 1 and 9 to make a move: ");
            int move;
            scanf("%d", &move);
            while (board[move-1] == 'X' || board[move-1] == 'O' || move < 1 || move > 9) {
                printf("Invalid move. Please enter a number between 1 and 9: ");
                scanf("%d", &move);
            }
            board[move-1] = 'X';
            clearScreen();
            displayBoard(board);
            over = checkOver(board, 'X');
            if (over == 1) {
                printf("Congratulations! You won!\n");
            }
            else if (over == 2) {
                printf("It's a tie!\n");
            }
            currentPlayer = 1;
        }
        else {
            // let the computer make a move
            printf("The computer is thinking...\n");
            int move = rand() % 9;
            while (board[move] == 'X' || board[move] == 'O') {
                move = rand() % 9;
            }
            board[move] = 'O';
            clearScreen();
            displayBoard(board);
            over = checkOver(board, 'O');
            if (over == 1) {
                printf("Sorry, the computer won. Better luck next time!\n");
            }
            else if (over == 2) {
                printf("It's a tie!\n");
            }
            currentPlayer = 0;
        }
    }

    return 0;
}