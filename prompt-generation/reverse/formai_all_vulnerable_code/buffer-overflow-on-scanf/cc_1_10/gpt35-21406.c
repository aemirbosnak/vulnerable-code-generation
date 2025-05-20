//FormAI DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

// Dictionary of valid words
char *dictionary[] = {"apple", "banana", "cherry", "dog", "elephant", "frog", "grape", "happy", "iguana", "jelly",
                      "kangaroo", "lemon", "monkey", "nobody", "orange", "penguin", "quail", "rabbit", "strawberry",
                      "turtle", "umbrella", "violin", "watermelon", "xylophone", "yak", "zebra"};

int num_valid_words = sizeof(dictionary) / sizeof(char *);

// Function to check if a word is in the dictionary of valid words
bool is_valid_word(char *word) {
    for (int i = 0; i < num_valid_words; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Function to check if a word is spelled correctly
bool is_spelled_correctly(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return false;
        }
        word[i] = tolower(word[i]);
    }
    return is_valid_word(word);
}

// Main function
int main() {
    char word[20];

    // Randomly choose a word from the dictionary
    srand(time(NULL));
    int random_index = rand() % num_valid_words;
    char *random_word = dictionary[random_index];

    // Print instructions for user
    printf("Welcome to the Spell Checker game! I have chosen a random word from the dictionary. Your task is to guess the word.\n");

    // Main loop where user guesses the word
    while (true) {
        // Get input from user
        printf("Enter a word: ");
        scanf("%s", word);

        // Check if the word is spelled correctly
        if (is_spelled_correctly(word)) {
            // Check if the user guessed the correct word
            if (strcmp(word, random_word) == 0) {
                printf("Congratulations! You guessed the word \"%s\" correctly!\n", random_word);
                break;
            } else {
                printf("Sorry, \"%s\" is not the correct word. Please try again.\n", word);
            }
        } else {
            printf("Sorry, \"%s\" is not a valid word. Please try again.\n", word);
        }
    }

    return 0;
}