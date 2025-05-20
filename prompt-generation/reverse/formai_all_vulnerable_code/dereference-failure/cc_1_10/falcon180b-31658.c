//Falcon-180B DATASET v1.0 Category: Table Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define HEIGHT 21
#define WIDTH 11
#define MAX_SCORE 50

void generate_board(char board[][HEIGHT]);
void print_board(const char board[][HEIGHT]);
bool check_win(const char board[][HEIGHT]);
void play_game();

int main() {
    srand(time(NULL));
    char board[HEIGHT][WIDTH];
    generate_board(board);
    play_game(board);
    return 0;
}

void generate_board(char board[][HEIGHT]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            board[i][j] = rand() % 2? 'X' : 'O';
        }
    }
}

void print_board(const char board[][HEIGHT]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool check_win(const char board[][HEIGHT]) {
    for (int i = 0; i < HEIGHT; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }

    for (int j = 0; j < WIDTH; ++j) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return true;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }

    return false;
}

void play_game(char board[][HEIGHT]) {
    int moves = 0;
    int player = 1;
    int score = 0;

    while (moves < MAX_SCORE &&!check_win(board)) {
        print_board(board);
        int x, y;
        printf("Player %d's turn. Enter your move (row and column): ", player);
        scanf("%d%d", &x, &y);

        if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH && board[x][y] == 'X' || board[x][y] == 'O') {
            board[x][y] = (player == 1)? 'X' : 'O';
            ++moves;

            if (check_win(board)) {
                printf("Player %d wins!\n", player);
                break;
            } else if (moves == MAX_SCORE) {
                printf("It's a draw.\n");
                break;
            }

            player = (player == 1)? 2 : 1;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    print_board(board);
}