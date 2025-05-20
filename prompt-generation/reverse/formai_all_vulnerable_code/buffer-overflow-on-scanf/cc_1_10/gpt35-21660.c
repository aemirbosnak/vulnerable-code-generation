//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    
    // Setting up the seed for random number generator
    srand(time(NULL));
    
    // Initializing and declaring variables
    int choice = 0, room = 1, key = 0, ghostEncounter = 0, doorOpen = 0;
    
    // Introduction of the game
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself standing in front of an abandoned house.\n");
    printf("Would you like to enter?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    // Making a decision based on user input
    if(choice == 1) {
        printf("\nYou enter the house and find yourself in the hallway.\n");
        printf("On your left you see a door and on your right you see a staircase leading upstairs.\n");
        printf("Which way do you want to go?\n");
        printf("1. Left\n");
        printf("2. Right\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Loop for exploring the house until the user finds the key and opens the door
        while(doorOpen == 0) {
            if(room == 1) {
                printf("\nYou enter the room on your left and see a key lying on the table.\n");
                printf("Do you want to pick up the key?\n");
                printf("1. Yes\n");
                printf("2. No\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                
                if(choice == 1) {
                    printf("\nYou pick up the key.\n");
                    key = 1;
                }
                else {
                    printf("\nYou leave the key and go back to the hallway.\n");
                }
                room++;
            }
            else {
                printf("\nYou climb upstairs and find yourself in a dark room.\n");
                printf("Suddenly, you hear strange noises...\n");
                ghostEncounter = rand() % 2; // random number generator giving either 0 or 1
                if(ghostEncounter == 1) {
                    printf("Ah! A ghost is attacking you!\n");
                    printf("You run back downstairs to the hallway, terrified.\n");
                }
                else {
                    printf("You breathe a sigh of relief as you realize there is no danger.\n");
                    printf("In front of you, you see a closed door.\n");
                    if(key == 1) {
                        printf("You use the key to open the door.\n");
                        printf("Congratulations! You have found your way out of the haunted house.\n");
                        doorOpen = 1;
                    }
                    else {
                        printf("The door is locked.\n");
                    }
                }
                room--;
            }
        }
    }
    else {
        printf("\nYou decided to not enter the haunted house.\n");
    }
    
    return 0;
}