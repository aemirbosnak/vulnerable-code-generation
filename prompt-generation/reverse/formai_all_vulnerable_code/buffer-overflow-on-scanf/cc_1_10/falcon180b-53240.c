//Falcon-180B DATASET v1.0 Category: Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10 // maximum size of the game board
#define MAX_ROWS 3 // maximum number of rows in the game
#define MAX_COLS 3 // maximum number of columns in the game

int generate_random_number() {
    return rand() % 10;
}

void initialize_game_board(int board[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            board[i][j] = 0;
        }
    }
}

void print_game_board(int board[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    int game_board[MAX_ROWS][MAX_COLS];
    initialize_game_board(game_board);

    int player_row = 0;
    int player_col = 0;
    int player_score = 0;
    int game_score = 0;

    while (player_score < 10) {
        printf("Welcome to the C Game!\n");
        printf("Score: %d\n", player_score);
        print_game_board(game_board);

        int move_row;
        int move_col;
        printf("Enter your move (row and column): ");
        scanf("%d%d", &move_row, &move_col);

        if (move_row >= 0 && move_row < MAX_ROWS && move_col >= 0 && move_col < MAX_COLS) {
            if (game_board[move_row][move_col] == 0) {
                game_board[move_row][move_col] = generate_random_number();
                player_score++;
            } else {
                printf("Sorry, that spot is already taken.\n");
            }
        } else {
            printf("Invalid move.\n");
        }

        if (game_score == 20 || player_score == 10) {
            printf("Game over!\n");
            break;
        }
    }

    return 0;
}