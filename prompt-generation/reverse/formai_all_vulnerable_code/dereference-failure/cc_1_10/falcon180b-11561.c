//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 10000

struct TrieNode {
    int isEndOfWord;
    struct TrieNode *children[26];
};

struct TrieNode *newNode() {
    struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < 26; i++)
        node->children[i] = NULL;
    return node;
}

void insert(struct TrieNode *root, char *word) {
    struct TrieNode *node = root;
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        int index = tolower(word[i]) - 'a';
        if (node->children[index] == NULL)
            node->children[index] = newNode();
        node = node->children[index];
    }

    node->isEndOfWord = 1;
}

int search(struct TrieNode *root, char *word) {
    struct TrieNode *node = root;
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        int index = tolower(word[i]) - 'a';
        if (node->children[index] == NULL)
            return 0;
        node = node->children[index];
    }

    return node->isEndOfWord;
}

void deleteTrie(struct TrieNode *root) {
    for (int i = 0; i < 26; i++) {
        if (root->children[i]!= NULL)
            deleteTrie(root->children[i]);
    }
    free(root);
}

int main() {
    FILE *dictionary;
    char word[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    struct TrieNode *root = newNode();

    dictionary = fopen("dictionary.txt", "r");

    if (dictionary == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        return 1;
    }

    while (fscanf(dictionary, "%s", line)!= EOF) {
        insert(root, line);
    }

    fclose(dictionary);

    char text[MAX_WORD_LENGTH];
    printf("Enter text to spell check: ");
    fgets(text, MAX_WORD_LENGTH, stdin);

    char *token = strtok(text, " ");
    while (token!= NULL) {
        if (search(root, token) == 0) {
            printf("%s is not in the dictionary.\n", token);
        }
        token = strtok(NULL, " ");
    }

    deleteTrie(root);

    return 0;
}