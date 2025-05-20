//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: immersive
/*
 * A unique C Tic Tac Toe AI example program in an immersive style
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 1
#define O 2
#define EMPTY 0

void print_board(int board[3][3]) {
    printf("  1 | 2 | 3\n");
    printf("  ---------\n");
    printf("  4 | 5 | 6\n");
    printf("  ---------\n");
    printf("  7 | 8 | 9\n");
}

int get_move(int board[3][3], int player) {
    int move;
    printf("Player %d, enter your move (1-9): ", player);
    scanf("%d", &move);
    while (move < 1 || move > 9) {
        printf("Invalid move. Enter a number between 1 and 9: ");
        scanf("%d", &move);
    }
    return move;
}

int evaluate_board(int board[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    } else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return EMPTY;
}

int make_move(int board[3][3], int player) {
    int move = get_move(board, player);
    board[move - 1][move - 1] = player;
}

int main() {
    int board[3][3] = {
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY}
    };

    srand(time(NULL));

    int player = rand() % 2 + 1;

    while (1) {
        print_board(board);
        make_move(board, player);
        int result = evaluate_board(board);
        if (result == X) {
            printf("Player 1 wins!\n");
            break;
        } else if (result == O) {
            printf("Player 2 wins!\n");
            break;
        }
        player = player == X ? O : X;
    }

    return 0;
}