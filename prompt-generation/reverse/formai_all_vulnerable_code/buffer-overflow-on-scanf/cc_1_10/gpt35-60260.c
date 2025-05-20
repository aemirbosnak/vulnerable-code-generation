//FormAI DATASET v1.0 Category: Chess engine ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

bool is_valid_move(int x1, int y1, int x2, int y2) {
    // check if move is within board bounds
    if (x1 < 0 || x1 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE
        || x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE) {
        return false;
    }
    
    // check if piece is actually moved
    if (x1 == x2 && y1 == y2) {
        return false;
    }
    
    // check if piece at x1,y1 can move to x2,y2
    // (this is just a placeholder check, you would need to implement actual chess rules here)
    if (board[x1][y1] == ' ' || board[x1][y1] == '.') {
        return false;
    }
    
    return true;
}

void print_board() {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d", i + 1);
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

int main() {
    int x1, y1, x2, y2;
    bool valid_move;

    print_board();
    
    do {
        printf("Enter move: ");
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        valid_move = is_valid_move(x1, y1, x2, y2);
        if (!valid_move) {
            printf("Invalid move!\n");
        }
    } while (!valid_move);
    
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = ' ';
    
    print_board();
    
    return 0;
}