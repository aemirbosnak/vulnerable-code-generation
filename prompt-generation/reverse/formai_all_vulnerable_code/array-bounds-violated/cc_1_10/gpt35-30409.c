//FormAI DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>

// function to print the game board
void print_board(char board[][3]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// function to check if the game is over
int check_game_over(char board[][3]) {
    int i, j;

    // check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2])
        || (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return 1;
    }

    // check for tie
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }

    return 2;
}

// main function
int main() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    int i, j, row, col, player = 1, choice;

    printf("Welcome to Tic Tac Toe!\n\n");

    // game loop
    while (1) {
        // print the game board
        print_board(board);

        // get the player's move
        do {
            printf("\nPlayer %d's turn (Enter a number 1-9): ", player);
            scanf("%d", &choice);

            row = (choice - 1) / 3;
            col = (choice - 1) % 3;
        } while (board[row][col] != ' ');

        // mark the player's move on the board
        if (player == 1) {
            board[row][col] = 'X';
        } else {
            board[row][col] = 'O';
        }

        // check for game over
        if (check_game_over(board) == 1) {
            // print the winning player and exit game loop
            print_board(board);
            printf("\nCongratulations! Player %d wins!\n", player);
            break;
        } else if (check_game_over(board) == 2) {
            // print tie and exit game loop
            print_board(board);
            printf("\nThe game ends in a tie!\n");
            break;
        }

        // switch players
        player = player == 1 ? 2 : 1;
    }

    return 0;
}