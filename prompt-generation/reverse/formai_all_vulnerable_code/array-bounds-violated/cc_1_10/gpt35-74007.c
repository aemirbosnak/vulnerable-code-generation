//FormAI DATASET v1.0 Category: Checkers Game ; Style: lively
#include <stdio.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];
int turn = 1;

void init_board() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if((i+j) % 2 == 0) {
                if(i < 3) {
                    board[i][j] = 'X';
                } else if(i > 4) {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = ' ';
                }
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

void print_board() {
    printf("  ");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'a' + i);
    }
    printf("\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i+1);
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", i+1);
    }
    printf("  ");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'a' + i);
    }
    printf("\n");
}

void move_piece(int src_x, int src_y, int dest_x, int dest_y) {
    if(dest_x < 0 || dest_x >= BOARD_SIZE || dest_y < 0 || dest_y >= BOARD_SIZE) {
        printf("Invalid move\n");
        return;
    }
    
    int dx = dest_x - src_x;
    int dy = dest_y - src_y;
    int adx = dx < 0 ? -dx : dx;
    int ady = dy < 0 ? -dy : dy;
    
    if(board[dest_x][dest_y] != ' ') {
        printf("Invalid move\n");
        return;
    }
    
    if(board[src_x][src_y] == 'X' && dy > 0) {
        printf("Invalid move\n");
        return;
    } else if(board[src_x][src_y] == 'O' && dy < 0) {
        printf("Invalid move\n");
        return;
    }
    
    if(dx == adx && dy == ady) {
        board[dest_x][dest_y] = board[src_x][src_y];
        board[src_x][src_y] = ' ';
        turn = turn == 1 ? 2 : 1;
    } else if(dx == 2 * adx && dy == 2 * ady) {
        int mid_x = (dest_x + src_x) / 2;
        int mid_y = (dest_y + src_y) / 2;
        if(board[mid_x][mid_y] == (turn == 1 ? 'O' : 'X')) {
            board[dest_x][dest_y] = board[src_x][src_y];
            board[src_x][src_y] = ' ';
            board[mid_x][mid_y] = ' ';
            turn = turn == 1 ? 2 : 1;
        } else {
            printf("Invalid move\n");
        }
    } else {
        printf("Invalid move\n");
    }
}

int main() {
    init_board();
    print_board();
    
    while(1) {
        printf("Player %d's turn\n", turn);
        printf("Enter source position (e.g. a1): ");
        char src_pos[3];
        scanf("%s", src_pos);
        int src_x = src_pos[0] - 'a';
        int src_y = src_pos[1] - '1';
        printf("Enter destination position (e.g. b2): ");
        char dest_pos[3];
        scanf("%s", dest_pos);
        int dest_x = dest_pos[0] - 'a';
        int dest_y = dest_pos[1] - '1';
        move_piece(src_y, src_x, dest_y, dest_x);
        print_board();
    }
    
    return 0;
}