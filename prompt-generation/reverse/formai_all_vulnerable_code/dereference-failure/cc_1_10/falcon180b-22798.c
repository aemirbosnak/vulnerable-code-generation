//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000 // maximum length of a sentence in words
#define MAX_WORD_LENGTH 20 // maximum length of a word in characters
#define NUM_SENTIMENTS 6 // number of possible sentiments

struct sentiment_score {
    char* name;
    int score;
};

struct sentiment_score sentiments[NUM_SENTIMENTS] = {
    {"positive", 3},
    {"negative", -3},
    {"neutral", 0},
    {"happy", 2},
    {"sad", -2},
    {"angry", -4}
};

void tokenize(char* sentence, char** tokens) {
    int num_tokens = 0;
    char* token = strtok(sentence, " ");
    while (token!= NULL) {
        tokens[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, " ");
    }
}

int count_words(char** tokens) {
    int count = 0;
    while (*tokens!= NULL) {
        count++;
        tokens++;
    }
    return count;
}

int calculate_sentiment_score(char** tokens, int num_tokens) {
    int score = 0;
    for (int i = 0; i < num_tokens; i++) {
        for (int j = 0; j < NUM_SENTIMENTS; j++) {
            if (strcmp(tokens[i], sentiments[j].name) == 0) {
                score += sentiments[j].score;
                break;
            }
        }
    }
    return score;
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    char* tokens[MAX_WORD_LENGTH];
    tokenize(sentence, tokens);

    int num_tokens = count_words(tokens);
    int sentiment_score = calculate_sentiment_score(tokens, num_tokens);

    printf("Sentiment score: %d\n", sentiment_score);

    return 0;
}