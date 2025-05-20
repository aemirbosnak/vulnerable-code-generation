//GPT-4o-mini DATASET v1.0 Category: Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_ITEMS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
    int treasures;
} Player;

typedef struct {
    char description[100];
    int difficulty;
    int treasureValue;
} Challenge;

void initializePlayer(Player *player) {
    printf("Enter your name, brave adventurer: ");
    fgets(player->name, MAX_NAME_LENGTH, stdin);
    player->name[strcspn(player->name, "\n")] = 0; // Remove trailing newline
    player->health = 100;
    player->treasures = 0;
}

void displayStatus(const Player *player) {
    printf("\n--- Adventurer Status ---\n");
    printf("Name: %s\n", player->name);
    printf("Health: %d\n", player->health);
    printf("Treasures Collected: %d\n", player->treasures);
    printf("-------------------------\n");
}

void challengeEncounter(Player *player) {
    Challenge challenges[] = {
        {"A fearsome dragon breathes fire!", 15, 30},
        {"A clever riddle from the enchanted sphinx!", 10, 20},
        {"A dark forest with hidden traps!", 12, 25},
        {"A vicious band of goblins!", 20, 50},
        {"A magical puzzle guarding the treasure!", 25, 35}
    };

    srand(time(NULL));
    int randomIndex = rand() % 5;
    Challenge currentChallenge = challenges[randomIndex];

    printf("\nYou have encountered: %s\n", currentChallenge.description);
    printf("Choose your action:\n");
    printf("1. Fight\n");
    printf("2. Solve Riddle\n");
    printf("3. Run Away\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You bravely fight the challenge but suffer some damage!\n");
        player->health -= currentChallenge.difficulty;
        if(player->health <= 0) {
            printf("You have fought valiantly, but succumbed to the challenge. \nYour adventure ends here!\n");
            exit(0);
        } else {
            printf("You defeated the challenge and found %d treasure!\n", currentChallenge.treasureValue);
            player->treasures += currentChallenge.treasureValue;
        }
    } else if (choice == 2) {
        printf("You cleverly solve the riddle!\n");
        printf("But it takes a toll on your health.\n");
        player->health -= currentChallenge.difficulty / 2;
        if(player->health <= 0) {
            printf("Your mind was too taxed, and you fainted!\n");
            printf("Your adventure ends here!\n");
            exit(0);
        } else {
            printf("You gain %d treasure for your wit!\n", currentChallenge.treasureValue);
            player->treasures += currentChallenge.treasureValue;
        }
    } else if (choice == 3) {
        printf("You fled the challenge, but you lose some health in the process!\n");
        player->health -= currentChallenge.difficulty / 4;
        if(player->health <= 0) {
            printf("Fleeing was not enough. You became too weak!\n");
            printf("Your adventure ends here!\n");
            exit(0);
        } else {
            printf("You managed to escape, but your bravery is challenged.\n");
        }
    } else {
        printf("Invalid choice! The challenge overcomes you.\n");
        player->health -= currentChallenge.difficulty;
        if(player->health <= 0) {
            printf("You've lost the battle against your indecision!\n");
            exit(0);
        }
    }
}

int main() {
    Player player;
    initializePlayer(&player);
    
    while (player.health > 0) {
        displayStatus(&player);
        challengeEncounter(&player);
    }
    
    printf("\nYour journey has come to an end, %s. Rest in peace!\n", player.name);
    return 0;
}