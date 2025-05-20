//FormAI DATASET v1.0 Category: Table Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Function to print the game board
void print_board(int board[][3]) {
    printf("\t\t  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t\t-----------\n");
    printf("\t\t  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t\t-----------\n");
    printf("\t\t  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// Function to check if a player has won
int check_win(int board[][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

int main() {
    int board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int players = 2; // number of players
    int player_turn = 0; // player turn
    int move_count = 0; // total moves played
    int row, col; // row and column input by user
    char mark; // X or O for the players
    int winner = 0; // flag to check if winner is found

    printf("\t\tTIC TAC TOE GAME\n\n");
    printf("Player 1 will be X and Player 2 will be O\n");

    while (move_count < 9) {
        print_board(board);
        player_turn %= players;
        mark = player_turn == 0 ? 'X' : 'O';

        printf("Player %d, enter a row (1, 2, or 3) for position %c: ", player_turn + 1, mark);
        scanf("%d", &row);
        printf("Enter a column (1, 2, or 3) for position %c: ", mark);
        scanf("%d", &col);

        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid input. Please try again.\n");
            continue;
        }
        if (board[row-1][col-1] == 'X' || board[row-1][col-1] == 'O') {
            printf("That space is already taken. Please try again.\n");
            continue;
        }
        board[row-1][col-1] = mark;
        move_count++;
        player_turn++;

        if (move_count >= 5) {
            winner = check_win(board, mark);
            if (winner) {
                print_board(board);
                printf("Player %d won!\n", player_turn);
                break;
            }
        }
    }

    if (!winner) {
        print_board(board);
        printf("It's a tie!\n");
    }

    return 0;
}