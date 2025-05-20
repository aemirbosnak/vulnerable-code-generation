//Falcon-180B DATASET v1.0 Category: Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 9
#define COLS 9

int main() {
    srand(time(NULL));
    int board[ROWS][COLS];
    int player = 1;
    int choice;
    int flag = 0;
    int count = 0;
    int i, j;
    bool valid_move = true;
    char mark;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }

    while (flag == 0) {
        system("clear");
        printf("Player 1: X and Player 2: O\n");
        printf("Please enter your move: ");
        scanf("%d", &choice);
        i = choice / 3;
        j = choice % 3;

        if (board[i][j]!= 0) {
            printf("Invalid move! Try again.\n");
            valid_move = false;
        } else if (player % 2 == 0) {
            mark = 'O';
            player++;
        } else {
            mark = 'X';
            player++;
        }

        if (valid_move) {
            board[i][j] = mark;
            count++;

            if (count == 9) {
                flag = 1;
                printf("\nPlayer %d wins!\n", player);
            } else if (count == 8) {
                printf("Tie game!\n");
                flag = 1;
            }
        }
    }

    return 0;
}