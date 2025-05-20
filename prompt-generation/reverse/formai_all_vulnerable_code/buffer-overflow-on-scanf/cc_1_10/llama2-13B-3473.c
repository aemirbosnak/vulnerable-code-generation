//LLAMA2-13B DATASET v1.0 Category: Terminal Based Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_GUESS 10
#define MAX_WORD_LENGTH 20

// Function to generate a random word
void generate_word(char *word) {
    int i, j;
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        word[i] = 'a' + (rand() % 26);
    }
}

// Function to check if the user's guess is correct
int check_guess(char *word, char guess) {
    int i;
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        if (word[i] == guess) {
            return 1;
        }
    }
    return 0;
}

// Function to display the game state and get the user's guess
void display_game_state(char *word, char *guess) {
    printf("Word: %s\n", word);
    printf("Guess: %c\n", guess);
}

int main() {
    char word[MAX_WORD_LENGTH];
    char guess;
    int attempts = 0;

    // Generate the random word
    generate_word(word);

    // Display the game state and get the user's guess
    display_game_state(word, guess);

    // Game loop
    while (1) {
        // Get the user's guess
        printf("Guess a letter: ");
        scanf(" %c", &guess);

        // Check if the user's guess is correct
        if (check_guess(word, guess)) {
            printf("Correct! You guessed %c\n", guess);
            break;
        }

        // Increment the number of attempts
        attempts++;

        // Display the game state and get the user's next guess
        display_game_state(word, guess);

        // If the user has run out of attempts, game over
        if (attempts >= MAX_GUESS) {
            printf("Game over! You ran out of attempts\n");
            break;
        }
    }

    return 0;
}