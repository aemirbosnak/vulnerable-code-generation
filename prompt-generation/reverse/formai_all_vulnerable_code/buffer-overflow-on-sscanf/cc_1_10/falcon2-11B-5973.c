//Falcon2-11B DATASET v1.0 Category: Sentiment analysis tool ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100
#define MAX_TOKENS 100

int sentiment_score(char* sentence, char* tokens[], int length) {
    int total_score = 0;
    int i;

    for (i = 0; i < length; i++) {
        char token[MAX_LENGTH];
        strncpy(token, tokens[i], MAX_LENGTH);

        if (strcmp(token, "love") == 0) {
            total_score += 5;
        } else if (strcmp(token, "hate") == 0) {
            total_score -= 5;
        } else if (strcmp(token, "romantic") == 0) {
            total_score += 3;
        } else if (strcmp(token, "sentimental") == 0) {
            total_score += 2;
        } else if (strcmp(token, "heartbreak") == 0) {
            total_score -= 3;
        } else if (strcmp(token, "cheerful") == 0) {
            total_score += 1;
        } else if (strcmp(token, "sadness") == 0) {
            total_score -= 1;
        } else {
            total_score += 0;
        }
    }

    return total_score;
}

int main() {
    char sentence[MAX_LENGTH];
    char tokens[MAX_TOKENS][MAX_LENGTH];
    int length = 0;
    int total_score = 0;

    printf("Enter a sentence: ");
    fgets(sentence, MAX_LENGTH, stdin);
    sentence[strcspn(sentence, "\n")] = '\0';

    sscanf(sentence, "%s", tokens[length]);
    while (sscanf(sentence, "%s", tokens[length]) == 1) {
        length++;
    }

    total_score = sentiment_score(sentence, tokens, length);
    printf("Sentiment Score: %d\n", total_score);

    return 0;
}