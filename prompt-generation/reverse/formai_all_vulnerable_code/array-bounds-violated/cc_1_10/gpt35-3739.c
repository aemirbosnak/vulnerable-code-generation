//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to clear the console screen
void clear_screen() {
    system("clear");
}

// function to display the game board
void display_board(char board[]) {
    clear_screen();

    printf(" ---------------------\n");
    printf("|       |       |      |\n");
    printf("|   %c   |   %c   |   %c   |\n", board[0], board[1], board[2]);
    printf("|       |       |      |\n");
    printf("|----------------------|\n");
    printf("|       |       |      |\n");
    printf("|   %c   |   %c   |   %c   |\n", board[3], board[4], board[5]);
    printf("|       |       |      |\n");
    printf("|----------------------|\n");
    printf("|       |       |      |\n");
    printf("|   %c   |   %c   |   %c   |\n", board[6], board[7], board[8]);
    printf("|       |       |      |\n");
    printf(" ---------------------\n\n");
}

// function to check if a player has won
int check_win(char board[], char player) {
    if (
        (board[0] == player && board[1] == player && board[2] == player) ||
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player) ||
        (board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player) ||
        (board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)
    ) {
        return 1;
    } else {
        return 0;
    }
}

// function to check if all spots on the board are filled
int check_tie(char board[]) {
    int i;

    for (i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return 0;
        }
    }

    return 1;
}

int main() {
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player1 = 'X', player2 = 'O', current;
    int spot, win, tie, player1_turn;

    srand(time(0)); // seed the random number generator

    // randomly determine which player goes first
    player1_turn = rand() % 2;

    // set the player whose turn it is
    if (player1_turn) {
        current = player1;
    } else {
        current = player2;
    }

    while (1) {
        display_board(board);

        if (current == player1) {
            printf("Player 1 (X), enter a spot on the board (1-9): ");
        } else {
            printf("Player 2 (O), enter a spot on the board (1-9): ");
        }

        scanf("%d", &spot);

        if (board[spot - 1] != ' ') {
            printf("That spot is already taken, please choose another.\n\n");
            continue;
        }

        board[spot - 1] = current;

        win = check_win(board, current);
        tie = check_tie(board);

        if (win) {
            display_board(board);

            if (current == player1) {
                printf("Player 1 (X) wins!\n");
            } else {
                printf("Player 2 (O) wins!\n");
            }

            break;
        } else if (tie) {
            display_board(board);
            printf("It is a tie!\n");
            break;
        }

        // switch to the other player's turn
        if (current == player1) {
            current = player2;
        } else {
            current = player1;
        }
    }

    return 0;
}