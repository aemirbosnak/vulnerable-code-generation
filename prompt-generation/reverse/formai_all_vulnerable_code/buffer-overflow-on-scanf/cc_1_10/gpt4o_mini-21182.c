//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_AGENTS 10
#define NUM_LOCATIONS 5
#define NUM_THEORIES 8
#define MAX_LENGTH 100

const char *agents[NUM_AGENTS] = {
    "Dr. Smith",
    "Agent Johnson",
    "Professor X",
    "Mysterious Stranger",
    "The Librarian",
    "Red Hat Guy",
    "Time Traveler",
    "A.I. Entity",
    "Uncle Larry",
    "Conspiracy Nut"
};

const char *locations[NUM_LOCATIONS] = {
    "the secret mountain base",
    "the abandoned warehouse",
    "the subterranean lair",
    "the observatory",
    "Area 51"
};

const char *theories[NUM_THEORIES] = {
    "the moon landing was staged",
    "aliens walked among us in the 70s",
    "the government is controlling the weather",
    "time travel is used to manipulate history",
    "the society of former presidents rules in the shadows",
    "the world is flat, and it's all a cover-up",
    "bigfoot is an experiment gone wrong",
    "the internet is a front for extraterrestrial communication"
};

void generateTheory(char *output) {
    int agentIndex = rand() % NUM_AGENTS;
    int locationIndex = rand() % NUM_LOCATIONS;
    int theoryIndex = rand() % NUM_THEORIES;

    sprintf(output, "According to %s, at %s, %s!", agents[agentIndex], locations[locationIndex], theories[theoryIndex]);
}

void generateMultipleTheories(int count) {
    char theory[MAX_LENGTH];
    for (int i = 0; i < count; i++) {
        generateTheory(theory);
        printf("%s\n\n", theory);
    }
}

void displayMenu() {
    printf("Welcome to the Conspiracy Theory Generator\n");
    printf("Choose how many theories you want to generate:\n");
    printf("1. 1 Theory\n");
    printf("2. 5 Theories\n");
    printf("3. 10 Theories\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
}

int main() {
    srand(time(NULL));
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateMultipleTheories(1);
                break;
            case 2:
                generateMultipleTheories(5);
                break;
            case 3:
                generateMultipleTheories(10);
                break;
            case 4:
                printf("Goodbye! Stay aware!\n");
                return 0;
            default:
                printf("Invalid choice, please select 1-4.\n");
        }
    }

    return 0;
}