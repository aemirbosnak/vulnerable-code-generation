//GPT-4o-mini DATASET v1.0 Category: Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH 100
#define MAX_ITEMS 5

typedef struct {
    char name[20];
    int health;
    int key; // 1 if the player has a key, 0 otherwise
    int items[MAX_ITEMS];
    int itemCount;
} Player;

void initializePlayer(Player *player) {
    player->health = MAX_HEALTH;
    player->key = 0;
    player->itemCount = 0;
}

void displayHealth(Player *player) {
    printf("Health: %d\n", player->health);
}

void collectItem(Player *player, int item) {
    if (player->itemCount < MAX_ITEMS) {
        player->items[player->itemCount] = item;
        player->itemCount++;
        printf("You collected an item! You have %d items.\n", player->itemCount);
    } else {
        printf("Your inventory is full!\n");
    }
}

void printRoomDescription(int room) {
    if (room == 1) {
        printf("You are in a dimly lit cave.\n");
        printf("There's a passageway to the left and right.\n");
    } else if (room == 2) {
        printf("You have found a treasure chest!\n");
        printf("You can open it or return to the previous room.\n");
    } else if (room == 3) {
        printf("You are in a dark chamber.\n");
        printf("There is a beast lurking here. You can either fight it or flee.\n");
    }
}

int main() {
    Player player;
    int room = 1;
    int choice;
    srand(time(0)); // Initialize random seed

    initializePlayer(&player);

    while (player.health > 0) {
        displayHealth(&player);
        printRoomDescription(room);
        
        printf("What do you want to do?\n");
        printf("1. Move to the next room\n");
        printf("2. Collect item\n");
        printf("3. Check inventory\n");
        printf("4. Exit game\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (room < 3) {
                    room++;
                    printf("You move to the next room.\n");
                } else {
                    printf("You have reached the last room.\n");
                }
                break;
            case 2:
                if (room == 2) {
                    collectItem(&player, room);
                    player.key = 1; // Get a key when collecting in room 2
                } else {
                    printf("There's nothing to collect here.\n");
                }
                break;
            case 3:
                printf("Your Inventory: ");
                for (int i = 0; i < player.itemCount; i++) {
                    printf("%d ", player.items[i]);
                }
                printf("\n");
                break;
            case 4:
                printf("Exiting the game. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }

        // Random encounter with the beast
        if (room == 3 && rand() % 2 == 0) {
            printf("A beast attacks you!\n");
            player.health -= 20;
            printf("You lose 20 health!\n");
        }
    }

    printf("You have died! Game Over.\n");
    return 0;
}