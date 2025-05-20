//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // Seed for random number
    int doorChoice, ghostChoice; // User input and ghost position respectively
    char playAgain = 'y'; // Play again variable
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself in front of a haunted house with three doors.\n");
    
    // Game loop
    while (playAgain == 'y')
    {
        printf("\nChoose a door (1 - 3): ");
        scanf("%d", &doorChoice);
        getchar(); // Clearing extra newline
        
        // Checking for valid input
        if (doorChoice < 1 || doorChoice > 3)
        {
            printf("Invalid choice. Please choose again.\n");
            continue;
        }
        
        printf("\nYou open door %d...\n", doorChoice);
        
        // Random ghost placement
        ghostChoice = rand() % 3 + 1;
        
        // Displaying ghost location if it's not behind the chosen door
        if (ghostChoice != doorChoice)
        {
            printf("There's a ghost behind door %d!\n", ghostChoice);
        }
        
        // Displaying win/loss
        if (ghostChoice == doorChoice)
        {
            printf("A ghost jumps out and scares you! Game over.\n");
        }
        else
        {
            printf("You escape the haunted house! You win!\n");
        }
        
        // Asking for replay
        printf("Do you want to play again? (y/n): ");
        scanf("%c", &playAgain);
    }
    
    printf("\nThanks for playing the Haunted House Simulator!");
    return 0;
}