//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 10
#define NUM_ITEMS 5

struct Room {
    int x;
    int y;
    char description[100];
};

struct Room rooms[NUM_ROOMS];

int main() {
    srand(time(NULL));
    for (int i = 0; i < NUM_ROOMS; i++) {
        rooms[i].x = rand() % 10;
        rooms[i].y = rand() % 10;
        sprintf(rooms[i].description, "You are in room (%d, %d).", rooms[i].x, rooms[i].y);
    }

    int playerX = 0;
    int playerY = 0;
    char command;
    while (1) {
        system("clear");
        for (int i = 0; i < NUM_ROOMS; i++) {
            if (rooms[i].x == playerX && rooms[i].y == playerY) {
                printf("%s\n", rooms[i].description);
            } else {
                printf("Room (%d, %d)\n", rooms[i].x, rooms[i].y);
            }
        }
        printf("> ");
        scanf("%c", &command);

        switch (command) {
            case 'w':
                if (playerX > 0 && rooms[--playerX].y == playerY) {
                    printf("You moved to room (%d, %d).\n", playerX, playerY);
                } else {
                    printf("There is no room to the west.\n");
                }
                break;
            case's':
                if (playerX < 9 && rooms[++playerX].y == playerY) {
                    printf("You moved to room (%d, %d).\n", playerX, playerY);
                } else {
                    printf("There is no room to the east.\n");
                }
                break;
            case 'n':
                if (playerY > 0 && rooms[playerX].y-- == playerY) {
                    printf("You moved to room (%d, %d).\n", playerX, playerY);
                } else {
                    printf("There is no room to the north.\n");
                }
                break;
            case 'e':
                if (playerY < 9 && rooms[playerX].y++ == playerY) {
                    printf("You moved to room (%d, %d).\n", playerX, playerY);
                } else {
                    printf("There is no room to the south.\n");
                }
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}