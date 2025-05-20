//GPT-4o-mini DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DUNGEON_SIZE 5
#define EMPTY ' '
#define TREASURE 'T'
#define MONSTER 'M'
#define PLAYER 'P'

typedef struct {
    int x, y;
} Player;

char dungeon[DUNGEON_SIZE][DUNGEON_SIZE];
Player player;

void initialize_dungeon() {
    for (int i = 0; i < DUNGEON_SIZE; i++) {
        for (int j = 0; j < DUNGEON_SIZE; j++) {
            dungeon[i][j] = EMPTY;
        }
    }

    // Place player
    player.x = rand() % DUNGEON_SIZE;
    player.y = rand() % DUNGEON_SIZE;
    dungeon[player.x][player.y] = PLAYER;

    // Place treasures and monsters randomly
    int num_items = (DUNGEON_SIZE * DUNGEON_SIZE) / 4;

    for (int i = 0; i < num_items; i++) {
        int x = rand() % DUNGEON_SIZE;
        int y = rand() % DUNGEON_SIZE;

        if (dungeon[x][y] == EMPTY) {
            dungeon[x][y] = (rand() % 2 == 0) ? TREASURE : MONSTER;  // 50% chance for treasure or monster
        }
    }
}

void display_dungeon() {
    printf("Dungeon Layout:\n");
    for (int i = 0; i < DUNGEON_SIZE; i++) {
        for (int j = 0; j < DUNGEON_SIZE; j++) {
            printf("%c ", dungeon[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void move_player(int dx, int dy) {
    int new_x = player.x + dx;
    int new_y = player.y + dy;

    // Check bounds
    if (new_x >= 0 && new_x < DUNGEON_SIZE && new_y >= 0 && new_y < DUNGEON_SIZE) {
        if (dungeon[new_x][new_y] == EMPTY || dungeon[new_x][new_y] == TREASURE) {
            // Move to the new position
            dungeon[player.x][player.y] = EMPTY;
            player.x = new_x;
            player.y = new_y;
            dungeon[player.x][player.y] = PLAYER;
        } else if (dungeon[new_x][new_y] == MONSTER) {
            printf("You encountered a monster! Game Over!\n");
            exit(0);  // End the game if a monster is encountered
        }
    }
}

void process_input(char action) {
    switch(action) {
        case 'w': move_player(-1, 0); break; // Up
        case 's': move_player(1, 0); break;  // Down
        case 'a': move_player(0, -1); break; // Left
        case 'd': move_player(0, 1); break;  // Right
        default: printf("Invalid action!\n");
    }
}

int main() {
    srand(time(0));
    initialize_dungeon();

    while (1) {
        display_dungeon();
        printf("Enter your action (w/a/s/d to move): ");
        char action;
        scanf(" %c", &action);
        process_input(action);
    }

    return 0;
}