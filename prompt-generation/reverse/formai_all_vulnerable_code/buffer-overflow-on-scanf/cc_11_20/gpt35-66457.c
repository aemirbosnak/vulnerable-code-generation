//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random generator with time
    int randomNumber = rand() % 10; // generate random number between 0 and 9
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are standing in front of a spooky, old house.\n");
    printf("Do you dare enter? (Type 'yes' or 'no')\n");
    
    char input[10];
    scanf("%s", input);
    
    if (strcmp(input, "yes") == 0) {
        printf("You cautiously push the creaky front door open.\n");
        printf("The door slams shut behind you, and you hear it lock.\n");
        printf("You are now trapped in the haunted house!\n");
        
        // spooky occurrences
        if (randomNumber == 0) {
            printf("You hear footsteps coming from upstairs...\n");
        } else if (randomNumber == 1) {
            printf("You feel a cold breeze brush against your face...\n");
        } else if (randomNumber == 2) {
            printf("You see a shadow move out of the corner of your eye...\n");
        } else if (randomNumber == 3) {
            printf("You smell a foul odor permeating from the darkness...\n");
        } else if (randomNumber == 4) {
            printf("You hear eerie whispers, but cannot make out what they are saying...\n");
        } else if (randomNumber == 5) {
            printf("You feel something brush against your leg...\n");
        } else if (randomNumber == 6) {
            printf("You see a pair of glowing eyes staring at you from the darkness...\n");
        } else if (randomNumber == 7) {
            printf("You hear a blood-curdling scream coming from somewhere in the house...\n");
        } else if (randomNumber == 8) {
            printf("You see a ghostly figure floating towards you...\n");
        } else {
            printf("You receive a chill down your spine...\n");
        }
        
        printf("You decide to explore the house...\n");
        printf("You come across a room with a table set for tea. Do you drink the tea? (Type 'yes' or 'no')\n");
        
        scanf("%s", input);
        
        if (strcmp(input, "yes") == 0) {
            printf("You drink the tea and feel a sudden urge to fall asleep...\n");
            printf("You wake up and find yourself outside the house, unharmed.\n");
            printf("You made it out alive!\n");
        } else {
            printf("You decide not to risk it and continue exploring...\n");
            printf("You come across a dusty old chest. Do you open it? (Type 'yes' or 'no')\n");
            
            scanf("%s", input);
            
            if (strcmp(input, "yes") == 0) {
                printf("You open the chest and find treasure inside!\n");
                printf("Congratulations, you survived the Haunted House Simulator!\n");
            } else {
                printf("You decide to leave the chest alone and continue exploring...\n");
                printf("You eventually find an exit and make it out of the house unharmed.\n");
                printf("Congratulations, you survived the Haunted House Simulator!\n");
            }
        }
        
    } else {
        printf("You chicken out and decide not to enter the haunted house.\n");
        printf("Maybe next time...\n");
    }

    return 0;
}