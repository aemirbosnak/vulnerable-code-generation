//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to clear the screen
void clear() {
    system("clear");
}

int main() {
    srand(time(NULL)); // Set random seed based on time
    
    int score = 0; // Keep track of score
    int game_over = 0; // Flag for end of game
    
    while (!game_over) {
        clear(); // Clear the screen
        
        // Print game title and instructions
        printf("=== WELCOME TO THE NUMBER GAME ===\n\n");
        printf("INSTRUCTIONS:\n");
        printf("1. You have 10 lives and your goal is to guess a random number (between 1 and 100)\n");
        printf("2. After each guess, you will be told if your guess is too high or too low\n");
        printf("3. Your score is calculated by the number of lives you have left\n\n");
        
        int lives = 10; // Set initial number of lives
        int num = rand() % 100 + 1; // Generate random number between 1 and 100
        
        while (lives > 0) {
            printf("Guess a number between 1 and 100: ");
            
            int guess;
            scanf("%d", &guess);
            
            if (guess == num) {
                printf("Congrats! You guessed the number.\n");
                printf("Your score is %d.\n", lives);
                score += lives; // Add remaining lives to score
                break;
            }
            else if (guess < num) {
                printf("Too low! Try again.\n");
            }
            else {
                printf("Too high! Try again.\n");
            }
            
            lives--; // Decrement lives
            
            if (lives == 0) {
                printf("Game over! The number was %d.\n", num);
                printf("Your score is 0.\n");
            }
            else {
                printf("Lives left: %d\n", lives);
            }
        }
        
        // Prompt user to play again
        printf("Do you want to play again? (y/n): ");
        
        char play_again;
        scanf(" %c", &play_again);
        
        if (play_again == 'n') {
            game_over = 1;
        }
    }
    
    printf("Thanks for playing! Your final score is %d.\n", score);
    
    return 0;
}