//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10
#define MAX_SITUATIONS 10
#define MAX_ADJECTIVES 10
#define MAX_OBJECTS 10

void getRandomFortune(char *fortune, char *situation, char *adjective, char *object) {
    // Array of fortunes
    const char *fortunes[MAX_FORTUNES] = {
        "You will find wisdom in unexpected places.",
        "A new opportunity is on the horizon.",
        "Change is coming, embrace it.",
        "Your efforts will soon pay off.",
        "Expect good news regarding a job.",
        "Love will find you when you least expect it.",
        "A long-awaited trip is imminent.",
        "You will make a new friend.",
        "A revelation will inspire you.",
        "Your past will guide your future."
    };

    // Array of situations
    const char *situations[MAX_SITUATIONS] = {
        "At work",
        "During a family event",
        "While hiking",
        "At a party",
        "In a dream",
        "On a rainy day",
        "While cooking",
        "When you're alone",
        "At a bus stop",
        "On a sunny afternoon"
    };

    // Array of adjectives
    const char *adjectives[MAX_ADJECTIVES] = {
        "brave",
        "mysterious",
        "lively",
        "calm",
        "exciting",
        "peaceful",
        "joyful",
        "thoughtful",
        "dynamic",
        "charming"
    };

    // Array of objects
    const char *objects[MAX_OBJECTS] = {
        "a book",
        "a smartphone",
        "an old photo",
        "a cup of tea",
        "a flower",
        "a piece of art",
        "an ancient tree",
        "a cozy blanket",
        "a star",
        "a river"
    };

    // Initialize random seed
    srand(time(NULL));

    // Pick random elements
    snprintf(fortune, 256, "%s", fortunes[rand() % MAX_FORTUNES]);
    snprintf(situation, 256, "%s", situations[rand() % MAX_SITUATIONS]);
    snprintf(adjective, 256, "%s", adjectives[rand() % MAX_ADJECTIVES]);
    snprintf(object, 256, "%s", objects[rand() % MAX_OBJECTS]);
}

void displayFortune() {
    char fortune[256];
    char situation[256];
    char adjective[256];
    char object[256];

    // Generate a random fortune
    getRandomFortune(fortune, situation, adjective, object);

    // Display the fortune
    printf("Here is your fortune:\n");
    printf("\"%s\".\n", fortune);
    printf("This will occur %s while you are feeling %s towards %s.\n", situation, adjective, object);
}

int main() {
    int numOfFortunes;
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("How many fortunes would you like to receive? (1-5): ");
    scanf("%d", &numOfFortunes);

    if (numOfFortunes < 1 || numOfFortunes > 5) {
        printf("Please enter a number between 1 and 5.\n");
        return 1;
    }

    for (int i = 0; i < numOfFortunes; i++) {
        displayFortune();
        printf("\n");
    }

    printf("Thank you for using the Automated Fortune Teller!\n");
    return 0;
}