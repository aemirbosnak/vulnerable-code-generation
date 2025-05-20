//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_BUFFER 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
    int score;
} Player;

void print_welcome() {
    printf("Welcome to the Mystic Adventure!\n");
    printf("You are about to embark on a thrilling journey filled with challenges and mysteries.\n");
    printf("Your goal is to gather treasures while keeping your health intact!\n");
}

void print_instructions() {
    printf("Instructions:\n");
    printf("1. You will be prompted with choices at each location.\n");
    printf("2. Type your choice (e.g., '1', '2') and press Enter.\n");
    printf("3. Make the best decisions to survive and win the game!\n");
}

void create_player(Player* player) {
    printf("Enter your character name: ");
    fgets(player->name, MAX_NAME_LENGTH, stdin);
    player->name[strcspn(player->name, "\n")] = '\0'; // Remove newline
    player->health = 100;
    player->score = 0;
}

void forest(Player* player) {
    printf("\nYou are in a dark and spooky forest.\n");
    printf("You can hear rustling sounds nearby.\n");
    printf("What do you want to do?\n");
    printf("1. Investigate the sound.\n");
    printf("2. Walk deeper into the forest.\n");
    printf("3. Return to the village.\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You found a hidden treasure chest! +50 points\n");
            player->score += 50;
            break;
        case 2:
            printf("You encountered a wild beast! Lost 20 health.\n");
            player->health -= 20;
            break;
        case 3:
            printf("You return to the village safely.\n");
            break;
        default:
            printf("Invalid choice. Returning to the village.\n");
            break;
    }
}

void village(Player* player) {
    printf("\nYou are in a peaceful village.\n");
    printf("Villagers welcome you.\n");
    printf("What do you want to do?\n");
    printf("1. Speak with the elders for advice.\n");
    printf("2. Go to the market.\n");
    printf("3. Head to the mysterious cave.\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("The elders provide you wisdom. +10 points\n");
            player->score += 10;
            break;
        case 2:
            printf("You bought a healing potion. +30 health.\n");
            player->health += 30;
            break;
        case 3:
            printf("You venture into the cave.\n");
            forest(player); // Move to forest as a part of cave exploration
            break;
        default:
            printf("Invalid choice. Sticking around the village.\n");
            break;
    }
}

void cave(Player* player) {
    printf("\nYou are in the mysterious cave.\n");
    printf("Strange noises echo around you.\n");
    printf("What do you want to do?\n");
    printf("1. Explore deeper.\n");
    printf("2. Look for treasure.\n");
    printf("3. Leave the cave.\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You stumbled upon a hidden creature! Lost 30 health.\n");
            player->health -= 30;
            break;
        case 2:
            printf("You found a rare gem! +100 points\n");
            player->score += 100;
            break;
        case 3:
            printf("You successfully exit the cave.\n");
            break;
        default:
            printf("Invalid choice. You are lost in the cave.\n");
            break;
    }
}

int main() {
    Player player;

    print_welcome();
    print_instructions();
    create_player(&player);

    while (player.health > 0) {
        printf("\nCurrent Health: %d | Score: %d\n", player.health, player.score);
        printf("Where would you like to go?\n");
        printf("1. Village\n");
        printf("2. Forest\n");
        printf("3. Cave\n");
        printf("4. Exit Game\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                village(&player);
                break;
            case 2:
                forest(&player);
                break;
            case 3:
                cave(&player);
                break;
            case 4:
                printf("Thanks for playing! Your final score is %d.\n", player.score);
                return 0;
            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }

        if (player.health <= 0) {
            printf("You have perished in your journey. Game Over!\n");
            return 0;
        }
    }

    return 0;
}