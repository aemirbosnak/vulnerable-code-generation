//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FORTUNE_COUNT 10

const char *fortunes[FORTUNE_COUNT] = {
    "The path you seek will reveal itself in time.",
    "Beware of those who wear masks, for truth lies beneath.",
    "An unexpected gift will bring you great joy.",
    "Tonight's stars whisper secrets of adventure.",
    "The storm may seem fierce, but calm follows soon.",
    "A forgotten dream will resurrect, take heed.",
    "A friend will become a foe, stay vigilant.",
    "Your inner light will guide you through the shadows.",
    "Change is afoot; embrace it.",
    "A riddle from your past may hold the key to the future."
};

void displayWelcomeMessage() {
    printf("===================================\n");
    printf("       Cryptic Fortune Teller      \n");
    printf("===================================\n");
    printf("Welcome, seeker of truths and mysteries!\n");
    printf("Today, we peer into the obscured realms of fate.\n");
    printf("Answer the queries of the universe to unveil thy future.\n");
    printf("===================================\n");
}

int getRandomFortuneIndex() {
    return rand() % FORTUNE_COUNT;
}

void revealFortune() {
    int index = getRandomFortuneIndex();
    printf("Your fortune:\n");
    printf("\"%s\"\n", fortunes[index]);
}

void promptUser() {
    char choice;

    printf("Do you wish to know your fortune? (y/n): ");
    scanf(" %c", &choice);
    
    if (choice == 'y' || choice == 'Y') {
        revealFortune();
    } else {
        printf("The winds of fate have accepted your silence.\n");
    }
}

void displayGoodbyeMessage() {
    printf("===================================\n");
    printf("        Farewell, seeker!         \n");
    printf("      May your path be illuminated! \n");
    printf("===================================\n");
}

int main() {
    srand(time(NULL));  // Seeds the random number generator

    displayWelcomeMessage();
    promptUser();
    displayGoodbyeMessage();

    return 0;
}