//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 30

// Declare the dictionary as an array of strings
char* dictionary[MAX_WORDS];

// Initialize the dictionary with a list of common words
void init_dictionary() {
    dictionary[0] = "the";
    dictionary[1] = "be";
    dictionary[2] = "to";
    dictionary[3] = "of";
    dictionary[4] = "and";
    dictionary[5] = "a";
    dictionary[6] = "in";
    dictionary[7] = "that";
    dictionary[8] = "have";
    dictionary[9] = "I";
}

// Check if a word is in the dictionary
int is_in_dictionary(char* word) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Get the number of misspelled words in a sentence
int get_num_misspellings(char* sentence) {
    int num_misspellings = 0;
    char* word = strtok(sentence, " ");
    while (word != NULL) {
        if (!is_in_dictionary(word)) {
            num_misspellings++;
        }
        word = strtok(NULL, " ");
    }
    return num_misspellings;
}

// Print the misspelled words in a sentence
void print_misspellings(char* sentence) {
    char* word = strtok(sentence, " ");
    while (word != NULL) {
        if (!is_in_dictionary(word)) {
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
    }
    printf("\n");
}

// Main function
int main() {
    // Initialize the dictionary
    init_dictionary();

    // Get the sentence from the user
    printf("Enter a sentence: ");
    char sentence[1000];
    gets(sentence);

    // Get the number of misspelled words in the sentence
    int num_misspellings = get_num_misspellings(sentence);

    // Print the misspelled words in the sentence
    if (num_misspellings > 0) {
        printf("Misspelled words: ");
        print_misspellings(sentence);
    } else {
        printf("No misspelled words found.\n");
    }

    return 0;
}