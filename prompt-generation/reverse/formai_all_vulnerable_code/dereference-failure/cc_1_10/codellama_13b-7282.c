//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: mathematical
/*
 * Word Frequency Counter in C
 *
 * This program reads a file containing a text and calculates the frequency of each word
 * in the text. The frequency of each word is calculated using the hash table data
 * structure.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hash table size
#define HASH_SIZE 1000

// Hash table node structure
typedef struct node {
    char *word;
    int freq;
    struct node *next;
} Node;

// Hash table structure
typedef struct {
    Node *table[HASH_SIZE];
} HashTable;

// Hash function to map a word to a hash table index
int hash(char *word) {
    int index = 0;
    for (int i = 0; i < strlen(word); i++) {
        index += word[i];
    }
    return index % HASH_SIZE;
}

// Adds a word to the hash table
void add_word(HashTable *ht, char *word) {
    int index = hash(word);
    Node *node = ht->table[index];
    while (node != NULL) {
        if (strcmp(node->word, word) == 0) {
            node->freq++;
            return;
        }
        node = node->next;
    }
    node = malloc(sizeof(Node));
    node->word = word;
    node->freq = 1;
    node->next = ht->table[index];
    ht->table[index] = node;
}

// Prints the frequency of each word in the hash table
void print_freq(HashTable *ht) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node *node = ht->table[i];
        while (node != NULL) {
            printf("%s: %d\n", node->word, node->freq);
            node = node->next;
        }
    }
}

// Main function
int main() {
    // Open the file
    FILE *file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Create a hash table
    HashTable *ht = malloc(sizeof(HashTable));
    for (int i = 0; i < HASH_SIZE; i++) {
        ht->table[i] = NULL;
    }

    // Read the file and add words to the hash table
    char word[100];
    while (fscanf(file, "%s", word) != EOF) {
        add_word(ht, word);
    }

    // Print the frequency of each word
    print_freq(ht);

    // Close the file and free the hash table
    fclose(file);
    free(ht);

    return 0;
}