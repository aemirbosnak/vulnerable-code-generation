//Falcon-180B DATASET v1.0 Category: Table Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define SYMBOLS 3

char board[ROWS][COLS];
char symbols[SYMBOLS] = {'X', 'O', '*'};
int current_symbol = 0;
int player = 1;
int flag = 0;

void init_board() {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = symbols[current_symbol];
        }
    }
}

void print_board() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win() {
    for(int i=0; i<ROWS; i++) {
        if((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || 
           (board[i][0] == board[i][2] && board[i][2] == board[i][1])) {
            return 1;
        }
    }
    for(int i=0; i<COLS; i++) {
        if((board[0][i] == board[1][i] && board[1][i] == board[2][i]) || 
           (board[0][i] == board[2][i] && board[2][i] == board[1][i])) {
            return 1;
        }
    }
    if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || 
       (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return 1;
    }
    return 0;
}

void change_symbol() {
    current_symbol = (current_symbol + 1) % SYMBOLS;
}

int main() {
    init_board();
    int choice;
    while(1) {
        system("clear");
        print_board();
        printf("\nPlayer %d's turn\n", player);
        printf("Enter your move (row and column): ");
        scanf("%d%d", &choice, &choice);
        if(choice < 1 || choice > 3) {
            printf("Invalid move\n");
            continue;
        }
        int row = (player - 1) / 2;
        int col = (3 - (player - 1) % 2) / 2;
        if(row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col]!= symbols[current_symbol]) {
            printf("Invalid move\n");
            continue;
        }
        board[row][col] = symbols[current_symbol];
        if(check_win()) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }
        player = (player + 1) % 2;
        change_symbol();
    }
    return 0;
}