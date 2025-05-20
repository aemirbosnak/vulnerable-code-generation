//FormAI DATASET v1.0 Category: Table Game ; Style: genious
/*This is a program for a unique C table game. 
The game requires two players. Each player will have six balls of the same color. 
The goal of the game is for each player to get all six balls in a line vertically, horizontally, or diagonally before the other player.*/

#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLUMNS 6

char board[ROWS][COLUMNS];  //initialize the game board

void initialize_board();  //function to initialize the game board
void display_board();  //function to display game board
int check_horizontal();  //function to check horizontal line
int check_vertical();  //function to check vertical line
int check_diagonal();  //function to check diagonal line

int main() {

    char player1[20];  //player1 name
    char player2[20];  //player2 name
    int row, col, i, j, flag, count = 0, winner = 0;
    initialize_board();  //initialize the game board

    printf("Welcome to the Six-Ball table game tutorial.\n");
    printf("Rules for the game are simple, but winning this game requires both skills and luck. \n");
    printf("Both players will have six balls of the same color. \n");
    printf("The goal of the game is for each player to get all six balls in a line vertically, horizontally, or diagonally before the other player.\n");
    printf("Let's Start the Game!\n");
    printf("Player 1, Enter your Name: ");
    scanf("%s", player1);
    printf("Player 2, Enter your Name: ");
    scanf("%s", player2);

    while (count < 36) {
        flag = count % 2 == 0 ? 1 : 2;  //alternate turn between player 1 and player 2

        printf("%s, Enter Grid Number to Put your Ball (1-6): ", flag == 1 ? player1 : player2);
        scanf("%d", &row);
        scanf("%d", &col);

        if (row >= 1 && row <= 6 && col >= 1 && col <= 6) {  //first check if row and column values are in the correct range

            if (board[row - 1][col - 1] == ' ') {  //check if the square is already filled

                if (flag == 1) {
                    board[row - 1][col - 1] = 'O';   //mark on the board with Player 1's mark
                }
                else {
                    board[row - 1][col - 1] = 'X';   //mark on the board with Player 2's mark
                }

                display_board();
                count++;

                if (count >= 12) {  // check winner after every 6 turns
                    winner = check_horizontal() + check_vertical() + check_diagonal();

                    if (winner == 1) {
                        printf("Congratulation, %s! You won the game. Better luck next time, %s.\n", flag == 1 ? player1 : player2, flag == 2 ? player1 : player2);
                        exit(0);
                    }
                }
            }
            else {
                printf("Oops! The given row:%d and column %d is already filled. Try with other Grid location\n", row, col);
                continue;
            }
        }
        else {
            printf("Oops! You entered a invalid row or column (Out of given range, 1-6). Try Again\n");
        }
    }
    printf("Oops! The Game is Draw. Better luck next time, %s and %s.\n", player1, player2);

    return 0;
}

void initialize_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            board[i][j] = ' ';
        }
    }
}

void display_board() {
    int i, j;

    printf("\n");

    for (i = 0; i < ROWS; i++) {

        for (j = 0; j < COLUMNS; j++) {
            printf("| %c\t", board[i][j]);
        }
        printf("|\n-------------------------------------------\n");
    }
}

int check_horizontal() {

    int i, j, flag;

    for (i = 0; i < ROWS; i++) {
        flag = 1;
        for (j = 1; j < COLUMNS; j++) {
            if (board[i][j] != board[i][0] || board[i][j] == ' ') {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            return 1;
        }
    }
    return 0;
}

int check_vertical() {

    int i, j, flag;

    for (i = 0; i < COLUMNS; i++) {
        flag = 1;
        for (j = 1; j < ROWS; j++) {
            if (board[j][i] != board[0][i] || board[j][i] == ' ') {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            return 1;
        }
    }
    return 0;
}

int check_diagonal() {

    int i, flag1 = 1, flag2 = 1;

    for (i = 1; i < ROWS; i++) {
        if (board[0][0] != board[i][i] || board[0][0] == ' ') {
            flag1 = 0;
        }
        if (board[0][COLUMNS - 1] != board[i][COLUMNS - 1 - i] || board[0][COLUMNS - 1] == ' ') {
            flag2 = 0;
        }
    }
    if (flag1 == 1 || flag2 == 1) {
        return 1;
    }
    else {
        return 0;
    }
}