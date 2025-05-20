//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

void display_board() {
    printf("\n");
    printf("\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t---+---+---\n");
    printf("\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t---+---+---\n");
    printf("\t %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int is_valid_move(int x, int y) {
    return (x >= 0 && x < 3 && y >= 0 && y < 3 && board[x][y] == ' ');
}

int get_board_score() {
    int score = 0;
    // evaluate rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') score += 10;
            else if (board[i][0] == 'O') score -= 10;
        }
    }
    // evaluate columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            if (board[0][j] == 'X') score += 10;
            else if (board[0][j] == 'O') score -= 10;
        }
    }
    // evaluate diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') score += 10;
        else if (board[0][0] == 'O') score -= 10;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X') score += 10;
        else if (board[0][2] == 'O') score -= 10;
    }
    return score;
}

int get_best_move(int *x, int *y) {
    int max_score = -100;
    // try all possible moves and select the best one
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (is_valid_move(i, j)) {
                board[i][j] = 'X';
                int score = minimax(board, 0, 0);
                board[i][j] = ' ';
                if (score > max_score) {
                    max_score = score;
                    *x = i;
                    *y = j;
                }
            }
        }
    }
    return max_score;
}

int minimax(char board[][3], int depth, int is_max) {
    int score = get_board_score();
    if (score == 10 || score == -10) return score;
    if (is_board_full()) return 0;
    if (is_max) {
        int max_score = -100;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (is_valid_move(i, j)) {
                    board[i][j] = 'X';
                    int s = minimax(board, depth + 1, 0);
                    max_score = (s > max_score) ? s : max_score;
                    board[i][j] = ' ';
                }
            }
        }
        return max_score;
    } else {
        int min_score = 100;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (is_valid_move(i, j)) {
                    board[i][j] = 'O';
                    int s = minimax(board, depth + 1, 1);
                    min_score = (s < min_score) ? s : min_score;
                    board[i][j] = ' ';
                }
            }
        }
        return min_score;
    }
}

int is_board_full() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    int x, y, turn = 0;
    display_board();
    while (!is_board_full()) {
        if (turn == 0) {
            printf("It is your turn! Enter the row and column number to place your symbol: ");
            scanf("%d %d", &x, &y);
            if (!is_valid_move(x, y)) {
                printf("Invalid move! Try again.\n");
                continue;
            }
            board[x][y] = 'O';
        } else {
            printf("It is the AI's turn!\n");
            get_best_move(&x, &y);
            board[x][y] = 'X';
        }
        display_board();
        int score = get_board_score();
        if (score == 10) {
            printf("Congratulations! You win!\n");
            break;
        } else if (score == -10) {
            printf("Oops! You lose!\n");
            break;
        }
        turn = (turn + 1) % 2;
    }
    if (is_board_full()) {
        printf("It's a tie! Better luck next time!\n");
    }
    return 0;
}