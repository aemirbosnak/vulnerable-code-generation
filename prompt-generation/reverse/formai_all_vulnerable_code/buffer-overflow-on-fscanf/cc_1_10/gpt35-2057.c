//FormAI DATASET v1.0 Category: Spell checking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DICTIONARY "dictionary.txt"

// Define node structure for the HashTable
typedef struct Node {
    char word[50];
    struct Node* next;
} Node;

// Initialize HashTable with 500 buckets
Node* hashTable[500];

// Hash Function using Bernstein Hash Algorithm
unsigned long hash(char* str) {
    unsigned long hashValue = 5381;
    int c;
    while ((c = *str++)) {
        hashValue = ((hashValue << 5) + hashValue) + c;
    }
    return hashValue % 500;
}

// Insert word into HashTable
void insert(char* word) {
    int index = hash(word);
    Node* newNode = (Node*) malloc(sizeof(Node));
    strncpy(newNode->word, word, 50);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Returns true if word is in dictionary, false otherwise
int check(char* word) {
    int index = hash(word);
    for (Node* node = hashTable[index]; node != NULL; node = node->next) {
        if (strcmp(word, node->word) == 0) {
            return 1;
        }
    }
    return 0;
}

// Check the spelling of text file and print misspelled words
void spellCheck(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    char word[50];
    char c;
    int i = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            word[i] = tolower(c);
            i++;
        }
        else if (i > 0) {
            word[i] = '\0';
            if (!check(word)) {
                printf("%s\n", word);
            }
            i = 0;
        }
    }
    fclose(fp);
}

int main() {
    // Load dictionary file into HashTable
    FILE* dict = fopen(DICTIONARY, "r");
    if (dict == NULL) {
        printf("Error opening file %s\n", DICTIONARY);
        return 1;
    }
    char word[50];
    while (fscanf(dict, "%s", word) != EOF) {
        insert(word);
    }
    fclose(dict);

    // Prompt user for text file to spell check
    char filename[50];
    printf("Enter file name: ");
    scanf("%s", filename);

    // Perform spell check on text file
    spellCheck(filename);

    return 0;
}