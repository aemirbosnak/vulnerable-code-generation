//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 2
#define MAX_ROUNDS 5

typedef struct {
    char name[20];
    int affection;
    int bravery;
    int fate;
} Character;

void initializeCharacters(Character characters[]) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter the name of character %d (Romeo or Paris): ", i + 1);
        scanf("%s", characters[i].name);
        characters[i].affection = rand() % 10 + 1; // Random affection score (1-10)
        characters[i].bravery = rand() % 10 + 1; // Random bravery score (1-10)
        characters[i].fate = 0; // Initialize fate score
    }
}

void displayStatus(Character characters[]) {
    printf("\nCurrent Status:\n");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("%s - Affection: %d, Bravery: %d, Fate Score: %d\n", 
            characters[i].name, characters[i].affection, characters[i].bravery, characters[i].fate);
    }
    printf("\n");
}

void compete(Character *attacker, Character *defender) {
    int action = rand() % 3; // Randomly choose an action: 0-Affect, 1-Challenge, 2-Try to win over

    switch (action) {
        case 0:
            // Affect love
            printf("%s tries to win Juliet's affection from %s!\n", attacker->name, defender->name);
            attacker->affection += 2; // Gain affection
            defender->affection -= 1; // Lose affection
            break;
        case 1:
            // Challenge bravery
            printf("%s challenges %s to a duel of bravery!\n", attacker->name, defender->name);
            if (attacker->bravery > defender->bravery) {
                printf("%s wins the duel!\n", attacker->name);
                attacker->fate += 1; // Gain fate
            } else {
                printf("%s wins the duel!\n", defender->name);
                defender->fate += 1; // Gain fate for defender
            }
            break;
        case 2:
            // Try to win Juliet over
            printf("%s attempts to win Juliet's heart!\n", attacker->name);
            if (attacker->affection > defender->affection) {
                printf("%s wins Juliet's heart!\n", attacker->name);
                attacker->fate += 2; // Gain more fate
            } else {
                printf("%s is still in the shadows!\n", attacker->name);
            }
            break;
        default:
            break;
    }
}

int main() {
    srand(time(0));
    Character characters[NUM_PLAYERS];

    printf("Welcome to the Game of Love: A Romeo and Juliet Adventure!\n");
    
    initializeCharacters(characters);

    for (int round = 1; round <= MAX_ROUNDS; round++) {
        printf("\n--- Round %d ---\n", round);
        displayStatus(characters);
        
        compete(&characters[0], &characters[1]);
        compete(&characters[1], &characters[0]);
    }

    // Final determination of fate
    printf("\n--- Final Results ---\n");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("%s's total fate score: %d\n", characters[i].name, characters[i].fate);
    }

    if (characters[0].fate > characters[1].fate) {
        printf("%s wins the love of Juliet!\n", characters[0].name);
    } else if (characters[1].fate > characters[0].fate) {
        printf("%s wins the love of Juliet!\n", characters[1].name);
    } else {
        printf("Both %s and %s have equal fate! A true tale of unrequited love!\n", 
            characters[0].name, characters[1].name);
    }

    return 0;
}