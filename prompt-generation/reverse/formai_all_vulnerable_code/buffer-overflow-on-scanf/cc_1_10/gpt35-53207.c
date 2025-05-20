//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_PLAYERS 5
#define MAX_FORTUNES 5

char fortunes[MAX_FORTUNES][100] = {
    "You will find love soon.",
    "You will have good fortune in your future finances.",
    "You will have a long and healthy life.",
    "You will be successful in all your goals.",
    "You will travel to exotic places in the near future."
};

int main() {
    int numPlayers;

    // Get number of players
    printf("Welcome to the Automated Fortune Teller! How many players are there? (1-%d)\n", MAX_PLAYERS);
    scanf("%d", &numPlayers);

    // Limit number of players
    if(numPlayers > MAX_PLAYERS) {
        printf("Sorry, the maximum number of players allowed is %d. Exiting program...", MAX_PLAYERS);
        return 0;
    }

    // Seed random number generator
    srand(time(NULL));

    // Start fortune telling game for each player
    int i;
    for(i = 0; i < numPlayers; i++) {
        printf("\nPlayer %d, please enter your name: ", i+1);
        char playerName[20];
        scanf("%s", playerName);

        printf("Welcome, %s! Let's see what your fortune is...\n", playerName);

        // Generate random fortune index
        int fortuneIndex = rand() % MAX_FORTUNES;

        // Print fortune
        printf("Your fortune is: %s\n", fortunes[fortuneIndex]);
    }

    printf("\nThanks for playing the Automated Fortune Teller!");

    return 0;
}