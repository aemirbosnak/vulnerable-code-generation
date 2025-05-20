//LLAMA2-13B DATASET v1.0 Category: Terminal Based Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 50
#define MIN_LENGTH 10
#define MAX_GUESS 10

// Structure to store the game state
typedef struct {
    int length;        // Current length of the word
    int guesses;      // Number of guesses made so far
    char word[MAX_LENGTH]; // Word to guess
} game_state_t;

// Function to generate a random word
void generate_word(game_state_t *state) {
    int i;
    for (i = 0; i < state->length; i++) {
        state->word[i] = 'a' + (rand() % 26);
    }
}

// Function to check if the guess is correct
int check_guess(game_state_t *state, char guess) {
    int i;
    for (i = 0; i < state->length; i++) {
        if (guess == state->word[i]) {
            return 1;
        }
    }
    return 0;
}

// Function to display the game state
void display_game_state(game_state_t *state) {
    printf("Current length: %d\n", state->length);
    printf("Guesses made: %d\n", state->guesses);
    printf("Word so far: %s\n", state->word);
}

// Function to play the game
void play_game(game_state_t *state) {
    int guess;

    // Display the game state
    display_game_state(state);

    // Ask the user for a guess
    printf("Guess a letter: ");
    scanf(" %c", &guess);

    // Check if the guess is correct
    if (check_guess(state, guess)) {
        // If the guess is correct, increment the length of the word
        state->length++;
        printf("Correct guess! Word length now %d\n", state->length);
    } else {
        // If the guess is incorrect, decrease the number of guesses left
        state->guesses--;
        printf("Incorrect guess. Guesses left: %d\n", state->guesses);
    }

    // Generate a new word if the length is max
    if (state->length == MAX_LENGTH) {
        generate_word(state);
    }

    // End the game when the word is guessed or all guesses are used up
    if (state->length == MIN_LENGTH || state->guesses == 0) {
        printf("Game over! You guessed the word in %d attempts\n", state->guesses);
        return;
    }

    // Ask the user to make another guess
    printf("Keep guessing! You have %d guesses left\n", state->guesses);
}

int main() {
    game_state_t state;

    // Initialize the game state
    state.length = MIN_LENGTH;
    state.guesses = MAX_GUESS;
    generate_word(&state);

    // Play the game
    play_game(&state);

    return 0;
}