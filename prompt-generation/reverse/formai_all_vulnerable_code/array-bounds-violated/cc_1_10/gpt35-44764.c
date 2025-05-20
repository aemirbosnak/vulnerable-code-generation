//FormAI DATASET v1.0 Category: Spell checking ; Style: artistic
// Spell Checking Program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50 // maximum length of a word
#define MAX_HASH_TABLE_SIZE 50000 // maximum size of hash table

// Data structure for each word in the dictionary
typedef struct Word {
    char word[MAX_WORD_LENGTH];
    int frequency;
    struct Word *next;
} Word;

// Hash table for the dictionary
Word *hash_table[MAX_HASH_TABLE_SIZE];

// Function that hashes a string to an integer
unsigned int hash(char *str) {
    unsigned int hashval;
    for (hashval = 0; *str != '\0'; str++)
        hashval = *str + 31 * hashval;
    return hashval % MAX_HASH_TABLE_SIZE;
}

// Function that inserts a word into the dictionary
void insert(Word *word) {
    unsigned int hashval = hash(word->word);
    Word *current = hash_table[hashval];
    while (current != NULL) {
        if (strcmp(current->word, word->word) == 0) {
            current->frequency++;
            return;
        }
        current = current->next;
    }
    word->next = hash_table[hashval];
    hash_table[hashval] = word;
}

// Function that checks if a word is spelled correctly
bool check_spelling(char *word) {
    unsigned int hashval = hash(word);
    Word *current = hash_table[hashval];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->frequency++;
            return true;
        }
        current = current->next;
    }
    return false;
}

int main() {
    // Load dictionary into hash table
    FILE *dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error: could not open dictionary file\n");
        return 1;
    }
    char buffer[MAX_WORD_LENGTH];
    while (fgets(buffer, MAX_WORD_LENGTH, dictionary) != NULL) {
        // Remove newline character at end of word
        buffer[strlen(buffer)-1] = '\0';
        Word *word = malloc(sizeof(Word));
        strcpy(word->word, buffer);
        word->frequency = 0;
        word->next = NULL;
        insert(word);
    }
    fclose(dictionary);

    // Check spelling of words in input file
    FILE *input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Error: could not open input file\n");
        return 1;
    }
    while (fscanf(input, "%s", buffer) != EOF) {
        // Remove punctuation from word
        int i, j;
        for (i = 0, j = 0; buffer[i]; i++) {
            if (isalpha(buffer[i]))
                buffer[j++] = tolower(buffer[i]);
        }
        buffer[j] = '\0';
        if (!check_spelling(buffer))
            printf("Possible misspelling: %s\n", buffer);
    }
    fclose(input);

    // Print frequency of words in dictionary
    printf("Word\t\tFrequency\n");
    printf("------------------------\n");
    for (int i = 0; i < MAX_HASH_TABLE_SIZE; i++) {
        Word *current = hash_table[i];
        while (current != NULL) {
            printf("%-20s %d\n", current->word, current->frequency);
            current = current->next;
        }
    }

    return 0;
}