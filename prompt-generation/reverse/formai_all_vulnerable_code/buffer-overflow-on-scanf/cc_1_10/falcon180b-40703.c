//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 10
#define HORROR_LEVEL 3

typedef struct {
    char name[100];
    char description[500];
    int horrorLevel;
} Room;

Room rooms[ROOMS];

void generateRooms() {
    srand(time(NULL));
    for (int i = 0; i < ROOMS; i++) {
        rooms[i].horrorLevel = rand() % HORROR_LEVEL + 1;
        printf("Enter name of room %d: ", i+1);
        scanf("%s", rooms[i].name);
        printf("Enter description of room %d: ", i+1);
        scanf("%s", rooms[i].description);
    }
}

void showRoom(int roomNumber) {
    printf("\nYou are in room %s.\n", rooms[roomNumber].name);
    printf("%s\n", rooms[roomNumber].description);
    printf("Horror level: %d\n", rooms[roomNumber].horrorLevel);
}

int main() {
    generateRooms();
    int currentRoom = 0;
    while (1) {
        printf("\nYou are in room %s.\n", rooms[currentRoom].name);
        printf("%s\n", rooms[currentRoom].description);
        printf("Horror level: %d\n", rooms[currentRoom].horrorLevel);
        printf("Enter 'next' to go to the next room or 'quit' to exit: ");
        char choice[10];
        scanf("%s", choice);
        if (strcmp(choice, "next") == 0) {
            currentRoom = (currentRoom + 1) % ROOMS;
        } else if (strcmp(choice, "quit") == 0) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}