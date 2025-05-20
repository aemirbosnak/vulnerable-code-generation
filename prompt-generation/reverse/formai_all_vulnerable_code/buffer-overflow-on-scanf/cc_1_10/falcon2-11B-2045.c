//Falcon2-11B DATASET v1.0 Category: Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Random number generator
    srand(time(0));
    
    // Player input
    char playerInput;
    int playerScore = 0;
    
    // Game loop
    while (1) {
        // Display score
        printf("Score: %d\n", playerScore);
        
        // Get player input
        printf("Press S for shoot, P for pass, Q to quit:\n");
        scanf(" %c", &playerInput);
        
        // Shoot
        if (playerInput == 'S') {
            // Generate random number
            int randomNumber = rand() % 10 + 1;
            
            // Display surprise
            printf("Oh my! The ball bounced and went straight to the goal!\n");
            
            // Update score
            playerScore += randomNumber;
            
            // Delay
            sleep(1);
        }
        
        // Pass
        else if (playerInput == 'P') {
            // Display surprise
            printf("Oh no! The ball bounced off the wall and went back to our team!\n");
            
            // Delay
            sleep(1);
        }
        
        // Quit
        else if (playerInput == 'Q') {
            printf("Game over!\n");
            break;
        }
    }
    
    // Exit
    return 0;
}