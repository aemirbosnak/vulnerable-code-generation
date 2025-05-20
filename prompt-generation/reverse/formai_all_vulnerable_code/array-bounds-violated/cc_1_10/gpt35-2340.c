//FormAI DATASET v1.0 Category: Table Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLUMNS 3

void init_board(char board[ROWS][COLUMNS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board(char board[ROWS][COLUMNS]) {
    printf("-------------\n");
    for(int i=0; i<ROWS; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

int check_winner(char board[ROWS][COLUMNS]) {
    // Check rows
    for(int i=0; i<ROWS; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
    }
    // Check columns
    for(int i=0; i<COLUMNS; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }
    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLUMNS];
    char players[2] = {'X', 'O'};
    int current_player = rand() % 2; // Randomly choose the starting player
    int row, column;
    int moves = 0;
    init_board(board);
    printf("Welcome to the Shape-Shifting Tic Tac Toe game!\n");
    printf("You can shift a row or a column to the left or to the right.\n");
    printf("To do that, enter 'R' for right, or 'L' for left, followed by the row/column number.\n");
    printf("For example, 'R2' means shifting row 2 to the right.\n");
    printf("Let's Play!\n");
    while(1) {
        printf("Player %c's turn.\n", players[current_player]);
        print_board(board);
        printf("Enter your move: ");
        char input[3];
        scanf("%s", input);
        if(input[0] == 'R' || input[0] == 'L') {
            int index = input[1] - '0';
            if(input[0] == 'R') {
                char temp = board[index-1][COLUMNS-1];
                for(int i=COLUMNS-1; i>0; i--) {
                    board[index-1][i] = board[index-1][i-1];
                }
                board[index-1][0] = temp;
            } else {
                char temp = board[index-1][0];
                for(int i=0; i<COLUMNS-1; i++) {
                    board[index-1][i] = board[index-1][i+1];
                }
                board[index-1][COLUMNS-1] = temp;
            }
        } else {
            row = input[0] - '1';
            column = input[1] - '1';
            if(board[row][column] == ' ') {
                board[row][column] = players[current_player];
                moves++;
                if(check_winner(board)) {
                    printf("Congratulations, player %c won!", players[current_player]);
                    break;
                }
                if(moves == ROWS * COLUMNS) {
                    printf("It's a draw!");
                    break;
                }
                current_player = (current_player + 1) % 2;
            } else {
                printf("This cell is already occupied.\n");
            }
        }
    }
    return 0;
}