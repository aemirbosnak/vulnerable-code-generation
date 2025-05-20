//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[3][3] = {0};
int current_player = 1;
int ttt_won = 0;

void print_board(void) {
    printf("     |     |     \n");
    printf("   %c  |   %c  |   %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("     |     |     \n");
    printf("   %c  |   %c  |   %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("     |     |     \n");
    printf("   %c  |   %c  |   %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n");
}

int check_win(int player) {
    if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {
        return 1;
    }
    if (board[0][1] == player && board[1][1] == player && board[2][1] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

int main(void) {
    int player_choice;
    int computer_choice;
    int board_filled = 0;
    int game_over = 0;

    srand(time(NULL));

    while (!game_over) {
        print_board();
        printf("Player %d, please choose a square: ", current_player % 2 + 1);
        scanf("%d", &player_choice);
        board[player_choice / 3][player_choice % 3] = current_player;
        current_player = (current_player + 1) % 2;
        if (check_win(current_player)) {
            printf("Player %d wins!\n", current_player);
            ttt_won = current_player;
            game_over = 1;
        } else if (board_filled == 9) {
            printf("Tie game!\n");
            game_over = 1;
        } else {
            printf("Player %d, please choose a square: ", current_player % 2 + 1);
            scanf("%d", &computer_choice);
            board[computer_choice / 3][computer_choice % 3] = 3 - current_player;
            current_player = (current_player + 1) % 2;
            if (check_win(current_player)) {
                printf("Computer wins!\n");
                ttt_won = current_player;
                game_over = 1;
            } else if (board_filled == 9) {
                printf("Tie game!\n");
                game_over = 1;
            } else {
                board_filled++;
            }
        }
    }
    if (ttt_won == 1) {
        printf("Player %d wins!\n", ttt_won);
    } else if (ttt_won == 2) {
        printf("Computer wins!\n");
    } else {
        printf("Tie game!\n");
    }
    return 0;
}