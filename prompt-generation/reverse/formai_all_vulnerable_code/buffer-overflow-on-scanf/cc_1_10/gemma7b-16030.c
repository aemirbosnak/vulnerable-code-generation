//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_GUESSES 5

char words[MAX_WORDS][20] = {
    "apple",
    "banana",
    "orange",
    "grapefruit",
    "pineapple",
    "mango",
    "apricot",
    "peach",
    "watermelon",
    "grapes"
};

int main() {
    char guess[20];
    int word_index, guesses = 0, is_guess_correct = 0;
    time_t t;

    // Seed the random number generator
    srand(time(&t));

    // Choose a random word
    word_index = rand() % MAX_WORDS;

    // Display the word
    printf("Guess the word: ");

    // Get the user's guess
    scanf("%s", guess);

    // Check if the guess is correct
    is_guess_correct = strcmp(guess, words[word_index]) == 0;

    // Increment the number of guesses
    guesses++;

    // Check if the user has won or lost
    if (is_guess_correct) {
        printf("Congratulations! You won!\n");
    } else if (guesses == MAX_GUESSES) {
        printf("Sorry, you lost. The answer was: %s\n", words[word_index]);
    } else {
        printf("Try again. You have %d guesses left.\n", MAX_GUESSES - guesses);
    }

    return 0;
}