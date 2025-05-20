//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5
#define MAX_ITEMS 3
#define GHOST_DAMAGE 20

typedef struct Room {
    char *description;
    int hasGhost;
    int itemIndex;
} Room;

typedef struct Player {
    int health;
    int items[MAX_ITEMS];
    int itemCount;
} Player;

Room rooms[MAX_ROOMS] = {
    {"You are in the dark hallway. There are doors to the left and right.", 1, 0},
    {"You find yourself in a dusty library filled with cobwebs.", 0, 1},
    {"You enter the spooky dining room with an eerie atmosphere.", 1, -1},
    {"This is the kitchen, you can smell something rotten.", 0, 2},
    {"You stand in a cold cellar, can you hear whispering?", 1, -1}
};

char *items[MAX_ITEMS] = {
    "Mysterious Key",
    "Ancient Tome",
    "Witch's Broom"
};

void describeRoom(Room room) {
    printf("%s\n", room.description);
    if (room.hasGhost) {
        printf("A ghost lurks in this room!\n");
    }
    if (room.itemIndex != -1) {
        printf("You see an item: %s\n", items[room.itemIndex]);
    }
}

void encounterGhost(Player *player) {
    printf("You encounter a ghost! It attacks you!\n");
    player->health -= GHOST_DAMAGE;
    printf("You lose %d health! Current health: %d\n", GHOST_DAMAGE, player->health);
}

int main() {
    srand(time(NULL));
    Player player = {100, {-1, -1, -1}, 0};
    int currentRoom = 0;
    char command[10];

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have %d health points.\n", player.health);

    while (player.health > 0) {
        describeRoom(rooms[currentRoom]);

        if (rooms[currentRoom].hasGhost) {
            encounterGhost(&player);
            rooms[currentRoom].hasGhost = 0; // Ghost defeated
        }

        printf("Enter your command (go [left/right], take [item], exit): ");
        scanf("%s", command);

        if (strcmp(command, "go") == 0) {
            char direction[10];
            scanf("%s", direction);
            if (strcmp(direction, "left") == 0) {
                currentRoom = (currentRoom - 1 + MAX_ROOMS) % MAX_ROOMS; // Loop around
            } else if (strcmp(direction, "right") == 0) {
                currentRoom = (currentRoom + 1) % MAX_ROOMS; // Loop around
            }
        } else if (strcmp(command, "take") == 0) {
            if (rooms[currentRoom].itemIndex != -1) {
                printf("You take the %s!\n", items[rooms[currentRoom].itemIndex]);
                player.items[player.itemCount] = rooms[currentRoom].itemIndex;
                player.itemCount++;
                rooms[currentRoom].itemIndex = -1; // Item removed
            } else {
                printf("There's no item to take!\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the haunted house. Your health was %d.\n", player.health);
            break;
        } else {
            printf("Unknown command.\n");
        }

        if (player.health <= 0) {
            printf("You have perished in the haunted house.\n");
        }
    }
    
    // Clean up if necessary (e.g., freeing dynamically allocated memory) 
    // would go here if needed.

    return 0;
}