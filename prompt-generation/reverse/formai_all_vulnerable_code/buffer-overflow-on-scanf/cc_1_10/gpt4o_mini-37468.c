//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ORGANIZATION_COUNT 10
#define EVENT_COUNT 10
#define ACTION_COUNT 10

// Define arrays for organizations, events, and actions
const char *organizations[ORGANIZATION_COUNT] = {
    "The Illuminati",
    "The Freemasons",
    "Big Pharma",
    "NASA",
    "The CIA",
    "Area 51 Researchers",
    "The Rothschild Family",
    "The Lizard People",
    "The New World Order",
    "The Environmentalists"
};

const char *events[EVENT_COUNT] = {
    "the moon landing",
    "the 9/11 attacks",
    "the COVID-19 pandemic",
    "global warming",
    "the assassination of JFK",
    "the sinking of the Titanic",
    "the rise of social media",
    "the Area 51 raid",
    "the 2020 Presidential election",
    "the disappearance of MH370"
};

const char *actions[ACTION_COUNT] = {
    "created a diversion",
    "stole technology",
    "controlled the narrative",
    "manipulated the stock market",
    "faked the evidence",
    "altered the weather",
    "infiltrated key positions",
    "ruined lives through disinformation",
    "built underground bunkers",
    "experimented with mind control"
};

// Function to generate a random conspiracy theory
void generateConspiracyTheory() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate random indices for each category
    int orgIndex = rand() % ORGANIZATION_COUNT;
    int eventIndex = rand() % EVENT_COUNT;
    int actionIndex = rand() % ACTION_COUNT;

    // Create the conspiracy theory
    printf("Conspiracy Theory:\n");
    printf("It is believed that %s was behind %s, as they %s to achieve their hidden agenda.\n",
           organizations[orgIndex],
           events[eventIndex],
           actions[actionIndex]);
}

int main() {
    int choice;

    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Press 1 to generate a conspiracy theory (or 0 to exit):\n");

    while(1) {
        printf("Your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            generateConspiracyTheory();
            printf("\nPress 1 to generate another theory (or 0 to exit):\n");
        } else if (choice == 0) {
            printf("Exiting the program. Stay curious!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}