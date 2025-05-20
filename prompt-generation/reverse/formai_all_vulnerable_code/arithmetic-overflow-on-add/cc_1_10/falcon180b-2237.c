//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

// Node structure for the trie
typedef struct node {
    int count;
    struct node *children[26];
} Node;

// Trie structure
Node *root = NULL;

// Function to create a new node
Node* newNode() {
    Node *node = (Node *)malloc(sizeof(Node));
    node->count = 0;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Function to insert a word into the trie
void insert(char *word) {
    Node *node = root;
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        int index = word[i] - 'a';
        if (node->children[index] == NULL) {
            node->children[index] = newNode();
        }
        node = node->children[index];
    }

    node->count++;
}

// Function to print the frequency of a word
void printFrequency(char *word) {
    Node *node = root;
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        int index = word[i] - 'a';
        if (node->children[index] == NULL) {
            printf("Word not found\n");
            return;
        }
        node = node->children[index];
    }

    printf("Frequency of '%s': %d\n", word, node->count);
}

// Function to delete the trie
void deleteTrie() {
    Node *node = root;
    Node *temp;

    while (node!= NULL) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i]!= NULL) {
                temp = node->children[i];
                while (temp->count == 0 && temp->children[0] == NULL) {
                    temp = temp->children[0];
                }
                node->children[i] = temp;
            }
        }
        temp = node;
        node = node->children[0];
        free(temp);
    }
}

// Main function
int main() {
    // Insert words
    insert("hello");
    insert("world");
    insert("hi");
    insert("bye");

    // Print frequency of words
    printFrequency("hello");
    printFrequency("world");
    printFrequency("hi");
    printFrequency("bye");

    // Delete the trie
    deleteTrie();

    return 0;
}