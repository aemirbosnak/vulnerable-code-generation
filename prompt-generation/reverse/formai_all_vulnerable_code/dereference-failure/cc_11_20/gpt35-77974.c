//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define starting location
int current_location = 0;

// Define maximum number of locations
#define MAX_LOCATIONS 5

// Define array of location names
char *locations[MAX_LOCATIONS] = {
    "The Village",
    "The Forest",
    "The Mountains",
    "The Beach",
    "The City"
};

// Define array of location descriptions
char *descriptions[MAX_LOCATIONS] = {
    "You are in the center of a small village. There are houses and shops all around you.",
    "You are deep in the forest. It is dark and the trees are thick.",
    "You are at the base of a massive mountain. The air is thin and the rocks are steep.",
    "You are walking along the beach. The waves are crashing and the sand is hot.",
    "You are in the heart of the city. There are skyscrapers and crowds of people everywhere."
};

// Define array of possible actions
char *actions[3] = {
    "look",
    "go",
    "quit"
};

// Define array of possible directions
char *directions[4] = {
    "north",
    "east",
    "south",
    "west"
};

int main()
{
    char input[50];
    char *token;
    char *delim = " ";
    int i, j;

    // Print starting location
    printf("%s\n\n", descriptions[current_location]);

    // Begin game loop
    while (1) {
        printf("What do you want to do? ");

        // Get user input
        fgets(input, sizeof(input), stdin);

        // Remove newline character from input
        strtok(input, "\n");

        // Tokenize input string
        token = strtok(input, delim);

        // Check if user wants to quit
        if (strcmp(token, "quit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        }

        // Check if user wants to look
        if (strcmp(token, "look") == 0) {
            printf("%s\n\n", descriptions[current_location]);
            continue;
        }

        // Check if user wants to go
        if (strcmp(token, "go") == 0) {
            token = strtok(NULL, delim);

            // Find direction in input
            for (i = 0; i < 4; i++) {
                if (strcmp(token, directions[i]) == 0) {
                    // Check if there is a location in that direction
                    for (j = 0; j < MAX_LOCATIONS; j++) {
                        if (i == j)
                            continue;
                        if (strcmp(locations[j], "") != 0 && (i == current_location-1 || i == current_location+1)) {
                            current_location = j;
                            printf("%s\n\n", descriptions[current_location]);
                            break;
                        }
                    }

                    // If no location in that direction, print error message
                    if (j == MAX_LOCATIONS) {
                        printf("You cannot go in that direction.\n\n");
                    }

                    break;
                }
            }

            // If direction not found in input, print error message
            if (i == 4) {
                printf("I don't know where that is.\n\n");
            }

            continue;
        }

        // If action not recognized, print error message
        printf("I don't know what you mean.\n\n");
    }

    return 0;
}