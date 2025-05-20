//FormAI DATASET v1.0 Category: Spell checking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100
#define HASH_TABLE_SIZE 100

// A linked list to handle collisions
typedef struct Node {
    char word[MAX_WORD_SIZE];
    struct Node *next;
} Node;

// Hash table data structure
typedef struct HashTable {
    Node *table[HASH_TABLE_SIZE];
} HashTable;

// Hash Function - Convert word into int
unsigned int hash(const char *word) {
    unsigned int hash = 0;

    for (int i = 0; i < strlen(word); i++)
        hash = hash * 31 + toupper(word[i]);

    return hash % HASH_TABLE_SIZE;
}

// Add word to hash table
void add_word(const char *word, HashTable *table) {
    unsigned int index = hash(word);

    Node *walker = table->table[index];

    while (walker) {
        if (strcmp(word, walker->word) == 0) 
            return;

        walker = walker->next;
    }

    Node *new_node = (Node *) malloc(sizeof(Node));
    strncpy(new_node->word, word, MAX_WORD_SIZE);
    new_node->next = table->table[index];
    table->table[index] = new_node;
}

// Check if word is in hash table
int check_word(const char *word, HashTable *table) {
    unsigned int index = hash(word);

    Node *walker = table->table[index];

    while (walker) {
        if (strcmp(word, walker->word) == 0) 
            return 1;

        walker = walker->next;
    }

    return 0;
}

// Free the memory allocated to the hash table
void free_table(HashTable *table) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Node *walker = table->table[i];

        while (walker) {
            Node *tmp = walker;
            walker = walker->next;
            free(tmp);
        }
    }

    free(table);
}

/* Main program */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: spell_check <filename>\n");
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    // Create hash table
    HashTable *table = (HashTable *) calloc(1, sizeof(HashTable));

    // Read words from file and add to hash table
    char buffer[MAX_WORD_SIZE];
    while(fscanf(file, "%s", buffer) == 1)
        add_word(buffer, table);

    // Close file
    fclose(file);

    // Check spelling of words from standard input
    printf("Enter word to check: ");
    while (fgets(buffer, MAX_WORD_SIZE, stdin)) {
        buffer[strlen(buffer) - 1] = 0; // Remove newline character

        if (check_word(buffer, table))
            printf("Correct\n");
        else
            printf("Incorrect\n");

        printf("Enter word to check: ");
    }

    // Free hash table
    free_table(table);

    return 0;
}