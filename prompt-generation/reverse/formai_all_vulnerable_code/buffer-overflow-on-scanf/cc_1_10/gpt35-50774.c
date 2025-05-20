//FormAI DATASET v1.0 Category: Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome message
    printf("Welcome to the Number Guessing Game!\n\n");
    printf("You have 10 attempts to guess the secret number between 1 and 100.\n");
    
    // Set up random seed
    srand(time(0));
    
    // Generate random secret number
    int secret_number = rand() % 100 + 1;
    
    // Set up number of attempts
    int attempts_remaining = 10;
    
    // Game loop
    while (attempts_remaining > 0) {
        printf("You have %d attempts remaining.\n", attempts_remaining);
        
        // Get user input
        int guess;
        printf("Enter your guess (between 1 and 100): ");
        scanf("%d", &guess);
        
        // Check if guess is correct
        if (guess == secret_number) {
            printf("Congratulations, you guessed the secret number!\n");
            break;
        }
        // Check if guess is too high or too low
        else if (guess > secret_number) {
            printf("Your guess is too high.\n");
        }
        else {
            printf("Your guess is too low.\n");
        }
        
        // Decrement attempts remaining
        attempts_remaining--;
    }
    
    // Check if player ran out of attempts
    if (attempts_remaining == 0) {
        printf("Sorry, you ran out of attempts. The secret number was %d.\n", secret_number);
    }
    
    return 0;
}