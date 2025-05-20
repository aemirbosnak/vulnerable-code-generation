//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // seed the random number generator

    // Welcome message
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself standing in front of a spooky house on a dark and stormy night.\n");
    printf("Do you dare enter?\n");

    // Get user input
    printf("Press 1 to enter the house, or any other key to run away: ");
    char userInput;
    scanf("%c",&userInput);
    printf("\n");

    // User decides to enter the house
    if (userInput == '1') {
        printf("You push open the creaky door and step inside...\n");

        // Randomly choose a spooky event
        int event = rand() % 3;

        // Event 0: A ghost appears
        if (event == 0) {
            printf("Suddenly, a ghost materializes in front of you!\n");
            printf("It floats towards you, moaning eerily.\n");
            printf("What do you do?\n");
            printf("Press 1 to run away, or 2 to try to talk to the ghost: ");

            // Get user input
            char ghostInput;
            scanf(" %c",&ghostInput);

            if (ghostInput == '1') {
                printf("You turn and flee from the ghost, running as fast as you can!\n");
            }
            else if (ghostInput == '2') {
                printf("You tentatively approach the ghost and ask it what it wants.\n");
                printf("To your surprise, the ghost starts to speak!\n");
                printf("It tells you a hidden treasure is hidden somewhere in the house...\n");
            }
            else {
                printf("You stand there frozen, unable to make a decision.\n");
                printf("The ghost floats away, leaving you alone in the haunted house.\n");
            }
        }

        // Event 1: A trap door opens
        else if (event == 1) {
            printf("You hear a loud noise from the floor underneath you...\n");
            printf("A trap door suddenly opens, revealing a dark, scary room.\n");
            printf("What do you do?\n");
            printf("Press 1 to explore the room, or 2 to close the trap door and leave: ");

            // Get user input
            char trapInput;
            scanf(" %c",&trapInput);

            if (trapInput == '1') {
                printf("You climb down into the spooky room, feeling your way around in the dark.\n");
                printf("You stumble upon a mysterious object...\n");
            }
            else if (trapInput == '2') {
                printf("You quickly close the trap door, not wanting to risk exploring the room.\n");
            }
            else {
                printf("You stand there frozen, unable to make a decision.\n");
                printf("The trap door slams shut, leaving you alone in the haunted house.\n");
            }
        }

        // Event 2: A skeleton attacks
        else {
            printf("You hear a rustling sound behind you...\n");
            printf("You turn around to see a skeleton crawling towards you!\n");
            printf("What do you do?\n");
            printf("Press 1 to fight the skeleton, or 2 to run away: ");

            // Get user input
            char skeletonInput;
            scanf(" %c",&skeletonInput);

            if (skeletonInput == '1') {
                printf("You swing your fists at the skeleton, but they go right through its bones!\n");
                printf("The skeleton chases after you, forcing you to flee through the house.\n");
            }
            else if (skeletonInput == '2') {
                printf("You turn and run from the skeleton as fast as you can!\n");
            }
            else {
                printf("You stand there frozen, unable to make a decision.\n");
                printf("The skeleton knocks you over, leaving you at its mercy...\n");
            }
        }

        printf("\nThanks for playing the Haunted House Simulator!\n");
    }

    // User decides not to enter the house
    else {
        printf("You turn and run away from the spooky house, heart racing.\n");
        printf("Thanks for playing the Haunted House Simulator!\n");
    }

    return 0;
}