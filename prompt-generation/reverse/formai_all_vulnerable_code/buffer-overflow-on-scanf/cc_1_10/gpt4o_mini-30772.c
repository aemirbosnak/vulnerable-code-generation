//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DUNGEON_SIZE 5
#define MAX_TREASURES 3
#define MAX_TRAPS 3

typedef struct {
    int x;
    int y;
} Player;

typedef struct {
    int x;
    int y;
} Entity;

char dungeon[DUNGEON_SIZE][DUNGEON_SIZE];
Player player;
Entity treasures[MAX_TREASURES];
Entity traps[MAX_TRAPS];

void initializeDungeon() {
    for (int i = 0; i < DUNGEON_SIZE; i++) {
        for (int j = 0; j < DUNGEON_SIZE; j++) {
            dungeon[i][j] = '.';
        }
    }

    player.x = 0;
    player.y = 0;
    dungeon[player.x][player.y] = 'P';

    for (int i = 0; i < MAX_TREASURES; i++) {
        int x, y;
        do {
            x = rand() % DUNGEON_SIZE;
            y = rand() % DUNGEON_SIZE;
        } while(dungeon[x][y] != '.');
        treasures[i].x = x;
        treasures[i].y = y;
        dungeon[x][y] = 'T';
    }

    for (int i = 0; i < MAX_TRAPS; i++) {
        int x, y;
        do {
            x = rand() % DUNGEON_SIZE;
            y = rand() % DUNGEON_SIZE;
        } while(dungeon[x][y] != '.');
        traps[i].x = x;
        traps[i].y = y;
        dungeon[x][y] = 'X';
    }
}

void printDungeon() {
    printf("\nDungeon Layout:\n");
    for (int i = 0; i < DUNGEON_SIZE; i++) {
        for (int j = 0; j < DUNGEON_SIZE; j++) {
            printf("%c ", dungeon[i][j]);
        }
        printf("\n");
    }
}

int movePlayer(char direction) {
    int newX = player.x;
    int newY = player.y;

    switch(direction) {
        case 'w': newX--; break; // up
        case 's': newX++; break; // down
        case 'a': newY--; break; // left
        case 'd': newY++; break; // right
        default: printf("Invalid move. Use W/A/S/D to move.\n"); return 0;
    }

    if (newX < 0 || newX >= DUNGEON_SIZE || newY < 0 || newY >= DUNGEON_SIZE) {
        printf("Out of bounds! You hit the wall.\n");
        return 0;
    }

    if (dungeon[newX][newY] == 'X') {
        printf("You stepped on a trap! Game over!\n");
        return -1;
    }

    dungeon[player.x][player.y] = '.';
    player.x = newX;
    player.y = newY;
    dungeon[player.x][player.y] = 'P';

    if (dungeon[newX][newY] == 'T') {
        printf("You found a treasure!\n");
        dungeon[newX][newY] = 'P'; // remove treasure
    }

    return 1;
}

int main() {
    srand(time(NULL));
    initializeDungeon();

    char command;
    int gameStatus = 1;

    while (gameStatus > 0) {
        printDungeon();
        printf("Enter your move (W/A/S/D): ");
        scanf(" %c", &command);
        gameStatus = movePlayer(command);
    }
    
    printf("Thank you for playing Dungeon Escape!\n");
    return 0;
}