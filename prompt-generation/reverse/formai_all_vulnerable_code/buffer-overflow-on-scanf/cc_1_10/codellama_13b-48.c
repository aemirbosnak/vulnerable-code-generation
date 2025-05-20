//Code Llama-13B DATASET v1.0 Category: Terminal Based Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TRIES 5
#define MAX_WORD_LEN 10

void play_game(char *word, int *guesses, int *tries);
void display_word(char *word, int *guesses);

int main() {
    char word[MAX_WORD_LEN];
    int guesses[MAX_WORD_LEN];
    int tries = 0;

    // Generate a random word
    srand(time(NULL));
    int random_num = rand() % 10000;
    snprintf(word, MAX_WORD_LEN, "%04d", random_num);

    // Play the game
    play_game(word, guesses, &tries);

    return 0;
}

void play_game(char *word, int *guesses, int *tries) {
    // Initialize the guesses array to all zeros
    memset(guesses, 0, MAX_WORD_LEN);

    while (*tries < MAX_TRIES) {
        // Display the word with the guessed letters
        display_word(word, guesses);

        // Get the user's guess
        char guess;
        printf("Guess a letter: ");
        scanf(" %c", &guess);

        // Check if the guess is in the word
        int found = 0;
        for (int i = 0; i < MAX_WORD_LEN; i++) {
            if (word[i] == guess) {
                guesses[i] = 1;
                found = 1;
            }
        }

        // If the guess was not in the word, update the tries counter
        if (!found) {
            *tries += 1;
        }

        // Check if the user has won the game
        int won = 1;
        for (int i = 0; i < MAX_WORD_LEN; i++) {
            if (guesses[i] == 0) {
                won = 0;
                break;
            }
        }

        if (won) {
            printf("Congratulations, you won!\n");
            break;
        }
    }

    // If the user has lost the game, display the correct word
    if (*tries == MAX_TRIES) {
        printf("Sorry, you lost.\n");
        printf("The correct word was: %s\n", word);
    }
}

void display_word(char *word, int *guesses) {
    printf("Word: ");
    for (int i = 0; i < MAX_WORD_LEN; i++) {
        if (guesses[i]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}