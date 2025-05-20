//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int roomNumber = 1; // variable to keep track of current room number
    int isGhost = 0; // variable to check if there is a ghost in the room
    int choice; // variable to take user input
    srand(time(NULL)); // seed for random number generator
    
    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You find yourself at the entrance of a spooky, old mansion. Do you dare to enter?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if(choice == 1) {
        printf("\nGreat! Let's start our adventure.\n\n");
        while(roomNumber <= 5) { // total number of rooms is 5
            printf("*******************\n");
            if(isGhost) {
                printf("A ghost appears and scares you out of the room! You backtrack to the previous room.\n");
                isGhost = 0;
                roomNumber--;
            }
            else {
                printf("You are in Room %d\n", roomNumber);
                int randomNumber = rand() % 4; // random number generator to determine if ghost is present
                if(randomNumber == 0) {
                    isGhost = 1;
                    printf("You sense a ghostly presence in the room.\n");
                }
                else {
                    printf("The room is eerily quiet.\n");
                }
                printf("Choose your next move:\n");
                printf("1. Move to the next room\n");
                printf("2. Explore the room\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                if(choice == 1) {
                    printf("\nYou cautiously move to the next room.\n\n");
                    roomNumber++;
                }
                else if(choice == 2) {
                    printf("\nYou explore the room but find nothing of interest.\n\n");
                }
                else {
                    printf("\nInvalid choice. Please try again.\n\n");
                }
            }
        }
        printf("********************\n");
        printf("Congratulations! You have successfully completed your adventure through the haunted house.\n");
        printf("Thanks for playing!\n");
    }
    else if(choice == 2) {
        printf("\nPerhaps it's better to stay safe and avoid this creepy mansion.\n");
        printf("Thanks for considering this adventure!\n");
    }
    else {
        printf("\nInvalid choice. Please choose again.\n");
    }
    return 0;
}