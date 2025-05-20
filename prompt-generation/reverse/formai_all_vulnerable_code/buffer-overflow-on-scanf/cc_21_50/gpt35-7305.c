//FormAI DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int moves[3][3], row, col;
    for(row = 0; row < 3; row++) {
        for(col = 0; col < 3; col++) {
            moves[row][col] = rand() % 9 + 1;
        }
    }
    int turn = 1, player_one_move, player_two_move, move_count = 0;
    printf("Welcome to the Unique C Table Game!\n");
    printf("In this game, each player will choose a move on the table,\n");
    printf("and the first player to get three in a row wins!\n\n");
    printf("Here is the table:\n");
    printf("\t1 | 2 | 3\n");
    printf("\t--|---|--\n");
    printf("\t4 | 5 | 6\n");
    printf("\t--|---|--\n");
    printf("\t7 | 8 | 9\n\n");
    printf("Player one will be represented by 'X' and player two will be represented by 'O'.\n");
    printf("Player one goes first.\n\n");
    while(1) {
        if(turn == 1) {
            printf("Player one, enter the number of the move you want to make: ");
            scanf("%d", &player_one_move);
            printf("\n");
            if(player_one_move < 1 || player_one_move > 9) {
                printf("Invalid input. Please enter a number between 1 and 9.\n\n");
                continue;
            }
            int row = (player_one_move - 1) / 3, col = (player_one_move - 1) % 3;
            if(moves[row][col] == 'X' || moves[row][col] == 'O') {
                printf("That move has already been made. Please choose another.\n\n");
                continue;
            }
            moves[row][col] = 'X';
            turn = 2;

        } else if(turn == 2) {
            printf("Player two, enter the number of the move you want to make: ");
            scanf("%d", &player_two_move);
            printf("\n");
            if(player_two_move < 1 || player_two_move > 9) {
                printf("Invalid input. Please enter a number between 1 and 9.\n\n");
                continue;
            }
            int row = (player_two_move - 1) / 3, col = (player_two_move - 1) % 3;
            if(moves[row][col] == 'X' || moves[row][col] == 'O') {
                printf("That move has already been made. Please choose another.\n\n");
                continue;
            }
            moves[row][col] = 'O';
            turn = 1;
        }
        move_count++;
        printf("The table now looks like this:\n");
        printf("\t%c | %c | %c\n", moves[0][0], moves[0][1], moves[0][2]);
        printf("\t--|---|--\n");
        printf("\t%c | %c | %c\n", moves[1][0], moves[1][1], moves[1][2]);
        printf("\t--|---|--\n");
        printf("\t%c | %c | %c\n\n", moves[2][0], moves[2][1], moves[2][2]);

        if(move_count >= 5) {
            int row, col;
            for(row = 0; row < 3; row++) {
                if(moves[row][0] == moves[row][1] && moves[row][1] == moves[row][2]) {
                    if(moves[row][0] == 'X') {
                        printf("Congratulations, player one has won the game!\n\n");
                        return 0;
                    } else if(moves[row][0] == 'O') {
                        printf("Congratulations, player two has won the game!\n\n");
                        return 0;
                    }
                }
            }
            for(col = 0; col < 3; col++) {
                if(moves[0][col] == moves[1][col] && moves[1][col] == moves[2][col]) {
                    if(moves[0][col] == 'X') {
                        printf("Congratulations, player one has won the game!\n\n");
                        return 0;
                    } else if(moves[0][col] == 'O') {
                        printf("Congratulations, player two has won the game!\n\n");
                        return 0;
                    }
                }
            }
            if(moves[0][0] == moves[1][1] && moves[1][1] == moves[2][2]) {
                if(moves[0][0] == 'X') {
                    printf("Congratulations, player one has won the game!\n\n");
                    return 0;
                } else if(moves[0][0] == 'O') {
                    printf("Congratulations, player two has won the game!\n\n");
                    return 0;
                }
            }
            if(moves[0][2] == moves[1][1] && moves[1][1] == moves[2][0]) {
                if(moves[0][2] == 'X') {
                    printf("Congratulations, player one has won the game!\n\n");
                    return 0;
                } else if(moves[0][2] == 'O') {
                    printf("Congratulations, player two has won the game!\n\n");
                    return 0;
                }
            }
            if(move_count == 9) {
                printf("The game is a tie!\n\n");
                return 0;
            }
        }
    }
}