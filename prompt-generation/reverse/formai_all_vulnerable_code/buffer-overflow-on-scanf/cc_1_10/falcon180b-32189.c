//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define EMPTY '.'
#define PLAYER 'X'
#define COMPUTER 'O'
#define WIN_CONDITION 111

int board[ROWS][COLS];
int player_row, player_col;
int computer_row, computer_col;
int game_over = 0;

void initialize_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void print_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win() {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0]!= EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return WIN_CONDITION;
        }
        if (board[0][i]!= EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return WIN_CONDITION;
        }
    }
    if (board[0][0]!= EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return WIN_CONDITION;
    }
    if (board[0][2]!= EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return WIN_CONDITION;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    initialize_board();
    player_row = rand() % ROWS;
    player_col = rand() % COLS;
    board[player_row][player_col] = PLAYER;
    print_board();

    while (!game_over) {
        int choice;
        printf("Enter your choice of row and column: ");
        scanf("%d %d", &choice, &choice);
        int row = (choice - 1) / COLS;
        int col = (choice - 1) % COLS;

        if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == EMPTY) {
            board[row][col] = PLAYER;
            print_board();

            if (check_win() == WIN_CONDITION) {
                printf("Congratulations! You Won!\n");
                game_over = 1;
            } else {
                computer_row = rand() % ROWS;
                computer_col = rand() % COLS;

                while (board[computer_row][computer_col]!= EMPTY) {
                    computer_row = rand() % ROWS;
                    computer_col = rand() % COLS;
                }

                board[computer_row][computer_col] = COMPUTER;
                print_board();

                if (check_win() == WIN_CONDITION) {
                    printf("Sorry! Computer Won!\n");
                    game_over = 1;
                }
            }
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}