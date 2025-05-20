//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define NUM_MINES 10

char board[MAX_ROWS][MAX_COLS];
int num_rows, num_cols, num_mines;
int game_over = 0;

void init_board() {
    srand(time(0));
    num_rows = rand() % MAX_ROWS + 1;
    num_cols = rand() % MAX_COLS + 1;
    num_mines = rand() % NUM_MINES + 1;

    int i, j;
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            board[i][j] = '.';
        }
    }

    int count = 0;
    while (count < num_mines) {
        int x, y;
        do {
            x = rand() % num_rows;
            y = rand() % num_cols;
        } while (board[x][y] == '*');

        board[x][y] = '*';
        count++;
    }
}

void print_board() {
    int i, j;
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win() {
    int i, j;
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            if (board[i][j] == '*') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    init_board();
    int player_x = 0, player_y = 0;

    while (!game_over) {
        system("clear");
        print_board();
        printf("Player position: (%d, %d)\n", player_x, player_y);

        char move;
        scanf("%c", &move);

        switch (move) {
        case 'w':
            if (player_y > 0 && board[player_y - 1][player_x]!= '*') {
                player_y--;
            }
            break;
        case's':
            if (player_y < num_rows - 1 && board[player_y + 1][player_x]!= '*') {
                player_y++;
            }
            break;
        case 'a':
            if (player_x > 0 && board[player_y][player_x - 1]!= '*') {
                player_x--;
            }
            break;
        case 'd':
            if (player_x < num_cols - 1 && board[player_y][player_x + 1]!= '*') {
                player_x++;
            }
            break;
        default:
            printf("Invalid move.\n");
        }

        if (board[player_y][player_x] == '*') {
            game_over = 1;
            printf("Game over! You stepped on a mine.\n");
        } else if (check_win()) {
            game_over = 1;
            printf("Congratulations! You won the game.\n");
        }
    }

    return 0;
}