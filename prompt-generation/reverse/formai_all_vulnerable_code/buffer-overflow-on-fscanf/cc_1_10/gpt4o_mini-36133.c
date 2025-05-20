//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 1000
#define BUFFER_SIZE 1024

// This function reads the dictionary words into an array.
void loadDictionary(const char *filename, char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH], int *wordCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open the dictionary file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int count = 0;
    while (fscanf(file, "%s", dictionary[count]) == 1 && count < DICTIONARY_SIZE) {
        count++;
    }
    fclose(file);
    *wordCount = count;
}

// This function checks if a word exists in the dictionary.
int checkSpelling(const char *word, char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH], int wordCount) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// This function provides suggestions by finding close matches.
void suggestCorrections(const char *word, char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH], int wordCount) {
    printf("Did you mean:\n");
    for (int i = 0; i < wordCount; i++) {
        if (abs((int)strlen(dictionary[i]) - (int)strlen(word)) <= 1) {
            printf(" - %s\n", dictionary[i]);
        }
    }
}

// Main function to run the spell checker
int main() {
    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int wordCount;

    // Load the dictionary - make sure you have words.txt in the same directory!
    loadDictionary("words.txt", dictionary, &wordCount);
    printf("Dictionary loaded with %d words. Thank you for using our program!\n\n", wordCount);

    char input[BUFFER_SIZE];

    // Read user input until they wish to exit
    while (1) {
        printf("Please enter a word to check (or type 'exit' to quit): ");
        fgets(input, BUFFER_SIZE, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        if (strcmp(input, "exit") == 0) {
            printf("Thank you for using the spell checker! Have a great day!\n");
            break;
        }

        if (checkSpelling(input, dictionary, wordCount)) {
            printf("The word '%s' is spelled correctly.\n", input);
        } else {
            printf("The word '%s' is not found in the dictionary.\n", input);
            suggestCorrections(input, dictionary, wordCount);
        }

        printf("\n");
    }

    return EXIT_SUCCESS;
}