//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to display the game board
void display_board(int board[3][3]) {
    printf("\n-------------\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("| %d ", board[i][j]);
        }
        printf("|\n-------------\n");
    }
}

// function to check if any player has won the game
int check_win(int board[3][3], int player) {
    // check rows for winning
    for(int i=0; i<3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // check columns for winning
    for(int i=0; i<3; i++) {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    // check diagonals for winning
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    // if no player has won the game yet
    return 0;
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    int board[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    display_board(board); // display the initial board
    int player = 1; // player 1 will start the game
    int num_moves = 0;
    while(num_moves < 9) { // no more than 9 moves can be made
        int row, col;
        printf("Player %d: Enter row and column to mark (e.g. 1 2): ", player);
        scanf("%d %d", &row, &col);
        // check if valid input is given
        if(row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid input! Try again.\n");
            continue; // go back to start of while loop
        }
        // check if the spot is already taken
        if(board[row-1][col-1] == 'X' || board[row-1][col-1] == 'O') {
            printf("This spot is already taken! Try again.\n");
            continue; // go back to start of while loop
        }
        // mark the spot with X or O based on the player
        if(player == 1) {
            board[row-1][col-1] = 'X';
            num_moves++;
            if(check_win(board, player)) { // player 1 has won
                printf("Player %d has won!\n", player);
                display_board(board);
                return 0;
            }
            printf("\nPlayer 2's turn:");
            player = 2; // switch to player 2
        }
        else {
            board[row-1][col-1] = 'O';
            num_moves++;
            if(check_win(board, player)) { // player 2 has won
                printf("Player %d has won!\n", player);
                display_board(board);
                return 0;
            }
            printf("\nPlayer 1's turn:");
            player = 1; // switch to player 1
        }
        display_board(board); // display the updated board
    }
    // if no player has won and all spots are filled, it's a draw!
    printf("It's a tie!\n");
    display_board(board);
    return 0;
}