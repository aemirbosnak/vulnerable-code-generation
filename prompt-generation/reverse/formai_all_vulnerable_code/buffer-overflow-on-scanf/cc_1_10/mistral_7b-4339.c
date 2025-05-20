//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    bool is_end_of_word;
    struct TrieNode* children[ALPHABET_SIZE];
};

void add_word(struct TrieNode* root, const char* word) {
    int length = strlen(word);
    struct TrieNode* current = root;

    for (int level = 0; level < length; level++) {
        int index = tolower(word[level]) - 'a';
        if (!current->children[index])
            current->children[index] = calloc(1, sizeof(struct TrieNode));

        current = current->children[index];
    }

    current->is_end_of_word = true;
}

bool search_word(struct TrieNode* root, const char* word, int length) {
    struct TrieNode* current = root;

    for (int level = 0; level < length; level++) {
        int index = tolower(word[level]) - 'a';

        if (!current->children[index])
            return false;

        current = current->children[index];
    }

    return current != NULL && current->is_end_of_word;
}

bool check_spell(const char* word) {
    int length = strlen(word);
    struct TrieNode root;
    memset(&root, 0, sizeof(root));

    add_word(&root, "magic");
    add_word(&root, "check");
    add_word(&root, word);

    return search_word(&root, word, length);
}

int main() {
    char user_input[100];

    printf("Welcome to MagicCheck, the magical spell checker! 🪄\n");
    printf("Please enter a word to check its spelling: ");
    scanf("%s", user_input);

    if (check_spell(user_input))
        printf("Congratulations! '%s' is spelled correctly. 🌟\n", user_input);
    else {
        printf("Uh-oh! '%s' is not spelled correctly. 😱\n", user_input);
        printf("Did you mean one of these suggestions?\n");
        // Implement suggestion feature here
    }

    return 0;
}