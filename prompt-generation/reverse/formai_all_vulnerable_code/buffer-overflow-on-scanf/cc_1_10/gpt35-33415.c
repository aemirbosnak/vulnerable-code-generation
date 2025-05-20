//FormAI DATASET v1.0 Category: Math exercise ; Style: protected
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
bool prompt_play_again();
void game_instructions();
int generate_random_number(int min, int max);
int get_guess_input();
bool check_guess(int secret_number, int guess);
void show_win_message(int tries);
void show_lose_message(int secret_number);

int main() {
    // Seed the RNG
    srand(time(NULL));

    // Program welcome message
    printf("Welcome to the Math Game!\n\n");

    // Display game instructions
    game_instructions();

    // Variables used during game
    int secret_number;
    int guess;
    int tries = 0;
    bool play_again = true;

    // Game loop
    while(play_again) {
        // Generate new random number for each game
        secret_number = generate_random_number(1, 1000);

        // Reset counter for new game
        tries = 0;

        // Gameplay loop
        while(true) {
            // Ask the user for their guess
            guess = get_guess_input();

            // Increment number of tries
            tries++;

            // Check guess against the secret_number
            if(check_guess(secret_number, guess)) {
                // Win condition
                show_win_message(tries);
                break;
            } else if(tries >= 10) {
                // Loss condition
                show_lose_message(secret_number);
                break;
            }
        }

        // Prompt user to play again
        play_again = prompt_play_again();
        printf("\n");
    }

    // End of program
    printf("Goodbye!\n");

    return 0;
}

// Function Definitions

bool prompt_play_again() {
    char play_again_input;
    printf("Would you like to play again? (y/n): ");
    scanf(" %c", &play_again_input);
    
    if(play_again_input == 'n') {
        return false;
    } else {
        return true;
    }
}

void game_instructions() {
    printf("Instructions:\n");
    printf("1. You have 10 chances to guess the secret number.\n");
    printf("2. The secret number is between 1 and 1000 inclusive.\n");
    printf("3. After each guess, you will be told if the secret number is higher or lower than your guess.\n");
    printf("4. Good luck!\n\n");
}

int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int get_guess_input() {
    int guess = 0;
    printf("Enter your guess (1-1000): ");
    scanf("%d", &guess);
    return guess;
}

bool check_guess(int secret_number, int guess) {
    if(guess == secret_number) {
        return true;
    } else if(guess < secret_number) {
        printf("The secret number is higher than %d\n", guess);
        return false;
    } else {
        printf("The secret number is lower than %d\n", guess);
        return false;
    }
}

void show_win_message(int tries) {
    printf("Congratulations! You Win!\n");
    printf("You guessed the secret number in %d tries.\n", tries);
}

void show_lose_message(int secret_number) {
    printf("Game Over. You Lose.\n");
    printf("The secret number was %d\n", secret_number);
}