//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 5
#define MAX_NUMBER 100

void print_instructions() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("You need to guess a number between 1 and %d.\n", MAX_NUMBER);
    printf("You have a maximum of %d attempts. Good luck!\n\n", MAX_ATTEMPTS);
}

int get_player_guess() {
    int guess;
    printf("Enter your guess: ");
    scanf("%d", &guess);
    return guess;
}

int main() {
    int target_number, player_guess;
    int attempts = 0;
    int win = 0;

    // Seed the random number generator
    srand(time(NULL));
    target_number = rand() % MAX_NUMBER + 1; // Random number between 1 and MAX_NUMBER

    print_instructions();

    while (attempts < MAX_ATTEMPTS) {
        player_guess = get_player_guess();
        attempts++;

        if (player_guess < 1 || player_guess > MAX_NUMBER) {
            printf("Please guess a number between 1 and %d.\n", MAX_NUMBER);
            attempts--; // Do not count invalid guess
            continue;
        }

        if (player_guess < target_number) {
            printf("Higher! You have %d attempts left.\n\n", MAX_ATTEMPTS - attempts);
        } else if (player_guess > target_number) {
            printf("Lower! You have %d attempts left.\n\n", MAX_ATTEMPTS - attempts);
        } else {
            win = 1;
            break;
        }
    }

    // Game Over
    if (win) {
        printf("Congratulations! You've guessed the correct number: %d\n", target_number);
    } else {
        printf("Sorry, you've used all your attempts. The number was: %d\n", target_number);
    }
    
    return 0;
}