//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 5
#define NUM_ITEMS 4

typedef struct {
    char name[50];
    char description[200];
    int north;
    int south;
    int east;
    int west;
    int item;
} Room;

typedef struct {
    char name[50];
    char description[200];
} Item;

Room rooms[NUM_ROOMS] = {
    {"Room 1", "You are in a small room with a door to the north.", 1, 0, 0, 0, 0},
    {"Room 2", "You are in a larger room with doors to the north and east.", 1, 1, 0, 0, 0},
    {"Room 3", "You are in a dark room with a door to the south.", 0, 0, 1, 0, 0},
    {"Room 4", "You are in a room with a door to the west.", 0, 0, 0, 1, 0},
    {"Room 5", "You are in a room with doors to the north and south.", 1, 0, 1, 0, 0}
};

Item items[NUM_ITEMS] = {
    {"Key", "A small key made of brass."},
    {"Lamp", "An old oil lamp with a flickering flame."},
    {"Map", "A tattered map of the labyrinth."},
    {"Sword", "A rusty sword with a sharp blade."}
};

int main() {
    srand(time(NULL));
    int player_room = rand() % NUM_ROOMS;
    printf("Welcome to the Labyrinth!\n");
    while (1) {
        printf("You are in room %d.\n", player_room + 1);
        printf("%s\n", rooms[player_room].description);
        printf("You can go to:\n");
        if (rooms[player_room].north) {
            printf("North - Room %d\n", rooms[player_room].north + 1);
        }
        if (rooms[player_room].south) {
            printf("South - Room %d\n", rooms[player_room].south + 1);
        }
        if (rooms[player_room].east) {
            printf("East - Room %d\n", rooms[player_room].east + 1);
        }
        if (rooms[player_room].west) {
            printf("West - Room %d\n", rooms[player_room].west + 1);
        }
        int choice;
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 4) {
            player_room = choice - 1;
        } else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}