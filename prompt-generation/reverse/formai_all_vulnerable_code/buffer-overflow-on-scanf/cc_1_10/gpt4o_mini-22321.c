//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 5
#define MAX_MONSTERS 5

typedef struct {
    char *name;
    char *description;
    int hasItem;
} Room;

typedef struct {
    char *name;
    char *description;
} Item;

typedef struct {
    char *name;
    char *attackDescription;
} Monster;

Room createRoom(char *name, char *description, int hasItem) {
    Room room;
    room.name = name;
    room.description = description;
    room.hasItem = hasItem;
    return room;
}

Item createItem(char *name, char *description) {
    Item item;
    item.name = name;
    item.description = description;
    return item;
}

Monster createMonster(char *name, char *attackDescription) {
    Monster monster;
    monster.name = name;
    monster.attackDescription = attackDescription;
    return monster;
}

void displayRoom(Room room) {
    printf("You are in: %s\n", room.name);
    printf("%s\n", room.description);
    if (room.hasItem) {
        printf("There's something shiny here!\n");
    }
}

void displayItems(Item items[], int itemCount) {
    printf("Items in the house:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("- %s: %s\n", items[i].name, items[i].description);
    }
}

void displayMonsters(Monster monsters[], int monsterCount) {
    printf("Monsters lurking:\n");
    for (int i = 0; i < monsterCount; i++) {
        printf("- %s: %s\n", monsters[i].name, monsters[i].attackDescription);
    }
}

void encounterMonster(Monster monster) {
    printf("A wild %s appears!\n", monster.name);
    printf("%s\n", monster.attackDescription);
    printf("You feel a chill run down your spine...\n");
}

int main() {
    srand(time(NULL));

    Room rooms[MAX_ROOMS];
    Item items[MAX_ITEMS];
    Monster monsters[MAX_MONSTERS];

    rooms[0] = createRoom("Foyer", "A grand entrance with a dusty chandelier.", 1);
    rooms[1] = createRoom("Library", "Shelves stacked with ancient tomes and cobwebs.", 0);
    rooms[2] = createRoom("Kitchen", "A cold, dark room filled with shadows and the scent of decay.", 1);
    rooms[3] = createRoom("Attic", "An eerie silence fills the air as you look around.", 1);
    rooms[4] = createRoom("Basement", "A damp staircase leads down into darkness.", 0);
    
    items[0] = createItem("Key", "An old rusty key that might unlock something.");
    items[1] = createItem("Candle", "A half-burned candle that flickers precariously.");
    items[2] = createItem("Rope", "A frayed rope, perhaps useful for climbing or binding.");
    items[3] = createItem("Book", "An ancient grimoire filled with dark secrets.");
    items[4] = createItem("Lantern", "An old lantern, it might illuminate the dark corners of the house.");

    monsters[0] = createMonster("Ghost", "It wails mournfully, seeking to drag you into the afterlife.");
    monsters[1] = createMonster("Skeleton", "Rattling bones echo as it lunges at you.");
    monsters[2] = createMonster("Zombie", "With a slow, dragging gait, it reaches for you.");
    monsters[3] = createMonster("Vampire", "Glaring with piercing eyes, it thirsts for your blood.");
    monsters[4] = createMonster("Werewolf", "A howl echoes, and it stalks you with primal fury.");

    int currentRoomIndex = 0;
    int itemFound = 0;
    char command[50];

    printf("Welcome to the Haunted House Simulator!\n");
    
    while (1) {
        displayRoom(rooms[currentRoomIndex]);
        
        if (rooms[currentRoomIndex].hasItem && !itemFound) {
            printf("Would you like to take the shiny item? (yes/no)\n");
            scanf("%s", command);
            if (strcmp(command, "yes") == 0) {
                printf("You took the item!\n");
                itemFound = 1;
            }
        }

        int encMonsterChance = rand() % 5;
        if (encMonsterChance == 0) {
            encounterMonster(monsters[rand() % MAX_MONSTERS]);
        }

        printf("What do you want to do? (move [room], view items, quit)\n");
        scanf("%s", command);

        if (strncmp(command, "move", 4) == 0) {
            char roomName[20];
            sscanf(command + 5, "%s", roomName);
            if (strcmp(roomName, "Foyer") == 0) currentRoomIndex = 0;
            else if (strcmp(roomName, "Library") == 0) currentRoomIndex = 1;
            else if (strcmp(roomName, "Kitchen") == 0) currentRoomIndex = 2;
            else if (strcmp(roomName, "Attic") == 0) currentRoomIndex = 3;
            else if (strcmp(roomName, "Basement") == 0) currentRoomIndex = 4;
            else printf("Room not found!\n");
        } else if (strcmp(command, "view") == 0) {
            displayItems(items, MAX_ITEMS);
        } else if (strcmp(command, "quit") == 0) {
            printf("Exiting the haunted house... until next time!\n");
            break;
        } else {
            printf("Invalid command!\n");
        }

        printf("\n");
    }

    return 0;
}