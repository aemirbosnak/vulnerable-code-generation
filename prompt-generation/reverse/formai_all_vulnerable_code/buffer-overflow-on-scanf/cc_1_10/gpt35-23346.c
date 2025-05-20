//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[3][3];
int player = 1;
int ai = 2;

int check_win(int player) {
    int win = 0;
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) win = 1; // check rows
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) win = 1; // check columns
    }
    
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) win = 1; // check diagonal
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) win = 1; // check diagonal
    
    return win;
}

void ai_turn() {
    int done = 0;
    while(done == 0) {
        int x = rand() % 3;
        int y = rand() % 3;
        if(board[x][y] == 0) {
            board[x][y] = ai;
            done = 1;
        }
    }
}

void player_turn() {
    int done = 0;
    while(done == 0) {
        int x, y;
        printf("Enter your move (row [1-3] column [1-3]): ");
        scanf("%d %d", &x, &y);
        if(board[x-1][y-1] == 0) {
            board[x-1][y-1] = player;
            done = 1;
        } else {
            printf("Invalid move, try again.\n");
        }
    }
}

void print_board() {
    printf("     1   2   3\n");
    printf("   +---+---+---+\n");
    for(int i = 0; i < 3; i++) {
        printf(" %d |", i+1);
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == 0) printf(" ");
            if(board[i][j] == 1) printf("X");
            if(board[i][j] == 2) printf("O");
            printf(" |");
        }
        printf("\n   +---+---+---+\n");
    }
}

int main() {
    srand(time(NULL));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = 0;
        }
    }
    int gameover = 0;
    while(gameover == 0) {
        print_board();
        if(player == 1) player_turn();
        else ai_turn();
        if(check_win(player) == 1) { 
            printf("You win!\n");
            gameover = 1;
            break;
        };
        if(player == 1) player = 2;
        else player = 1;
        if(check_win(ai) == 1) { 
            printf("AI wins!\n");
            gameover = 1;
            break;
        };
    }
    print_board();
    return 0;
}