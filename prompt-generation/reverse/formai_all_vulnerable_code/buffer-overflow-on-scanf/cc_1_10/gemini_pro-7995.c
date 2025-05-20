//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10

typedef struct room {
    int north;
    int south;
    int east;
    int west;
    int visited;
} room;

room rooms[MAX_ROOMS];
int currentRoom = 0;
int numRooms = 0;

void createRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].north = -1;
        rooms[i].south = -1;
        rooms[i].east = -1;
        rooms[i].west = -1;
        rooms[i].visited = 0;
    }
}

void connectRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (i != 0) {
            rooms[i].south = i - 1;
        }
        if (i != MAX_ROOMS - 1) {
            rooms[i].north = i + 1;
        }
        if (i % 2 == 0) {
            rooms[i].east = i + 1;
        } else {
            rooms[i].west = i - 1;
        }
    }
}

void printRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("Room %d:\n", i);
        printf("North: %d\n", rooms[i].north);
        printf("South: %d\n", rooms[i].south);
        printf("East: %d\n", rooms[i].east);
        printf("West: %d\n", rooms[i].west);
        printf("Visited: %d\n", rooms[i].visited);
        printf("\n");
    }
}

void playGame() {
    char input[10];
    while (1) {
        printf("You are in room %d.\n", currentRoom);
        printf("Which direction would you like to go? (n, s, e, w)\n");
        scanf("%s", input);
        if (strcmp(input, "n") == 0) {
            if (rooms[currentRoom].north != -1) {
                currentRoom = rooms[currentRoom].north;
            } else {
                printf("There is no door to the north.\n");
            }
        } else if (strcmp(input, "s") == 0) {
            if (rooms[currentRoom].south != -1) {
                currentRoom = rooms[currentRoom].south;
            } else {
                printf("There is no door to the south.\n");
            }
        } else if (strcmp(input, "e") == 0) {
            if (rooms[currentRoom].east != -1) {
                currentRoom = rooms[currentRoom].east;
            } else {
                printf("There is no door to the east.\n");
            }
        } else if (strcmp(input, "w") == 0) {
            if (rooms[currentRoom].west != -1) {
                currentRoom = rooms[currentRoom].west;
            } else {
                printf("There is no door to the west.\n");
            }
        } else {
            printf("Invalid input.\n");
        }
        rooms[currentRoom].visited = 1;
        if (rooms[currentRoom].visited == MAX_ROOMS) {
            printf("You have explored all of the rooms. Congratulations!\n");
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    createRooms();
    connectRooms();
    printRooms();
    playGame();
    return 0;
}