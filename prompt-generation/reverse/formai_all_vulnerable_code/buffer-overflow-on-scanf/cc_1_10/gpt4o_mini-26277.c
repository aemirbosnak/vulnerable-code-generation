//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT 10000
#define MAX_WORD_LENGTH 100
#define HASH_SIZE 1000

typedef struct WordCount {
    char word[MAX_WORD_LENGTH];
    int count;
    struct WordCount* next;
} WordCount;

WordCount* hashTable[HASH_SIZE];

unsigned int hash(const char* word) {
    unsigned int hashValue = 0;
    while (*word) {
        hashValue += tolower(*word) - 'a';
        word++;
    }
    return hashValue % HASH_SIZE;
}

void insertWord(const char* word) {
    unsigned int index = hash(word);
    WordCount* newWord = malloc(sizeof(WordCount));
    strcpy(newWord->word, word);
    newWord->count = 1;
    newWord->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newWord;
    } else {
        WordCount* current = hashTable[index];
        while (current != NULL) {
            if (strcmp(current->word, word) == 0) {
                current->count++;
                free(newWord);
                return;
            }
            if (current->next == NULL) break;
            current = current->next;
        }
        current->next = newWord;
    }
}

void printSummary(int topN) {
    WordCount* allWords[HASH_SIZE];
    int count = 0;

    for (int i = 0; i < HASH_SIZE; i++) {
        if (hashTable[i] != NULL) {
            WordCount* current = hashTable[i];
            while (current != NULL) {
                allWords[count++] = current;
                current = current->next;
            }
        }
    }

    // Simple bubble sort based on word count (to find top N frequent words)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (allWords[j]->count < allWords[j + 1]->count) {
                WordCount* temp = allWords[j];
                allWords[j] = allWords[j + 1];
                allWords[j + 1] = temp;
            }
        }
    }

    printf("Top %d words:\n", topN);
    for (int i = 0; i < topN && i < count; i++) {
        printf("%s: %d\n", allWords[i]->word, allWords[i]->count);
    }
}

void freeHashTable() {
    for (int i = 0; i < HASH_SIZE; i++) {
        WordCount* current = hashTable[i];
        while (current != NULL) {
            WordCount* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

void summarizeText(const char* text, int topN) {
    char* token;
    char* textCopy = strdup(text);
    token = strtok(textCopy, " .,;!?\"\n");

    while (token != NULL) {
        if (strlen(token) > 0) {
            insertWord(token);
        }
        token = strtok(NULL, " .,;!?\"\n");
    }
    free(textCopy);
    printSummary(topN);
}

int main() {
    char text[MAX_TEXT];

    printf("Enter the text to be summarized (max %d characters):\n", MAX_TEXT);
    fgets(text, sizeof(text), stdin);

    int topN;
    printf("How many top frequent words would you like to see? ");
    scanf("%d", &topN);

    summarizeText(text, topN);
    freeHashTable();

    return 0;
}