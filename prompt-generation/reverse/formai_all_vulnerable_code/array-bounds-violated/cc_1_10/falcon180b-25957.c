//Falcon-180B DATASET v1.0 Category: Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define NUM_EMPTY_SPACES (ROWS * COLS)

void print_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // Initialize the game board with empty spaces
    char board[ROWS][COLS] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int player = 1;
    int choice;
    int valid_move = 0;

    while (valid_move == 0) {
        system("clear");
        print_board(board);
        printf("\nPlayer %d's turn.\n", player);

        valid_move = 1;

        printf("Enter your move (row and column separated by a space): ");
        scanf("%d %d", &choice, &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid move. Please try again.\n");
            valid_move = 0;
        } else if (board[choice - 1][0]!= 'X' && board[choice - 1][1]!= 'X' && board[choice - 1][2]!= 'X') {
            board[choice - 1][0] = (player % 2 == 0)? 'X' : 'O';
            valid_move = 0;
        } else {
            printf("That space is already taken. Please try again.\n");
        }

        player++;
        if (player > 2) {
            player = 1;
        }
    }

    if (player == 1) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    return 0;
}