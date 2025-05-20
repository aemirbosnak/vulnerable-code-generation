//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1024
#define MAX_WORDS 100

char *words[MAX_WORDS];
int word_count = 0;

void tokenize(char *sentence) {
    char *token = strtok(sentence, " ");
    while (token != NULL && word_count < MAX_WORDS) {
        words[word_count++] = token;
        token = strtok(NULL, " ");
    }
}

int get_sentiment(char *sentence) {
    int sentiment = 0;
    for (int i = 0; i < word_count; i++) {
        if (strcmp(words[i], "good") == 0 || strcmp(words[i], "great") == 0) {
            sentiment++;
        } else if (strcmp(words[i], "bad") == 0 || strcmp(words[i], "terrible") == 0) {
            sentiment--;
        }
    }
    return sentiment;
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    scanf("%s", sentence);

    tokenize(sentence);
    int sentiment = get_sentiment(sentence);

    printf("Sentiment: ");
    if (sentiment > 0) {
        printf("Positive");
    } else if (sentiment < 0) {
        printf("Negative");
    } else {
        printf("Neutral");
    }
    printf("\n");

    return 0;
}