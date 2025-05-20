//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 30

// Load the dictionary into a hash table
void load_dictionary(char* filename, char* hash_table[MAX_WORDS]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }

    char line[MAX_WORD_LENGTH + 1];
    while (fgets(line, MAX_WORD_LENGTH + 1, file) != NULL) {
        // Remove the newline character
        line[strlen(line) - 1] = '\0';

        // Convert the word to lowercase
        for (int i = 0; i < strlen(line); i++) {
            line[i] = tolower(line[i]);
        }

        // Insert the word into the hash table
        int index = hash(line);
        hash_table[index] = strdup(line);
    }

    fclose(file);
}

// Hash function
int hash(char* word) {
    int hash_value = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash_value += word[i] - 'a';
    }
    return hash_value % MAX_WORDS;
}

// Check if a word is in the dictionary
int is_in_dictionary(char* word, char* hash_table[MAX_WORDS]) {
    int index = hash(word);
    return hash_table[index] != NULL && strcmp(hash_table[index], word) == 0;
}

// Check the spelling of a word
void check_spelling(char* word, char* hash_table[MAX_WORDS]) {
    if (is_in_dictionary(word, hash_table)) {
        printf("%s is spelled correctly.\n", word);
    } else {
        printf("%s is spelled incorrectly.\n", word);
    }
}

// Get a word from the user
char* get_word() {
    char* word = malloc(MAX_WORD_LENGTH + 1);
    if (word == NULL) {
        perror("Error allocating memory for word");
        exit(1);
    }

    printf("Enter a word: ");
    scanf("%s", word);

    return word;
}

// Free the memory allocated for a word
void free_word(char* word) {
    free(word);
}

// Free the memory allocated for the hash table
void free_hash_table(char* hash_table[MAX_WORDS]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (hash_table[i] != NULL) {
            free(hash_table[i]);
        }
    }
}

// Main function
int main() {
    // Load the dictionary
    char* hash_table[MAX_WORDS] = { NULL };
    load_dictionary("dictionary.txt", hash_table);

    // Get a word from the user
    char* word = get_word();

    // Check the spelling of the word
    check_spelling(word, hash_table);

    // Free the memory allocated for the word and the hash table
    free_word(word);
    free_hash_table(hash_table);

    return 0;
}