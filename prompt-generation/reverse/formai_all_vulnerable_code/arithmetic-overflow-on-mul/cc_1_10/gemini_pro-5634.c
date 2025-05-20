//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define BOARD_SIZE 4
#define NUM_SYMBOLS 8
#define NUM_TURNS 10

typedef struct {
    int row;
    int col;
} Position;

char symbols[NUM_SYMBOLS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

char board[BOARD_SIZE][BOARD_SIZE];
int revealed[BOARD_SIZE][BOARD_SIZE];

Position turn_history[NUM_TURNS];
int turn_count = 0;

void print_board() {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%c ", board[i][j]);
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
}

int get_random_symbol() {
    return rand() % NUM_SYMBOLS;
}

void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = symbols[get_random_symbol()];
            revealed[i][j] = 0;
        }
    }
}

int get_input() {
    int row, col;
    printf("Enter row and column (1-4): ");
    scanf("%d %d", &row, &col);
    return row * BOARD_SIZE + col;
}

int check_match(Position p1, Position p2) {
    return board[p1.row][p1.col] == board[p2.row][p2.col];
}

void reveal_symbol(Position p) {
    revealed[p.row][p.col] = 1;
}

void add_to_history(Position p) {
    turn_history[turn_count++] = p;
}

int can_reveal(Position p) {
    return p.row >= 0 && p.row < BOARD_SIZE && p.col >= 0 && p.col < BOARD_SIZE && !revealed[p.row][p.col];
}

void play_game() {
    initialize_board();
    print_board();
    int input1, input2;
    Position p1, p2;
    while (turn_count < NUM_TURNS) {
        input1 = get_input();
        p1.row = (input1 - 1) / BOARD_SIZE;
        p1.col = (input1 - 1) % BOARD_SIZE;
        if (!can_reveal(p1)) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        reveal_symbol(p1);
        add_to_history(p1);
        print_board();
        input2 = get_input();
        p2.row = (input2 - 1) / BOARD_SIZE;
        p2.col = (input2 - 1) % BOARD_SIZE;
        if (!can_reveal(p2)) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        reveal_symbol(p2);
        add_to_history(p2);
        print_board();
        if (check_match(p1, p2)) {
            printf("Match!\n");
        } else {
            printf("No match.\n");
        }
    }
}

int main() {
    srand(time(NULL));
    play_game();
    return 0;
}