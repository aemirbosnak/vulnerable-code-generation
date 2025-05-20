//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define DICTIONARY_FILE "dictionary.txt"

// Function to read words from the dictionary file into a dynamically allocated array
void load_dictionary(char** dictionary, int* size) {
    FILE* file = fopen(DICTIONARY_FILE, "r");
    char line[MAX_WORD_LENGTH + 1];
    int i = 0;

    if (file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        *size = 0;
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        size_t len = strlen(line);
        if (len > MAX_WORD_LENGTH) {
            printf("Warning: Dictionary file contains a word '%s' that is too long.\n", line);
            continue;
        }
        dictionary[i] = malloc(len + 1);
        strncpy(dictionary[i], line, len + 1);
        i++;
    }

    fclose(file);
    *size = i;
}

// Function to check if a given word is present in the dictionary array
int is_word_in_dictionary(char* word, char* dictionary, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Main function to get words from the user and check them against the dictionary
int main() {
    char* dictionary = NULL;
    int size = 0;

    // Load the dictionary from file
    load_dictionary(&dictionary, &size);

    // Check spelling of words given by the user
    char word[MAX_WORD_LENGTH + 1];
    while (1) {
        printf("Enter a word or type 'quit' to exit: ");
        scanf("%s", word);

        if (strcmp(word, "quit") == 0) {
            break;
        }

        int is_valid_word = is_word_in_dictionary(word, dictionary, size);

        if (is_valid_word) {
            printf("Congratulations! '%s' is a valid word.\n", word);
        } else {
            printf("Warning: '%s' is not a valid word. Please check the spelling.\n", word);
        }
    }

    // Free memory allocated for dictionary
    for (int i = 0; i < size; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    return 0;
}