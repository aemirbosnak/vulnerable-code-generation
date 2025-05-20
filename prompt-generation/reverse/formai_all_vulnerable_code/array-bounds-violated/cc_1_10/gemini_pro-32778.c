//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main() {
    // Create an array of words to check
    char *words[] = {"hello", "world", "computer", "science", "programming"};
    int num_words = sizeof(words) / sizeof(char *);

    // Create a dictionary of known words
    Word dictionary[MAX_WORDS];
    int num_dictionary_words = 0;

    // Load the dictionary from a file
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        return EXIT_FAILURE;
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp) != NULL) {
        // Remove the newline character from the end of the word
        line[strlen(line) - 1] = '\0';

        // Add the word to the dictionary
        strcpy(dictionary[num_dictionary_words].word, line);
        dictionary[num_dictionary_words].count = 0;
        num_dictionary_words++;
    }

    fclose(fp);

    // Check each word in the array against the dictionary
    for (int i = 0; i < num_words; i++) {
        int found = 0;

        // Check if the word is in the dictionary
        for (int j = 0; j < num_dictionary_words; j++) {
            if (strcmp(words[i], dictionary[j].word) == 0) {
                // Increment the word's count
                dictionary[j].count++;
                found = 1;
                break;
            }
        }

        // If the word is not in the dictionary, print it out
        if (!found) {
            printf("The word '%s' is not in the dictionary.\n", words[i]);
        }
    }

    // Print out the words in the dictionary and their counts
    for (int i = 0; i < num_dictionary_words; i++) {
        printf("The word '%s' appears %d times in the text.\n", dictionary[i].word, dictionary[i].count);
    }

    return EXIT_SUCCESS;
}