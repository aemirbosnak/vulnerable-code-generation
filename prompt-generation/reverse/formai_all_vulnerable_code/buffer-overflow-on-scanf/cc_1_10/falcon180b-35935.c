//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define MAP_WIDTH 10
#define MAP_HEIGHT 5
#define PLAYER_X 0
#define PLAYER_Y 0
#define PLAYER_CHAR '@'
#define WALL_CHAR '#'
#define ENEMY_CHAR 'E'
#define TREASURE_CHAR '$'

typedef struct {
    int x;
    int y;
} Point;

void generate_map(char map[MAP_HEIGHT][MAP_WIDTH]) {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = WALL_CHAR;
        }
    }
    map[0][0] = PLAYER_CHAR;
}

void print_map(char map[MAP_HEIGHT][MAP_WIDTH]) {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int move(int dx, int dy, char map[MAP_HEIGHT][MAP_WIDTH], Point *player) {
    Point new_player = {player->x + dx, player->y + dy};
    if (new_player.x >= 0 && new_player.x < MAP_WIDTH && new_player.y >= 0 && new_player.y < MAP_HEIGHT && map[new_player.y][new_player.x]!= WALL_CHAR) {
        *player = new_player;
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));

    char map[MAP_HEIGHT][MAP_WIDTH];
    generate_map(map);

    Point player = {PLAYER_X, PLAYER_Y};

    int game_over = 0;
    while (!game_over) {
        system("clear");
        print_map(map);

        char input;
        scanf("%c", &input);

        switch (input) {
            case 'w':
            case 'W':
                move(0, -1, map, &player);
                break;
            case's':
            case 'S':
                move(0, 1, map, &player);
                break;
            case 'a':
            case 'A':
                move(-1, 0, map, &player);
                break;
            case 'd':
            case 'D':
                move(1, 0, map, &player);
                break;
            default:
                break;
        }

        if (map[player.y][player.x] == TREASURE_CHAR) {
            printf("You found the treasure! Congratulations!\n");
            game_over = 1;
        } else if (map[player.y][player.x] == ENEMY_CHAR) {
            printf("You encountered an enemy! Game over.\n");
            game_over = 1;
        }
    }

    return 0;
}