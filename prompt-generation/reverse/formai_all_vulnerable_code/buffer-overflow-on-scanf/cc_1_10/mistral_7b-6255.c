//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int is_end_of_word;
} TrieNode;

TrieNode* createNode() {
    TrieNode *node = (TrieNode*) malloc(sizeof(TrieNode));
    node->is_end_of_word = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(TrieNode *root, const char *word) {
    TrieNode *current = root;
    for (int level = 0; level < strlen(word); level++) {
        int index = tolower(word[level]) - 'a';
        if (!current->children[index]) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    current->is_end_of_word = 1;
}

int search(TrieNode *root, const char *word) {
    TrieNode *current = root;
    for (int level = 0; level < strlen(word); level++) {
        int index = tolower(word[level]) - 'a';
        if (!current->children[index]) {
            return 0;
        }
        current = current->children[index];
    }
    return current != NULL && current->is_end_of_word;
}

int hasPrefix(TrieNode *root, const char *prefix) {
    TrieNode *current = root;
    for (int level = 0; level < strlen(prefix); level++) {
        int index = tolower(prefix[level]) - 'a';
        if (!current->children[index]) {
            return 0;
        }
        current = current->children[index];
    }
    return 1;
}

int spellCheck(TrieNode *root, const char *word) {
    if (search(root, word)) {
        return 1;
    }
    int prefix = hasPrefix(root, word);
    if (prefix) {
        int length = strlen(word);
        for (int i = length - 1; i >= 0; i--) {
            if (isalpha(word[i])) {
                char temp[length];
                strncpy(temp, word, i);
                temp[i] = '\0';
                if (search(root, temp)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    int num_words;
    scanf("%d", &num_words);

    TrieNode *root = createNode();
    for (int i = 0; i < num_words; i++) {
        char word[50];
        scanf("%s", word);
        insert(root, word);
    }

    char query[50];
    while (1) {
        printf("Enter a word to check or type 'quit' to exit: ");
        scanf("%s", query);
        if (strcmp(query, "quit") == 0) {
            break;
        }
        int result = spellCheck(root, query);
        if (result) {
            printf("The word '%s' is spelled correctly.\n", query);
        } else {
            printf("The word '%s' is not in the dictionary.\n", query);
        }
    }

    return 0;
}