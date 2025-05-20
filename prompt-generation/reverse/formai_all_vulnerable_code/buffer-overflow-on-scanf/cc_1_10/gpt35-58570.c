//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SENTIMENT_POSITIVE "positive"
#define SENTIMENT_NEGATIVE "negative"
#define SENTIMENT_NEUTRAL "neutral"

int analyze_sentiment(char *input) {
    int positive_words = 0;
    int negative_words = 0;

    const char *positive_word_list[] = {"happy", "excited", "love", "fun", "success"};
    const char *negative_word_list[] = {"sad", "depressed", "hate", "failure", "anger"};

    char *copy_input = strdup(input);
    char *token = strtok(copy_input, " ");

    while (token != NULL) {
        for (int i = 0; i < sizeof(positive_word_list)/sizeof(positive_word_list[0]); i++) {
            if (strcmp(token, positive_word_list[i]) == 0) {
                positive_words++;
                break;
            }
        }

        for (int i = 0; i < sizeof(negative_word_list)/sizeof(negative_word_list[0]); i++) {
            if (strcmp(token, negative_word_list[i]) == 0) {
                negative_words++;
                break;
            }
        }

        token = strtok(NULL, " ");
    }

    free(copy_input);

    if (positive_words > negative_words) {
        return SENTIMENT_POSITIVE;
    } else if (negative_words > positive_words) {
        return SENTIMENT_NEGATIVE;
    } else {
        return SENTIMENT_NEUTRAL;
    }
}

int main() {
    char input[100];

    printf("Enter your sentence: ");
    scanf("%[^\n]s", input);

    int sentiment = analyze_sentiment(input);

    printf("The sentiment of your sentence is %s\n", sentiment);

    return 0;
}