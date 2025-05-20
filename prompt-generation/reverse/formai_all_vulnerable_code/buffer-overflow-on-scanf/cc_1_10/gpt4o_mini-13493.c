//GPT-4o-mini DATASET v1.0 Category: Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_GUESSES 7
#define WORD_COUNT 10
#define WORD_LENGTH 20

void select_word(char *word) {
    const char *word_list[WORD_COUNT] = {
        "programming", "linux", "computer", "development", "functionality",
        "challenge", "variable", "algorithm", "data", "syntax"
    };
    srand(time(NULL));
    strcpy(word, word_list[rand() % WORD_COUNT]);
}

void initialize_display(char *display, const char *word) {
    for (int i = 0; i < strlen(word); i++) {
        display[i] = '_'; // initialize display with underscores
    }
    display[strlen(word)] = '\0'; // null terminate the string
}

void print_display(const char *display) {
    printf("\nCurrent word: ");
    for (int i = 0; i < strlen(display); i++) {
        printf("%c ", display[i]);
    }
    printf("\n");
}

int main() {
    char word[WORD_LENGTH];
    char display[WORD_LENGTH];
    char guessed_letters[26];
    int num_guesses = 0;
    int correct_guesses = 0;
    int letter_found;
    char guess;

    printf("Welcome to the Word Guessing Game!\n");
    select_word(word);
    initialize_display(display, word);

    while (num_guesses < MAX_GUESSES && correct_guesses < strlen(word)) {
        print_display(display);
        printf("Guessed letters: ");
        for (int i = 0; i < num_guesses; i++) {
            printf("%c ", guessed_letters[i]);
        }
        printf("\nAttempts left: %d\n", MAX_GUESSES - num_guesses);
        
        printf("Enter a letter: ");
        scanf(" %c", &guess);

        // Check if the letter has already been guessed
        int already_guessed = 0;
        for (int i = 0; i < num_guesses; i++) {
            if (guessed_letters[i] == guess) {
                already_guessed = 1;
                break;
            }
        }

        if (already_guessed) {
            printf("You've already guessed that letter. Try again!\n");
            continue;
        }

        guessed_letters[num_guesses++] = guess; // save the guessed letter

        // Check if the guessed letter is in the word
        letter_found = 0;
        for (int i = 0; i < strlen(word); i++) {
            if (word[i] == guess) {
                if (display[i] == '_') {
                    display[i] = guess; // reveal the letter
                    correct_guesses++;
                }
                letter_found = 1;
            }
        }

        if (!letter_found) {
            printf("Incorrect guess!\n");
        } else {
            printf("Good guess!\n");
        }
    }

    if (correct_guesses == strlen(word)) {
        printf("Congratulations! You've guessed the word: '%s'\n", word);
    } else {
        printf("Sorry, you've run out of attempts! The word was: '%s'\n", word);
    }

    return 0;
}