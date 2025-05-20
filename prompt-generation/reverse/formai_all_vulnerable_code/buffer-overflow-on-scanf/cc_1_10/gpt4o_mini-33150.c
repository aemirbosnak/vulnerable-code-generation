//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 5
#define MAX_EVENTS 3

typedef struct {
    char *description;
    int hasGhost;
    int hasTreasure;
} Room;

typedef struct {
    char *eventDescription;
} Event;

void initializeRooms(Room rooms[]) {
    rooms[0].description = "You enter the dusty living room.";
    rooms[0].hasGhost = 1;
    rooms[0].hasTreasure = 0;

    rooms[1].description = "You find yourself in a dark kitchen.";
    rooms[1].hasGhost = 0;
    rooms[1].hasTreasure = 1;

    rooms[2].description = "You are standing in a creepy bedroom.";
    rooms[2].hasGhost = 1;
    rooms[2].hasTreasure = 0;

    rooms[3].description = "You have entered a musty basement.";
    rooms[3].hasGhost = 0;
    rooms[3].hasTreasure = 0;

    rooms[4].description = "You discover an eerie attic.";
    rooms[4].hasGhost = 1;
    rooms[4].hasTreasure = 1;
}

void initializeEvents(Event events[]) {
    events[0].eventDescription = "A chill runs down your spine as you feel an icy breath.";
    events[1].eventDescription = "You hear distant moaning echoing through the halls.";
    events[2].eventDescription = "A ghost appears before you! It looks menacing.";
}

void visitRoom(Room currentRoom, Event events[]) {
    printf("%s\n", currentRoom.description);
    
    if (currentRoom.hasGhost) {
        printf("%s\n", events[rand() % MAX_EVENTS].eventDescription);
    }
    if (currentRoom.hasTreasure) {
        printf("You found a hidden treasure in this room!\n");
    }
}

int main() {
    Room rooms[ROOMS];
    Event events[MAX_EVENTS];
    int choice;
    
    srand(time(NULL));
    initializeRooms(rooms);
    initializeEvents(events);

    printf("Welcome to the Haunted House Simulator!\n");
    
    while (1) {
        printf("Choose a room to enter (0 to 4) or -1 to exit: ");
        scanf("%d", &choice);
        
        if (choice == -1) {
            printf("You are leaving the haunted house. Goodbye!\n");
            break;
        } else if (choice < 0 || choice >= ROOMS) {
            printf("Invalid choice, please select a valid room.\n");
            continue;
        }

        visitRoom(rooms[choice], events);
    }
    
    return 0;
}