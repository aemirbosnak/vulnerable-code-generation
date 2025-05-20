//GPT-4o-mini DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DUNGEON_SIZE 5
#define ROOM_NUMBER 3
#define TREASURE_VALUE 50

typedef struct {
    int hasTreasure;
    int hasMonster;
} Room;

void initializeDungeon(Room dungeon[DUNGEON_SIZE][DUNGEON_SIZE]) {
    for (int i = 0; i < DUNGEON_SIZE; i++) {
        for (int j = 0; j < DUNGEON_SIZE; j++) {
            dungeon[i][j].hasTreasure = rand() % 2;
            dungeon[i][j].hasMonster = rand() % 2;
        }
    }
}

void displayDungeon(Room dungeon[DUNGEON_SIZE][DUNGEON_SIZE]) {
    printf("Dungeon Layout:\n");
    for (int i = 0; i < DUNGEON_SIZE; i++) {
        for (int j = 0; j < DUNGEON_SIZE; j++) {
            if (dungeon[i][j].hasMonster) {
                printf("[M] ");
            } else if (dungeon[i][j].hasTreasure) {
                printf("[T] ");
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}

void exploreRoom(Room room, int *score) {
    if (room.hasTreasure) {
        *score += TREASURE_VALUE;
        printf("You found treasure worth %d points!\n", TREASURE_VALUE);
    } else if (room.hasMonster) {
        printf("A monster appears! You lose 20 points!\n");
        *score -= 20;
    } else {
        printf("The room is empty, but safe.\n");
    }
}

int main() {
    srand(time(NULL));

    Room dungeon[DUNGEON_SIZE][DUNGEON_SIZE];
    initializeDungeon(dungeon);
    int score = 0;
    int x = 0, y = 0;
    
    while (1) {
        displayDungeon(dungeon);
        printf("Current Score: %d\n", score);
        char move;
        printf("You are at room (%d, %d). Enter 'e' to explore, or 'q' to quit: ", x, y);
        scanf(" %c", &move);

        if (move == 'e') {
            exploreRoom(dungeon[x][y], &score);
        } else if (move == 'q') {
            printf("Thanks for playing! Your final score is: %d\n", score);
            break;
        } else {
            printf("Invalid input, please try again.\n");
        }

        // Move logic: simple boundary checks
        printf("Move (w/a/s/d): ");
        scanf(" %c", &move);
        if (move == 'w' && x > 0) x--;
        else if (move == 's' && x < DUNGEON_SIZE - 1) x++;
        else if (move == 'a' && y > 0) y--;
        else if (move == 'd' && y < DUNGEON_SIZE - 1) y++;
        else printf("You can't move in that direction!\n");
    }

    return 0;
}