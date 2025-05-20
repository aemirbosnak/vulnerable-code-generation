//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];
char opponent;
char player;
char empty = ' ';
int turn = 1;

void initialize_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = empty;
        }
    }
}

int game_over() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != empty) {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != empty) {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != empty) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != empty) {
        return 1;
    }
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == empty) {
                return 0;
            }
        }
    }
    return 2;
}

void computer_turn() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == empty) {
                board[i][j] = opponent;
                int score = -1 * alpha_beta_pruning(&opponent, &player, 1);
                board[i][j] = empty;
                if (score > turn) {
                    turn = score;
                    board[i][j] = opponent;
                    return;
                }
            }
        }
    }
}

int alpha_beta_pruning(char *maximizer, char *minimizer, int depth) {
    int i, j, game_state = game_over();
    if (game_state == 1) {
        return -1;
    }
    if (game_state == 2) {
        return 0;
    }
    if (*maximizer == player) {
        int min_score = 2, score;
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == empty) {
                    board[i][j] = player;
                    score = alpha_beta_pruning(minimizer, maximizer, depth + 1);
                    if (score < min_score) {
                        min_score = score;
                    }
                    board[i][j] = empty;
                }
            }
        }
        return min_score;
    } else {
        int max_score = -2, score;
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == empty) {
                    board[i][j] = opponent;
                    score = alpha_beta_pruning(minimizer, maximizer, depth + 1);
                    if (score > max_score) {
                        max_score = score;
                    }
                    board[i][j] = empty;
                }
            }
        }
        return max_score;
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
}

void human_turn() {
    int x, y;
    printf("Enter the x co-ordinate:\n");
    scanf("%d", &x);
    printf("Enter the y co-ordinate:\n");
    scanf("%d", &y);
    while (board[x][y] != empty || x > BOARD_SIZE - 1 || y > BOARD_SIZE - 1) {
        printf("Invalid move, please make another:\n");
        scanf("%d", &x);
        scanf("%d", &y);
    }
    board[x][y] = player;
}

int main() {
    printf("Welcome to Tic Tac Toe!");
    printf("\nWould you like to go first? (y/n)\n");
    char input;
    scanf(" %c", &input);
    srand(time(NULL));
    opponent = rand() % 2 == 0 ? 'X' : 'O';
    player = input == 'y' ? opponent == 'X' ? 'O' : 'X' : opponent;
    initialize_board();
    while (game_over() == 0) {
        print_board();
        if (turn % 2 == 1 && player == 'X' || turn % 2 == 0 && player == 'O') {
            human_turn();
        } else {
            computer_turn();
        }
        turn++;
    }
    print_board();
    switch (game_over()) {
        case 1:
            printf("Game over. %c wins!", player == 'X' ? 'O' : 'X');
            break;
        case 2:
            printf("Game over. It's a tie!");
            break;
    }
    return 0;
}