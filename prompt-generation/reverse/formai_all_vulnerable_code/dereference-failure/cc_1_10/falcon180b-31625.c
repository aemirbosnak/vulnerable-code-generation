//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

// node structure for the trie
typedef struct node {
    int count;
    struct node *children[26];
} TrieNode;

// trie structure
TrieNode *trie = NULL;

// function to create a new node in the trie
TrieNode *create_node() {
    TrieNode *node = (TrieNode *) malloc(sizeof(TrieNode));
    node->count = 0;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// function to insert a word into the trie
void insert_word(char *word) {
    TrieNode *node = trie;
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        char c = toupper(word[i]);
        if (node->children[c - 'A'] == NULL) {
            node->children[c - 'A'] = create_node();
        }
        node = node->children[c - 'A'];
    }

    node->count++;
}

// function to traverse the trie and count the frequency of each word
void count_words(TrieNode *node, char *prefix, int prefix_length, FILE *output) {
    if (node == NULL) {
        return;
    }

    if (node->count > 0) {
        fprintf(output, "%s:%d\n", prefix, node->count);
    }

    for (int i = 0; i < 26; i++) {
        if (node->children[i]!= NULL) {
            char c = 'A' + i;
            count_words(node->children[i], prefix, prefix_length + 1, output);
        }
    }
}

// function to read a text file and count the frequency of each word
void count_file(char *filename, FILE *output) {
    FILE *input = fopen(filename, "r");

    if (input == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    TrieNode *node = trie;
    int prefix_length = 0;

    while (fscanf(input, "%s", word)!= EOF) {
        int length = strlen(word);

        for (int i = 0; i < length; i++) {
            char c = toupper(word[i]);

            if (node->children[c - 'A'] == NULL) {
                node->children[c - 'A'] = create_node();
            }

            node = node->children[c - 'A'];
        }

        node->count++;
    }

    fclose(input);

    count_words(trie, "", 0, output);

    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    trie = create_node();

    count_file(argv[1], argv[2]);

    return 0;
}