//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];
char player_mark, ai_mark;

void init_board() {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board() {
    int i, j;

    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int check_win(char mark) {
    int i, j, row_win, col_win, diag_win;

    // Check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        row_win = 1;
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != mark) {
                row_win = 0;
                break;
            }
        }
        if (row_win == 1) {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < BOARD_SIZE; i++) {
        col_win = 1;
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[j][i] != mark) {
                col_win = 0;
                break;
            }
        }
        if (col_win == 1) {
            return 1;
        }
    }

    // Check diagonals
    diag_win = 1;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][i] != mark) {
            diag_win = 0;
            break;
        }
    }

    if (diag_win == 1) {
        return 1;
    }

    diag_win = 1;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][BOARD_SIZE-i-1] != mark) {
            diag_win = 0;
            break;
        }
    }

    if (diag_win == 1) {
        return 1;
    }

    return 0;
}

int get_random_move() {
    int i, j;

    do {
        i = rand() % BOARD_SIZE;
        j = rand() % BOARD_SIZE;
    } while (board[i][j] != '-');

    return i * BOARD_SIZE + j;
}

int minimax(int depth, int is_maximizing, int alpha, int beta) {
    int i, j, score;
    int best_score = is_maximizing ? -1000 : 1000;
    int curr_score, move;

    if (depth == 0 || check_win(ai_mark) || check_win(player_mark)) {
        if (check_win(ai_mark)) {
            return 10;
        } else if (check_win(player_mark)) {
            return -10;
        } else {
            return 0;
        }
    }

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '-') {
                if (is_maximizing) {
                    board[i][j] = ai_mark;
                    curr_score = minimax(depth - 1, 0, alpha, beta);
                    if (curr_score > best_score) {
                        best_score = curr_score;
                        move = i * BOARD_SIZE + j;
                    }
                    alpha = alpha > best_score ? alpha : best_score;
                } else {
                    board[i][j] = player_mark;
                    curr_score = minimax(depth - 1, 1, alpha, beta);
                    if (curr_score < best_score) {
                        best_score = curr_score;
                        move = i * BOARD_SIZE + j;
                    }
                    beta = beta < best_score ? beta : best_score;
                }
                board[i][j] = '-';
                if (alpha >= beta) {
                    break; // Alpha-beta pruning
                }
            }
        }
    }

    return depth == 6 ? move : best_score;
}

void ai_turn() {
    int i, j, move;

    if (board[1][1] == '-') {
        move = minimax(6, 1, -1000, 1000);
    } else {
        if (board[0][0] == '-' || board[2][2] == '-') {
            move = 0;
        } else if (board[0][2] == '-' || board[2][0] == '-') {
            move = 2;
        } else {
            move = get_random_move();
        }
    }

    i = move / BOARD_SIZE;
    j = move % BOARD_SIZE;
    board[i][j] = ai_mark;
    printf("AI chose position (%d, %d).\n", i, j);
}

void player_turn() {
    int i, j;

    do {
        printf("Enter row and column (example: 0 1): ");
        scanf("%d %d", &i, &j);
    } while (i < 0 || i >= BOARD_SIZE || j < 0 || j >= BOARD_SIZE || board[i][j] != '-');

    board[i][j] = player_mark;
}

void game() {
    int turn = 0;

    printf("Welcome to Tic Tac Toe!\n");
    printf("Choose your mark (X or O): ");
    scanf("%c", &player_mark);

    if (player_mark == 'X') {
        ai_mark = 'O';
    } else {
        ai_mark = 'X';
    }

    srand(time(0));

    init_board();
    print_board();

    while (!check_win(player_mark) && !check_win(ai_mark) && turn < BOARD_SIZE * BOARD_SIZE) {
        if (turn % 2 == 0) {
            player_turn();
        } else {
            ai_turn();
        }
        print_board();
        turn++;
    }

    if (check_win(player_mark)) {
        printf("You win!\n");
    } else if (check_win(ai_mark)) {
        printf("AI wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}

int main() {
    game();
    return 0;
}