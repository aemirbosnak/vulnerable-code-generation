//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main() {
    int board[ROWS][COLS] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
    int player = 1;
    int choice;
    int flag = 0;
    int count = 0;
    int audio = 0;

    srand(time(NULL));

    system("afplay memory_game_bgm.mp3 &");

    while (!flag) {
        system("clear");
        printf("Player 1's Turn\n");

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf(" %d ", board[i][j]);
            }
            printf("\n");
        }

        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (board[choice / COLS][choice % COLS] == 0) {
            board[choice / COLS][choice % COLS] = player;
            player = (player == 1)? 2 : 1;
            count++;
        } else {
            printf("\a");
        }

        if (count == 16) {
            flag = 1;
            printf("\n");
            printf("Player %d wins!\n", player);
        }
    }

    return 0;
}