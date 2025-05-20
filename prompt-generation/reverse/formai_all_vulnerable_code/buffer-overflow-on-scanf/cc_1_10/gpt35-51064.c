//FormAI DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>

int main() {
    // Welcome message
    printf("Welcome to my C game example program!\n\n");
    
    // Game loop variables
    int continueGame = 1;
    int score = 0;
    
    // Game loop
    while(continueGame) {
        printf("Your current score is %d\n", score);
        printf("Enter 1 to play, or 0 to quit: ");
        
        // Get user input
        int userInput;
        scanf("%d", &userInput);
        
        if(userInput == 0) {
            // Quit game
            printf("\nThanks for playing! Your final score is %d\n", score);
            continueGame = 0;
        } else if(userInput == 1) {
            // Play game
            int randomNumber = rand() % 10 + 1;
            printf("Guess a number between 1 and 10: ");
            int userGuess;
            scanf("%d", &userGuess);
            
            if(userGuess == randomNumber) {
                // Correct guess
                printf("You guessed correctly! +1 point\n");
                score++;
            } else {
                // Incorrect guess
                printf("Sorry, that was incorrect. The number was %d. No points awarded.\n", randomNumber);
            }
        } else {
            // Invalid input
            printf("Invalid input, please try again.\n");
        }
        
        // Wait for input before continuing
        printf("\nPress Enter to continue...");
        getchar();
    }
    
    return 0;
}