//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM 5

typedef struct {
    const char* description;
    int scareLevel;
} Room;

void initializeRooms(Room rooms[MAX_ROOM]) {
    rooms[0] = (Room){"You are in a dimly lit foyer. A chill runs down your spine.", 1};
    rooms[1] = (Room){"This room is filled with the sound of whispering shadows.", 3};
    rooms[2] = (Room){"You step into a dusty library, the shelves filled with tombs of the forgotten.", 4};
    rooms[3] = (Room){"You enter a kitchen where the pots and pans start rattling unexpectedly.", 5};
    rooms[4] = (Room){"The attic is dark and filled with cobwebs. You feel like someone is watching you.", 6};
}

void displayRoom(const Room room) {
    printf("%s\n", room.description);
}

int randomEvent() {
    return rand() % 100 + 1;
}

void encounter(int scareLevel) {
    int event = randomEvent();
    if (event <= scareLevel * 10) {
        printf("You encountered a ghost! It lets out a terrifying wail!\n");
    } else {
        printf("Nothing happens... it's eerily quiet.\n");
    }
}

int main() {
    Room rooms[MAX_ROOM];
    initializeRooms(rooms);

    int currentRoom = 0;
    char choice;

    srand(time(NULL)); // Seed for random number generation

    printf("Welcome to the Haunted House Simulator!\n");
    
    while (currentRoom < MAX_ROOM) {
        displayRoom(rooms[currentRoom]);
        encounter(rooms[currentRoom].scareLevel);
        
        if (currentRoom < MAX_ROOM - 1) {
            printf("Do you want to proceed to the next room? (y/n): ");
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y') {
                currentRoom++;
            } else {
                printf("You decided to stay put, but something feels off...\n");
            }
        } else {
            printf("You have reached the end of the haunted house! Thanks for playing!\n");
            break;
        }
    }

    return 0;
}