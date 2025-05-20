//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool is_word;
} TrieNode;

void insert(TrieNode *root, const char *word) {
    TrieNode *current = root;
    for (int level = 0; level < strlen(word); level++) {
        int index = tolower(word[level]) - 'a';
        if (!current->children[index]) {
            current->children[index] = calloc(1, sizeof(TrieNode));
        }
        current = current->children[index];
    }
    current->is_word = true;
}

bool search(const TrieNode *root, const char *word, int depth) {
    if (depth == strlen(word)) {
        return root->is_word;
    }

    TrieNode *current = root->children[tolower(word[depth]) - 'a'];
    if (!current) {
        return false;
    }

    return search(current, word, depth + 1);
}

bool check_word(const char *word) {
    TrieNode *root = calloc(1, sizeof(TrieNode));
    bool result = false;

    insert(root, word);
    result = search(root, word, 0);

    free(root);

    return result;
}

void free_trie(TrieNode *node) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            free_trie(node->children[i]);
        }
    }

    free(node);
}

int main() {
    int num_words;
    scanf("%d", &num_words);

    TrieNode *trie = calloc(1, sizeof(TrieNode));

    for (int i = 0; i < num_words; i++) {
        char word[50];
        scanf("%s", word);
        if (!check_word(word)) {
            printf("Invalid word: %s\n", word);
        }
    }

    free_trie(trie);

    return 0;
}