//FormAI DATASET v1.0 Category: Table Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to check if the user input is a valid move
int isValidMove(int board[], int move) {
    if (move >= 1 && move <= 9 && board[move] == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

//Function to check if the game is over
int isGameOver(int board[]) {
    //Checking horizontal and vertical rows for winning combinations
    for (int i = 1; i <= 7; i += 3) {
        if (board[i] == board[i+1] && board[i] == board[i+2] && board[i] != 0) {
            return 1;
        }
    }
    for (int i = 1; i <= 3; i++) {
        if (board[i] == board[i+3] && board[i] == board[i+6] && board[i] != 0) {
            return 1;
        }
    }
    //Checking diagonal rows for winning combinations
    if (board[1] == board[5] && board[1] == board[9] && board[1] != 0) {
        return 1;
    }
    if (board[3] == board[5] && board[3] == board[7] && board[3] != 0) {
        return 1;
    }
    //Checking if all the spaces are filled to declare a tie
    for (int i = 1; i <= 9; i++) {
        if (board[i] == 0) {
            return 0;
        }
    }
    //If all the spaces are filled and no winning combination is found, declare a tie
    return 2;
}

//Function to display the game board
void displayBoard(int board[]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[1] ? board[1] : ' ', board[2] ? board[2] : ' ', board[3] ? board[3] : ' ');
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[4] ? board[4] : ' ', board[5] ? board[5] : ' ', board[6] ? board[6] : ' ');
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[7] ? board[7] : ' ', board[8] ? board[8] : ' ', board[9] ? board[9] : ' ');
    printf("\n");
}

//Function to get computer's move
int getComputerMove(int board[]) {
    int move = 0;
    int foundWinningMove = 0;
    int foundBlockingMove = 0;
    srand(time(NULL));
    //Check for winning moves
    for (int i = 1; i <= 9; i++) {
        if (isValidMove(board, i)) {
            board[i] = 'X';
            if (isGameOver(board) == 1) {
                move = i;
                foundWinningMove = 1;
            }
            board[i] = 0;
        }
    }
    //Check for blocking moves
    for (int i = 1; i <= 9; i++) {
        if (isValidMove(board, i)) {
            board[i] = 'O';
            if (isGameOver(board) == 1) {
                move = i;
                foundBlockingMove = 1;
            }
            board[i] = 0;
        }
    }
    //Make a random move if no winning or blocking move is found
    while (!move) {
        int random = rand() % 9 + 1;
        if (isValidMove(board, random)) {
            move = random;
        }
    }
    //Print the result of the computer's move
    printf("Computer has made its move. \n");
    return move;
}

//Function for the player's move
int getPlayerMove(int board[]) {
    int move;
    printf("Enter your move (1-9): ");
    scanf("%d", &move);
    while (!isValidMove(board, move)) {
        printf("Invalid move. Enter a valid move (1-9): ");
        scanf("%d", &move);
    }
    board[move] = 'O';
    return move;
}

int main() {
    int board[10] = {0};
    int turn = 1;
    int result;
    //Loop to play the game until it is over
    while ((result = isGameOver(board)) == 0) {
        displayBoard(board);
        if (turn == 1) {
            getPlayerMove(board);
        }
        else {
            getComputerMove(board);
        }
        turn = turn % 2 + 1;
    }
    //Print the final result of the game
    displayBoard(board);
    if (result == 1) {
        printf("Game Over! %s wins!\n", turn == 1 ? "Computer" : "Player");
    }
    else if (result == 2) {
        printf("Game Over! It's a Tie!\n");
    }
    return 0;
}