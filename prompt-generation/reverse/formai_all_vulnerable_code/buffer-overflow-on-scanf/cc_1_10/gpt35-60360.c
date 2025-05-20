//FormAI DATASET v1.0 Category: Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 0 and 9
int generate_random_number() {
    srand(time(NULL));
    return rand() % 10;
}

int main() {
    // Initialize variables
    int target_number = generate_random_number();
    int guess, num_guesses = 0;
    char* player_name;

    // Get player's name
    printf("What is your name?\n");
    scanf("%s", player_name);

    // Instructions
    printf("%s, I'm thinking of a number between 0 and 9. You have 3 guesses to get it right.\n", player_name);

    // Loop for 3 guesses
    while(num_guesses < 3) {
        // Get user's guess
        printf("Guess #%d: ", num_guesses+1);
        scanf("%d", &guess);

        // Check if guess is correct
        if(guess == target_number) {
            printf("Congratulations, %s! You guessed the number in %d tries.\n", player_name, num_guesses+1);
            return 0;
        }
        // Check if guess is too high or too low
        else if(guess > target_number) {
            printf("Sorry, %s, your guess is too high.\n", player_name);
        }
        else {
            printf("Sorry, %s, your guess is too low.\n", player_name);
        }

        // Increment number of guesses
        num_guesses++;
    }

    // If player didn't guess the number in 3 tries
    printf("Sorry, %s, you didn't guess the number in 3 tries. The number was %d.\n", player_name, target_number);

    // Exit program
    return 0;
}