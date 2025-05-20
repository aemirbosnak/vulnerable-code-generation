//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define MAX_SENTENCE_LEN 100
#define MAX_VOCABULARY_SIZE 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Vocabulary;

Vocabulary vocabulary[MAX_VOCABULARY_SIZE];
int vocabularyCount = 0;

void loadVocabulary(char *filename) {
    FILE *fp;
    char line[MAX_WORD_LEN];
    char word[MAX_WORD_LEN];
    int count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    while (fscanf(fp, "%s %d", word, &count)!= EOF) {
        strcpy(vocabulary[vocabularyCount].word, word);
        vocabulary[vocabularyCount].count = count;
        vocabularyCount++;
    }

    fclose(fp);
}

int getVocabularyIndex(char *word) {
    int i;

    for (i = 0; i < vocabularyCount; i++) {
        if (strcmp(word, vocabulary[i].word) == 0) {
            return i;
        }
    }

    return -1;
}

void generateSentence(char *sentence, int length) {
    int i, j;
    char word[MAX_WORD_LEN];
    int wordIndex;

    for (i = 0; i < length; i++) {
        if (i == 0) {
            wordIndex = rand() % vocabularyCount;
        } else {
            wordIndex = getVocabularyIndex(sentence + (i - 1));
        }

        strcpy(word, vocabulary[wordIndex].word);
        strcat(sentence, word);
        strcat(sentence, " ");
    }
}

int main() {
    char sentence[MAX_SENTENCE_LEN];
    int length;

    printf("Enter the length of the sentence: ");
    scanf("%d", &length);

    loadVocabulary("vocabulary.txt");

    generateSentence(sentence, length);

    printf("Generated sentence: %s\n", sentence);

    return 0;
}