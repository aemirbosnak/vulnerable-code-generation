//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); //to generate random numbers later
    
    //welcome screen
    printf("Welcome to the Text Adventure Game\n");
    printf("---------------------------------\n\n");
    printf("You find yourself in a dark room with no windows. You can see a door on the opposite side of the room.\n\n");

    //initialize variables for the game
    int choice;
    int hasKey = 0;
    
    //while loop to keep playing the game until the player wins or loses
    while(1) {
        printf("What do you want to do?\n");
        printf("1. Look for a key\n");
        printf("2. Try to open the door\n");
        scanf("%d", &choice);
        
        //check if input is valid
        while(choice < 1 || choice > 2) {
            printf("Invalid input. Please enter 1 or 2.\n");
            scanf("%d", &choice);
        }
        
        if(choice == 1) {
            //generate a random number to simulate searching for a key
            int search = rand() % 3 + 1;
            printf("\nLooking for a key...\n");
            
            if(search == 1) {
                printf("You found a key!\n");
                hasKey = 1;
            }
            else {
                printf("You didn't find anything.\n");
            }
        }
        else if(choice == 2) {
            if(hasKey) {
                printf("\nYou use the key to unlock the door and escape the room!\n");
                break; //exit the game loop since the player won
            }
            else {
                printf("\nThe door is locked and you don't have the key.\n");
            }
        }
    }
    
    printf("\nThanks for playing!\n");

    return 0;
}