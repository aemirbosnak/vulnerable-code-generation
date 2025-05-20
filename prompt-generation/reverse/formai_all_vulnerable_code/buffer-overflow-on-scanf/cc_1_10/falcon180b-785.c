//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 0
#define G 1
#define B 2
#define W 3

int map[10][10];
int player_x = 0, player_y = 0;
int enemy_x = 0, enemy_y = 0;
int treasure_x = 0, treasure_y = 0;
int game_over = 0;

void init_map() {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            map[i][j] = W;
        }
    }
}

void draw_map() {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (map[i][j] == W) {
                printf(" ");
            } else if (map[i][j] == B) {
                printf("#");
            } else if (map[i][j] == G) {
                printf("$");
            } else if (map[i][j] == R) {
                printf("E");
            }
        }
        printf("\n");
    }
}

void move(int dx, int dy) {
    int new_x = player_x + dx;
    int new_y = player_y + dy;

    if (new_x >= 0 && new_x < 10 && new_y >= 0 && new_y < 10 && map[new_x][new_y] == W) {
        player_x = new_x;
        player_y = new_y;
    }
}

int main() {
    srand(time(NULL));

    init_map();
    player_x = rand() % 10;
    player_y = rand() % 10;
    treasure_x = rand() % 10;
    treasure_y = rand() % 10;
    enemy_x = rand() % 10;
    enemy_y = rand() % 10;

    while (!game_over) {
        draw_map();
        printf("Score: $%d\n", treasure_x + treasure_y);
        printf("Enemy at (%d,%d)\n", enemy_x, enemy_y);

        char command;
        scanf(" %c", &command);

        switch (command) {
            case 'w':
                move(0, -1);
                break;
            case's':
                move(0, 1);
                break;
            case 'a':
                move(-1, 0);
                break;
            case 'd':
                move(1, 0);
                break;
            case 'q':
                game_over = 1;
                break;
            default:
                printf("Invalid command\n");
        }

        if (player_x == treasure_x && player_y == treasure_y) {
            printf("You found the treasure! Game over.\n");
            game_over = 1;
        } else if (player_x == enemy_x && player_y == enemy_y) {
            printf("You were caught by the enemy. Game over.\n");
            game_over = 1;
        }
    }

    return 0;
}