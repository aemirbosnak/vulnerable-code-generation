//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 256
#define MAX_DICTIONARY_SIZE 10000

// Function to load the dictionary into a hash table
int load_dictionary(char *filename, char **dictionary) {
    // Open the dictionary file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening dictionary file\n");
        return -1;
    }

    // Read the dictionary words into the hash table
    int count = 0;
    while (!feof(file)) {
        char word[MAX_WORD_LENGTH];
        fscanf(file, "%s\n", word);
        dictionary[count] = strdup(word);
        count++;
    }

    // Close the dictionary file
    fclose(file);

    return count;
}

// Function to check if a word is spelled correctly
int is_spelled_correctly(char *word, char **dictionary, int dictionary_size) {
    // Convert the word to lowercase
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    // Search for the word in the dictionary
    for (int i = 0; i < dictionary_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }

    // The word was not found in the dictionary
    return 0;
}

// Function to print the misspelled words
void print_misspelled_words(char **words, int num_words, char **dictionary, int dictionary_size) {
    for (int i = 0; i < num_words; i++) {
        if (!is_spelled_correctly(words[i], dictionary, dictionary_size)) {
            printf("%s\n", words[i]);
        }
    }
}

// Main function
int main() {
    // Load the dictionary into a hash table
    char *dictionary[MAX_DICTIONARY_SIZE];
    int dictionary_size = load_dictionary("dictionary.txt", dictionary);

    // Get the list of words to check
    char *words[] = {"hello", "world", "spelled", "correctly", "misspelled", "word"};
    int num_words = sizeof(words) / sizeof(words[0]);

    // Check if each word is spelled correctly
    print_misspelled_words(words, num_words, dictionary, dictionary_size);

    // Free the memory allocated for the dictionary
    for (int i = 0; i < dictionary_size; i++) {
        free(dictionary[i]);
    }

    return 0;
}