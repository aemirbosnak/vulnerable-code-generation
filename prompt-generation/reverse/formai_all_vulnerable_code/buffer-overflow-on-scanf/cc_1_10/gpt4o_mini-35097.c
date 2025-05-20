//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLUES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[256];
    int isFound;
} Clue;

typedef struct {
    char question[256];
    char answer[50];
} Riddle;

void displayWelcomeMessage() {
    printf("Welcome to 'Sherlock Holmes: Space Adventure'\n");
    printf("You are on a mission to investigate a mysterious spaceship crash.\n");
    printf("Gather clues and solve riddles to uncover the truth!\n\n");
}

void displayClues(Clue clues[], int count) {
    printf("\nClues Found:\n");
    for (int i = 0; i < count; i++) {
        if (clues[i].isFound) {
            printf("- %s: %s\n", clues[i].name, clues[i].description);
        }
    }
}

void checkClue(Clue clues[], int count, int index) {
    if (index >= 0 && index < count) {
        if (!clues[index].isFound) {
            clues[index].isFound = 1;
            printf("You found a clue: %s - %s\n", clues[index].name, clues[index].description);
        } else {
            printf("You have already found this clue.\n");
        }
    }
}

int checkRiddle(Riddle riddle) {
    char userAnswer[50];
    printf("%s\nYour answer: ", riddle.question);
    scanf("%s", userAnswer);
    return strcmp(userAnswer, riddle.answer) == 0;
}

void solveRiddles() {
    Riddle riddles[] = {
        {"I speak without a mouth and hear without ears. What am I?", "echo"},
        {"I come from a mine and get stronger the more you use me. What am I?", "diamond"}
    };

    for (int i = 0; i < sizeof(riddles) / sizeof(Riddle); i++) {
        if (checkRiddle(riddles[i])) {
            printf("Correct! You've solved the riddle.\n");
        } else {
            printf("Wrong answer! Try again later.\n");
        }
    }
}

int main() {
    Clue clues[MAX_CLUES] = {
        {"Spacesuit", "A vintage spacesuit with a strange emblem.", 0},
        {"Alien Artifact", "A glowing orb found near the crash site.", 0},
        {"Rusty Key", "An old key with strange markings.", 0},
        {"Star Map", "A map showing distant galaxies.", 0},
        {"Enigmatic Message", "A message written in an unknown language.", 0}
    };

    int cluesFound = 0;
    char choice;

    displayWelcomeMessage();

    while (1) {
        printf("\nYour choices:\n");
        printf("1. Investigate the crash site\n");
        printf("2. Solve a riddle\n");
        printf("3. Examine clues\n");
        printf("4. Exit\n");
        printf("What would you like to do? ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                if (cluesFound < MAX_CLUES) {
                    checkClue(clues, MAX_CLUES, cluesFound);
                    cluesFound++;
                } else {
                    printf("You've already found all clues at the crash site.\n");
                }
                break;
            case '2':
                solveRiddles();
                break;
            case '3':
                displayClues(clues, MAX_CLUES);
                break;
            case '4':
                printf("Thank you for playing!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}