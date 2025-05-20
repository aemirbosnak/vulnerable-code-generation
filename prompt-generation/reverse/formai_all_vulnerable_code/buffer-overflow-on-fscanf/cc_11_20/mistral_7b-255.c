//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int sentiment;
} Word;

Word sentiment_rules[] = {
    {"happy", 1},
    {"joyful", 1},
    {"excited", 1},
    {"love", 1},
    {"smile", 1},

    {"sad", -1},
    {"depressed", -1},
    {"miserable", -1},
    {"cry", -1},
    {"angry", -1},
    {"frustrated", -1},
    {"hate", -1},
    {"mad", -1},

    {"neutral", 0},
    {"good", 1},
    {"great", 1},
    {"fine", 1},
    {"okay", 1},
    {"calm", 0},
    {"peaceful", 0},
    {"quiet", 0},
    {"serene", 0},
    {"still", 0}
};

int main() {
    int num_words = 0;
    char word[WORD_LENGTH];
    int sentiment = 0;

    while (fscanf(stdin, "%s", word) != EOF) {
        int i;

        // Convert to lowercase
        for (i = 0; word[i]; i++)
            word[i] = tolower(word[i]);

        for (i = 0; i < sizeof(sentiment_rules) / sizeof(Word); i++) {
            if (strncmp(sentiment_rules[i].word, word, strlen(sentiment_rules[i].word)) == 0) {
                sentiment = sentiment_rules[i].sentiment;
                break;
            }
        }

        if (i == sizeof(sentiment_rules) / sizeof(Word)) {
            // Unknown word, assume neutral sentiment
            sentiment = 0;
        }

        num_words++;

        if (num_words % 10 == 0) {
            printf("Processed %d words. Current sentiment: %s\n", num_words, sentiment > 0 ? "Positive" : sentiment < 0 ? "Negative" : "Neutral");
        }
    }

    printf("\nFinal sentiment: %s\n", sentiment > 0 ? "Positive" : sentiment < 0 ? "Negative" : "Neutral");

    return 0;
}