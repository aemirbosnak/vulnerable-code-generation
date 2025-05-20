//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_DICT_SIZE 100000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} Trie;

Trie* createTrie() {
    Trie* trie = (Trie*) malloc(sizeof(Trie));
    trie->head = NULL;
    trie->size = 0;
    return trie;
}

void insertWord(Trie* trie, char* word) {
    Node* node = trie->head;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        char c = tolower(word[i]);
        if (node->word[i]!= c) {
            node->word[i] = c;
            node->count++;
        }
        node = node->next;
    }
    trie->size++;
}

void deleteTrie(Trie* trie) {
    Node* node = trie->head;
    while (node!= NULL) {
        Node* temp = node->next;
        free(node);
        node = temp;
    }
    free(trie);
}

int isWordInDict(Trie* trie, char* word) {
    Node* node = trie->head;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        char c = tolower(word[i]);
        if (node->word[i]!= c) {
            return 0;
        }
        node = node->next;
    }
    return 1;
}

void spellCheck(Trie* trie, char* text) {
    char* word = strtok(text, " ");
    while (word!= NULL) {
        if (isWordInDict(trie, word)) {
            printf("%s\n", word);
        } else {
            printf("Possible spelling mistake: %s\n", word);
        }
        word = strtok(NULL, " ");
    }
}

int main() {
    Trie* trie = createTrie();
    FILE* dictFile = fopen("dictionary.txt", "r");
    char word[MAX_WORD_LEN];
    while (fscanf(dictFile, "%s", word)!= EOF) {
        insertWord(trie, word);
    }
    fclose(dictFile);

    char text[100000];
    printf("Enter text to spell check:\n");
    fgets(text, sizeof(text), stdin);
    spellCheck(trie, text);

    deleteTrie(trie);
    return 0;
}