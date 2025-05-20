//FormAI DATASET v1.0 Category: Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guesses[5];
    int guess_count = 0;
    int random_number;
    
    // Generate a random number between 1 and 100
    srand(time(NULL));  // Initialize random seed
    random_number = rand() % 100 + 1;  // Get random number
    
    // Game instructions
    printf("Welcome to the number guessing game!\n");
    printf("I am thinking of a number between 1 and 100.\n");
    printf("You have 5 chances to guess the correct number.\n");
    
    // Guessing loop
    while (guess_count < 5) {
        int guess;
        printf("\nEnter your guess (between 1 and 100): ");
        scanf("%d", &guess);
        
        // Check if guess is correct
        if (guess == random_number) {
            printf("Congratulations, you guessed the correct number!\n");
            return 0;
        }
        // Check if guess is out of range or a repeat
        else if (guess < 1 || guess > 100) {
            printf("Invalid input, please enter a number between 1 and 100.\n");
            continue;
        }
        else if (guess_count > 0) {
            for (int i = 0; i < guess_count; i++) {
                if (guesses[i] == guess) {
                    printf("You already guessed that number, try a different number.\n");
                    guess_count++;
                    continue;
                }
            }
        }
        
        // Incorrect guess
        guesses[guess_count] = guess;
        guess_count++;
        printf("Incorrect guess, please try again. You have %d guesses left.\n", 5 - guess_count);
    }
    
    // Out of guesses
    printf("Sorry, you ran out of guesses. The correct number was %d.\n", random_number);
    return 0;
}