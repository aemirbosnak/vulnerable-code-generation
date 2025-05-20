//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

int main() {
    srand(time(NULL));
    int board[BOARD_SIZE][BOARD_SIZE] = {{0}};
    int player_pos_x = 0, player_pos_y = 0;
    int score = 0;
    int move_count = 0;

    system("clear");

    while (1) {
        system("clear");
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == 1) {
                    printf("\033[1;31mX\033[0m");
                } else if (board[i][j] == 2) {
                    printf("\033[1;32mO\033[0m");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\nScore: %d\n", score);
        printf("Move Count: %d\n", move_count);

        int choice;
        printf("\nChoose your move:\n");
        printf("1. Up\n");
        printf("2. Down\n");
        printf("3. Left\n");
        printf("4. Right\n");
        scanf("%d", &choice);

        int new_x = player_pos_x;
        int new_y = player_pos_y;

        switch (choice) {
            case 1:
                if (player_pos_y > 0 && board[player_pos_x][player_pos_y - 1] == 0) {
                    new_y--;
                }
                break;
            case 2:
                if (player_pos_y < BOARD_SIZE - 1 && board[player_pos_x][player_pos_y + 1] == 0) {
                    new_y++;
                }
                break;
            case 3:
                if (player_pos_x > 0 && board[player_pos_x - 1][player_pos_y] == 0) {
                    new_x--;
                }
                break;
            case 4:
                if (player_pos_x < BOARD_SIZE - 1 && board[player_pos_x + 1][player_pos_y] == 0) {
                    new_x++;
                }
                break;
        }

        if (new_x!= player_pos_x || new_y!= player_pos_y) {
            move_count++;
            if (board[new_x][new_y] == 1) {
                score++;
            }
            board[player_pos_x][player_pos_y] = 0;
            board[new_x][new_y] = 2;
            player_pos_x = new_x;
            player_pos_y = new_y;
        }
    }

    return 0;
}