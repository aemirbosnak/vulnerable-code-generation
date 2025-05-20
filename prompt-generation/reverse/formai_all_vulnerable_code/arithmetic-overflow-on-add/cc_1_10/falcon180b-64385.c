//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_ROOM_SIZE 10
#define MAX_ITEMS 10
#define MAX_ENEMIES 10
#define MAX_PLAYER_HEALTH 10

typedef struct {
    char symbol;
    int color;
} Cell;

typedef struct {
    Cell **cells;
    int width;
    int height;
} Room;

typedef struct {
    Room *rooms[MAX_ROOMS];
    int num_rooms;
    int player_x;
    int player_y;
    int player_health;
    int num_items;
    int num_enemies;
} Game;

void generate_room(Room *room) {
    int i, j;
    for (i = 0; i < room->height; i++) {
        for (j = 0; j < room->width; j++) {
            room->cells[i][j].symbol = rand() % 3 + 'A';
            room->cells[i][j].color = rand() % 7;
        }
    }
}

void generate_game(Game *game) {
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        game->rooms[i] = malloc(sizeof(Room));
        game->rooms[i]->cells = malloc(MAX_ROOM_SIZE * MAX_ROOM_SIZE * sizeof(Cell));
        game->rooms[i]->width = rand() % MAX_ROOM_SIZE + 3;
        game->rooms[i]->height = rand() % MAX_ROOM_SIZE + 3;
        game->num_rooms++;
    }
    game->player_x = 0;
    game->player_y = 0;
    game->player_health = MAX_PLAYER_HEALTH;
    game->num_items = rand() % MAX_ITEMS + 1;
    game->num_enemies = rand() % MAX_ENEMIES + 1;
}

void print_room(Room *room) {
    int i, j;
    for (i = 0; i < room->height; i++) {
        for (j = 0; j < room->width; j++) {
            printf("%c", room->cells[i][j].symbol);
        }
        printf("\n");
    }
}

void print_game(Game *game) {
    int i;
    for (i = 0; i < game->num_rooms; i++) {
        print_room(game->rooms[i]);
    }
}

int main() {
    srand(time(NULL));
    Game game;
    generate_game(&game);
    print_game(&game);
    return 0;
}