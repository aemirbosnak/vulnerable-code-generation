//GPT-4o-mini DATASET v1.0 Category: Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 10

// Function prototypes
void display_instructions();
int get_valid_input(int min, int max);
void play_game(int target_number);

int main() {
    int play_again = 1;
    
    // Seed the random number generator
    srand(time(0));
    
    while (play_again) {
        int target_number = rand() % 100 + 1; // Generate random number between 1 and 100
        display_instructions();
        play_game(target_number);
        
        printf("\nDo you want to play again? (1 - Yes, 0 - No): ");
        scanf("%d", &play_again);
    }
    
    printf("Thanks for playing!\n");
    return 0;
}

// Function to display the game instructions
void display_instructions() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a random number between 1 and 100.\n");
    printf("You will have %d attempts to guess the number.\n", MAX_ATTEMPTS);
    printf("After each guess, I will tell you if the guess is too high, too low, or correct.\n");
    printf("Good luck!\n\n");
}

// Function to get valid input from the player
int get_valid_input(int min, int max) {
    int guess;

    while (1) {
        printf("Enter your guess (%d - %d): ", min, max);
        scanf("%d", &guess);
        
        if (guess < min || guess > max) {
            printf("Invalid input! Please guess a number between %d and %d.\n", min, max);
        } else {
            break; // valid input received
        }
    }
    return guess;
}

// Function to play the game
void play_game(int target_number) {
    int guess;
    int attempts = 0;
    
    while (attempts < MAX_ATTEMPTS) {
        guess = get_valid_input(1, 100);
        attempts++;
        
        if (guess < target_number) {
            printf("Too low! Try again.\n");
        } else if (guess > target_number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You've guessed the number %d in %d attempts!\n", target_number, attempts);
            return; // exit the function if guessed correctly
        }
    }
    
    printf("Sorry, you've used all %d attempts. The number was %d.\n", MAX_ATTEMPTS, target_number);
}