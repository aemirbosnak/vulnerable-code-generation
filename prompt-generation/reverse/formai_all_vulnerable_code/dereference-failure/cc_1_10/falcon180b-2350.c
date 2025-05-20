//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Define a struct to store word and its sentiment score
typedef struct {
    char *word;
    int score;
} WordScore;

// Function to compare two WordScore structs based on their scores
int compare(const void *a, const void *b) {
    const WordScore *ws1 = a;
    const WordScore *ws2 = b;

    if (ws1->score > ws2->score) {
        return -1;
    } else if (ws1->score < ws2->score) {
        return 1;
    } else {
        return 0;
    }
}

// Function to tokenize a sentence into words
void tokenize(char *sentence, char **tokens) {
    char *token = strtok(sentence, ",.?!;:");
    int count = 0;

    while (token!= NULL) {
        tokens[count++] = token;
        token = strtok(NULL, ",.?!;:");
    }
}

// Function to calculate the sentiment score of a word
int calculateScore(char *word) {
    int score = 0;
    int i;

    for (i = 0; i < strlen(word); i++) {
        if (isupper(word[i])) {
            score--;
        } else if (islower(word[i])) {
            score++;
        }
    }

    return score;
}

// Function to perform sentiment analysis on a sentence
void sentimentAnalysis(char *sentence) {
    char **tokens = malloc(100 * sizeof(char *));
    int numTokens = 0;

    tokenize(sentence, tokens);
    qsort(tokens, numTokens, sizeof(char *), compare);

    printf("Sentiment Analysis:\n");
    for (int i = 0; i < numTokens; i++) {
        printf("%s: %d\n", tokens[i], calculateScore(tokens[i]));
    }
}

int main() {
    char sentence[1000];

    printf("Enter a sentence:\n");
    scanf("%[^\n]", sentence);

    sentimentAnalysis(sentence);

    return 0;
}