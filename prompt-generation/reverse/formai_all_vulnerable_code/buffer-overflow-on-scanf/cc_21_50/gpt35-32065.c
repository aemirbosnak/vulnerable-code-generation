//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: inquisitive
#include <stdio.h>

int main() {
    printf("Welcome to the Inquisitive Adventure Game!\n\n");
    printf("You find yourself in a room with two doors.\n");
    printf("One door is red and the other is green.\n");
    printf("Which door do you choose to go through?\n");
    
    char choice;
    while(1) {  
        printf("\nEnter R for red door or G for green door: ");
        scanf(" %c", &choice);
        if(choice == 'R' || choice == 'r') {
            printf("\nYou open the red door and enter a dark cavern.\n");
            printf("You can hear the sound of dripping water in the distance.\n");
            printf("You see a faint light in the distance, do you follow it? Y/N\n");
            while(1) {
                printf("\nEnter Y to follow the light or N to stay put: ");
                scanf(" %c", &choice);
                if(choice == 'Y' || choice == 'y') {
                    printf("\nYou cautiously make your way towards the light.\n");
                    printf("As you get closer, you can hear the sound of voices.\n");
                    printf("You approach and see a group of people gathered around a campfire.\n");
                    printf("They welcome you and offer you food and shelter for the night.\n");
                    printf("You have now completed your adventure!\n");
                    return 0;
                } 
                else if(choice == 'N' || choice == 'n') {
                    printf("\nYou decide to wait in the darkness.\n");
                    printf("After a few moments, you hear footsteps approaching.\n");
                    printf("You turn and see a group of creatures emerging from the shadows.\n");
                    printf("You have been captured and your adventure comes to an abrupt end.\n");
                    return 0;
                } 
                else {
                    printf("\nPlease enter Y or N.\n");
                }
            }
        }
        else if(choice == 'G' || choice == 'g') {
            printf("\nYou open the green door and find yourself in a lush forest.\n");
            printf("You can hear the sound of a river nearby. Do you follow it? Y/N\n");
            while(1) {
                printf("\nEnter Y to follow the river or N to explore the forest: ");
                scanf(" %c", &choice);
                if(choice == 'Y' || choice == 'y') {
                    printf("\nYou follow the river and come across a beautiful waterfall.\n");
                    printf("You rest for a while and feel reinvigorated.\n");
                    printf("As you continue along the river, you see a glimmering object in the distance.\n");
                    printf("Do you investigate? Y/N\n");
                    while(1) {
                        printf("\nEnter Y to investigate or N to continue on: ");
                        scanf(" %c", &choice);
                        if(choice == 'Y' || choice == 'y') {
                            printf("\nYou follow the glimmering object and find a treasure chest!\n");
                            printf("Inside, you find valuable gems and a map to even more treasure.\n");
                            printf("You have now completed your adventure!\n");
                            return 0;
                        }
                        else if(choice == 'N' || choice == 'n') {
                            printf("\nYou decide to continue along the river.\n");
                            printf("As you walk, you hear a rustling in the bushes.\n");
                            printf("A bear emerges and attacks you.\n");
                            printf("You have been mauled and your adventure comes to an abrupt end.\n");
                            return 0;
                        }
                        else {
                            printf("\nPlease enter Y or N.\n");
                        }
                    }
                }
                else if(choice == 'N' || choice == 'n') {
                    printf("\nYou explore the forest and come across a clearing.\n");
                    printf("In the center of the clearing, you see a strange object.\n");
                    printf("As you approach, you realize it's a spaceship!\n");
                    printf("Do you investigate? Y/N\n");
                    while(1) {
                        printf("\nEnter Y to investigate or N to continue exploring: ");
                        scanf(" %c", &choice);
                        if(choice == 'Y' || choice == 'y') {
                            printf("\nYou investigate the spaceship and find advanced technology.\n");
                            printf("You use this technology to start your own empire and become a great leader.\n");
                            printf("You have now completed your adventure!\n");
                            return 0;
                        }
                        else if(choice == 'N' || choice == 'n') {
                            printf("\nYou decide to continue exploring.\n");
                            printf("As you walk, you come across a group of unfriendly creatures.\n");
                            printf("You try to defend yourself, but they overpower you.\n");
                            printf("Your adventure comes to an abrupt end.\n");
                            return 0;
                        }
                        else {
                            printf("\nPlease enter Y or N.\n");
                        }
                    }
                }
                else {
                    printf("\nPlease enter Y or N.\n");
                }
            }
        }
        else {
            printf("\nPlease enter R or G.\n");
        }
    }
}