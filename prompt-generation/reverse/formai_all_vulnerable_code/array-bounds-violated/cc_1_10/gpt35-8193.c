//FormAI DATASET v1.0 Category: Spell checking ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define HASH_SIZE 10000

typedef struct Node {
    char *word;
    struct Node *next;
} Node;

Node *hash_table[HASH_SIZE];

/* Hash function to map word to index in hash table */
unsigned int hash(char *word) {
    unsigned int hash_val = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash_val = hash_val * 31 + word[i];
    }
    return hash_val % HASH_SIZE;
}

/* Inserts a word into the hash table */
void insert_word(char *word) {
    int index = hash(word);
    Node *new_node = malloc(sizeof(Node));
    new_node->word = word;
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

/* Checks if a word is in the hash table */
int check_word(char *word) {
    int index = hash(word);
    Node *curr = hash_table[index];
    while (curr != NULL) {
        if (strcmp(curr->word, word) == 0) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

/* Frees memory used by hash table */
void free_table() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node *curr = hash_table[i];
        while (curr != NULL) {
            Node *temp = curr;
            curr = curr->next;
            free(temp->word);
            free(temp);
        }
    }
}

/* Main program */
int main() {
    FILE *dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: dictionary file not found\n");
        return 1;
    }

    /* Insert words from dictionary file into hash table */
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, dict_file) != NULL) {
        int len = strlen(line);
        if (line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        insert_word(strdup(line)); // strdup dynamically allocates memory for string
    }
    fclose(dict_file);

    /* Prompt user for input text and check each word for spelling errors */
    printf("Enter text (press Ctrl-D to exit):\n");
    char word[MAX_WORD_LENGTH];
    while (scanf("%s", word) != EOF) {
        int len = strlen(word);
        if (len > 0 && word[len-1] == '.') {
            word[len-1] = '\0';
        }
        if (!check_word(word)) {
            printf("'%s' is misspelled\n", word);
        }
    }

    free_table(); // Free memory used by hash table
    return 0;
}