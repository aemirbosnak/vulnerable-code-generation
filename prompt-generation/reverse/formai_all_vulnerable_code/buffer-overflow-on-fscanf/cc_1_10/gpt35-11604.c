//FormAI DATASET v1.0 Category: Spell checking ; Style: happy
// Welcome to the Happy Spell Checker!
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Define a maximum word length
#define MAX_WORD_LEN 50

// The dictionary file name
#define DICTIONARY_FILE "dictionary.txt"

// Function to check if a word is spelled correctly
int is_spelled_correctly(const char *word, const char *dictionary[]) {
    int i;

    // Loop through the dictionary array
    for (i = 0; dictionary[i] != NULL; i++) {

        // Compare the word to the dictionary entry
        if (strcasecmp(word, dictionary[i]) == 0) {
            return 1; // The word is in the dictionary
        }
    }

    return 0; // The word is not in the dictionary
}

int main() {
    // Open the dictionary file
    FILE *dict = fopen(DICTIONARY_FILE, "r");

    char *dictionary[1000] = { NULL }; // Initialize the dictionary array

    if (dict == NULL) {
        printf("Uh oh, couldn't open dictionary file: %s\n", DICTIONARY_FILE);
        return 1;
    }

    // Loop through the file, adding each word to the dictionary array
    char word[MAX_WORD_LEN];
    int n = 0;
    while (fscanf(dict, " %s", word) == 1) {
        dictionary[n++] = strdup(word);
    }

    fclose(dict); // Close the dictionary file

    // Welcome message
    printf("Welcome to the Happy Spell Checker!\n");

    // Get the input file name from the user
    char input_file[MAX_WORD_LEN];
    printf("Please enter the name of the input file: ");
    scanf("%s", input_file);

    // Open the input file
    FILE *input = fopen(input_file, "r");

    if (input == NULL) {
        printf("Uh oh, couldn't open input file: %s\n", input_file);
        return 1;
    }

    // Loop through each word in the input file
    while (fscanf(input, " %s", word) == 1) {
        // Remove any punctuation from the beginning and end of the word
        for (int i = 0; i < strlen(word); i++) {
            if (ispunct(word[i])) {
                memmove(&word[i], &word[i+1], strlen(word)-i);
            }
        }
        int len = strlen(word);
        if (ispunct(word[len-1])) {
            word[len-1] = '\0';
        }

        // Check if the word is in the dictionary
        if (!is_spelled_correctly(word, dictionary)) {
            printf("Uh oh, '%s' is not spelled correctly. Please fix it!\n", word);
        }
    }

    // Close the input file
    fclose(input);

    // Goodbye message
    printf("Thank you for using the Happy Spell Checker!\n");

    // Free the dictionary memory
    for (int i = 0; dictionary[i] != NULL; i++) {
        free(dictionary[i]);
    }

    return 0;
}