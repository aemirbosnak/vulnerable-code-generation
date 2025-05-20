//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define HASH_TABLE_SIZE 1000

typedef struct Node {
    char word[MAX_WORD_LENGTH];
    int count;
    struct Node* next;
} Node;

Node* hashTable[HASH_TABLE_SIZE];

unsigned int hash(const char* word) {
    unsigned int hashValue = 0;
    while (*word) {
        hashValue = (hashValue << 5) + *word++;
    }
    return hashValue % HASH_TABLE_SIZE;
}

void insertWord(const char* word) {
    unsigned int index = hash(word);
    Node* current = hashTable[index];

    // Check if the word already exists
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }

    // Create a new node and insert it at the beginning of the list
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

void printWordFrequencies() {
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Node* current = hashTable[i];
        while (current != NULL) {
            printf("%s: %d\n", current->word, current->count);
            current = current->next;
        }
    }
}

void freeMemory() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Node* current = hashTable[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

void processFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        // Remove punctuation and convert to lowercase
        char cleanedWord[MAX_WORD_LENGTH];
        int j = 0;
        for (int i = 0; word[i] != '\0'; i++) {
            if (isalpha(word[i])) {
                cleanedWord[j++] = tolower(word[i]);
            }
        }
        cleanedWord[j] = '\0';
        
        // Insert the cleaned word into the hash table
        if (j > 0) {
            insertWord(cleanedWord);
        }
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    processFile(argv[1]);
    printWordFrequencies();
    freeMemory();

    return 0;
}