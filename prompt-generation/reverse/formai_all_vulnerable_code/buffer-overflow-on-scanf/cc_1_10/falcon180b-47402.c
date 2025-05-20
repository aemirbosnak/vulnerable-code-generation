//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_VOCABULARY_SIZE 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency vocabulary[MAX_VOCABULARY_SIZE];
    int size;
} Vocabulary;

void initializeVocabulary(Vocabulary* vocabulary) {
    vocabulary->size = 0;
}

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*)a;
    const WordFrequency* wordB = (const WordFrequency*)b;

    return strcmp(wordA->word, wordB->word);
}

void addWord(Vocabulary* vocabulary, const char* word) {
    WordFrequency* newWord = (WordFrequency*)malloc(sizeof(WordFrequency));

    if (newWord == NULL) {
        printf("Out of memory.\n");
        exit(1);
    }

    strcpy(newWord->word, word);
    newWord->frequency = 1;

    qsort(vocabulary->vocabulary, vocabulary->size, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < vocabulary->size; i++) {
        if (strcmp(newWord->word, vocabulary->vocabulary[i].word) == 0) {
            vocabulary->vocabulary[i].frequency++;
            free(newWord);
            return;
        }
    }

    vocabulary->vocabulary[vocabulary->size++] = *newWord;
}

void printVocabulary(Vocabulary* vocabulary) {
    for (int i = 0; i < vocabulary->size; i++) {
        printf("%s: %d\n", vocabulary->vocabulary[i].word, vocabulary->vocabulary[i].frequency);
    }
}

int main() {
    char input[MAX_WORD_LENGTH];
    Vocabulary vocabulary;

    initializeVocabulary(&vocabulary);

    while (1) {
        printf("Enter a word: ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        addWord(&vocabulary, input);
    }

    printVocabulary(&vocabulary);

    return 0;
}