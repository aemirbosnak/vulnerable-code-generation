//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 5
#define LINES_PER_ROOM 3
#define MAX_OBJECTS 10
#define MAX_ENEMIES 5

typedef struct {
    char *name;
    char *description;
} Object;

typedef struct {
    char *name;
    int health;
    int attack;
} Enemy;

typedef struct {
    char **rooms;
    Object *objects;
    Enemy *enemies;
    int player_health;
    int player_attack;
    int current_room;
} Game;

void generate_room(char room[LINES_PER_ROOM][100]) {
    int i, j;
    for (i = 0; i < LINES_PER_ROOM; i++) {
        for (j = 0; j < 100; j++) {
            room[i][j] = rand() % 10 + '0';
        }
        room[i][j] = '\0';
    }
}

void print_room(char room[LINES_PER_ROOM][100]) {
    int i;
    for (i = 0; i < LINES_PER_ROOM; i++) {
        printf("%s\n", room[i]);
    }
}

int main() {
    srand(time(NULL));

    Game game = {
       .rooms = malloc(ROOMS * sizeof(char *)),
       .objects = malloc(MAX_OBJECTS * sizeof(Object)),
       .enemies = malloc(MAX_ENEMIES * sizeof(Enemy)),
       .player_health = 100,
       .player_attack = 10,
       .current_room = 0
    };

    game.rooms[0] = malloc(LINES_PER_ROOM * sizeof(char *));
    generate_room(game.rooms[0]);
    print_room(game.rooms[0]);

    return 0;
}