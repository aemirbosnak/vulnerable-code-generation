//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define HASH_SIZE 1000

typedef struct WordCount {
    char word[MAX_WORD_LENGTH];
    int count;
    struct WordCount *next;
} WordCount;

WordCount *hashTable[HASH_SIZE];

unsigned int hashFunction(const char *word) {
    unsigned int hash = 0;
    while (*word) {
        hash = (hash << 5) + *word++;
    }
    return hash % HASH_SIZE;
}

WordCount *createWordCountNode(const char *word) {
    WordCount *newNode = (WordCount *)malloc(sizeof(WordCount));
    if (newNode != NULL) {
        strncpy(newNode->word, word, MAX_WORD_LENGTH);
        newNode->count = 1;
        newNode->next = NULL;
    }
    return newNode;
}

void insertOrUpdateWord(const char *word) {
    unsigned int index = hashFunction(word);
    WordCount *current = hashTable[index];

    while (current) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }

    WordCount *newNode = createWordCountNode(word);
    if (newNode) {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

void convertToLower(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

void cleanup() {
    for (int i = 0; i < HASH_SIZE; i++) {
        WordCount *current = hashTable[i];
        while (current) {
            WordCount *temp = current;
            current = current->next;
            free(temp);
        }
    }
}

void printWordCounts() {
    printf("\nWord Frequency Count:\n");
    printf("----------------------------------\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        WordCount *current = hashTable[i];
        while (current) {
            printf("%-20s : %d\n", current->word, current->count);
            current = current->next;
        }
    }
}

void analyzeTextFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char word[MAX_WORD_LENGTH];
    
    while (fscanf(file, "%s", word) == 1) {
        convertToLower(word);
        insertOrUpdateWord(word);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    memset(hashTable, 0, sizeof(hashTable));
    
    analyzeTextFile(argv[1]);
    printWordCounts();
    
    cleanup();

    return EXIT_SUCCESS;
}