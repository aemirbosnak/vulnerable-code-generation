//GEMINI-pro DATASET v1.0 Category: Chess engine ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} square;

typedef struct {
    square from, to;
} move;

int board[8][8];
move history[1000];
int history_count;

void print_board() {
    for (int y = 7; y >= 0; y--) {
        for (int x = 0; x < 8; x++) {
            printf("%c", board[x][y] ? 'X' : '*');
        }
        printf("\n");
    }
}

int is_valid_move(move m) {
    int dx = abs(m.from.x - m.to.x);
    int dy = abs(m.from.y - m.to.y);
    return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
}

void make_move(move m) {
    board[m.to.x][m.to.y] = 1;
    board[m.from.x][m.from.y] = 0;
    history[history_count++] = m;
}

void undo_move() {
    move m = history[--history_count];
    board[m.from.x][m.from.y] = 1;
    board[m.to.x][m.to.y] = 0;
}

int main() {
    // Initialize the board
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            board[x][y] = 0;
        }
    }
    board[3][4] = 1;

    // Print the initial board
    print_board();

    // Get a move from the user
    move m;
    printf("Enter a move (e.g. e2e4): ");
    scanf(" %c%c %c%c", &m.from.x, &m.from.y, &m.to.x, &m.to.y);

    // Check if the move is valid
    if (!is_valid_move(m)) {
        printf("Invalid move!\n");
        return 1;
    }

    // Make the move
    make_move(m);

    // Print the updated board
    print_board();

    // Undo the move
    undo_move();

    // Print the original board
    print_board();

    return 0;
}