//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PATHS 8
#define MAX_ACTIONS 3

const char *puzzleMessages[] = {
    "You see a strange spiral staircase. Do you want to go up, down, or stay?",
    "A dense fog engulfs you. Choose to step forward, retreat, or scream.",
    "You find a mirror. Do you want to look closely, smash it, or ignore it?",
    "An echoing laugh surrounds you. Do you want to laugh back, run away, or ask for help?",
};

typedef struct Path {
    char *description;
    int nextPaths[MAX_PATHS];
    int numPaths;
} Path;

Path paths[MAX_PATHS];

void initializePaths() {
    paths[0] = (Path){"You have entered the dream realm.", {1, 2, -1}, 2};
    paths[1] = (Path){"You are in a dark forest. The trees whisper your name.", {3, 4, -1}, 2};
    paths[2] = (Path){"You are by a calm lake reflecting a twisted sky.", {5, 6, -1}, 2};
    paths[3] = (Path){"You step into a cabin where shadows dance.", {7, -1, -1}, 1};
    paths[4] = (Path){"You find a unicorn in distress. Do you help it?", {-1, -1, -1}, 0};
    paths[5] = (Path){"A boat appears, but it looks rickety. Get in or stay?", {7, -1, -1}, 1};
    paths[6] = (Path){"The lake sparkles. You see a fish jump and talk. Engage?", {-1, -1, -1}, 0};
    paths[7] = (Path){"You feel strangely free here. You wake up! [Victory]", {-1, -1, -1}, 0};
}

void printMenu(int currentPath) {
    printf("\n--- %s ---\n\n", paths[currentPath].description);
    
    for (int i = 0; i < paths[currentPath].numPaths; i++) {
        if (paths[currentPath].nextPaths[i] != -1) {
            printf("Option %d: Go to Path %d\n", i + 1, paths[currentPath].nextPaths[i]);
        }
    }

    printf("\nWhat will you do? (Enter option number or -1 to exit): ");
}

int main() {
    srand(time(NULL));
    initializePaths();

    int currentPath = 0;
    int choice = 0;

    while (choice != -1) {
        printMenu(currentPath);
        scanf("%d", &choice);
        
        if (choice > 0 && choice <= paths[currentPath].numPaths) {
            currentPath = paths[currentPath].nextPaths[choice - 1];
        } else if (choice == -1) {
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }

        if (currentPath < 0) {
            printf("You have exited the dream realm. Game Over.\n");
            break;
        }

        if (rand() % 5 == 0) {
            int puzzleIndex = rand() % MAX_ACTIONS;
            printf("Puzzle: %s\n", puzzleMessages[puzzleIndex]);
            int action = 0;
            printf("Choose an action (1 to 3): ");
            scanf("%d", &action);
        }
    }

    printf("Thank you for playing this mind-bending experience!\n");
    
    return 0;
}