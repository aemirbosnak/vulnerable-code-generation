//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 5000

// Function to convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to read words from a file and store them in an array
int read_dictionary(const char *filename, char words[MAX_WORDS][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open dictionary file %s\n", filename);
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%s", words[count]) != EOF && count < MAX_WORDS) {
        to_lowercase(words[count]);
        count++;
    }

    fclose(file);
    return count;
}

// Function to check if a word is in the dictionary
int is_correctly_spelled(const char *word, char words[MAX_WORDS][MAX_WORD_LENGTH], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, words[i]) == 0) {
            return 1; // Word is correct
        }
    }
    return 0; // Word is incorrect
}

// Function to get suggestions for a misspelled word
void get_suggestions(const char *word, char words[MAX_WORDS][MAX_WORD_LENGTH], int dict_size) {
    printf("Suggestions for the word '%s':\n", word);
    for (int i = 0; i < dict_size; i++) {
        if (abs((int)strlen(word) - (int)strlen(words[i])) <= 1) {
            // Suggest words that are one character different in length
            int differences = 0;
            for (int j = 0; j < strlen(word) && j < strlen(words[i]); j++) {
                if (word[j] != words[i][j]) {
                    differences++;
                }
            }
            differences += abs((int)strlen(word) - (int)strlen(words[i]));
            if (differences == 1) {
                printf("  - %s\n", words[i]);
            }
        }
    }
}

// Function to process user input and check spelling
void check_spelling(const char *dictionary_file) {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int dict_size = read_dictionary(dictionary_file, words);
    if (dict_size == 0) {
        return; // Exit if dictionary is empty
    }

    char input[MAX_WORD_LENGTH];
    printf("Enter words to check (type 'exit' to quit):\n");
    
    while (1) {
        printf("> ");
        scanf("%s", input);
        to_lowercase(input);
        
        if (strcmp(input, "exit") == 0) {
            break; // Exit the loop
        }
        
        if (!is_correctly_spelled(input, words, dict_size)) {
            printf("'%s' is misspelled.\n", input);
            get_suggestions(input, words, dict_size);
        } else {
            printf("'%s' is spelled correctly!\n", input);
        }
    }
}

// Main function: entry point of the program
int main() {
    const char *dictionary_file = "dictionary.txt"; // Path to dictionary file
    check_spelling(dictionary_file);
    return 0;
}