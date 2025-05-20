//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOCABULARY 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Vocabulary;

typedef struct {
    Vocabulary *vocabulary;
    int size;
} VocabularyList;

void initVocabularyList(VocabularyList *list) {
    list->vocabulary = (Vocabulary *)malloc(MAX_VOCABULARY * sizeof(Vocabulary));
    list->size = 0;
}

void addVocabulary(VocabularyList *list, char *word) {
    Vocabulary *vocab = &list->vocabulary[list->size];
    strcpy(vocab->word, word);
    vocab->frequency = 1;
    list->size++;
}

int compareVocabulary(const void *a, const void *b) {
    Vocabulary *vocabA = (Vocabulary *)a;
    Vocabulary *vocabB = (Vocabulary *)b;

    if (vocabA->frequency > vocabB->frequency)
        return -1;
    else if (vocabA->frequency < vocabB->frequency)
        return 1;
    else
        return 0;
}

void sortVocabularyList(VocabularyList *list) {
    qsort(list->vocabulary, list->size, sizeof(Vocabulary), compareVocabulary);
}

void printVocabularyList(VocabularyList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%s %d\n", list->vocabulary[i].word, list->vocabulary[i].frequency);
    }
}

int main() {
    VocabularyList vocabularyList;
    initVocabularyList(&vocabularyList);

    char input[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter a word: ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        addVocabulary(&vocabularyList, input);
    }

    sortVocabularyList(&vocabularyList);
    printVocabularyList(&vocabularyList);

    return 0;
}