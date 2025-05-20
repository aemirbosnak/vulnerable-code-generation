//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000

// Function to tokenize a sentence
void tokenize(char* sentence, char** tokens) {
    int i = 0;
    char* token = strtok(sentence, " ");
    while (token!= NULL) {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
}

// Function to calculate the sentiment of a sentence
int calculate_sentiment(char** tokens) {
    int positive_words = 0;
    int negative_words = 0;
    for (int i = 0; tokens[i]!= NULL; i++) {
        if (strcmp(tokens[i], "happy") == 0 || strcmp(tokens[i], "joy") == 0) {
            positive_words++;
        } else if (strcmp(tokens[i], "sad") == 0 || strcmp(tokens[i], "angry") == 0) {
            negative_words++;
        }
    }
    if (positive_words > negative_words) {
        return 1; // Positive sentiment
    } else if (negative_words > positive_words) {
        return -1; // Negative sentiment
    } else {
        return 0; // Neutral sentiment
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Remove newline character from the end of the sentence
    sentence[strcspn(sentence, "\n")] = '\0';

    char* tokens[MAX_SENTENCE_LENGTH/2]; // Assuming maximum of half the sentence length are words
    tokenize(sentence, tokens);

    int sentiment = calculate_sentiment(tokens);

    if (sentiment == 1) {
        printf("The sentiment of the sentence is positive.\n");
    } else if (sentiment == -1) {
        printf("The sentiment of the sentence is negative.\n");
    } else {
        printf("The sentiment of the sentence is neutral.\n");
    }

    return 0;
}