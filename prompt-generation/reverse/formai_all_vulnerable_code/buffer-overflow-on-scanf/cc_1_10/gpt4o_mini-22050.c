//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROOM_COUNT 6
#define ITEM_COUNT 5

typedef struct {
    char *name;
    char *description;
    int hasItem;
} Room;

typedef struct {
    char *name;
    char *effect;
} Item;

void initializeRooms(Room rooms[]);
void initializeItems(Item items[]);
void enterRoom(Room *room);
void encounterGhost();

int main() {
    srand(time(0)); // Seed random number generator

    Room rooms[ROOM_COUNT];
    initializeRooms(rooms);

    Item items[ITEM_COUNT];
    initializeItems(items);

    int currentRoomIndex = 0;
    int gameRunning = 1;

    printf("Welcome to the Medieval Haunted House Simulator!\n\n");

    while (gameRunning) {
        printf("You are in the %s.\n", rooms[currentRoomIndex].name);
        enterRoom(&rooms[currentRoomIndex]);

        if (rooms[currentRoomIndex].hasItem) {
            printf("You have found an item: %s\n", items[rand() % ITEM_COUNT].name);
            rooms[currentRoomIndex].hasItem = 0; // Item can be found only once
        }

        printf("Choose your next step:\n");
        printf("1. Move to the next room\n");
        printf("2. Encounter a ghost\n");
        printf("3. Leave the Haunted House\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                currentRoomIndex = (currentRoomIndex + 1) % ROOM_COUNT;
                break;
            case 2:
                encounterGhost();
                break;
            case 3:
                gameRunning = 0;
                printf("You bravely escaped the haunted house!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}

void initializeRooms(Room rooms[]) {
    rooms[0] = (Room){"Great Hall", "A grand hall adorned with ancient tapestries." , 1};
    rooms[1] = (Room){"Dungeon", "A dark and damp dungeon filled with echoes.", 1};
    rooms[2] = (Room){"Library", "A dusty library filled with mysterious tomes.", 1};
    rooms[3] = (Room){"Dining Room", "An eerie dining room with cobwebbed chandeliers.", 1};
    rooms[4] = (Room){"Cloister", "An abandoned cloister echoing with whispers.", 1};
    rooms[5] = (Room){"Entrance", "The entrance of the haunted house leading to the outside.", 0};
}

void initializeItems(Item items[]) {
    items[0] = (Item){"Golden Chalice", "It glows with a warm light."};
    items[1] = (Item){"Cursed Pendant", "A dark aura surrounds it."};
    items[2] = (Item){"Ancient Scroll", "It could hold powerful spells."};
    items[3] = (Item){"Crystal Ball", "Shows visions of the future."};
    items[4] = (Item){"Mystical Potion", "Can heal or harm, depending on usage."};
}

void enterRoom(Room *room) {
    printf("%s\n", room->description);
}

void encounterGhost() {
    printf("A ghost appears before you, its eyes glowing with a haunting light!\n");
    printf("1. Try to communicate with the ghost\n");
    printf("2. Run away\n");
    
    int ghostChoice;
    scanf("%d", &ghostChoice);

    if (ghostChoice == 1) {
        printf("You attempt to speak with the ghost. It reveals secrets of the house.\n");
    } else if (ghostChoice == 2) {
        printf("You flee from the ghost in terror!\n");
    } else {
        printf("You stand frozen in fear as the ghost wails!\n");
    }
}