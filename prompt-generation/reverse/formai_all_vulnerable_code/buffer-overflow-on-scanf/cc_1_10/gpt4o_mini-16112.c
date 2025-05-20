//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100

typedef struct {
    char name[50];
    int health;
    int strength;
} Player;

typedef struct {
    char description[200];
    char choice1[50];
    char choice2[50];
} Scene;

void initializePlayer(Player *player);
void displayScene(Scene scene);
int processChoice(Player *player, Scene scene, int choice);
void encounterCreature(Player *player);
void victory();
void defeat();

int main() {
    Player player;
    Scene scenes[3];
    int currentScene = 0;

    srand(time(NULL));
    initializePlayer(&player);

    // Define scenes
    strcpy(scenes[0].description, "You find yourself in a dark, damp forest. Shadows loom around you.");
    strcpy(scenes[0].choice1, "Investigate the eerie noise");
    strcpy(scenes[0].choice2, "Walk away cautiously");

    strcpy(scenes[1].description, "You've encountered a wild creature! It growls menacingly.");
    strcpy(scenes[1].choice1, "Attack the creature");
    strcpy(scenes[1].choice2, "Try to escape");

    strcpy(scenes[2].description, "You stumble upon a treasure chest. It glimmers in the dim light.");
    strcpy(scenes[2].choice1, "Open the chest");
    strcpy(scenes[2].choice2, "Leave it alone");

    while (1) {
        displayScene(scenes[currentScene]);
        printf("Choose an option (1 or 2): ");
        
        int choice;
        scanf("%d", &choice);
        if (!processChoice(&player, scenes[currentScene], choice)) {
            break; // Game ends if user dies or quits
        }

        if (currentScene < 2) {
            currentScene++;
        } else {
            printf("Congratulations! You have explored the entire forest!\n");
            break; // End of game
        }
    }

    return 0;
}

void initializePlayer(Player *player) {
    printf("Enter your name, brave adventurer: ");
    scanf("%s", player->name);
    player->health = 100;
    player->strength = 10;
    printf("Welcome, %s! Your journey begins with %d health and %d strength.\n", player->name, player->health, player->strength);
}

void displayScene(Scene scene) {
    printf("\n%s\n", scene.description);
    printf("1. %s\n", scene.choice1);
    printf("2. %s\n", scene.choice2);
}

int processChoice(Player *player, Scene scene, int choice) {
    if (choice == 1) {
        switch (strcmp(scene.description, "You've encountered a wild creature! It growls menacingly.")) {
            case 0:
                encounterCreature(player);
                break;
            case -1:
                printf("You bravely investigate and discover nothing but silence.\n");
                break;
            case 1:
            default:
                printf("You open the chest and find a mystical item that heals you!\n");
                player->health += 20;
                printf("%s now has %d health!\n", player->name, player->health);
                break;
        }
    } else if (choice == 2) {
        if (strcmp(scene.description, "You've encountered a wild creature! It growls menacingly.") == 0) {
            printf("You attempt to flee, but the creature blocks your path.\n");
            encounterCreature(player);
        } else {
            printf("You decide to walk away and live another day.\n");
        }
    } else {
        printf("Invalid choice. Please select 1 or 2.\n");
        return 1; // Continue game
    }
    
    if (player->health <= 0) {
        defeat();
        return 0; // End game
    }
    
    return 1; // Continue game
}

void encounterCreature(Player *player) {
    printf("The creature lunges at you! Prepare to fight!\n");
    
    while (player->health > 0) {
        int creatureHealth = rand() % 30 + 10; // Random creature health

        while (creatureHealth > 0 && player->health > 0) {
            printf("You attack the creature for %d damage!\n", player->strength);
            creatureHealth -= player->strength;
            if (creatureHealth > 0) {
                int damage = rand() % 8 + 3; // Random damage from creature
                player->health -= damage;
                printf("The creature retaliates, dealing %d damage! Your health is now %d.\n", damage, player->health);
            }
        }
        
        if (creatureHealth <= 0) {
            victory();
            return; // Player wins
        }
    }
}

void victory() {
    printf("You have defeated the creature! You can continue your adventure!\n");
}

void defeat() {
    printf("You've fallen in battle. Rest well, brave adventurer...\n");
}