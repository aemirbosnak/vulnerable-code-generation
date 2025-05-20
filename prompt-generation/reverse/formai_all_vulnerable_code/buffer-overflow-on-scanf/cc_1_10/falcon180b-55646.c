//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];
char players[2] = {'X', 'O'};
int current_player = 0;

void print_board() {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win() {
    for(int i=0; i<BOARD_SIZE; i++) {
        // rows
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        // columns
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

void switch_player() {
    current_player =!current_player;
}

int main() {
    srand(time(0));
    int player_choice;
    int ai_choice;

    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }

    while(1) {
        system("clear");
        print_board();
        printf("\nPlayer %c's turn.\n", players[current_player]);
        scanf("%d", &player_choice);

        if(player_choice < 1 || player_choice > BOARD_SIZE*BOARD_SIZE) {
            printf("Invalid move!\n");
            continue;
        }

        if(board[player_choice/BOARD_SIZE][player_choice%BOARD_SIZE]!= '-') {
            printf("Spot taken!\n");
            continue;
        }

        board[player_choice/BOARD_SIZE][player_choice%BOARD_SIZE] = players[current_player];

        if(check_win()) {
            printf("%c wins!\n", players[current_player]);
            break;
        }

        switch_player();
    }

    return 0;
}