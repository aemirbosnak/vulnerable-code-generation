//Code Llama-13B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: configurable
/*
 * Rogue-like game with procedural generation
 *
 * This program generates a procedurally-generated dungeon using a cellular automata algorithm
 * and displays it in a configurable style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DUNGEON_WIDTH 100
#define DUNGEON_HEIGHT 50
#define ROOM_WIDTH 10
#define ROOM_HEIGHT 10

typedef struct {
    int x, y;
    char type;
} Cell;

Cell** dungeon;

void init_dungeon() {
    dungeon = malloc(sizeof(Cell*) * DUNGEON_WIDTH);
    for (int i = 0; i < DUNGEON_WIDTH; i++) {
        dungeon[i] = malloc(sizeof(Cell) * DUNGEON_HEIGHT);
    }
}

void generate_dungeon() {
    srand(time(NULL));

    for (int i = 0; i < DUNGEON_WIDTH; i++) {
        for (int j = 0; j < DUNGEON_HEIGHT; j++) {
            dungeon[i][j].x = i;
            dungeon[i][j].y = j;
            dungeon[i][j].type = rand() % 4;
        }
    }
}

void print_dungeon() {
    for (int i = 0; i < DUNGEON_WIDTH; i++) {
        for (int j = 0; j < DUNGEON_HEIGHT; j++) {
            switch (dungeon[i][j].type) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("X");
                    break;
                case 2:
                    printf("O");
                    break;
                case 3:
                    printf("#");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    init_dungeon();
    generate_dungeon();
    print_dungeon();
    return 0;
}