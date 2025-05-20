//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_OPTIONS 3
#define BUFFER_SIZE 100

void clearScreen() {
    printf("\033[H\033[J");
}

void displayIntro() {
    clearScreen();
    printf("*************************************\n");
    printf("        Cyberpunk Adventure          \n");
    printf("*************************************\n\n");
    printf("In the neon-lit streets of Neo-Tokyo, \n");
    printf("you are a hacker with a thirst for truth. \n");
    printf("Your journey begins now...\n\n");
}

void showLocation(char *location) {
    printf("You are at: %s\n", location);
}

void makeChoice(char *prompt, char options[][BUFFER_SIZE], int numOptions) {
    int choice = -1;
    while (choice < 1 || choice > numOptions) {
        printf("%s\n", prompt);
        for (int i = 0; i < numOptions; i++) {
            printf("%d: %s\n", i + 1, options[i]);
        }
        printf("Choose an option (1-%d): ", numOptions);
        scanf("%d", &choice);
        getchar(); // Clear newline
    }
    printf("\nYou chose: %s\n\n", options[choice - 1]);
}

void hackingSequence() {
    printf("You hack into a corporate database...\n");
    srand(time(0));
    int success = rand() % 2; // 50% chance to succeed
    if (success) {
        printf("Hacking successful! You obtain sensitive data.\n");
    } else {
        printf("Hacking failed! Security triggered an alarm.\n");
    }
    printf("\n");
}

void alleyEncounter() {
    char *location = "Dark Alley";
    showLocation(location);

    char options[MAX_OPTIONS][BUFFER_SIZE] = {
        "Sneak past the gang members.",
        "Confront the gang.",
        "Try to talk your way out."
    };
    makeChoice("You see a group of gang members blocking your path.", options, MAX_OPTIONS);
}

void corporateBuilding() {
    char *location = "Corporate Building Rooftop";
    showLocation(location);

    char options[MAX_OPTIONS][BUFFER_SIZE] = {
        "Jump to the next building.",
        "Search for hidden tech.",
        "Call a drone for extraction."
    };
    makeChoice("You are at the top of a corporate building.", options, MAX_OPTIONS);
}

void centralMarket() {
    char *location = "Central Market District";
    showLocation(location);

    char options[MAX_OPTIONS][BUFFER_SIZE] = {
        "Buy information.",
        "Make a deal with a vendor.",
        "Scout for potential allies."
    };
    makeChoice("Vibrant stalls and vendors surround you.", options, MAX_OPTIONS);
}

void finalChoice() {
    char *location = "Government Tower";
    showLocation(location);

    char options[MAX_OPTIONS][BUFFER_SIZE] = {
        "Infiltrate the tower.",
        "Stage a protest outside.",
        "Expose the corruption online."
    };
    makeChoice("You have found the center of power.", options, MAX_OPTIONS);
    printf("Your actions will shape the future of Neo-Tokyo.\n");
}

int main() {
    displayIntro();

    alleyEncounter();
    hackingSequence();

    corporateBuilding();
    centralMarket();
    
    finalChoice();

    printf("Thank you for playing! The fate of Neo-Tokyo is now in your hands.\n");
    return 0;
}