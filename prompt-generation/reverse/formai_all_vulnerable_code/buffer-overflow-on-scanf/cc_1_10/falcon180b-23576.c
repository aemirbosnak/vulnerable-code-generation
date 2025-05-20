//Falcon-180B DATASET v1.0 Category: Chess engine ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define PIECE 6

int board[SIZE][SIZE];
int piece_count[PIECE];

void init_board() {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            board[i][j] = -1;
        }
    }
    for(i = 0; i < PIECE; i++) {
        piece_count[i] = 16;
    }
}

void draw_board() {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void place_piece(int piece, int x, int y) {
    if(piece >= 0 && piece < PIECE) {
        board[x][y] = piece;
        piece_count[piece]--;
    }
}

int check_win() {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(board[i][j] == -1) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    init_board();
    int turn = 0;
    while(1) {
        system("clear");
        draw_board();
        printf("Turn: %d\n", turn);
        int x, y;
        scanf("%d %d", &x, &y);
        if(board[x][y] == -1) {
            place_piece(turn % PIECE, x, y);
            turn++;
        } else {
            printf("Invalid move.\n");
        }
        if(check_win()) {
            printf("Player %d wins!\n", turn % PIECE);
            break;
        }
        turn++;
    }
    return 0;
}