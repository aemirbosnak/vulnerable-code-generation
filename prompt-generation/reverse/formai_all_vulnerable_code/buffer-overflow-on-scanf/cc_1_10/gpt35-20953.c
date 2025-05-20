//FormAI DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to print the board
void printBoard(char board[]) {
    printf("\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0], board[1], board[2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[3], board[4], board[5]);
    printf("_____|_____|_____\n");
    printf("     |     |    \n");
    printf("  %c  |  %c  |  %c  \n", board[6], board[7], board[8]);
    printf("     |     |     \n\n");
}

// function to check if the game has ended
int checkEnd(char board[]) {
    if ((board[0] == board[1] && board[1] == board[2]) ||
        (board[3] == board[4] && board[4] == board[5]) ||
        (board[6] == board[7] && board[7] == board[8]) ||
        (board[0] == board[3] && board[3] == board[6]) ||
        (board[1] == board[4] && board[4] == board[7]) ||
        (board[2] == board[5] && board[5] == board[8]) ||
        (board[0] == board[4] && board[4] == board[8]) ||
        (board[2] == board[4] && board[4] == board[6])) {
            return 1;
    }
    if (board[0] != '1' && board[1] != '2' && board[2] != '3' && 
        board[3] != '4' && board[4] != '5' && board[5] != '6' && 
        board[6] != '7' && board[7] != '8' && board[8] != '9') {
            return 0;
    }
    return -1;
}

// function to place the marker on the board
void placeMarker(char board[], int pos, char marker) {
    board[pos-1] = marker;
}

// function for computer's turn
void computerTurn(char board[], char computerMarker) {
    int flag = 0, pos;

    srand(time(NULL));
    while (flag == 0) {
        pos = rand() % 9;
        if (board[pos] == (pos+1)+'0') {
            placeMarker(board, pos+1, computerMarker);
            flag = 1;
        }
    }
}

// function for player's turn
void playerTurn(char board[], char playerMarker) {
    int pos, valid = 0;

    while (valid == 0) {
        printf("Enter a position (1-9) to place your marker: ");
        scanf("%d", &pos);
        if (pos < 1 || pos > 9) {
            printf("Invalid Input! Please Enter a number between 1 to 9.\n");
        } else if (board[pos-1] == 'X' || board[pos-1] == 'O') {
            printf("The position is already occupied! Please choose another position.\n");
        } else {
            valid = 1;
        }
    }

    placeMarker(board, pos, playerMarker);
}

// main function
int main() {
    int choice;
    char board[9] = {"123456789"};
    char computerMarker, playerMarker;

    printf("Welcome to Tic Tac Toe Game!\n");

    while (1) {
        printf("\nPlease select your marker (X|O): ");
        scanf(" %c", &playerMarker);
        if (playerMarker == 'X' || playerMarker == 'O') {
            break;
        } else {
            printf("Invalid Input! Please Enter X or O.\n");
        }
    }

    computerMarker = (playerMarker == 'X') ? 'O' : 'X';

    printf("\nHere is the position number map:\n\n");
    printf("     |     |     \n");
    printf("  1  |  2  |  3  \n");
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  4  |  5  |  6  \n");
    printf("_____|_____|_____\n");
    printf("     |     |    \n");
    printf("  7  |  8  |  9  \n");
    printf("     |     |     \n\n");

    while (1) {
        printf("Enter your choice: \n");
        printf("1. Start the Game\n");
        printf("2. Quit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            while (1) {
                printBoard(board);
                playerTurn(board, playerMarker);
                if (checkEnd(board) == 1) {
                    printBoard(board);
                    printf("Congratulations! You have Won!!\n");
                    break;
                } else if (checkEnd(board) == 0) {
                    printBoard(board);
                    printf("The Game has ended in a Tie!!\n");
                    break;
                }
                computerTurn(board, computerMarker);
                if (checkEnd(board) == 1) {
                    printBoard(board);
                    printf("You have lost to the computer!!\n");
                    break;
                } else if (checkEnd(board) == 0) {
                    printBoard(board);
                    printf("The Game has ended in a Tie!!\n");
                    break;
                }
            }
            // Resetting the board for next game
            board[0] = '1';board[1] = '2';board[2] = '3';
            board[3] = '4';board[4] = '5';board[5] = '6';
            board[6] = '7';board[7] = '8';board[8] = '9';
        } else if (choice == 2) {
            printf("Thanks for Playing!\n");
            break;
        } else {
            printf("Invalid Choice!!\n");
        }
    }

    return 0;
}