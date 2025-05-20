//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ITEMS 10
#define MAX_TRAPS 3
#define MAX_ROOMS 5
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int value;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Inventory;

typedef struct {
    int roomNumber;
    bool hasTreasure;
    bool hasTrap;
    Item treasure;
} Room;

typedef struct {
    int level;
    Inventory inventory;
    int score;
    int health;
} Player;

Room rooms[MAX_ROOMS];

void initRooms() {
    srand(time(NULL));
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].hasTreasure = (rand() % 2 == 0) ? true : false;
        rooms[i].hasTrap = (rand() % 2 == 0) ? true : false;

        if (rooms[i].hasTreasure) {
            snprintf(rooms[i].treasure.name, MAX_NAME_LENGTH, "Treasure_%d", i + 1);
            rooms[i].treasure.value = (rand() % 100) + 1;
        }
    }
}

void printWelcome() {
    printf("Welcome to the Cave Adventure Game!\n");
    printf("Try to collect treasures while avoiding traps.\n");
}

void printInstructions() {
    printf("Instructions:\n");
    printf("1. Navigate through the rooms by entering room numbers (1-%d).\n", MAX_ROOMS);
    printf("2. Collect treasures and keep an eye out for traps.\n");
    printf("3. Your objective is to collect the most value in treasures while maintaining your health.\n");
}

void printStatus(Player player) {
    printf("\n--- Player Status ---\n");
    printf("Level: %d\n", player.level);
    printf("Score: %d\n", player.score);
    printf("Health: %d\n", player.health);
    printf("Items Collected: %d\n", player.inventory.itemCount);
    for (int i = 0; i < player.inventory.itemCount; i++) {
        printf(" - %s (Value: %d)\n", player.inventory.items[i].name, player.inventory.items[i].value);
    }
    printf("-----------------------\n");
}

void navigateRoom(Player *player, int roomNumber) {
    Room room = rooms[roomNumber - 1];
    
    printf("\nYou entered room %d.\n", room.roomNumber);
    
    if (room.hasTreasure) {
        printf("Congrats! You found %s worth %d points!\n", room.treasure.name, room.treasure.value);
        player->inventory.items[player->inventory.itemCount++] = room.treasure;
        player->score += room.treasure.value;
    }

    if (room.hasTrap) {
        printf("Oh no! You fell into a trap!\n");
        player->health -= 10;
        if (player->health <= 0) {
            printf("You have lost all your health. Game Over!\n");
            exit(0);
        }
    }
}

int main() {
    Player player = {1, {{}, 0}, 0, 100};
    int choice;

    printWelcome();
    printInstructions();
    initRooms();
    
    while (true) {
        printStatus(player);
        printf("Enter room number (1-%d) to navigate or 0 to exit: ", MAX_ROOMS);
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("Thank you for playing! Your final score is %d.\n", player.score);
            break;
        } else if (choice < 1 || choice > MAX_ROOMS) {
            printf("Invalid room number. Please try again.\n");
            continue;
        }

        navigateRoom(&player, choice);
    }

    return 0;
}