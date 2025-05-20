//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000

int main() {

    char text[MAX_WORDS];
    printf("Enter text: ");
    gets(text);

    char *words[MAX_WORDS];
    int numWords = tokenize(text, words);

    int sentiment = analyzeSentiment(words, numWords);

    switch (sentiment) {
        case 0:
            printf("Neutral\n");
            break;
        case 1:
            printf("Positive\n");
            break;
        case -1:
            printf("Negative\n");
            break;
    }

    return 0;
}

int tokenize(char *text, char **words) {
    int numWords = 0;
    char *token = strtok(text, " ");

    while (token) {
        words[numWords++] = token;
        token = strtok(NULL, " ");
    }

    return numWords;
}

int analyzeSentiment(char **words, int numWords) {
    int sentiment = 0;
    for (int i = 0; i < numWords; i++) {
        char *word = words[i];

        if (isWordPositive(word)) {
            sentiment++;
        } else if (isWordNegative(word)) {
            sentiment--;
        }
    }

    return sentiment;
}

int isWordPositive(char *word) {
    return wordContains(word, "good") || wordContains(word, "great") || wordContains(word, "excellent") || wordContains(word, "wonderful") || wordContains(word, "fantastic");
}

int isWordNegative(char *word) {
    return wordContains(word, "bad") || wordContains(word, "terrible") || wordContains(word, "awful") || wordContains(word, "horrible") || wordContains(word, "atrocious");
}

int wordContains(char *word, char *phrase) {
    return strstr(word, phrase) != NULL;
}