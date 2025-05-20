//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 20
#define MAX_GHOSTS 5

typedef struct {
    char name[50];
    int value;
} Item;

typedef struct {
    char name[50];
    int health;
    int speed;
} Ghost;

typedef struct {
    char description[100];
    int numItems;
    Item items[MAX_ITEMS];
    int numGhosts;
    Ghost ghosts[MAX_GHOSTS];
} Room;

void generateRandomRoom(Room *room) {
    int i;
    srand(time(NULL));
    room->numItems = rand() % (MAX_ITEMS - 1) + 1;
    room->numGhosts = rand() % (MAX_GHOSTS - 1) + 1;
    for (i = 0; i < room->numItems; i++) {
        room->items[i].value = rand() % 100;
        sprintf(room->items[i].name, "Item %d", i + 1);
    }
    for (i = 0; i < room->numGhosts; i++) {
        room->ghosts[i].health = rand() % 100;
        room->ghosts[i].speed = rand() % 100;
        sprintf(room->ghosts[i].name, "Ghost %d", i + 1);
    }
}

void printRoom(Room *room) {
    int i;
    printf("You are in the %s.\n", room->description);
    printf("There are %d items and %d ghosts in this room.\n", room->numItems, room->numGhosts);
    for (i = 0; i < room->numItems; i++) {
        printf("- %s (value: %d)\n", room->items[i].name, room->items[i].value);
    }
    for (i = 0; i < room->numGhosts; i++) {
        printf("- %s (health: %d, speed: %d)\n", room->ghosts[i].name, room->ghosts[i].health, room->ghosts[i].speed);
    }
}

int main() {
    Room rooms[MAX_ROOMS];
    int choice, numRooms = 0;

    printf("Welcome to the Haunted House!\n");
    printf("How many rooms do you want to explore? (1-%d): ", MAX_ROOMS - 1);
    scanf("%d", &numRooms);

    for (int i = 0; i < numRooms; i++) {
        generateRandomRoom(&rooms[i]);
    }

    while (1) {
        printf("\nWhich room do you want to go to? (1-%d): ", numRooms - 1);
        scanf("%d", &choice);
        if (choice >= 1 && choice <= numRooms - 1) {
            printRoom(&rooms[choice - 1]);
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}