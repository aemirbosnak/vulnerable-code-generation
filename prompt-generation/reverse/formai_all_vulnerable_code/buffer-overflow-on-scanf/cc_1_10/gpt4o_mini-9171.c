//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM 10

typedef struct {
    char *description;
    int dangerLevel;
    int itemsInRoom;
} Room;

typedef struct {
    char *name;
    int health;
    int score;
    int inventory[MAX_ROOM];
    int inventoryCount;
} Player;

void initializeRooms(Room rooms[]) {
    rooms[0].description = "A dimly lit hallway with eerie portraits.";
    rooms[0].dangerLevel = 1;
    rooms[0].itemsInRoom = 2;

    rooms[1].description = "A dusty library filled with ancient tomes.";
    rooms[1].dangerLevel = 2;
    rooms[1].itemsInRoom = 1;

    rooms[2].description = "A small kitchen that smells of rot.";
    rooms[2].dangerLevel = 3;
    rooms[2].itemsInRoom = 0;

    rooms[3].description = "An attic cluttered with old furniture.";
    rooms[3].dangerLevel = 2;
    rooms[3].itemsInRoom = 3;

    rooms[4].description = "A spooky cellar echoing with strange noises.";
    rooms[4].dangerLevel = 4;
    rooms[4].itemsInRoom = 1;

    rooms[5].description = "A strange room with hanging chains.";
    rooms[5].dangerLevel = 5;
    rooms[5].itemsInRoom = 0;

    rooms[6].description = "A secret passage that leads to nowhere.";
    rooms[6].dangerLevel = 3;
    rooms[6].itemsInRoom = 2;

    rooms[7].description = "A bedroom with flickering candles.";
    rooms[7].dangerLevel = 1;
    rooms[7].itemsInRoom = 1;

    rooms[8].description = "A haunted bathroom with a broken mirror.";
    rooms[8].dangerLevel = 3;
    rooms[8].itemsInRoom = 0;

    rooms[9].description = "An outdoor graveyard under a full moon.";
    rooms[9].dangerLevel = 6;
    rooms[9].itemsInRoom = 2;
}

void printRoom(Room room) {
    printf("You entered: %s\n", room.description);
    printf("Danger Level: %d\n", room.dangerLevel);
    if (room.itemsInRoom > 0) {
        printf("There are %d items here.\n", room.itemsInRoom);
    } else {
        printf("No items found in this room.\n");
    }
}

void battle(Player *player, Room room) {
    printf("Oh no! You encountered a ghost!\n");
    int damage = room.dangerLevel * (rand() % 3 + 1);
    player->health -= damage;

    printf("The ghost attacks you and deals %d damage!\n", damage);
    printf("Your health is now %d.\n", player->health);

    if (player->health <= 0) {
        printf("You have succumbed to the dangers of the haunted house. Game Over!\n");
        exit(0);
    }
}

void collectItem(Player *player) {
    if (player->inventoryCount < MAX_ROOM) {
        player->inventory[player->inventoryCount++] = 1; // just a placeholder for item
        printf("You collected an item! You now have %d items in your inventory.\n", player->inventoryCount);
    } else {
        printf("Your inventory is full!\n");
    }
}

int main() {
    srand(time(0));

    Room rooms[MAX_ROOM];
    initializeRooms(rooms);

    Player player = {"Ghost Hunter", 100, 0, {0}, 0};

    int currentRoomIndex = 0;
    char command[10];

    printf("Welcome to the Haunted House Simulator!\n");

    while (1) {
        printRoom(rooms[currentRoomIndex]);

        printf("Choose your action (explore, collect, quit): ");
        scanf("%s", command);

        if (strcmp(command, "explore") == 0) {
            if (currentRoomIndex < MAX_ROOM - 1) {
                currentRoomIndex++;
                printf("You move to the next room...\n");
            } else {
                printf("You've explored all the rooms! Time to leave.\n");
            }
        } else if (strcmp(command, "collect") == 0) {
            if (rooms[currentRoomIndex].itemsInRoom > 0) {
                collectItem(&player);
                rooms[currentRoomIndex].itemsInRoom--;
            } else {
                printf("No items available to collect!\n");
            }
        } else if (strcmp(command, "quit") == 0) {
            printf("Thanks for playing! Your score: %d\n", player.score);
            break;
        } else {
            printf("Unknown command. Try again.\n");
        }

        if (rand() % 5 == 0) { // 20% chance of battle
            battle(&player, rooms[currentRoomIndex]);
        }
    }

    return 0;
}