//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int player_x, player_y;
    int enemy_x, enemy_y;
    int maze[10][10];

    player_x = rand() % 10;
    player_y = rand() % 10;
    maze[player_x][player_y] = 1;

    enemy_x = rand() % 10;
    enemy_y = rand() % 10;
    maze[enemy_x][enemy_y] = 2;

    int game_over = 0;

    while (!game_over) {
        system("clear");
        printf("Maze:\n");

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (maze[i][j] == 1) {
                    printf("@ ");
                } else if (maze[i][j] == 2) {
                    printf("E ");
                } else {
                    printf("# ");
                }
            }
            printf("\n");
        }

        int move;
        printf("Enter your move (up, down, left, right): ");
        scanf("%d", &move);

        switch (move) {
        case 0:
            if (player_y > 0 && maze[player_x][player_y - 1]!= 2) {
                player_y--;
            }
            break;
        case 1:
            if (player_y < 9 && maze[player_x][player_y + 1]!= 2) {
                player_y++;
            }
            break;
        case 2:
            if (player_x > 0 && maze[player_x - 1][player_y]!= 2) {
                player_x--;
            }
            break;
        case 3:
            if (player_x < 9 && maze[player_x + 1][player_y]!= 2) {
                player_x++;
            }
            break;
        default:
            printf("Invalid move.\n");
        }

        if (maze[player_x][player_y] == 2) {
            game_over = 1;
        }
    }

    if (game_over) {
        printf("Game over.\n");
    } else {
        printf("You win!\n");
    }

    return 0;
}