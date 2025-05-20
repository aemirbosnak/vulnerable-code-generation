//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Function to display intro message
void introMessage() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are exploring a haunted house and your goal is to find your way out alive.\n");
    printf("Be careful, as there are many dangers lurking in the shadows.\n");
}

// Function to display randomized spooky messages
void spookyMessage() {
    char messages[5][50] = {
        "You hear a faint whisper in the distance.",
        "The walls creak as you make your way through the house.",
        "A chill runs down your spine.",
        "You get the feeling that something is watching you.",
        "You stumble upon a room filled with cobwebs and dust."
    };
    int randomIndex = rand() % 5;
    printf("%s\n", messages[randomIndex]);
}

// Function to simulate a monster attack
void monsterAttack() {
    printf("Suddenly, a monster appears out of nowhere!\n");
    printf("You try to run, but the monster catches up to you.\n");
    printf("You fight with all your might, but it's no use.\n");
    printf("You have been killed by the monster...\n");
    exit(0);
}

// Function to simulate finding the exit
void foundExit() {
    printf("Congratulations, you have found the exit!\n");
    printf("You escape from the haunted house just in time.\n");
    exit(0);
}

int main() {
    introMessage(); // Display intro message
    bool hasKey = false; // Initialize key status to false
    srand(time(0)); // Seed random number generator

    // Loop until player finds the exit or is killed
    while(true) {
        spookyMessage(); // Display spooky message
        printf("Choose an action:\n");
        printf("1. Open a door\n");
        printf("2. Search for a key\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You open a door and walk through it.\n");

                // 50% chance of encountering a monster or finding the exit
                if(rand() % 2 == 0) {
                    foundExit();
                } else {
                    monsterAttack();
                }
                break;

            case 2:
                printf("You search for a key...\n");

                // 30% chance of finding a key
                if(rand() % 10 < 3) {
                    printf("You found a key!\n");
                    hasKey = true;
                } else {
                    printf("You search the room but find nothing.\n");
                }
                break;

            case 3:
                printf("Thanks for playing!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        // If player has the key, give option to use it
        if(hasKey) {
            printf("You have a key. Do you want to use it?\n");
            printf("1. Yes\n");
            printf("2. No\n");

            int keyChoice;
            scanf("%d", &keyChoice);

            if(keyChoice == 1) {
                foundExit();
            }
        }
    }

    return 0;
}