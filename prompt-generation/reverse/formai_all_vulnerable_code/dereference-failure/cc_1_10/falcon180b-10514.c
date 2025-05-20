//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency *words;
    int numWords;
} SentimentAnalysis;

void initSentimentAnalysis(SentimentAnalysis *analysis) {
    analysis->words = (WordFrequency *) malloc(MAX_WORDS * sizeof(WordFrequency));
    analysis->numWords = 0;
}

void freeSentimentAnalysis(SentimentAnalysis *analysis) {
    free(analysis->words);
}

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *) a;
    WordFrequency *wordB = (WordFrequency *) b;

    return strcmp(wordA->word, wordB->word);
}

void analyzeSentiment(char *sentence, SentimentAnalysis *analysis) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int wordLength = strlen(token);
        if (wordLength > MAX_WORD_LENGTH) {
            wordLength = MAX_WORD_LENGTH;
        }

        WordFrequency *word = (WordFrequency *) malloc(sizeof(WordFrequency));
        strncpy(word->word, token, wordLength);
        word->word[wordLength] = '\0';
        word->frequency = 1;

        int index = 0;
        while (index < analysis->numWords && strcmp(analysis->words[index].word, word->word) < 0) {
            index++;
        }

        if (index == analysis->numWords) {
            analysis->words[analysis->numWords++] = *word;
            qsort(analysis->words, analysis->numWords, sizeof(WordFrequency), compareWords);
        } else {
            free(word);
        }

        token = strtok(NULL, " ");
    }
}

void printSentimentAnalysis(SentimentAnalysis *analysis) {
    for (int i = 0; i < analysis->numWords; i++) {
        printf("%s: %d\n", analysis->words[i].word, analysis->words[i].frequency);
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    SentimentAnalysis analysis;
    initSentimentAnalysis(&analysis);
    analyzeSentiment(sentence, &analysis);
    printSentimentAnalysis(&analysis);

    freeSentimentAnalysis(&analysis);

    return 0;
}