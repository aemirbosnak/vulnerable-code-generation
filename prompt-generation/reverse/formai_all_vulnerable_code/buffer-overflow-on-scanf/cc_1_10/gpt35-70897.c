//FormAI DATASET v1.0 Category: Memory Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_MOVES 16

void make_random_move(int *row, int *col, int *prev_row, int *prev_col, int move_num);
void print_board(char board[][COLS]);
int get_user_move(int *row, int *col);

int main(void) {
    int row, col, prev_row, prev_col, user_row, user_col, moves = 0;
    char board[ROWS][COLS] = {'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'E', 'E', 'F', 'F', 'G', 'G', 'H', 'H'};
    int board_shown[ROWS][COLS] = {0};
    int game_over = 0;

    srand(time(NULL));

    do {
        system("clear");
        printf("Move number: %d / %d\n\n", moves, MAX_MOVES);
        print_board(board);

        if (moves % 2 == 0) {
            make_random_move(&row, &col, &prev_row, &prev_col, moves);
            printf("Computer chose row %d, col %d\n\n", row+1, col+1);
        } else {
            do {
                printf("Enter a row (1-%d) and column (1-%d): ", ROWS, COLS);
                scanf("%d%d", &user_row, &user_col);
            } while(!get_user_move(&user_row, &user_col));
            user_row--;
            user_col--;
            prev_row = row;
            prev_col = col;
            row = user_row;
            col = user_col;
        }

        if (board[row][col] == board[prev_row][prev_col] && !(row == prev_row && col == prev_col)) {
            board_shown[row][col] = 1;
            board_shown[prev_row][prev_col] = 1;
        } else {
            printf("No match. Press enter to continue.\n");
            getchar();
        }

        game_over = 1;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (!board_shown[i][j]) {
                    game_over = 0;
                    break;
                }
            }

            if (!game_over) {
                break;
            }
        }

        moves++;
    } while(!game_over && moves < MAX_MOVES);

    printf("Game over!\n");
    print_board(board);
    return 0;
}

void make_random_move(int *row, int *col, int *prev_row, int *prev_col, int move_num) {
    int valid_move;
    do {
        *row = rand() % ROWS;
        *col = rand() % COLS;
        valid_move = (*row != *prev_row || *col != *prev_col);
    } while(!valid_move);
}

void print_board(char board[][COLS]) {
    printf("    ");
    for (int i = 1; i <= COLS; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf(" %d ", i+1);
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int get_user_move(int *row, int *col) {
    if (*row < 1 || *row > ROWS || *col < 1 || *col > COLS) {
        printf("Invalid move. Please enter a row (1-%d) and column (1-%d).\n", ROWS, COLS);
        return 0;
    }

    return 1;
}