//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LEN 30

struct trie_node {
    int is_word;
    struct trie_node *children[26];
};

struct trie_node *create_node() {
    struct trie_node *node = (struct trie_node *)malloc(sizeof(struct trie_node));
    memset(node->children, 0, sizeof(node->children));
    node->is_word = 0;
    return node;
}

void insert_word(struct trie_node *root, char *word) {
    struct trie_node *node = root;
    int len = strlen(word);

    for (int i = 0; i < len; i++) {
        int index = tolower(word[i]) - 'a';
        if (node->children[index] == NULL) {
            node->children[index] = create_node();
        }
        node = node->children[index];
    }

    node->is_word = 1;
}

int search_word(struct trie_node *root, char *word) {
    struct trie_node *node = root;
    int len = strlen(word);

    for (int i = 0; i < len; i++) {
        int index = tolower(word[i]) - 'a';
        if (node->children[index] == NULL) {
            return 0;
        }
        node = node->children[index];
    }

    return node->is_word;
}

int main() {
    char word[MAX_WORD_LEN];
    char line[100];
    FILE *dict_file = fopen("dictionary.txt", "r");
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    struct trie_node *root = create_node();

    while (fscanf(dict_file, "%s", word)!= EOF) {
        insert_word(root, word);
    }

    fclose(dict_file);

    while (fscanf(input_file, "%s", line)!= EOF) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (search_word(root, token) == 0) {
                fprintf(output_file, "%s\n", token);
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}