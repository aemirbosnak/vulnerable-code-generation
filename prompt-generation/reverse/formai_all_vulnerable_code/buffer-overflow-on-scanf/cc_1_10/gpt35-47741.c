//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Variables
    int choice, darkness, sound;
    char name[20];

    // Introduction
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Before we begin, please enter your name: ");
    scanf("%s", name);
    printf("\nHello %s, let's begin!\n", name);

    // Generate random values for darkness and sound
    srand(time(NULL));
    darkness = rand() % 11;
    sound = rand() % 11;

    // Start simulation
    printf("You enter a dark, creepy house.\n");
    printf("It is %d out of 10 in darkness.\n", darkness);

    // Give player options
    printf("What do you want to do?\n");
    printf("1. Turn on flashlight\n");
    printf("2. Keep walking in the dark\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Player options based on choice
    if(choice == 1) {
        printf("You turn on the flashlight and continue walking.\n");
        printf("It's still pretty dark, but at least you can see where you're going.\n");

        if(sound > 5) {
            printf("You hear a strange noise from the darkness...\n");
            printf("Do you want to investigate?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if(choice == 1) {
                printf("You cautiously walk towards the noise...\n");
                printf("But there's nothing there!\n");
                printf("You decide to turn back and keep walking.\n");
            } else {
                printf("You decide it's best to keep moving and ignore the noise.\n");
            }
        } else {
            printf("The house is eerily quiet...\n");
        }
    } else {
        printf("You try to navigate in the darkness, but you can't see anything.\n");
        printf("Suddenly, you hear a loud noise!\n");
        printf("Do you want to investigate?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("You stumble forward in the darkness, trying to find the source of the noise...\n");
            printf("But you trip and fall down the stairs!\n");
            printf("You get up, dust yourself off, and continue on.\n");
        } else {
            printf("You decide it's best to keep moving and ignore the noise.\n");
        }
    }

    // End simulation
    printf("You keep walking and eventually make it through the entire house.\n");
    printf("Congratulations, %s! You survived the Haunted House Simulator.\n", name);

    return 0;
}