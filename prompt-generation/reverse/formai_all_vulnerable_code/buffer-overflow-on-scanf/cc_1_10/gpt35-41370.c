//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 5

// Function to simulate a haunted room
int hauntedRoom()
{
    int ghost = rand() % 2; // Randomly generate the presence of a ghost (0 or 1)
    if(ghost)
    {
        printf("There's a ghost in this room!\n");
        return 1; // Indicate that the room is haunted
    }
    else
    {
        printf("This room seems safe.\n");
        return 0; // Indicate that the room is not haunted
    }
}

int main()
{
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("--------------------------------------\n\n");
    
    int currentRoom = 1; // Start in room 1
    int playerWon = 0; // Flag to indicate if the player has won
    
    // Loop through each room in the house
    for(int i=0; i<ROOMS; i++)
    {
        printf("You are in room %d.\n", currentRoom);
        int isHaunted = hauntedRoom(); // Check if the room is haunted
        if(isHaunted)
        {
            printf("Sorry, you were scared out of the house! GAME OVER.\n");
            break; // Exit the loop, ending the game
        }
        else
        {
            printf("You have successfully cleared this room.\n");
            if(currentRoom == ROOMS)
            {
                playerWon = 1; // Player has cleared all rooms and won the game
                break; // Exit the loop
            }
            // Ask the player which room to go to next
            printf("Which room would you like to go to next? (Enter a number between %d and %d): ", currentRoom+1, ROOMS);
            int nextRoom;
            scanf("%d", &nextRoom);
            if(nextRoom > ROOMS || nextRoom <= currentRoom)
            {
                printf("Invalid room number. GAME OVER.\n");
                break; // Exit the loop, ending the game
            }
            currentRoom = nextRoom; // Move to the next room
        }
    }
    
    if(playerWon)
        printf("\nCongratulations, you cleared all the rooms and won the game!\n");
    
    printf("\nThank you for playing the Haunted House Simulator. Goodbye!\n");
    
    return 0;
}