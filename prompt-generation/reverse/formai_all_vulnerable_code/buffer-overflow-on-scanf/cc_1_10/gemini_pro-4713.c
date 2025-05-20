//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

// Create a node for the Trie
typedef struct TrieNode {
    char letter;
    struct TrieNode *children[26];
    int is_word;
} TrieNode;

// Create a new Trie node
TrieNode *create_trie_node(char letter) {
    TrieNode *node = malloc(sizeof(TrieNode));
    node->letter = letter;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->is_word = 0;
    return node;
}

// Insert a word into the Trie
void insert_word(TrieNode *root, char *word) {
    TrieNode *current = root;
    int index;
    for (int i = 0; i < strlen(word); i++) {
        index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = create_trie_node(word[i]);
        }
        current = current->children[index];
    }
    current->is_word = 1;
}

// Check if a word is in the Trie
int is_word_in_trie(TrieNode *root, char *word) {
    TrieNode *current = root;
    int index;
    for (int i = 0; i < strlen(word); i++) {
        index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current->is_word;
}

// Get the closest word to the given word from the Trie
char *get_closest_word(TrieNode *root, char *word) {
    TrieNode *current = root;
    char *closest_word = malloc(sizeof(char) * MAX_WORD_LENGTH);
    int index;
    for (int i = 0; i < strlen(word); i++) {
        index = word[i] - 'a';
        if (current->children[index] != NULL) {
            closest_word[i] = word[i];
            current = current->children[index];
        } else {
            break;
        }
    }
    while (current != NULL && current->is_word == 0) {
        for (int i = 0; i < 26; i++) {
            if (current->children[i] != NULL) {
                closest_word[strlen(closest_word)] = current->children[i]->letter;
                current = current->children[i];
                break;
            }
        }
    }
    if (current != NULL && current->is_word == 1) {
        return closest_word;
    } else {
        return NULL;
    }
}

// Load the dictionary into the Trie
TrieNode *load_dictionary(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }
    TrieNode *root = create_trie_node(' ');
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        insert_word(root, word);
    }
    fclose(file);
    return root;
}

// Spell check a word
char *spell_check(TrieNode *root, char *word) {
    if (is_word_in_trie(root, word)) {
        return word;
    } else {
        return get_closest_word(root, word);
    }
}

// Get the user input
char *get_user_input() {
    char *input = malloc(sizeof(char) * MAX_WORD_LENGTH);
    printf("Enter a word to spell check: ");
    scanf("%s", input);
    return input;
}

// Print the results
void print_results(char *word, char *closest_word) {
    if (closest_word == NULL) {
        printf("The word \"%s\" is not in the dictionary.\n", word);
    } else {
        printf("The closest word to \"%s\" in the dictionary is \"%s\".\n", word, closest_word);
    }
}

int main() {
    TrieNode *root = load_dictionary("dictionary.txt");
    char *word = get_user_input();
    char *closest_word = spell_check(root, word);
    print_results(word, closest_word);
    return 0;
}