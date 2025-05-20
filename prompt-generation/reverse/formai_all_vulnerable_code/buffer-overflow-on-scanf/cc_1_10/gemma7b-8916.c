//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ANSWERS 5

typedef struct Spell {
    char name[20];
    int cost;
    int success_rate;
} Spell;

Spell spells[] = {
    {"Fireball", 10, 80},
    {"Lightning Bolt", 15, 75},
    {"Ice Beam", 12, 85},
    {"Hex", 18, 60},
    {"Summon Demon", 20, 55}
};

int main() {
    srand(time(NULL));
    int user_choice, spell_index;
    char answer[MAX_ANSWERS];

    // Welcome the user to the fortune teller's lair
    printf("Welcome to the Mystical Oracle of the West! Prepare for a journey into the realm of destiny...");

    // Get the user's choice of spell
    printf("Choose a spell from the following list:");
    for (int i = 0; i < MAX_ANSWERS; i++) {
        printf("%d. %s (Cost: %d, Success Rate: %d%%)\n", i + 1, spells[i].name, spells[i].cost, spells[i].success_rate);
    }
    scanf("%d", &user_choice);

    // Validate the user's choice
    if (user_choice < 1 || user_choice > MAX_ANSWERS) {
        printf("Invalid choice. Please try again.\n");
        return 1;
    }

    // Determine the spell index
    spell_index = user_choice - 1;

    // Cast the spell
    int success = rand() % spells[spell_index].success_rate;

    // Get the answer
    if (success) {
        sprintf(answer, "Your spell was successful! You have brought misfortune upon your enemies.");
    } else {
        sprintf(answer, "Your spell failed. You have angered the gods.");
    }

    // Print the answer
    printf("%s\n", answer);

    return 0;
}