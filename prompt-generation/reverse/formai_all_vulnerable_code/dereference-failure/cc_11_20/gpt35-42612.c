//FormAI DATASET v1.0 Category: Spell checking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // Check if a file was provided as an argument
    if (argc != 2) {
        printf("Error: Please provide a file to check as an argument.\n");
        return 1;
    }

    // Load the dictionary of valid words
    FILE *dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    // Create a hash table for quick lookup
    const int TABLE_SIZE = 10000;
    char **hash_table = calloc(TABLE_SIZE, sizeof(char *));
    if (hash_table == NULL) {
        printf("Error: Could not allocate memory for hash table.\n");
        return 1;
    }

    // Load words into the hash table
    char word[47]; // longest word in the dictionary is 46 characters
    while (fscanf(dictionary, "%s", word) != EOF) {
        // Convert word to lowercase
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        // Compute hash value (djb2 algorithm)
        unsigned long hash = 5381;
        for (int i = 0; word[i]; i++) {
            hash = ((hash << 5) + hash) + word[i];
        }
        hash %= TABLE_SIZE;

        // Add word to hash table
        hash_table[hash] = strdup(word);
    }
    fclose(dictionary);

    // Open the file to check
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Loop through each word in the file
    while (fscanf(file, "%s", word) != EOF) {
        // Strip non-alphabetic characters
        int j = 0;
        for (int i = 0; word[i]; i++) {
            if (isalpha(word[i])) {
                word[j++] = tolower(word[i]);
            }
        }
        word[j] = '\0';

        // Check if word is in hash table
        unsigned long hash = 5381;
        for (int i = 0; word[i]; i++) {
            hash = ((hash << 5) + hash) + word[i];
        }
        hash %= TABLE_SIZE;

        if (hash_table[hash] == NULL) {
            printf("Unknown word: %s\n", word);
        } else if (strcmp(hash_table[hash], word) != 0) {
            printf("Misspelled word: %s (did you mean %s?)\n", word, hash_table[hash]);
        }
    }

    fclose(file);

    // Free memory used by hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        free(hash_table[i]);
    }
    free(hash_table);

    return 0;
}