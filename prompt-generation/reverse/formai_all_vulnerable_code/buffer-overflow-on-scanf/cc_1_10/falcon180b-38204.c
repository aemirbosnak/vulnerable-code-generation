//Falcon-180B DATASET v1.0 Category: Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define PLAYER_X 0
#define PLAYER_Y 0
#define ENEMY_X 9
#define ENEMY_Y 9

char map[MAP_WIDTH][MAP_HEIGHT];
int player_x, player_y;
int enemy_x, enemy_y;

void init_map() {
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            map[i][j] = '.';
        }
    }
    map[PLAYER_X][PLAYER_Y] = 'P';
    map[ENEMY_X][ENEMY_Y] = 'E';
}

void print_map() {
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    init_map();
    print_map();

    while (1) {
        char input;
        printf("Enter your move (w/a/s/d): ");
        scanf("%c", &input);

        switch (input) {
            case 'w':
                if (player_y > 0 && map[player_x][player_y - 1] == '.') {
                    player_y--;
                }
                break;
            case 'a':
                if (player_x > 0 && map[player_x - 1][player_y] == '.') {
                    player_x--;
                }
                break;
            case's':
                if (player_y < MAP_HEIGHT - 1 && map[player_x][player_y + 1] == '.') {
                    player_y++;
                }
                break;
            case 'd':
                if (player_x < MAP_WIDTH - 1 && map[player_x + 1][player_y] == '.') {
                    player_x++;
                }
                break;
            default:
                printf("Invalid move.\n");
        }

        if (player_x == ENEMY_X && player_y == ENEMY_Y) {
            printf("You have reached the enemy!\n");
            break;
        }

        print_map();
    }

    return 0;
}