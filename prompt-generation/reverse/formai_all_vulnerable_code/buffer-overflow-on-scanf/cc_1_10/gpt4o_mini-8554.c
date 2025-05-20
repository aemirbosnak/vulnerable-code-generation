//GPT-4o-mini DATASET v1.0 Category: Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 5

typedef struct {
    char name[30];
    int happinessLevel;
} Item;

typedef struct {
    char name[30];
    int happinessLevel;
} Creature;

void displayInstructions() {
    printf("Welcome to the Land of Joy!\n");
    printf("Your mission is to collect magical items and meet cheerful creatures.\n");
    printf("You need to gather %d items to reach the Magical Castle!\n", MAX_ITEMS);
    printf("Use 'explore' to find items, 'creature' to meet a creature, and 'exit' to leave the game.\n");
}

void explore(Item items[], int *itemCount) {
    const char *possibleItems[] = {"Rainbow Gem", "Sparkling Star", "Golden Leaf", "Happy Bell", "Joyful Feather"};
    int i, found = 0;

    if (*itemCount < MAX_ITEMS) {
        srand(time(0));
        i = rand() % 5;
        if (strcmp(items[*itemCount].name, possibleItems[i]) != 0) {
            strcpy(items[*itemCount].name, possibleItems[i]);
            items[*itemCount].happinessLevel = 10 + rand() % 21; // Random happiness level between 10 and 30
            (*itemCount)++;
            printf("You found a %s! It brings you %d points of happiness!\n", items[*itemCount - 1].name, items[*itemCount - 1].happinessLevel);
        } else {
            printf("You explored but found nothing new this time.\n");
        }
    } else {
        printf("You have collected enough items! Head to the Magical Castle!\n");
    }
}

void meetCreature(Creature creatures[], int *creatureCount) {
    const char *possibleCreatures[] = {"Happy Unicorn", "Cheerful Elf", "Joyful Fairy", "Sparkling Mermaid", "Playful Dragon"};
    int i;

    if (*creatureCount < 5) {
        srand(time(0));
        i = rand() % 5;
        strcpy(creatures[*creatureCount].name, possibleCreatures[i]);
        creatures[*creatureCount].happinessLevel = 20 + rand() % 21; // Random happiness level between 20 and 40
        printf("You met a %s! It brings you %d points of happiness!\n", creatures[*creatureCount].name, creatures[*creatureCount].happinessLevel);
        (*creatureCount)++;
    } else {
        printf("You've met all the cheerful creatures! You're so lucky!\n");
    }
}

void reachCastle(Item items[], int itemCount) {
    if (itemCount >= MAX_ITEMS) {
        printf("Congratulations! You have collected enough magical items!\n");
        printf("You reach the Magical Castle and unlock its gates with happiness!\n");
        printf("You and your collected items are now a part of the magical realm of joy forever! ✨\n");
    } else {
        printf("You need to collect %d more items to enter the Magical Castle!\n", MAX_ITEMS - itemCount);
    }
}

int main() {
    char command[20];
    Item items[MAX_ITEMS] = {{"", 0}};
    Creature creatures[5] = {{"", 0}};
    int itemCount = 0, creatureCount = 0;

    displayInstructions();

    while (1) {
        printf("What would you like to do? (explore/creature/castle/exit): ");
        scanf("%s", command);

        if (strcmp(command, "explore") == 0) {
            explore(items, &itemCount);
        } else if (strcmp(command, "creature") == 0) {
            meetCreature(creatures, &creatureCount);
        } else if (strcmp(command, "castle") == 0) {
            reachCastle(items, itemCount);
        } else if (strcmp(command, "exit") == 0) {
            printf("Thank you for visiting the Land of Joy! Until next time! 😊\n");
            break;
        } else {
            printf("Invalid command! Please try again.\n");
        }
    }

    return 0;
}