//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to print the game board
void print_board(char board[][3]) {
    printf("\n");
    printf("\t%s | %s | %s\n", &board[0][0], &board[0][1], &board[0][2]);
    printf("\t-- | -- | --\n");
    printf("\t%s | %s | %s\n", &board[1][0], &board[1][1], &board[1][2]);
    printf("\t-- | -- | --\n");
    printf("\t%s | %s | %s\n", &board[2][0], &board[2][1], &board[2][2]);
    printf("\n");
}

// function to check if a player has won the game
int check_win(char board[][3], char player) {
    int i,j;
    for(i=0;i<3;i++) {
        if((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
           (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    if((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
       (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

int main() {
    char board[3][3] = {"1","2","3","4","5","6","7","8","9"};
    int row, col, move_valid, i, j, player, move_count=0;

    srand(time(NULL)); // initialize random seed

    printf("Welcome to the Tic-Tac-Toe game!\n");

    print_board(board); // print the initial game board

    // randomly select who goes first
    player = rand() % 2 + 1; // choose player 1 or player 2

    while(move_count < 9) { // loop while there are still moves left
        printf("Player %d, enter the row and column to place your piece (e.g. 1 2): ", player);
        scanf("%d %d", &row, &col); // get the row and column from the player

        // check if move is valid
        move_valid = 0;
        if(board[row-1][col-1] != 'X' && board[row-1][col-1] != 'O') {
            move_valid = 1;
        }

        if(move_valid) { // if the move is valid, make the move and update the board
            if(player == 1) {
                board[row-1][col-1] = 'X';
            } else {
                board[row-1][col-1] = 'O';
            }
            move_count++; // increment the move count
        } else { // if the move is not valid, ask the player to enter a new move
            printf("Invalid move. Please enter a different row and column.\n");
            continue;
        }

        print_board(board); // print the updated game board

        // check if the player has won the game
        if(check_win(board, player == 1 ? 'X' : 'O')) {
            printf("Player %d wins!\n", player);
            break;
        }

        // switch to the other player
        player = (player == 1 ? 2 : 1);
    }

    if(move_count == 9) { // if all the moves have been made and no one has won, it is a tie
        printf("Tie game!\n");
    }

    return 0;
}