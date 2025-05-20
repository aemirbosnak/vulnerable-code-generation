//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define MAX_NUMBER 1000

int main() {
    int numOfWords = 0;
    char word[MAX_LENGTH];
    char *words[MAX_NUMBER];
    int i, j, k;

    // Generate a random word
    srand(time(NULL));
    for (i = 0; i < MAX_NUMBER; i++) {
        words[i] = malloc(MAX_LENGTH * sizeof(char));
        for (j = 0; j < MAX_LENGTH; j++) {
            words[i][j] = 'a' + (rand() % 26);
        }
        words[i][MAX_LENGTH] = '\0';
    }

    // Create a trie data structure
    struct trie {
        char *word;
        struct trie *children[26];
    };
    struct trie *root = NULL;

    // Insert words into the trie
    for (i = 0; i < MAX_NUMBER; i++) {
        struct trie *current = root;
        for (j = 0; j < MAX_LENGTH; j++) {
            int index = words[i][j] - 'a';
            if (current->children[index] == NULL) {
                current->children[index] = malloc(sizeof(struct trie));
                current = current->children[index];
            }
            current = current->children[index];
        }
        current->word = words[i];
    }

    // Search for all words in the trie
    for (i = 0; i < MAX_NUMBER; i++) {
        struct trie *current = root;
        char search[MAX_LENGTH];
        int j = 0;

        // Search for the word
        while (current != NULL && j < MAX_LENGTH) {
            if (words[i][j] == current->word[j]) {
                j++;
                current = current->children[words[i][j] - 'a'];
            } else {
                break;
            }
        }

        // Print the found words
        if (current != NULL) {
            printf("%s\n", current->word);
        }
    }

    // Free memory
    for (i = 0; i < MAX_NUMBER; i++) {
        free(words[i]);
    }
    free(root);

    return 0;
}