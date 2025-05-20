//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
    // Enable random number generation
    srand(time(NULL));

    // Create some arrays to hold spooky words and phrases
    const char *adjectives[] = {"creepy", "eerie", "haunted", "scary", "spooky", "terrifying"};
    const char *nouns[] = {"house", "manor", "mansion", "castle", "asylum", "sanctum"};
    const char *scaryObjects[] = {"ghost", "skeleton", "zombie", "werewolf", "vampire", "demon"};

    // Create some variables to hold randomly selected words and phrases
    const char *adjective = adjectives[rand() % 6];
    const char *noun = nouns[rand() % 6];
    const char *scaryObject = scaryObjects[rand() % 6];

    // Print out the name of the haunted house
    printf("Welcome to the %s %s!\n", adjective, noun);

    // Ask the user if they want to enter the haunted house
    printf("Do you dare to enter? (yes/no): ");
    char response[10];
    scanf("%s", response);

    // If user enters "yes", continue with the simulation
    if (strcmp(response, "yes") == 0) {
        // Display a scary object
        printf("As you enter the house, you see a %s!\n", scaryObject);

        // Ask the user if they want to approach the scary object
        printf("Do you approach the %s? (yes/no): ", scaryObject);
        scanf("%s", response);

        // If user enters "yes", show a jump scare and end the simulation
        if (strcmp(response, "yes") == 0) {
            printf("\n\nBOO! You are now a ghost trapped in the %s %s forever!\n\n", adjective, noun);
        }
        // If user enters "no", continue with the simulation
        else if (strcmp(response, "no") == 0) {
            // Display creaking floorboards
            printf("As you walk through the house, the floorboards creak beneath your feet.\n");

            // Ask the user if they want to continue through the house
            printf("Do you continue exploring? (yes/no): ");
            scanf("%s", response);

            // If user enters "yes", display a scary sound and end the simulation
            if (strcmp(response, "yes") == 0) {
                printf("You hear a loud scream coming from upstairs!\n");
                printf("You decide to leave the %s %s and never return. Good call!\n", adjective, noun);
            }
            // If user enters "no", end the simulation
            else if (strcmp(response, "no") == 0) {
                printf("You decide to leave the %s %s and never return. Good call!\n", adjective, noun);
            }
            // If user enters anything else, end the simulation
            else {
                printf("Invalid response. Goodbye!\n");
            }
        }
        // If user enters anything else, end the simulation
        else {
            printf("Invalid response. Goodbye!\n");
        }
    }
    // If user enters "no", end the simulation
    else if (strcmp(response, "no") == 0) {
        printf("You decide not to enter the %s %s. Good call!\n", adjective, noun);
    }
    // If user enters anything else, end the simulation
    else {
        printf("Invalid response. Goodbye!\n");
    }

    return 0;
}