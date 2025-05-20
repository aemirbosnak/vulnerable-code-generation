//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 5
#define MAX_ITEMS 3

typedef struct {
    const char *name;
    const char *description;
    int hasGhost;
    int items[MAX_ITEMS];
} Room;

typedef struct {
    const char *name;
    int health;
    int courage;
} Player;

void printRoomDescription(Room room) {
    printf("You enter the %s.\n", room.name);
    printf("%s\n", room.description);
    if (room.hasGhost) {
        printf("A ghost appears!\n");
    }
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (room.items[i]) {
            printf("You see an item: %d\n", room.items[i]);
        }
    }
}

int checkCourage(Player player, Room room) {
    if (player.courage < 5 && room.hasGhost) {
        printf("You are too scared to face the ghost!\n");
        return 0;
    }
    return 1;
}

void encounterGhost(Player *player) {
    if (player->courage > 5) {
        printf("You bravely face the ghost!\n");
        player->courage -= 2;
        printf("Your courage is now %d.\n", player->courage);
    } else {
        printf("You flee the room in terror!\n");
        player->health -= 1;
        printf("Your health drops to %d.\n", player->health);
    }
}

int main() {
    srand(time(NULL));

    Room rooms[NUM_ROOMS] = {
        {"Spooky Hallway", "A dimly lit hallway with creaky floorboards.", 1, {0, 1, 0}},
        {"Abandoned Library", "Books scattered everywhere, dusty and eerie.", 0, {2, 0, 0}},
        {"Forgotten Basement", "A dark, musty room that smells of mildew.", 1, {0, 0, 3}},
        {"Creepy Attic", "The sound of rats scurrying, with cobwebs everywhere.", 1, {0, 0, 0}},
        {"Haunted Bedroom", "The air is thick with despair, and furniture is tipped over.", 1, {0, 2, 0}}
    };

    Player player = {"Adventurer", 5, 10};

    int currentRoom = 0;
    char command[20];
    
    printf("Welcome to the Haunted House Simulator!\n");

    while (player.health > 0) {
        printRoomDescription(rooms[currentRoom]);
        
        printf("What would you like to do? (explore/exit): ");
        scanf("%s", command);
        
        if (strcmp(command, "explore") == 0) {
            if (checkCourage(player, rooms[currentRoom])) {
                if (rooms[currentRoom].hasGhost) {
                    encounterGhost(&player);
                }
                // Simulate finding an item
                int foundItem = rand() % 3;
                if (rooms[currentRoom].items[foundItem] != 0) {
                    printf("You found an item: %d!\n", rooms[currentRoom].items[foundItem]);
                    rooms[currentRoom].items[foundItem] = 0; // Item is now collected
                }
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the haunted house. Good luck next time!\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }

        // Simulate room change
        currentRoom = (currentRoom + 1) % NUM_ROOMS;
        printf("\n");
    }

    if (player.health <= 0) {
        printf("You have succumbed to the horrors of the haunted house.\n");
    }

    return 0;
}