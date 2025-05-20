//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000
#define MAX_WORD_LEN 100

typedef struct node {
    int count;
    char word[MAX_WORD_LEN];
} Node;

void build_trie(Node* root, char* word) {
    int len = strlen(word);
    Node* node = root;
    for (int i = 0; i < len; i++) {
        char c = word[i];
        if (node->word[i] == '\0') {
            node->word[i] = c;
            node->count++;
        }
        node = node->word[c];
    }
}

void search_trie(Node* root, char* word) {
    int len = strlen(word);
    Node* node = root;
    for (int i = 0; i < len; i++) {
        char c = word[i];
        if (node->word[c] == '\0') {
            break;
        }
        node = node->word[c];
    }
    if (node->word[len] == '\0') {
        printf("%s: %d\n", word, node->count);
    }
}

int main() {
    FILE* file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    char word[MAX_WORD_LEN];
    Node root = {0};
    while (fscanf(file, "%s", word)!= EOF) {
        build_trie(&root, word);
    }
    fclose(file);

    char search_word[MAX_WORD_LEN];
    while (1) {
        printf("Enter a word to search: ");
        fgets(search_word, MAX_WORD_LEN, stdin);
        search_word[strcspn(search_word, "\n")] = '\0';
        search_trie(&root, search_word);
    }
    return 0;
}