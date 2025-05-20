//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Romeo and Juliet
#include <stdio.h>

#define BOARD_SIZE 3

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
            if (j < BOARD_SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) {
            printf("-+-+-\n");
        }
    }
}

int get_ai_move(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Implement AI move logic here
    return 0;
}

int is_game_over(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Check if someone has won or if the board is full
    return 0;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int player = 1;

    while (!is_game_over(board)) {
        print_board(board);

        int row, col;
        if (player == 1) {
            printf("Player 1's turn: ");
            scanf("%d %d", &row, &col);
        } else {
            printf("AI's turn\n");
            int move = get_ai_move(board);
            row = move / BOARD_SIZE;
            col = move % BOARD_SIZE;
        }

        if (board[row][col] != ' ') {
            printf("That spot is already taken! Try again.\n");
            continue;
        }

        board[row][col] = player == 1 ? 'X' : 'O';

        player = player == 1 ? 2 : 1;
    }

    print_board(board);

    printf("Game over!\n");

    return 0;
}