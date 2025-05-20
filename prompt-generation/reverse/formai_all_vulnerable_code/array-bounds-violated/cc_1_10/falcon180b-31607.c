//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

// Function prototypes
void generate_word_list(char *words[], int num_words);
void print_word_list(char *words[], int num_words);
int main();

// Main function
int main() {
    char *words[MAX_WORDS];
    int num_words;
    int max_tries = 6;
    int tries_left = max_tries;
    int word_index;
    char guess[MAX_WORD_LENGTH + 1];
    char correct_guesses[MAX_WORD_LENGTH];
    int num_correct_guesses = 0;
    int i;

    // Seed the random number generator
    srand(time(NULL));

    // Generate a list of words
    num_words = rand() % MAX_WORDS + 1;
    generate_word_list(words, num_words);

    // Print the list of words
    printf("Here are the words:\n");
    print_word_list(words, num_words);

    // Start the game
    printf("Guess a word:\n");
    while (tries_left > 0 && num_correct_guesses < num_words) {
        scanf("%s", guess);

        // Convert guess to uppercase
        for (i = 0; i < strlen(guess); i++) {
            guess[i] = toupper(guess[i]);
        }

        // Check if guess is correct
        word_index = -1;
        for (i = 0; i < num_words; i++) {
            if (strcmp(guess, words[i]) == 0) {
                word_index = i;
                break;
            }
        }

        if (word_index == -1) {
            printf("Incorrect guess.\n");
            tries_left--;
        } else {
            printf("Correct guess!\n");
            num_correct_guesses++;
        }
    }

    // Print the list of correct guesses
    printf("You guessed %d words correctly:\n", num_correct_guesses);
    for (i = 0; i < num_correct_guesses; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}

// Generate a list of words
void generate_word_list(char *words[], int num_words) {
    char *word_list[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon", "mango", "nectarine", "orange", "pear", "plum", "quince", "raspberry", "strawberry", "tangerine", "watermelon", "xylophone", "yogurt", "zebra"};
    int i, j;

    for (i = 0; i < num_words; i++) {
        j = rand() % 26;
        words[i] = word_list[j];
    }
}

// Print the list of words
void print_word_list(char *words[], int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}