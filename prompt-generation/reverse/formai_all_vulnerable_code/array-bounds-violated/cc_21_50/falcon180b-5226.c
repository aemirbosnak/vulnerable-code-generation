//Falcon-180B DATASET v1.0 Category: Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int map[10][10] = {0};
    int player_x = 0, player_y = 0, player_score = 0;
    int enemy_x = 0, enemy_y = 0, enemy_score = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = rand() % 2;
        }
    }

    while (1) {
        system("clear");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (map[i][j] == 0) {
                    printf("  ");
                } else {
                    printf("X ");
                }
            }
            printf("\n");
        }
        printf("Player score: %d\n", player_score);
        printf("Enemy score: %d\n", enemy_score);
        printf("Press any key to continue...\n");
        getchar();

        if (player_score >= 10 || enemy_score >= 10) {
            break;
        }

        int move = rand() % 4;
        switch (move) {
            case 0:
                player_y--;
                break;
            case 1:
                player_y++;
                break;
            case 2:
                player_x--;
                break;
            case 3:
                player_x++;
                break;
        }

        if (map[player_y][player_x] == 0) {
            map[player_y][player_x] = 1;
            player_score++;
        } else {
            map[player_y][player_x] = 0;
        }

        int enemy_move = rand() % 4;
        switch (enemy_move) {
            case 0:
                enemy_y--;
                break;
            case 1:
                enemy_y++;
                break;
            case 2:
                enemy_x--;
                break;
            case 3:
                enemy_x++;
                break;
        }

        if (map[enemy_y][enemy_x] == 0) {
            map[enemy_y][enemy_x] = 2;
            enemy_score++;
        } else {
            map[enemy_y][enemy_x] = 0;
        }
    }

    if (player_score > enemy_score) {
        printf("Player wins!\n");
    } else if (enemy_score > player_score) {
        printf("Enemy wins!\n");
    } else {
        printf("Tie game!\n");
    }

    return 0;
}