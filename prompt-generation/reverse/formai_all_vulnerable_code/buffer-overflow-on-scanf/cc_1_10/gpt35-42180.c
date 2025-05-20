//FormAI DATASET v1.0 Category: Table Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

char board[3][3];
char player = 'X';

void initialize_board();
void print_board();
int is_valid_move(int x, int y);
int is_game_over();
int check_winner();

int main() {
    int x, y;

    initialize_board();

    while (!is_game_over()) {
        print_board();

        printf("Player %c's turn \n", player);
        printf("Enter x-coordinate: ");
        scanf("%d", &x);
        printf("Enter y-coordinate: ");
        scanf("%d", &y);

        if (is_valid_move(x, y)) {
            board[x][y] = player;
            player = player == 'X' ? 'O' : 'X';
        } else {
            printf("Invalid move, try again\n");
        }
    }

    print_board();

    if (check_winner() == 1) {
        printf("Player X wins!\n");
    } else if (check_winner() == -1) {
        printf("Player O wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}

void initialize_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    printf("  0 1 2\n");

    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int x, int y) {
    if (x < 0 || x > 2 || y < 0 || y > 2) {
        return 0;
    } else if (board[x][y] != ' ') {
        return 0;
    }
    return 1;
}

int is_game_over() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int check_winner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0] == 'X' ? 1 : -1;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i] == 'X' ? 1 : -1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0] == 'X' ? 1 : -1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2] == 'X' ? 1 : -1;
    }

    return 0;
}