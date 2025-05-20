#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define WORLD_WIDTH 100
#define WORLD_HEIGHT 50
#define PLAYER_SPEED 2

typedef struct {
    int x, y;
} Position;

void draw_world(char world[WORLD_WIDTH][WORLD_HEIGHT]) {
    int x, y;
    for (y = 0; y < WORLD_HEIGHT; y++) {
        for (x = 0; x < WORLD_WIDTH; x++) {
            if (y >= WORLD_HEIGHT || x >= WORLD_WIDTH) {
                world[x][y] = '*';
            }
            printf("%c", world[x][y]);
        }
        printf("\n");
    }
}

void update_player(Position *player, char world[WORLD_WIDTH][WORLD_HEIGHT]) {
    Position new_position = {player->x + PLAYER_SPEED, player->y};
    if (new_position.x < 0 || new_position.y < 0 || new_position.x >= WORLD_WIDTH || new_position.y >= WORLD_HEIGHT) {
        world[player->x][player->y] = 'X';
        player->x = new_position.x;
        player->y = new_position.y;
    }
}

int main() {
    char world[WORLD_WIDTH][WORLD_HEIGHT];
    Position player = {5, 5};

    int i;
    for (i = 0; i < WORLD_WIDTH * WORLD_HEIGHT; i++) {
        world[i / WORLD_WIDTH][i % WORLD_WIDTH] = ' ';
    }

    int exit = 0;
    while (!exit) {
        draw_world(world);
        update_player(&player, world);
        getchar();
        system("clear");
    }

    return 0;
}
