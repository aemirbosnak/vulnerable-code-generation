//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: visionary
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_SIZE 100000

// Node structure for trie
typedef struct node {
    int count;
    struct node *children[26];
} TrieNode;

// Trie structure
TrieNode *trie = NULL;

// Function to create a new node in the trie
void createNode() {
    trie = (TrieNode *) malloc(sizeof(TrieNode));
    trie->count = 0;
    for (int i = 0; i < 26; i++) {
        trie->children[i] = NULL;
    }
}

// Function to insert a word into the trie
void insertWord(char *word) {
    TrieNode *current = trie;
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        char c = tolower(word[i]);
        int index = c - 'a';

        if (current->children[index] == NULL) {
            current->children[index] = (TrieNode *) malloc(sizeof(TrieNode));
        }

        current = current->children[index];
    }

    current->count++;
}

// Function to check if a word is in the trie
bool isInTrie(char *word) {
    TrieNode *current = trie;
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        char c = tolower(word[i]);
        int index = c - 'a';

        if (current->children[index] == NULL) {
            return false;
        }

        current = current->children[index];
    }

    return true;
}

// Function to delete a word from the trie
void deleteWord(char *word) {
    TrieNode *current = trie;
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        char c = tolower(word[i]);
        int index = c - 'a';

        if (current->children[index] == NULL) {
            return;
        }

        current = current->children[index];
    }

    current->count--;
}

// Function to load dictionary into the trie
void loadDictionary(char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        insertWord(word);
    }

    fclose(file);
}

// Function to check spelling of a file
void checkSpelling(char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (!isInTrie(word)) {
            printf("Possible spelling error: %s\n", word);
        }
    }

    fclose(file);
}

int main() {
    createNode();
    loadDictionary("dictionary.txt");

    char filename[MAX_WORD_LENGTH];
    printf("Enter filename to check spelling: ");
    scanf("%s", filename);

    checkSpelling(filename);

    return 0;
}