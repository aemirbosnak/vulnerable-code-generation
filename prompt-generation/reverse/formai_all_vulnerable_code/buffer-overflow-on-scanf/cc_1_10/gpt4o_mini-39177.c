//GPT-4o-mini DATASET v1.0 Category: Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DUNGEON_SIZE 5
#define TREASURE 1
#define TRAP 2
#define EMPTY 0

void displayDungeon(int dungeon[DUNGEON_SIZE][DUNGEON_SIZE]);
void generateDungeon(int dungeon[DUNGEON_SIZE][DUNGEON_SIZE]);
void navigateDungeon(int dungeon[DUNGEON_SIZE][DUNGEON_SIZE]);

int main() {
    int dungeon[DUNGEON_SIZE][DUNGEON_SIZE];

    srand(time(NULL)); // Seed for random number generator
    generateDungeon(dungeon);
    navigateDungeon(dungeon);

    return 0;
}

void generateDungeon(int dungeon[DUNGEON_SIZE][DUNGEON_SIZE]) {
    for (int i = 0; i < DUNGEON_SIZE; i++) {
        for (int j = 0; j < DUNGEON_SIZE; j++) {
            int randomEvent = rand() % 3; // 0: empty, 1: treasure, 2: trap
            dungeon[i][j] = randomEvent;
        }
    }
    // Place the player at the start position
    dungeon[0][0] = EMPTY;
}

void displayDungeon(int dungeon[DUNGEON_SIZE][DUNGEON_SIZE]) {
    printf("Dungeon Layout:\n");
    for (int i = 0; i < DUNGEON_SIZE; i++) {
        for (int j = 0; j < DUNGEON_SIZE; j++) {
            if (dungeon[i][j] == EMPTY) {
                printf("[ ] ");
            } else if (dungeon[i][j] == TREASURE) {
                printf("[T] ");
            } else if (dungeon[i][j] == TRAP) {
                printf("[X] ");
            }
        }
        printf("\n");
    }
}

void navigateDungeon(int dungeon[DUNGEON_SIZE][DUNGEON_SIZE]) {
    int x = 0, y = 0;
    int score = 0;
    char move;

    while (1) {
        displayDungeon(dungeon);
        printf("Current score: %d\n", score);
        printf("You are at position (%d, %d). Enter your move (w/a/s/d to move, q to quit): ", x, y);
        scanf(" %c", &move);

        if (move == 'q') {
            printf("Thanks for playing! Your final score is: %d\n", score);
            break;
        }

        int newX = x, newY = y;

        switch (move) {
            case 'w':
                newX--; break; // Move up
            case 'a':
                newY--; break; // Move left
            case 's':
                newX++; break; // Move down
            case 'd':
                newY++; break; // Move right
            default:
                printf("Invalid move. Use w/a/s/d.\n");
                continue;
        }

        // Check for boundaries
        if (newX >= 0 && newX < DUNGEON_SIZE && newY >= 0 && newY < DUNGEON_SIZE) {
            // Check the event in the new cell
            if (dungeon[newX][newY] == TREASURE) {
                score += 10;
                printf("You found a treasure! Score increased.\n");
            } else if (dungeon[newX][newY] == TRAP) {
                score -= 5;
                printf("You fell into a trap! Score decreased.\n");
            }
            // Move player to new position
            x = newX;
            y = newY;
        } else {
            printf("You're trying to move out of bounds. Try again.\n");
        }
    }
}