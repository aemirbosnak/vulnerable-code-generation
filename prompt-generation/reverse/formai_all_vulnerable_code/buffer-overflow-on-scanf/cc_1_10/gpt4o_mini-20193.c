//GPT-4o-mini DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROOMS 10
#define ROOM_SIZE 5
#define PLAYER_SYMBOL 'P'
#define MONSTER_SYMBOL 'M'
#define TREASURE_SYMBOL 'T'
#define EMPTY_SYMBOL '.'

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int collected;
} Player;

typedef struct {
    Position pos;
} Monster;

typedef struct {
    Position pos;
} Treasure;

typedef struct {
    char grid[ROOM_SIZE][ROOM_SIZE];
} Room;

Room rooms[MAX_ROOMS];
Player player;
Monster monsters[3];
Treasure treasures[3];

void initializeRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        for (int j = 0; j < ROOM_SIZE; j++) {
            for (int k = 0; k < ROOM_SIZE; k++) {
                rooms[i].grid[j][k] = EMPTY_SYMBOL;
            }
        }
    }
}

void placePlayer() {
    player.pos.x = 0;
    player.pos.y = 0;
    rooms[player.pos.x].grid[player.pos.y][player.pos.y] = PLAYER_SYMBOL;
}

void placeMonsters() {
    for (int i = 0; i < 3; i++) {
        monsters[i].pos.x = rand() % ROOM_SIZE;
        monsters[i].pos.y = rand() % ROOM_SIZE;
        rooms[0].grid[monsters[i].pos.x][monsters[i].pos.y] = MONSTER_SYMBOL;
    }
}

void placeTreasures() {
    for (int i = 0; i < 3; i++) {
        treasures[i].pos.x = rand() % ROOM_SIZE;
        treasures[i].pos.y = rand() % ROOM_SIZE;
        rooms[0].grid[treasures[i].pos.x][treasures[i].pos.y] = TREASURE_SYMBOL;
    }
}

void printRoom(int roomIndex) {
    for (int i = 0; i < ROOM_SIZE; i++) {
        for (int j = 0; j < ROOM_SIZE; j++) {
            putchar(rooms[roomIndex].grid[i][j]);
        }
        putchar('\n');
    }
}

void movePlayer(char direction) {
    int newX = player.pos.x;
    int newY = player.pos.y;

    switch (direction) {
        case 'w': newX--; break; // Up
        case 's': newX++; break; // Down
        case 'a': newY--; break; // Left
        case 'd': newY++; break; // Right
    }

    if (newX >= 0 && newX < ROOM_SIZE && newY >= 0 && newY < ROOM_SIZE) {
        if (rooms[0].grid[newX][newY] == EMPTY_SYMBOL) {
            rooms[0].grid[player.pos.x][player.pos.y] = EMPTY_SYMBOL;
            player.pos.x = newX;
            player.pos.y = newY;
            rooms[0].grid[player.pos.x][player.pos.y] = PLAYER_SYMBOL;
        } else if (rooms[0].grid[newX][newY] == TREASURE_SYMBOL) {
            rooms[0].grid[player.pos.x][player.pos.y] = EMPTY_SYMBOL;
            player.pos.x = newX;
            player.pos.y = newY;
            player.collected++;
            rooms[0].grid[player.pos.x][player.pos.y] = PLAYER_SYMBOL;
            printf("Treasure collected! Total: %d\n", player.collected);
        } else if (rooms[0].grid[newX][newY] == MONSTER_SYMBOL) {
            printf("You encountered a monster! Game Over.\n");
            exit(0);
        }
    }
}

int main() {
    srand(time(NULL));
    initializeRooms();
    placePlayer();
    placeMonsters();
    placeTreasures();

    char command;
    while (1) {
        printRoom(0);
        printf("Command (w/a/s/d): ");
        scanf(" %c", &command);
        movePlayer(command);
    }

    return 0;
}