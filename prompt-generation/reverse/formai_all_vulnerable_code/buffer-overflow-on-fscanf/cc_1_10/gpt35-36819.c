//FormAI DATASET v1.0 Category: Spell checking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50
#define DICTIONARY_SIZE 100000

struct Node {
    char word[MAX_WORD_SIZE];
    struct Node* next;
};

struct Node* dictionary[DICTIONARY_SIZE];

unsigned int hash(char* word) {
    unsigned int hash = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash += (word[i] * i);
    }
    return hash % DICTIONARY_SIZE;
}

void insert(char* word) {
    unsigned int index = hash(word);
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    strcpy(node->word, word);
    node->next = dictionary[index];
    dictionary[index] = node;
}

int contains(char* word) {
    unsigned int index = hash(word);
    struct Node* curr = dictionary[index];
    while (curr != NULL) {
        if (strcmp(curr->word, word) == 0) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

int main() {
    FILE* textFile = fopen("sample_text.txt", "r");
    FILE* dictFile = fopen("dictionary.txt", "r");

    if (textFile == NULL || dictFile == NULL) {
        printf("Could not open files\n");
        return 1;
    }

    // Load dictionary into hash table
    char dictWord[MAX_WORD_SIZE];
    while (fscanf(dictFile, "%s", dictWord) != EOF) {
        insert(dictWord);
    }

    // Check each word in text file for spelling errors
    char textWord[MAX_WORD_SIZE];
    int line = 1;
    while (fscanf(textFile, "%s", textWord) != EOF) {
        for (int i = 0; i < strlen(textWord); i++) {
            if (!isalpha(textWord[i])) {
                // Ignore non-alphabetic characters
                continue;
            }
            if (!contains(textWord)) {
                printf("Error: Word '%s' on line %d is misspelled\n", textWord, line);
                break;
            }
        }
        if (textWord[strlen(textWord)-1] == '\n') {
            line++;
        }
    }

    fclose(textFile);
    fclose(dictFile);
    return 0;
}