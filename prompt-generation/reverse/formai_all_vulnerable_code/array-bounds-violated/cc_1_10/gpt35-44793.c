//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 5
#define COLS 10
#define INVADER_ROWS 3
#define INVADER_COLS 5

char invaders[INVADER_ROWS][INVADER_COLS] = {
{' ','o',' ','o',' '},
{'o','o','o','o','o'},
{'o','o',' ','o','o'}
};

void init_board(char board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board(char board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void update_invaders(char board[ROWS][COLS]) {
    static bool going_right = true;
    static int pos_x = 0, pos_y = 0;
    int rows = pos_x + INVADER_ROWS;
    int cols = pos_y + INVADER_COLS;
    if(cols >= COLS || pos_y == 0) {
        going_right = !going_right;
        pos_x++;
    }
    if(pos_x >= ROWS) {
        pos_x = 0;
        pos_y = 0;
        init_board(board);
    }
    if(going_right) {
        pos_y++;
    } else {
        pos_y--;
    }
    for(int i = pos_x, k = 0; i < rows; i++, k++) {
        for(int j = pos_y, l = 0; j < cols; j++, l++) {
            if(invaders[k][l] == 'o') {
                board[i][j] = invaders[k][l];
            }
        }
    }
}

void clear_ship(char board[ROWS][COLS], int pos) {
    for(int i = ROWS - 1; i > ROWS - 2; i--) {
        for(int j = pos; j < pos + 3; j++) {
            board[i][j] = ' ';
        }
    }
}

bool update_ship(char board[ROWS][COLS], int pos, bool move_right) {
    clear_ship(board, pos);
    if(move_right && pos < COLS - 3) {
        pos++;
    } else if(!move_right && pos > 0) {
        pos--;
    }
    for(int i = ROWS - 1; i > ROWS - 2; i--) {
        for(int j = pos; j < pos + 3; j++) {
            board[i][j] = '^';
        }
    }
    return move_right;
}

void update_missile(char board[ROWS][COLS], int *missile_x, int *missile_y, bool *missile_fired) {
    if(*missile_fired) {
        board[*missile_x][*missile_y] = ' ';
        if((*missile_x) > 0) {
            (*missile_x)--;
        } else {
            *missile_fired = false;
        }
        board[*missile_x][*missile_y] = '|';
    }   
}

void update_game(char board[ROWS][COLS], int *pos, bool *move_right, int *missile_x, int *missile_y, bool *missile_fired, char input) {
    if(input == 'a' || input == 'A') {
        *move_right = false;
    } else if(input == 'd' || input == 'D') {
        *move_right = true;
    } else if(input == ' ') {
        if(!*missile_fired) {
            *missile_fired = true;
            *missile_x = ROWS - 2;
            *missile_y = (*pos) + 1;
        }
    }
    *move_right = update_ship(board, *pos, *move_right);
    update_missile(board, missile_x, missile_y, missile_fired);
    update_invaders(board);
    print_board(board);
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    int pos = COLS/2 - 1;
    bool move_right = true;
    bool missile_fired = false;
    int missile_x, missile_y;
    init_board(board);
    update_ship(board, pos, move_right);
    print_board(board);
    while(true) {
        char input = ' ';
        while(input == ' ') {
            input = getchar();
        }
        if(input == 'q' || input == 'Q') {
            return 0;
        }
        update_game(board, &pos, &move_right, &missile_x, &missile_y, &missile_fired, input);
    }
    return 0;
}