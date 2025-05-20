//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define MAX_SENTENCES 1000
#define MAX_WORDS 10000

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount *words;
    int numWords;
    int numSentences;
} SentimentAnalysis;

void initializeWords(SentimentAnalysis *analysis) {
    analysis->words = (WordCount *)malloc(MAX_WORDS * sizeof(WordCount));
    analysis->numWords = 0;
    analysis->numSentences = 0;
}

void addWord(SentimentAnalysis *analysis, char *word) {
    int i;
    for (i = 0; i < analysis->numWords; i++) {
        if (strcmp(analysis->words[i].word, word) == 0) {
            analysis->words[i].count++;
            return;
        }
    }
    WordCount *newWord = (WordCount *)malloc(sizeof(WordCount));
    strcpy(newWord->word, word);
    newWord->count = 1;
    analysis->words[analysis->numWords++] = *newWord;
}

void analyzeSentence(SentimentAnalysis *analysis, char *sentence) {
    char *token;
    char *rest = strdup(sentence);
    token = strtok_r(rest, ",.?!;:\"'", &rest);
    while (token!= NULL) {
        addWord(analysis, token);
        token = strtok_r(rest, ",.?!;:\"'", &rest);
    }
    free(rest);
}

void printTopWords(SentimentAnalysis *analysis) {
    int i;
    for (i = 0; i < analysis->numWords; i++) {
        if (analysis->words[i].count > 0) {
            printf("%s: %d\n", analysis->words[i].word, analysis->words[i].count);
        }
    }
}

int main() {
    SentimentAnalysis analysis;
    initializeWords(&analysis);

    char sentence[MAX_SENTENCE_LENGTH];
    int numSentences = 0;

    while (fgets(sentence, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        if (numSentences >= MAX_SENTENCES) {
            printf("Error: Too many sentences.\n");
            exit(1);
        }
        analyzeSentence(&analysis, sentence);
        numSentences++;
    }

    printTopWords(&analysis);

    return 0;
}