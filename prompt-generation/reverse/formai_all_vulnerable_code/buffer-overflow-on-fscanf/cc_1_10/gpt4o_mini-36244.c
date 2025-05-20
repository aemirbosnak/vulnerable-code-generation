//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 30
#define DICTIONARY_SIZE 1000

// Function to check if a word exists in the dictionary
int check_word(const char *word, char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// Function to load the dictionary from a file
int load_dictionary(const char *filename, char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open dictionary file: %s\n", filename);
        return -1;
    }
    
    int count = 0;
    while (fscanf(file, "%s", dictionary[count]) != EOF && count < DICTIONARY_SIZE) {
        count++;
    }
    
    fclose(file);
    return count; // Return the number of words loaded
}

// Function to display a message to the user
void display_message(const char *message) {
    printf("\n=====================\n");
    printf("%s\n", message);
    printf("=====================\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }

    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int dict_size = load_dictionary(argv[1], dictionary);
    if (dict_size == -1) {
        return 1; // Terminate on load error
    }

    FILE *text_file = fopen(argv[2], "r");
    if (text_file == NULL) {
        display_message("Could not open text file for spelling check!");
        return 1;
    }

    display_message("Ready to check spelling. Let's go!");

    char word[MAX_WORD_LENGTH];
    while (fscanf(text_file, "%s", word) != EOF) {
        // Remove punctuation and convert to lowercase
        char clean_word[MAX_WORD_LENGTH];
        int j = 0;
        for (int i = 0; word[i] != '\0'; i++) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                clean_word[j++] = word[i];
            } else if (word[i] >= 'A' && word[i] <= 'Z') {
                clean_word[j++] = word[i] + ('a' - 'A');
            }
        }
        clean_word[j] = '\0'; // Null-terminate the clean word

        if (!check_word(clean_word, dictionary, dict_size)) {
            printf("Misspelled word found: %s\n", clean_word);
        }
    }

    fclose(text_file);
    display_message("Spelling check completed.");

    return 0;
}