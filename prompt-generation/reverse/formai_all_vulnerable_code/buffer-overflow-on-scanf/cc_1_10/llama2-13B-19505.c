//LLAMA2-13B DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MAX_GUESS 10

// Structure to store word and its corresponding guesses
typedef struct {
    char word[MAX_WORD_LENGTH];
    char guesses[MAX_GUESS];
} word_t;

// Function to generate a random word
void generate_word(word_t *word) {
    int i, j;
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        word->word[i] = 'a' + (rand() % 26);
    }
}

// Function to check if a guess is correct
int check_guess(word_t *word, char guess) {
    int i, j;
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        if (word->word[i] == guess) {
            word->guesses[i] = 1;
            return 1;
        }
    }
    return 0;
}

// Function to display the word and its guesses
void display_word(word_t *word) {
    int i;
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        printf("%c ", word->word[i]);
    }
    printf("\n");
    for (i = 0; i < MAX_GUESS; i++) {
        printf("Guess %d: %c\n", i + 1, word->guesses[i]);
    }
}

int main() {
    word_t word;
    generate_word(&word);
    display_word(&word);

    char guess;
    do {
        printf("Enter a guess: ");
        scanf(" %c", &guess);
        if (check_guess(&word, guess)) {
            printf("Correct guess! You guessed %c\n", guess);
        } else {
            printf("Incorrect guess. You guessed %c\n", guess);
        }
    } while (1);

    return 0;
}