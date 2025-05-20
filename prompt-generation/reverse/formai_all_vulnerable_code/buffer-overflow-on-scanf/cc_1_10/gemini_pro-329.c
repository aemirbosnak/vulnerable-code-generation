//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

typedef struct {
    int value;
    int revealed;
} Tile;

Tile board[BOARD_SIZE][BOARD_SIZE];

int player1_score = 0;
int player2_score = 0;

int current_player = 1;

void print_board() {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].revealed) {
                printf("%d ", board[i][j].value);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int get_input() {
    int input;
    while (1) {
        printf("Player %d, enter the coordinates of the tile you want to reveal (row, column): ", current_player);
        scanf("%d %d", &input, &input);
        input--;
        if (input >= 0 && input < BOARD_SIZE) {
            return input;
        } else {
            printf("Invalid input. Please enter a valid coordinate.\n");
        }
    }
}

void reveal_tile(int row, int column) {
    if (!board[row][column].revealed) {
        board[row][column].revealed = 1;
        if (board[row][column].value == 0) {
            printf("You revealed an empty tile.\n");
            current_player = 3 - current_player;
        } else {
            if (current_player == 1) {
                player1_score += board[row][column].value;
            } else {
                player2_score += board[row][column].value;
            }
            printf("You revealed a tile with the value %d.\n", board[row][column].value);
        }
        print_board();
    } else {
        printf("You already revealed this tile.\n");
    }
}

int check_for_win() {
    int player1_wins = 1;
    int player2_wins = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!board[i][j].revealed) {
                player1_wins = 0;
                player2_wins = 0;
                break;
            }
        }
    }

    if (player1_wins) {
        printf("Player 1 wins!\n");
        return 1;
    } else if (player2_wins) {
        printf("Player 2 wins!\n");
        return 1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(NULL));

    // Initialize the board with random values
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].value = rand() % 10 + 1;
            board[i][j].revealed = 0;
        }
    }

    // Print the initial board
    print_board();

    while (!check_for_win()) {
        int row = get_input();
        int column = get_input();
        reveal_tile(row, column);
    }

    return 0;
}