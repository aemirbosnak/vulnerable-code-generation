//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_VOCABULARY_SIZE 10000
#define UNKNOWN_WORD "<UNKNOWN>"

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Vocabulary;

Vocabulary vocabulary[MAX_VOCABULARY_SIZE];
int vocabularySize = 0;

void loadVocabulary(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading vocabulary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fscanf(file, "%s %s", line, line) == 2) {
        strcpy(vocabulary[vocabularySize].english, line);
        strcpy(vocabulary[vocabularySize].alien, line);
        vocabularySize++;
        if (vocabularySize >= MAX_VOCABULARY_SIZE) {
            printf("Vocabulary limit reached.\n");
            exit(1);
        }
    }

    fclose(file);
}

int binarySearch(Vocabulary vocabulary[], int size, char* word) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int cmp = strcmp(word, vocabulary[mid].english);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}

void translateSentence(char* sentence) {
    char word[MAX_WORD_LENGTH];
    char alienWord[MAX_WORD_LENGTH];
    int i = 0;

    while (i < strlen(sentence)) {
        if (isspace(sentence[i])) {
            sentence[i] = '\0';
            int wordIndex = binarySearch(vocabulary, vocabularySize, word);

            if (wordIndex == -1) {
                strcpy(alienWord, UNKNOWN_WORD);
            } else {
                strcpy(alienWord, vocabulary[wordIndex].alien);
            }

            printf("%s -> %s\n", word, alienWord);
            i += strlen(word) + 1;
            memset(word, 0, sizeof(word));
        } else {
            strncat(word, &sentence[i], 1);
            i++;
        }
    }
}

int main() {
    loadVocabulary("vocabulary.txt");

    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence to translate: ");
    fgets(sentence, sizeof(sentence), stdin);

    translateSentence(sentence);

    return 0;
}