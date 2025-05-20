//FormAI DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare Constant
#define MAX 100

// Function Prototypes
int generate_number(int max);
int compare_numbers(int guess, int answer);
int play_game();

// Main Function
int main() {
    int choice, score = 0, try_again = 1;
    srand(time(NULL)); // Set seed for random number generation
    
    printf("Welcome to the Number Guessing Game!\n");
    
    while(try_again) {
        score += play_game();
        printf("Your Score: %d\n\n", score);
        printf("Would you like to play again? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
        try_again = choice ? 1 : 0;
    }
    
    printf("Thanks for playing!\n");
    return 0;
}

// Function to generate random number
int generate_number(int max) {
    return rand() % max + 1; // Generate random number from 1 to max
}

// Function to compare guess with answer
int compare_numbers(int guess, int answer) {
    if(guess > answer) {
        printf("Too high!\n");
        return 1; // Return 1 for too high guess
    }
    else if(guess < answer) {
        printf("Too low!\n");
        return -1; // Return -1 for too low guess
    }
    else {
        printf("You got it!\n");
        return 0; // Return 0 for correct guess
    }
}

// Function to run game logic
int play_game() {
    int answer, guess, tries = 0, result;
    answer = generate_number(MAX);
    printf("Guess a number between 1 and %d\n", MAX);
    do {
        printf("Guess #%d: ", ++tries);
        scanf("%d", &guess);
        result = compare_numbers(guess, answer);
    } while(result != 0);
    return tries;
}