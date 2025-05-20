#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_HEALTH 100

typedef struct {
    int health;
    int hasFlashlight;
} Player;

void printInventory(Player *player) {
    printf("Health: %d\n", player->health);
    if (player->hasFlashlight) {
        printf("Inventory: Flashlight\n");
    } else {
        printf("Inventory: Empty\n");
    }
}

int main() {
    Player player = {MAX_HEALTH, 0};
    int choice;

    printf("Welcome to the Haunted House Adventure!\n");

    while (player.health > 0) {
        printInventory(&player);

        printf("\nYou find yourself at a fork in the path.\n");
        printf("1. Go left into the dark room.\n");
        printf("2. Go right through the old door.\n");
        printf("3. Check your inventory.\n");
        printf("4. Exit the game.\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (!player.hasFlashlight) {
                    printf("The room is pitch black! You feel something cold and sharp...\n");
                    player.health -= 20;
                } else {
                    printf("You use your flashlight to explore the room.\n");
                    printf("You find a mysterious artifact that increases your health by 10!\n");
                    player.health += 10;
                }
                break;
            case 2:
                printf("You open the old door and step inside.\n");
                printf("A ghost appears! It whispers, 'Take this!' and gives you a flashlight.\n");
                player.hasFlashlight = 1;
                break;
            case 3:
                printInventory(&player);
                break;
            case 4:
                printf("Thanks for playing! Goodbye.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        if (player.health <= 0) {
            printf("You have been defeated by the darkness. Game over.\n");
        }
    }

    return 0;
}
