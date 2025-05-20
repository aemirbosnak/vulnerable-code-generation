//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_VOCABULARY_SIZE 10000
#define UNKNOWN_WORD "UNKNOWN"

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Vocabulary;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void loadVocabulary(Vocabulary vocabulary[], int size) {
    FILE *file = fopen("vocabulary.txt", "r");
    if (file == NULL) {
        printf("Error loading vocabulary.\n");
        exit(1);
    }

    int count = 0;
    while (count < size && fscanf(file, "%s %s", vocabulary[count].english, vocabulary[count].alien) == 2) {
        count++;
    }

    fclose(file);

    qsort(vocabulary, count, sizeof(Vocabulary), compareWords);
}

char *translateSentence(char sentence[], Vocabulary vocabulary[], int size) {
    char *result = malloc(MAX_SENTENCE_LENGTH);
    strcpy(result, "");

    char word[MAX_WORD_LENGTH];
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        strcpy(word, token);
        WordFrequency frequency = {.word = word,.count = 0 };
        int index = binarySearch(vocabulary, size, frequency, compareWords);

        if (index!= -1) {
            strcat(result, vocabulary[index].alien);
            strcat(result, " ");
        } else {
            strcat(result, UNKNOWN_WORD);
            strcat(result, " ");
        }

        token = strtok(NULL, " ");
    }

    return result;
}

int binarySearch(Vocabulary vocabulary[], int size, WordFrequency frequency, int (*compare)(const void *, const void *)) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int cmp = compare(&frequency, &vocabulary[mid]);
        if (cmp == 0) {
            frequency.count++;
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    Vocabulary vocabulary[MAX_VOCABULARY_SIZE];
    loadVocabulary(vocabulary, MAX_VOCABULARY_SIZE);

    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence to translate: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    char *translation = translateSentence(sentence, vocabulary, MAX_VOCABULARY_SIZE);
    printf("Translation: %s\n", translation);

    free(translation);

    return 0;
}