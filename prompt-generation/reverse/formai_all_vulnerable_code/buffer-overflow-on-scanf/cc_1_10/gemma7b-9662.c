//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SENTIMENT_WORDS 100

typedef struct SentimentWord {
    char word[MAX_SENTIMENT_WORDS];
    int sentiment_score;
} SentimentWord;

SentimentWord sentiment_words[MAX_SENTIMENT_WORDS] = {
    {"happy", 5},
    {"sad", -5},
    {"good", 4},
    {"bad", -4},
    {"excellent", 6},
    {"terrible", -6},
    // Add more words...
};

int sentiment_analyzer(char *sentence) {
    int i, score = 0;
    char word[MAX_SENTIMENT_WORDS];

    for (i = 0; i < MAX_SENTIMENT_WORDS && sentiment_words[i].word[0] != '\0'; i++) {
        strcpy(word, sentiment_words[i].word);
        if (strcmp(word, sentence) == 0) {
            score += sentiment_words[i].sentiment_score;
        }
    }

    return score;
}

int main() {
    char sentence[100];
    int sentiment_score;

    printf("Enter a sentence: ");
    scanf("%s", sentence);

    sentiment_score = sentiment_analyzer(sentence);

    if (sentiment_score > 0) {
        printf("The sentiment of the sentence is positive.\n");
    } else if (sentiment_score < 0) {
        printf("The sentiment of the sentence is negative.\n");
    } else {
        printf("The sentiment of the sentence is neutral.\n");
    }

    return 0;
}