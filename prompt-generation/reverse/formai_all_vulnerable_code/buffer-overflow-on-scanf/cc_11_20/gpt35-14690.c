//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //initialize random seed

    //define variables
    int choice, hauntedRoom, lightOn = 1;
    int ghostPresence, numGhosts, i;

    printf("Welcome to the Haunted House Simulator!\n");

    while(1) {
        printf("\nYou are in the living room. What do you want to do?\n");
        printf("1. Check out the kitchen\n");
        printf("2. Go upstairs\n");
        printf("3. Turn off the lights\n");
        printf("4. Exit the house\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                hauntedRoom = rand() % 2; //randomly select a room to haunt
                if(hauntedRoom == 0) {
                    printf("\nYou enter the kitchen and suddenly feel a cold breeze and hear a creaking sound.\n");
                    ghostPresence = rand() % 2; //randomly determine if a ghost is present
                    if(ghostPresence == 1) {
                        printf("You sense a chill and see a ghostly apparition. You run back to the living room in terror!\n");
                    } else {
                        printf("Phew! It was just the wind. You explore the kitchen and find nothing of interest.\n");
                    }
                } else {
                    printf("\nYou enter the kitchen and see a shadowy figure move across the room out of the corner of your eye.\n");
                    printf("You try to approach the figure, but suddenly, all the pots and pans crash to the ground!\n");
                    printf("You run back to the living room in terror!\n");
                }
                break;
            case 2:
                hauntedRoom = rand() % 3 + 2; //randomly select a room to haunt
                if(hauntedRoom == 2) {
                    printf("\nYou climb the stairs to the bedroom and see a flickering light.\n");
                    if(lightOn == 1) {
                        printf("You turn on the light and see a ghostly figure sitting on the bed!\n");
                        printf("You run back to the living room in terror!\n");
                    } else {
                        printf("You approach the bed, but suddenly, the light goes out and you hear ghostly laughter from all around you!\n");
                        ghostPresence = rand() % 2; //randomly determine if more than one ghost is present
                        if(ghostPresence == 1) {
                            numGhosts = rand() % 3 + 1; //randomly determine how many ghosts are present
                            printf("You frantically try to find your way back to the living room as %d ghosts close in on you!\n", numGhosts);
                        } else {
                            printf("You fumble around in the dark for a while before finding your way back to the living room.\n");
                        }
                    }
                } else if(hauntedRoom == 3) {
                    printf("\nYou climb the stairs to the bathroom and suddenly feel a cold breeze.\n");
                    ghostPresence = rand() % 2; //randomly determine if a ghost is present
                    if(ghostPresence == 1) {
                        printf("You feel a chill and see a ghostly apparition in the mirror. You run back to the living room in terror!\n");
                    } else {
                        printf("Phew! It was just your imagination. You explore the bathroom and find nothing of interest.\n");
                    }
                } else {
                    printf("\nYou climb the stairs to the attic and see a single light bulb hanging from the ceiling.\n");
                    printf("You approach the bulb, but suddenly, it flickers and goes out!\n");
                    printf("You hear footsteps and strange whispers all around you!\n");
                    ghostPresence = rand() % 2; //randomly determine if more than one ghost is present
                    if(ghostPresence == 1) {
                        numGhosts = rand() % 3 + 1; //randomly determine how many ghosts are present
                        printf("You frantically try to find your way back to the living room as %d ghosts close in on you!\n", numGhosts);
                    } else {
                        printf("You fumble around in the dark for a while before finding your way back to the living room.\n");
                    }
                }
                break;
            case 3:
                if(lightOn == 1) {
                    printf("\nYou turn off the lights. Suddenly, you hear footsteps and strange whispers all around you!\n");
                    ghostPresence = rand() % 2; //randomly determine if more than one ghost is present
                    if(ghostPresence == 1) {
                        numGhosts = rand() % 3 + 1; //randomly determine how many ghosts are present
                        printf("You frantically try to find your way back to the living room as %d ghosts close in on you!\n", numGhosts);
                    } else {
                        printf("You fumble around in the dark for a while before finding your way back to the living room.\n");
                    }
                } else {
                    printf("\nThe lights are already off.\n");
                }
                lightOn = 0; //turn off the lights
                break;
            case 4:
                printf("\nThank you for visiting the haunted house simulator!\n");
                exit(0); //exit program
            default:
                printf("\nInvalid choice. Please choose again.\n"); //if user inputs wrong choice.
                break;
        }
    }

    return 0;
}