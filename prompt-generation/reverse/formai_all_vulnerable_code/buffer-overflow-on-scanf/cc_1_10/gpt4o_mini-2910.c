//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef enum { EMPTY, PLAYER1, PLAYER2, KING1, KING2 } Cell;

void initialize_board(Cell board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 != 0) {
                if (i < 3) {
                    board[i][j] = PLAYER1;
                } else if (i > 4) {
                    board[i][j] = PLAYER2;
                } else {
                    board[i][j] = EMPTY;
                }
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

void print_board(Cell board[SIZE][SIZE]) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            switch (board[i][j]) {
                case PLAYER1: printf("P "); break;
                case PLAYER2: printf("p "); break;
                case KING1:   printf("K "); break;
                case KING2:   printf("k "); break;
                case EMPTY:   printf(". "); break;
            }
        }
        printf("\n");
    }
}

int valid_move(int x1, int y1, int x2, int y2, Cell board[SIZE][SIZE], Cell player) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    if (board[x1][y1] == player && board[x2][y2] == EMPTY &&
        ((player == PLAYER1 && dx == 1 && (dy == -1 || dy == 1)) ||
         (player == PLAYER2 && dx == -1 && (dy == -1 || dy == 1)))) {
        return 1;
    }

    if ((player == PLAYER1 && dx == 2) || (player == PLAYER2 && dx == -2)) {
        if ((dy == -2 || dy == 2) && 
            ((player == PLAYER1 && board[x1 + 1][y1 + (dy / 2)] == PLAYER2) ||
             (player == PLAYER2 && board[x1 - 1][y1 + (dy / 2)] == PLAYER1))) {
            return 1;
        }
    }
    return 0;
}

void make_move(int x1, int y1, int x2, int y2, Cell board[SIZE][SIZE], Cell player) {
    board[x2][y2] = player;
    board[x1][y1] = EMPTY;
    if ((player == PLAYER1 && x2 == SIZE - 1) || 
        (player == PLAYER2 && x2 == 0)) {
        board[x2][y2] = (player == PLAYER1) ? KING1 : KING2;
    }
}

int main() {
    Cell board[SIZE][SIZE];
    initialize_board(board);
    
    Cell current_player = PLAYER1;
    int x1, y1, x2, y2;
    
    while (1) {
        print_board(board);
        printf("Player %s turn. Enter move (e.g., a3 b4): ", (current_player == PLAYER1) ? "1 (P)" : "2 (p)");
        char from[3], to[3];
        scanf("%s %s", from, to);
        
        x1 = from[1] - '1';
        y1 = from[0] - 'a';
        x2 = to[1] - '1';
        y2 = to[0] - 'a';
        
        if (valid_move(x1, y1, x2, y2, board, current_player)) {
            make_move(x1, y1, x2, y2, board, current_player);
            current_player = (current_player == PLAYER1) ? PLAYER2 : PLAYER1; // Switch player
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    return 0;
}