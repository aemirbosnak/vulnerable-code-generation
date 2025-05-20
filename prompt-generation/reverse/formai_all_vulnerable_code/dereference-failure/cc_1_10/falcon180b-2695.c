//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORDS 1000
#define POSITIVE 1
#define NEGATIVE -1
#define NEUTRAL 0

typedef struct {
    char *word;
    int sentiment;
} WordSentiment;

int getSentiment(char *sentence) {
    int length = strlen(sentence);
    int i = 0;
    int sentiment = 0;
    char *word = malloc(MAX_SENTENCE_LENGTH);

    while (i < length) {
        if (isalpha(sentence[i])) {
            strncpy(word, &sentence[i], MAX_SENTENCE_LENGTH);
            word[strcspn(word, " ")] = '\0';
            if (strlen(word) > 0) {
                sentiment += getWordSentiment(word);
            }
        }
        i++;
    }

    free(word);
    return sentiment;
}

int getWordSentiment(char *word) {
    int length = strlen(word);
    int i = 0;
    int sentiment = 0;

    while (i < length) {
        if (isalpha(word[i])) {
            sentiment += tolower(word[i]) - 'a' + 1;
        }
        i++;
    }

    return sentiment;
}

void printSentiment(int sentiment) {
    if (sentiment > 0) {
        printf("Positive\n");
    } else if (sentiment < 0) {
        printf("Negative\n");
    } else {
        printf("Neutral\n");
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    int sentiment = getSentiment(sentence);
    printSentiment(sentiment);
    return 0;
}