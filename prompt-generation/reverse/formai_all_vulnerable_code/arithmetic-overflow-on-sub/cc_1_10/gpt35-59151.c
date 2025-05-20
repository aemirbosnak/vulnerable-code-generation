//FormAI DATASET v1.0 Category: Table Game ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ROWS 3
#define COLUMNS 3
#define MAX_MOVES 9

char board[ROWS][COLUMNS];
bool isGameOver = false;

void print_board() {
    printf("\n\n");
    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t_____|_____|_____\n");

    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t_____|_____|_____\n");

    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\t     |     |     \n");
}

bool is_valid_move(int x, int y) {
    if (x < 0 || x > ROWS - 1 || y < 0 || y > COLUMNS - 1) {
        return false;
    }

    if (board[x][y] == 'X' || board[x][y] == 'O') {
        return false;
    }

    return true;
}

void get_move(int *x, int *y, char player) {
    do {
        printf("Player %c, please enter row and column numbers (1-3): ", player);
        scanf("%d %d", x, y);
        (*x)--;
        (*y)--;
    } while (!is_valid_move(*x, *y));
}

bool check_diagonal() {
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }

    return false;
}

bool check_row_col(char x, int row_col_num) {
    if (board[row_col_num][0] == x && board[row_col_num][1] == x && board[row_col_num][2] == x) {
        return true;
    }

    if (board[0][row_col_num] == x && board[1][row_col_num] == x && board[2][row_col_num] == x) {
        return true;
    }

    return false;
}

bool check_win(char player) {
    if (check_diagonal()) {
        return true;
    }

    for (int i = 0; i < ROWS; i++) {
        if (check_row_col(player, i)) {
            return true;
        }
    }

    return false;
}

bool check_tie() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }

    return true;
}

void play_game() {
    int current_move = 0;

    print_board();

    while (current_move < MAX_MOVES) {
        char player = current_move % 2 == 0 ? 'X' : 'O';
        int x, y;

        get_move(&x, &y, player);

        board[x][y] = player;

        print_board();

        if (check_win(player)) {
            printf("Congratulations Player %c! You have won the game\n", player);
            isGameOver = true;
            break;
        }

        if (check_tie()) {
            printf("The game is tied.\n");
            isGameOver = true;
            break;
        }

        current_move++;
    }
}

int main() {
    printf("Welcome to Tic Tac Toe game!\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = ' ';
        }
    }

    while (!isGameOver) {
        play_game();

        printf("Do you want to play again? Press y for Yes or any other key to quit.\n");
        char user_input;
        scanf(" %c", &user_input);

        if (user_input != 'y') {
            break;
        }

        isGameOver = false;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                board[i][j] = ' ';
            }
        }
    }

    printf("Thank you for playing! Goodbye.\n");

    return 0;
}