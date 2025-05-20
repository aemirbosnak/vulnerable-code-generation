//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 5
#define MAX_ROOMS 3

typedef struct {
    char *name;
    int collected;
} Item;

typedef struct {
    char *description;
    Item items[MAX_ITEMS];
    int itemCount;
} Room;

void initializeRooms(Room *rooms) {
    rooms[0].description = "You enter a dimly lit foyer with cobwebs everywhere.";
    rooms[0].items[0] = (Item){"An old key", 0};
    rooms[0].itemCount = 1;

    rooms[1].description = "You enter a dusty library filled with ancient books.";
    rooms[1].items[0] = (Item){"A mysterious book", 0};
    rooms[1].items[1] = (Item){"A ghostly amulet", 0};
    rooms[1].itemCount = 2;

    rooms[2].description = "You step into a creepy cellar with a foul smell.";
    rooms[2].items[0] = (Item){"A rusty dagger", 0};
    rooms[2].itemCount = 1;
}

void displayRoom(Room room) {
    printf("%s\n", room.description);
    printf("Items available:\n");
    for (int i = 0; i < room.itemCount; i++) {
        if (!room.items[i].collected) {
            printf(" - %s\n", room.items[i].name);
        }
    }
}

int collectItem(Room *room) {
    for (int i = 0; i < room->itemCount; i++) {
        if (!room->items[i].collected) {
            room->items[i].collected = 1;
            printf("You collected: %s!\n", room->items[i].name);
            return 1;
        }
    }
    printf("No items left to collect in this room.\n");
    return 0;
}

void hauntedEvent() {
    int event = rand() % 3;
    switch(event) {
        case 0:
            printf("A cold breeze sweeps through the room, chilling your bones!\n");
            break;
        case 1:
            printf("A ghost appears, whispering secrets of the past!\n");
            break;
        case 2:
            printf("You hear eerie laughter echoing in the distance.\n");
            break;
    }
}

int main() {
    srand(time(NULL));
    
    Room hauntedHouse[MAX_ROOMS];
    initializeRooms(hauntedHouse);

    int currentRoom = 0;
    char action;
    int gameOn = 1;

    printf("Welcome to the Haunted House Simulator!\n\n");

    while (gameOn) {
        printf("\nYou are in room %d: \n", currentRoom + 1);
        displayRoom(hauntedHouse[currentRoom]);
        
        printf("\nWhat would you like to do? (c: collect item, n: next room, q: quit): ");
        scanf(" %c", &action);

        switch (action) {
            case 'c':
                collectItem(&hauntedHouse[currentRoom]);
                hauntedEvent();
                break;
            case 'n':
                currentRoom++;
                if (currentRoom >= MAX_ROOMS) {
                    printf("You wander into the abyss, you've reached the end of the haunted house!\n");
                    gameOn = 0;
                }
                break;
            case 'q':
                printf("You have exited the haunted house. Thank you for playing!\n");
                gameOn = 0;
                break;
            default:
                printf("Invalid input! Try again.\n");
                break;
        }
    }

    return 0;
}