//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define NUM_SENTIMENTS 6

typedef struct {
    char *name;
    int value;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {{"joy", 1}, {"sadness", -1}, {"anger", -1}, {"fear", -1}, {"disgust", -1}, {"surprise", 1}};

int get_sentiment_value(char *sentiment_name) {
    int i;
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (strcmp(sentiments[i].name, sentiment_name) == 0) {
            return sentiments[i].value;
        }
    }
    return 0;
}

int analyze_sentiment(char *sentence) {
    int sentiment_value = 0;
    int i, j;
    char *word;

    for (i = 0; i < strlen(sentence); i++) {
        if (isspace(sentence[i])) {
            word = (char *) malloc((i + 1) * sizeof(char));
            strncpy(word, sentence, i);
            word[i] = '\0';
            j = 0;
            while (j < strlen(word)) {
                if (isalpha(word[j])) {
                    sentiment_value += get_sentiment_value(word);
                }
                j++;
            }
            free(word);
            word = NULL;
        }
    }

    return sentiment_value;
}

void print_sentiments(int sentiment_value) {
    int i;
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (sentiments[i].value == sentiment_value) {
            printf("%s\n", sentiments[i].name);
        }
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    int sentiment_value = analyze_sentiment(sentence);
    printf("Sentiment: ");
    print_sentiments(sentiment_value);

    return 0;
}