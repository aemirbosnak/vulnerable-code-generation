//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: retro
#include <stdio.h>
#include <stdlib.h>

void display_board(char board[9]);
int winning_move(char board[9], char ch);
int check_winner(char board[9]);
int minimax(char board[9], int depth, int is_max_player, char marker);
int get_best_move(char board[9], char marker);

int main() {
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player_marker, computer_marker;
    int move = 0, winner = 0;

    printf("Welcome to Tic Tac Toe!\n");
    printf("Choose your marker (X/O): ");
    scanf(" %c", &player_marker);

    if (player_marker == 'X') {
        computer_marker = 'O';
    } else {
        computer_marker = 'X';
    }

    display_board(board);

    while (winner == 0) {
        // Player's turn
        printf("\nYour move (1-9): ");
        scanf("%d", &move);

        if (board[move - 1] == ' ') {
            board[move - 1] = player_marker;
        } else {
            printf("That spot is already taken.\n");
            continue;
        }

        display_board(board);

        winner = check_winner(board);

        if (winner != 0) {
            break;
        }

        // Computer's turn
        printf("\nComputer's move:\n");

        int best_move = get_best_move(board, computer_marker);

        board[best_move] = computer_marker;

        display_board(board);

        winner = check_winner(board);
    }

    if (winner == 3) {
        printf("\nIt's a tie!\n");
    } else if (winner == 1) {
        printf("\nYou win!\n");
    } else if (winner == 2) {
        printf("\nThe computer wins!\n");
    }

    return 0;
}

void display_board(char board[9]) {
    printf("\n");

    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
}

int winning_move(char board[9], char ch) {
    if ((board[0] == ch && board[1] == ch && board[2] == ch) ||
        (board[3] == ch && board[4] == ch && board[5] == ch) ||
        (board[6] == ch && board[7] == ch && board[8] == ch) ||
        (board[0] == ch && board[3] == ch && board[6] == ch) ||
        (board[1] == ch && board[4] == ch && board[7] == ch) ||
        (board[2] == ch && board[5] == ch && board[8] == ch) ||
        (board[0] == ch && board[4] == ch && board[8] == ch) ||
        (board[2] == ch && board[4] == ch && board[6] == ch)) {
        return 1;
    }

    return 0;
}

int check_winner(char board[9]) {
    if (winning_move(board, 'X')) {
        return 1;
    }

    if (winning_move(board, 'O')) {
        return 2;
    }

    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return 0;
        }
    }

    return 3;
}

int minimax(char board[9], int depth, int is_max_player, char marker) {
    int score = check_winner(board);

    if (score == 1) {
        return 10 - depth;
    }

    if (score == 2) {
        return depth - 10;
    }

    if (score == 3) {
        return 0;
    }

    if (is_max_player) {
        int max_score = -1000;

        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                board[i] = marker;

                int current_score = minimax(board, depth + 1, 0, marker);

                if (current_score > max_score) {
                    max_score = current_score;
                }

                board[i] = ' ';
            }
        }

        return max_score;
    } else {
        int min_score = 1000;

        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                board[i] = (marker == 'X') ? 'O' : 'X';

                int current_score = minimax(board, depth + 1, 1, marker);

                if (current_score < min_score) {
                    min_score = current_score;
                }

                board[i] = ' ';
            }
        }

        return min_score;
    }
}

int get_best_move(char board[9], char marker) {
    int best_move = -1;
    int max_score = -1000;

    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = marker;

            int current_score = minimax(board, 0, 0, marker);

            if (current_score > max_score) {
                max_score = current_score;
                best_move = i;
            }

            board[i] = ' ';
        }
    }

    return best_move;
}