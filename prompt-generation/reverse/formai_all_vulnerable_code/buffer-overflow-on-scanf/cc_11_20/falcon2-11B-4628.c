//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int ttt_board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
bool board_full = false;
bool is_ai_turn = false;

void print_board() {
    printf("-------------\n");
    printf("| %c %c %c |\n", ttt_board[0][0] + 'a', ttt_board[0][1] + 'a', ttt_board[0][2] + 'a');
    printf("| %c %c %c |\n", ttt_board[1][0] + 'a', ttt_board[1][1] + 'a', ttt_board[1][2] + 'a');
    printf("| %c %c %c |\n", ttt_board[2][0] + 'a', ttt_board[2][1] + 'a', ttt_board[2][2] + 'a');
    printf("-------------\n");
}

int check_win(int player) {
    if (ttt_board[0][0] == player && ttt_board[0][1] == player && ttt_board[0][2] == player) {
        return 1;
    }
    if (ttt_board[1][0] == player && ttt_board[1][1] == player && ttt_board[1][2] == player) {
        return 1;
    }
    if (ttt_board[2][0] == player && ttt_board[2][1] == player && ttt_board[2][2] == player) {
        return 1;
    }
    if (ttt_board[0][0] == player && ttt_board[1][0] == player && ttt_board[2][0] == player) {
        return 1;
    }
    if (ttt_board[0][1] == player && ttt_board[1][1] == player && ttt_board[2][1] == player) {
        return 1;
    }
    if (ttt_board[0][2] == player && ttt_board[1][2] == player && ttt_board[2][2] == player) {
        return 1;
    }
    if (ttt_board[0][0] == player && ttt_board[1][1] == player && ttt_board[2][2] == player) {
        return 1;
    }
    if (ttt_board[2][0] == player && ttt_board[1][1] == player && ttt_board[0][2] == player) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char player_input = 'X';
    char ai_input = 'O';

    int row, col;
    while (!board_full) {
        print_board();

        if (is_ai_turn) {
            row = rand() % 3;
            col = rand() % 3;
            ttt_board[row][col] = ai_input;
            is_ai_turn = false;
        } else {
            row = -1;
            col = -1;

            while (row < 0 || row > 2 || col < 0 || col > 2) {
                printf("Enter row and column (0-2): ");
                scanf("%d %d", &row, &col);
            }

            ttt_board[row][col] = player_input;
            is_ai_turn = true;
        }

        if (check_win(ai_input)) {
            printf("AI wins!\n");
            break;
        } else if (check_win(player_input)) {
            printf("Player wins!\n");
            break;
        }
    }

    printf("Game Over\n");

    return 0;
}