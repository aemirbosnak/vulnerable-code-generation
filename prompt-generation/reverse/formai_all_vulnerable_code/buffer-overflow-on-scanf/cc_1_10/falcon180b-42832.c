//Falcon-180B DATASET v1.0 Category: Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to print the game board
void print_board(int board[3][3]) {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(board[i][j] == 1)
                printf("X ");
            else if(board[i][j] == 2)
                printf("O ");
            else
                printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check for a win condition
bool check_win(int board[3][3]) {
    // Check rows
    for(int i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
    }

    // Check columns
    for(int j=0; j<3; j++) {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return true;
    }

    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

// Function to get user input for a move
int get_move(int board[3][3]) {
    int row, col;
    printf("Enter your move (row and column): ");
    scanf("%d%d", &row, &col);
    if(row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == 0)
        return row*3 + col;
    else
        return -1;
}

int main() {
    srand(time(NULL));
    int board[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    int player = 1; // Player 1 starts
    int move;

    while(true) {
        system("clear");
        printf("\nPlayer 1: X, Player 2: O\n");
        print_board(board);
        move = get_move(board);
        if(move == -1) {
            printf("\nInvalid move. Try again.\n");
            continue;
        }
        board[move/3][move%3] = player;
        player = (player == 1)? 2 : 1;
        if(check_win(board)) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }
    }

    return 0;
}