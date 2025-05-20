//FormAI DATASET v1.0 Category: Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    // Welcome message
    printf("=============================\n");
    printf("|   Welcome to GuessGame!   |\n");
    printf("=============================\n\n");
    
    // Initialize random seed
    srand(time(NULL));
    
    // Set the range of numbers to guess from
    int min_num = 1;
    int max_num = 100;
    
    // Generate random number to guess
    int num_to_guess = (rand() % (max_num - min_num + 1)) + min_num;
    
    // Initialize variables
    int num_of_guesses = 0;
    int user_guess = 0;
    char play_again = 'y';
    
    // Loop until user decides to quit
    while (play_again == 'y') {
        
        // Reset the number of guesses
        num_of_guesses = 0;
        
        // Display instructions
        printf("\nI'm thinking of a number between %d and %d, can you guess it?\n\n", min_num, max_num);
        
        // Loop until user guesses the correct number
        while (user_guess != num_to_guess) {
            // Get user's guess
            printf("Enter your guess: ");
            scanf("%d", &user_guess);
            
            // Increment number of guesses
            num_of_guesses++;
            
            // Check if guess is too high or too low and provide feedback
            if (user_guess < num_to_guess) {
                printf("Too low, try again!\n");
            } else if (user_guess > num_to_guess) {
                printf("Too high, try again!\n");
            } else {
                printf("\nCongratulations, you guessed the number in %d tries!\n", num_of_guesses);
            }
        }
        
        // Ask user if they want to play again
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &play_again);
        
        // Generate new random number to guess
        num_to_guess = (rand() % (max_num - min_num + 1)) + min_num;
    }
    
    // Exit message
    printf("\nThank you for playing GuessGame!\n");
    return 0;
}