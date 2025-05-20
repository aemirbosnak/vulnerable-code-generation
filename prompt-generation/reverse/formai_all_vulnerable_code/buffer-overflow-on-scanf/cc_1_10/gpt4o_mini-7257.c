//GPT-4o-mini DATASET v1.0 Category: Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_ITEMS 3

void welcomePlayer();
void showMenu();
void adventure();
void exploreForest();
void exploreCave();
void findTreasure();
void giveItem(char *item);

int main() {
    welcomePlayer();
    adventure();
    return 0;
}

void welcomePlayer() {
    char playerName[MAX_NAME_LENGTH];
    printf("=======================================\n");
    printf("Welcome to the Mystery of the Lost Treasure!\n");
    printf("=======================================\n");
    printf("Enter your brave explorer name: ");
    fgets(playerName, MAX_NAME_LENGTH, stdin);
    playerName[strcspn(playerName, "\n")] = 0; // Remove trailing newline
    printf("Ahoy, %s! Prepare for an exhilarating adventure!\n", playerName);
}

void showMenu() {
    printf("\nWhat will you do next?\n");
    printf("1. Search the Enchanted Forest\n");
    printf("2. Venture into the Mysterious Cave\n");
    printf("3. Rest and Regroup\n");
    printf("4. Exit Game\n");
    printf("Choose an option (1-4): ");
}

void adventure() {
    int choice;
    srand(time(0)); // Seed random number generator
    while (1) {
        showMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                exploreForest();
                break;
            case 2:
                exploreCave();
                break;
            case 3:
                printf("You take a moment to rest. Good luck on your next journey!\n");
                break;
            case 4:
                printf("Thanks for playing! Until next time, brave explorer!\n");
                exit(0);
            default:
                printf("Oops! That's not a valid choice. Try again!\n");
        }
    }
}

void exploreForest() {
    printf("\nYou step into the Enchanted Forest filled with vibrant colors and whispers of magic.\n");
    int treasureFound = rand() % 2; // Randomly determines if the player finds treasure
    if (treasureFound) {
        findTreasure();
    } else {
        printf("You wander around but find nothing but enchanting sounds.\n");
    }
}

void exploreCave() {
    printf("\nYou cautiously enter the Mysterious Cave. The sound of dripping water echoes.\n");
    int monsterEncountered = rand() % 2; // Randomly determines if a monster appears
    if (monsterEncountered) {
        printf("Oh no! A wild monster appears! You must defend yourself!\n");
        char action[10];
        printf("Type 'fight' or 'flee': ");
        scanf("%s", action);
        if (strcmp(action, "fight") == 0) {
            printf("Your bravery prevails! You defeat the monster!\n");
            giveItem("Monster's Fang");
        } else {
            printf("You wisely retreat, avoiding a nasty encounter!\n");
        }
    } else {
        printf("The cave is dark, but you find an old treasure chest!\n");
        findTreasure();
    }
}

void findTreasure() {
    printf("Congratulations! You've found the treasure!\n");
    char *treasures[] = { "Golden coin", "Ancient relic", "Magic wand" };
    int idx = rand() % 3; // Picks a random treasure
    printf("You uncovered: %s! What a fantastic find!\n", treasures[idx]);
}

void giveItem(char *item) {
    printf("You have received: %s! This will surely aid you on your adventure!\n", item);
}