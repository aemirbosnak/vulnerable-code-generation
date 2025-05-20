//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENCOUNTERS 5

typedef struct {
    char name[30];
    int health;
    int attack;
} Alien;

typedef struct {
    char name[30];
    int health;
    int resources;
} Player;

void initializePlayer(Player *player) {
    printf("Enter your spaceship name: ");
    scanf("%s", player->name);
    player->health = 100;
    player->resources = 50;
}

void encounterAlien(Player *player, Alien *alien) {
    printf("You have encountered an alien ship named %s!\n", alien->name);
    printf("Alien health: %d\n", alien->health);
    printf("Your health: %d\n", player->health);
    
    while (player->health > 0 && alien->health > 0) {
        // Player attacks
        printf("Attacking alien...\n");
        alien->health -= (rand() % 20) + 10;

        if (alien->health > 0) {
            // Alien attacks
            printf("Alien is attacking...\n");
            player->health -= alien->attack;
            printf("You were hit! Your health is now %d.\n", player->health);
        }
    }

    if (player->health <= 0) {
        printf("You have been defeated by the alien!\n");
    } else {
        printf("You defeated the alien!\n");
        int loot = (rand() % 30) + 10;
        player->resources += loot;
        printf("You collected %d resources! Total resources: %d\n", loot, player->resources);
    }
}

void displayStatus(Player *player) {
    printf("\n--- Player Status ---\n");
    printf("Name: %s\n", player->name);
    printf("Health: %d\n", player->health);
    printf("Resources: %d\n", player->resources);
    printf("---------------------\n");
}

int main() {
    srand(time(NULL));

    Player player;
    initializePlayer(&player);

    Alien aliens[MAX_ENCOUNTERS] = {
        {"Zorg", 100, 15},
        {"Kron", 80, 20},
        {"Yarno", 90, 25},
        {"Blip", 70, 10},
        {"Snork", 110, 18}
    };

    for (int i = 0; i < MAX_ENCOUNTERS; i++) {
        char choice;
        displayStatus(&player);
        
        printf("Do you want to encounter alien %d (Yes: y, No: n)? ", i + 1);
        scanf(" %c", &choice);

        if (choice == 'y') {
            encounterAlien(&player, &aliens[i]);
        } else {
            printf("You chose to avoid the alien.\n");
        }

        if (player.health <= 0) {
            break; // End the game if the player is defeated
        }
    }

    if (player.health > 0) {
        printf("Congratulations %s! You survived the adventures with %d resources left.\n", player.name, player.resources);
    } else {
        printf("Game Over. Better luck next time!\n");
    }

    return 0;
}