//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_board(char[][3], int);
int check_winner(char[][3], char);
void generate_move(char[][3], char);

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player_symbol = 'X', comp_symbol = 'O';
    int turn = 0, winner = 0;

    printf("Welcome to Tic-Tac-Toe! You are 'X', and the computer is 'O'.\n");

    display_board(board, turn);

    while (turn < 9 && winner == 0) {
        if (turn % 2 == 0) {
            int row, col;
            printf("Enter row and column for your move: ");
            scanf("%d %d", &row, &col);

            if (row < 0 || row > 2 || col < 0 || col > 2) {
                printf("Invalid input! You lost your turn.\n");
                continue;
            }

            if (board[row][col] != ' ') {
                printf("That spot is already taken! You lost your turn.\n");
                continue;
            }

            board[row][col] = player_symbol;
        } 
        else {
            generate_move(board, comp_symbol);
        }

        turn++;
        display_board(board, turn);
        winner = check_winner(board, comp_symbol);
    }

    if (winner == 1) {
        printf("Game over! The computer wins!\n");
    } 
    else if (winner == -1) {
        printf("Game over! You win!\n");
    } 
    else {
        printf("Game over! It's a tie!\n");
    }

    return 0;
}

void display_board(char board[][3], int turn) {
    system("clear");
    printf("\nTIC-TAC-TOE!\n\n");

    for (int row=0; row<3; row++) {
        printf("     |     |     \n");
        printf("  %c  |  %c  |  %c  \n", board[row][0], board[row][1], board[row][2]);
        printf("_____|_____|_____\n");
    }

    printf("     |     |     \n");

    if (turn % 2 == 0) {
        printf("Your turn (%c)! Enter row and column: ", 'X');
    } 
    else {
        printf("Computer's turn (%c)!\n", 'O');
    }
}

int check_winner(char board[][3], char symbol) {
    for (int i=0; i<3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }

        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return 1;
        }
    }

    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }

    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }

    return -1;
}

void generate_move(char board[][3], char symbol) {
    printf("The computer is thinking...");

    srand(time(NULL));

    while (1) {
        int row = rand() % 3;
        int col = rand() % 3;

        if (board[row][col] == ' ') {
            printf("Computer chooses row %d, col %d!\n", row, col);
            board[row][col] = symbol;
            break;
        }
    }
}