//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main() {
    char userDecision;
    bool keepPlaying = true;
    srand(time(NULL));
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are a brave adventurer who has stumbled upon an abandoned house. Do you dare enter?\n");

    while (keepPlaying) {
        printf("\nEnter 'y' for yes or 'n' for no: ");
        scanf(" %c", &userDecision);
        
        if (userDecision == 'n') {
            keepPlaying = false;
            printf("\nThanks for playing the Haunted House Simulator! Come back soon!\n");
            exit(0);
        } else if (userDecision == 'y') {
            printf("\nYou push open the creaky front door and enter the dimly lit foyer.\n");
            break;
        } else {
            printf("\nInvalid input. Try again.\n");
        }
    }
    
    printf("\nAs you look around, you notice spider webs in every corner and a musty smell in the air.\n");
    printf("Suddenly, you hear a strange noise and a chill runs down your spine.\n");
    printf("Do you want to investigate the noise or leave the house?\n");
    
    while (keepPlaying) {
        printf("\nEnter 'i' to investigate or 'l' to leave: ");
        scanf(" %c", &userDecision);
        
        if (userDecision == 'l') {
            printf("\nYou quickly leave the house, too scared to find out what made the noise.\n");
            keepPlaying = false;
        } else if (userDecision == 'i') {
            printf("\nYou slowly walk towards the source of the noise, heart racing.\n");
            printf("You come across a room with a creaky door, do you open it?\n");
            break;
        } else {
            printf("\nInvalid input. Try again.\n");
        }
    }
    
    int randomNum = rand() % 2;
    printf("\nYou take a deep breath and open the door...\n");
    printf("There is ");
    
    if (randomNum == 0) {
        printf("nothing there. Just an empty room.\n");
    } else {
        printf("a ghost standing in the middle of the room!");
        printf("\n\nYou scream and run out of the house as fast as you can, not stopping until you are far away.\n");
        printf("Congratulations on surviving the Haunted House Simulator!\n");
        keepPlaying = false;
    }
    
    return 0;
}