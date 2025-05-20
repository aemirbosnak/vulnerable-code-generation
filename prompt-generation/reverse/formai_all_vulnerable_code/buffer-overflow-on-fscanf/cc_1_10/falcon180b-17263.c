//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 100
#define MIN_SENTENCE_LENGTH 5

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

void readSentences(Sentence sentences[], int maxSentences, FILE *fp) {
    int i = 0;
    char ch;
    Sentence currentSentence = {0};

    while (i < maxSentences && fscanf(fp, "%c", &ch)!= EOF) {
        if (ch == '.' || ch == '!' || ch == '?') {
            currentSentence.length = strlen(currentSentence.sentence);
            if (currentSentence.length >= MIN_SENTENCE_LENGTH) {
                strcpy(sentences[i].sentence, currentSentence.sentence);
                sentences[i].length = currentSentence.length;
                i++;
            }
            memset(currentSentence.sentence, 0, MAX_SENTENCE_LENGTH);
        } else if (isalpha(ch)) {
            strncat(currentSentence.sentence, &ch, 1);
        }
    }
}

void countWords(Sentence sentences[], int numSentences, WordFrequency wordFrequencies[], int maxWordFrequencies) {
    int i, j, k;

    for (i = 0; i < numSentences; i++) {
        char *token = strtok(sentences[i].sentence, ",.?!;:");
        while (token!= NULL) {
            for (j = 0; j < i; j++) {
                if (strcmp(token, sentences[j].sentence) == 0) {
                    wordFrequencies[j].count++;
                    break;
                }
            }
            if (j == i) {
                for (k = 0; k < maxWordFrequencies; k++) {
                    if (wordFrequencies[k].count == 0) {
                        strcpy(wordFrequencies[k].word, token);
                        wordFrequencies[k].count = 1;
                        break;
                    }
                }
            }
            token = strtok(NULL, ",.?!;:");
        }
    }
}

void printSummary(WordFrequency wordFrequencies[], int numWordFrequencies) {
    int i;

    for (i = 0; i < numWordFrequencies; i++) {
        if (wordFrequencies[i].count > 0) {
            printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    Sentence sentences[MAX_SENTENCES];
    WordFrequency wordFrequencies[MAX_WORD_LENGTH];
    int numSentences = 0, numWordFrequencies = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    readSentences(sentences, MAX_SENTENCES, fp);
    fclose(fp);

    countWords(sentences, numSentences, wordFrequencies, MAX_WORD_LENGTH);

    printSummary(wordFrequencies, numWordFrequencies);

    return 0;
}