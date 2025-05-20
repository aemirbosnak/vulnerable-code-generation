//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

int ttt_board[MAX_SIZE][MAX_SIZE] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

void print_board() {
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", ttt_board[0][0], ttt_board[0][1], ttt_board[0][2]);
    printf("   |   |   \n");
    printf("-------------\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", ttt_board[1][0], ttt_board[1][1], ttt_board[1][2]);
    printf("   |   |   \n");
    printf("-------------\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", ttt_board[2][0], ttt_board[2][1], ttt_board[2][2]);
    printf("   |   |   \n");
}

int check_winner() {
    int i, j;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (ttt_board[i][j] == 'X' || ttt_board[i][j] == 'O') {
                continue;
            } else {
                return 0;
            }
        }
    }
    if (ttt_board[0][0] == 'X' && ttt_board[1][1] == 'X' && ttt_board[2][2] == 'X') {
        return 1;
    } else if (ttt_board[0][2] == 'X' && ttt_board[1][1] == 'X' && ttt_board[2][0] == 'X') {
        return 1;
    } else if (ttt_board[0][0] == 'X' && ttt_board[0][1] == 'X' && ttt_board[0][2] == 'X') {
        return 1;
    } else if (ttt_board[1][0] == 'X' && ttt_board[1][1] == 'X' && ttt_board[1][2] == 'X') {
        return 1;
    } else if (ttt_board[2][0] == 'X' && ttt_board[2][1] == 'X' && ttt_board[2][2] == 'X') {
        return 1;
    } else if (ttt_board[0][0] == 'O' && ttt_board[1][1] == 'O' && ttt_board[2][2] == 'O') {
        return 2;
    } else if (ttt_board[0][2] == 'O' && ttt_board[1][1] == 'O' && ttt_board[2][0] == 'O') {
        return 2;
    } else if (ttt_board[0][0] == 'O' && ttt_board[0][1] == 'O' && ttt_board[0][2] == 'O') {
        return 2;
    } else if (ttt_board[1][0] == 'O' && ttt_board[1][1] == 'O' && ttt_board[1][2] == 'O') {
        return 2;
    } else if (ttt_board[2][0] == 'O' && ttt_board[2][1] == 'O' && ttt_board[2][2] == 'O') {
        return 2;
    } else {
        return 0;
    }
}

void print_winning_message() {
    if (check_winner() == 1) {
        printf("X wins!\n");
    } else if (check_winner() == 2) {
        printf("O wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}

int main() {
    int move;
    printf("Welcome to Tic Tac Toe!\n");
    while (1) {
        print_board();
        printf("It's %c's turn.\n", (check_winner() == 1)? 'X' : (check_winner() == 2)? 'O' : 'O');
        scanf("%d", &move);
        if (move == 1) {
            if (check_winner() == 1) {
                continue;
            }
            if (check_winner() == 2) {
                break;
            }
            if (ttt_board[move - 1][0]!= 0) {
                continue;
            }
            ttt_board[move - 1][0] = 'X';
            print_board();
            if (check_winner() == 1) {
                print_winning_message();
                break;
            }
        } else if (move == 2) {
            if (check_winner() == 1) {
                continue;
            }
            if (check_winner() == 2) {
                break;
            }
            if (ttt_board[move - 1][2]!= 0) {
                continue;
            }
            ttt_board[move - 1][2] = 'O';
            print_board();
            if (check_winner() == 2) {
                print_winning_message();
                break;
            }
        } else if (move == 3) {
            if (check_winner() == 1) {
                continue;
            }
            if (check_winner() == 2) {
                break;
            }
            if (ttt_board[move - 1][1]!= 0) {
                continue;
            }
            ttt_board[move - 1][1] = 'O';
            print_board();
            if (check_winner() == 2) {
                print_winning_message();
                break;
            }
        } else {
            printf("Invalid move!\n");
        }
    }
    return 0;
}