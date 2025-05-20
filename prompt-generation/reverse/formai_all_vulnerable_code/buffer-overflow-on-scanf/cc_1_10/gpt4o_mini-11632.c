//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENCOUNTERS 5

typedef struct Creature {
    char name[30];
    char description[100];
    int isFriendly;
} Creature;

Creature creatures[MAX_ENCOUNTERS];

void initializeCreatures() {
    // Defining some magical creatures
    snprintf(creatures[0].name, sizeof(creatures[0].name), "Woodland Elf");
    snprintf(creatures[0].description, sizeof(creatures[0].description), "A graceful being with an affinity for nature.");
    creatures[0].isFriendly = 1;

    snprintf(creatures[1].name, sizeof(creatures[1].name), "Dark Goblin");
    snprintf(creatures[1].description, sizeof(creatures[1].description), "A sneaky creature, known for its trickery.");
    creatures[1].isFriendly = 0;

    snprintf(creatures[2].name, sizeof(creatures[2].name), "Mystic Unicorn");
    snprintf(creatures[2].description, sizeof(creatures[2].description), "A legendary horse with a horn, symbol of purity.");
    creatures[2].isFriendly = 1;

    snprintf(creatures[3].name, sizeof(creatures[3].name), "Vengeful Spirit");
    snprintf(creatures[3].description, sizeof(creatures[3].description), "A lost soul wandering the forest, seeking revenge.");
    creatures[3].isFriendly = 0;

    snprintf(creatures[4].name, sizeof(creatures[4].name), "Wise Old Oak");
    snprintf(creatures[4].description, sizeof(creatures[4].description), "A towering tree that speaks in riddles.");
    creatures[4].isFriendly = 1;
}

void encounterCreature(int index) {
    printf("\nYou encounter a %s!\n", creatures[index].name);
    printf("%s\n", creatures[index].description);

    if (creatures[index].isFriendly) {
        printf("The creature is friendly! You can ask for advice.\n");
        printf("Do you want to ask for advice? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y') {
            printf("The %s shares some wisdom with you.\n", creatures[index].name);
        } else {
            printf("You politely decline.\n");
        }
    } else {
        printf("The creature is hostile! Do you want to run away? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y') {
            printf("You run away safely!\n");
        } else {
            printf("You confront the %s! Good luck!\n", creatures[index].name);
        }
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    initializeCreatures();

    printf("Welcome to Mystic Forest Adventure!\n");
    printf("You will navigate through the forest and encounter magical creatures.\n");

    for (int i = 0; i < MAX_ENCOUNTERS; i++) {
        int creatureIndex = rand() % MAX_ENCOUNTERS; // Randomly choose a creature
        encounterCreature(creatureIndex);
    }

    printf("\nThank you for playing Mystic Forest Adventure! Have a magical day!\n");
    return 0;
}