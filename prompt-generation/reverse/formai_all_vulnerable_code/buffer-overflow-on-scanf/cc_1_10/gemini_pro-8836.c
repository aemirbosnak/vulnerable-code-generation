//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum word length
#define MAX_WORD_LENGTH 20

// Define the number of words in the dictionary
#define NUM_WORDS 10

// Define the dictionary
const char *dictionary[] = {
    "apple",
    "banana",
    "cherry",
    "dog",
    "cat",
    "fish",
    "bird",
    "house",
    "car",
    "tree"
};

// Define the function to check if a word is spelled correctly
int is_spelled_correctly(const char *word) {
    // Iterate over the dictionary
    for (int i = 0; i < NUM_WORDS; i++) {
        // If the word is found in the dictionary, return true
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }

    // If the word is not found in the dictionary, return false
    return 0;
}

// Define the main function
int main() {
    // Get the word to check from the user
    char word[MAX_WORD_LENGTH];
    printf("Enter a word to check: ");
    scanf("%s", word);

    // Check if the word is spelled correctly
    int is_correct = is_spelled_correctly(word);

    // Print the result
    if (is_correct) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is not spelled correctly.\n");
    }

    return 0;
}