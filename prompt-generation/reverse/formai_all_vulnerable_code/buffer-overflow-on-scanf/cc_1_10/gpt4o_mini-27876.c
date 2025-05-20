//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Function prototypes
void to_lowercase(char *word);
int is_word_in_dictionary(const char *word, FILE *dict);
void check_spelling(const char *text_filename, const char *dict_filename);

int main() {
    char text_file[100], dict_file[100];

    // User input for file names
    printf("Welcome to the Chill Spell Checker!\n");
    printf("Please enter the name of the text file to check (e.g. text.txt): ");
    scanf("%s", text_file);
    printf("And now, enter the name of your dictionary file (e.g. dictionary.txt): ");
    scanf("%s", dict_file);

    check_spelling(text_file, dict_file);
    
    printf("Spell checking completed. Keep it cool!\n");
    return 0;
}

// Function to convert a word to lowercase
void to_lowercase(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

// Function to check if a word is in the dictionary
int is_word_in_dictionary(const char *word, FILE *dict) {
    char dict_word[MAX_WORD_LENGTH];

    while (fgets(dict_word, sizeof(dict_word), dict) != NULL) {
        // Remove newline character
        dict_word[strcspn(dict_word, "\n")] = 0;
        to_lowercase(dict_word);
        
        if (strcmp(dict_word, word) == 0) {
            return 1; // Found the word
        }
    }
    return 0; // Not found
}

// Function to check spelling in the given text file
void check_spelling(const char *text_filename, const char *dict_filename) {
    FILE *text_file = fopen(text_filename, "r");
    FILE *dict_file = fopen(dict_filename, "r");
    
    if (!text_file || !dict_file) {
        printf("Error: Could not open one of the files. Please check the file names.\n");
        return;
    }

    char word[MAX_WORD_LENGTH];
    printf("Let's see how many words are feeling a bit off in the text...\n");
    int misspelled_count = 0;

    while (fscanf(text_file, "%s", word) != EOF) {
        // Clean and check each word
        to_lowercase(word);
        if (!is_word_in_dictionary(word, dict_file)) {
            printf("Misspelled word found: %s\n", word);
            misspelled_count++;
        }

        // Reset the dictionary file pointer for next word check
        rewind(dict_file);
    }

    // Summary of results
    if (misspelled_count == 0) {
        printf("All words are perfect! No misspellings detected. 🎉\n");
    } else {
        printf("Total misspelled words found: %d. Don't worry, it happens! 😅\n", misspelled_count);
    }

    fclose(text_file);
    fclose(dict_file);
}