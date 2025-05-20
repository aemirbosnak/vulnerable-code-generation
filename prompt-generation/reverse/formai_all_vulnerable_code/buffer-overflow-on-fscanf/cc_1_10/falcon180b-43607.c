//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTIMENT_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int sentiment;
} SentimentWord;

SentimentWord sentimentWords[MAX_SENTIMENT_WORDS];
int numSentimentWords;

void loadSentimentWords(char* filename) {
    FILE* file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open sentiment words file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fscanf(file, "%s %d", line, &sentimentWords[numSentimentWords].sentiment)!= EOF) {
        strcpy(sentimentWords[numSentimentWords].word, line);
        numSentimentWords++;
    }

    fclose(file);
}

int getSentiment(char* word) {
    for (int i = 0; i < numSentimentWords; i++) {
        if (strcmp(sentimentWords[i].word, word) == 0) {
            return sentimentWords[i].sentiment;
        }
    }

    return 0;
}

void analyzeSentiment(char* text) {
    char word[MAX_WORD_LENGTH];
    char* token;
    int sentiment = 0;
    int numWords = 0;

    token = strtok(text, " ");
    while (token!= NULL) {
        strcpy(word, token);
        sentiment += getSentiment(word);
        numWords++;
        token = strtok(NULL, " ");
    }

    printf("Sentiment: %d\n", sentiment / numWords);
}

int main() {
    loadSentimentWords("sentiment_words.txt");

    char text[] = "I love this product. It is amazing!";
    analyzeSentiment(text);

    return 0;
}