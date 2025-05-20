//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: intelligent
/*
* Word Frequency Counter Example Program
*
* This program takes a string as input and counts the frequency of each word in the string.
* The result is displayed in a table with the word and its frequency.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to count the frequency of each word in a string
int count_word_frequency(char *str) {
    // Initialize a hash map to store the word and its frequency
    // The hash map uses the word as the key and the frequency as the value
    // The hash map is implemented using a linked list
    struct hash_map {
        char *word;
        int frequency;
        struct hash_map *next;
    };

    // Initialize the hash map with the first word
    struct hash_map *map = (struct hash_map *)malloc(sizeof(struct hash_map));
    map->word = strtok(str, " ");
    map->frequency = 1;
    map->next = NULL;

    // Iterate through the remaining words in the string
    char *word = strtok(NULL, " ");
    while (word != NULL) {
        // Check if the word is already in the hash map
        struct hash_map *entry = map;
        while (entry != NULL) {
            if (strcmp(entry->word, word) == 0) {
                // Increment the frequency of the word
                entry->frequency++;
                break;
            }
            entry = entry->next;
        }

        // If the word is not in the hash map, add it
        if (entry == NULL) {
            struct hash_map *new_entry = (struct hash_map *)malloc(sizeof(struct hash_map));
            new_entry->word = word;
            new_entry->frequency = 1;
            new_entry->next = NULL;
            map->next = new_entry;
        }

        // Get the next word in the string
        word = strtok(NULL, " ");
    }

    // Print the result in a table
    printf("Word\tFrequency\n");
    printf("----\t---------\n");
    struct hash_map *entry = map;
    while (entry != NULL) {
        printf("%s\t%d\n", entry->word, entry->frequency);
        entry = entry->next;
    }

    // Free the memory allocated for the hash map
    free(map);

    return 0;
}

int main() {
    // Test the program with a sample string
    char *str = "Hello World! This is a test string.";
    count_word_frequency(str);

    return 0;
}