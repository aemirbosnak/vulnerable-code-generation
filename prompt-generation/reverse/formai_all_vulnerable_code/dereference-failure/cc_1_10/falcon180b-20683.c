//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORD_LENGTH 100

// Function to tokenize a sentence into words
void tokenize(char* sentence, char** tokens) {
    int num_tokens = 0;
    char* token = strtok(sentence, ",.?!;:");
    while (token!= NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, ",.?!;:");
    }
}

// Function to remove stop words from a sentence
void remove_stop_words(char** tokens) {
    int i = 0;
    while (tokens[i]!= NULL) {
        if (strcmp(tokens[i], "the") == 0 || strcmp(tokens[i], "a") == 0 || strcmp(tokens[i], "an") == 0) {
            for (int j = i; j < MAX_SENTENCE_LENGTH - 1; j++) {
                tokens[j] = tokens[j + 1];
            }
            tokens[MAX_SENTENCE_LENGTH - 1] = NULL;
        } else {
            i++;
        }
    }
}

// Function to calculate the sentiment of a sentence
int calculate_sentiment(char** tokens) {
    int positive_words = 0;
    int negative_words = 0;
    int neutral_words = 0;
    for (int i = 0; tokens[i]!= NULL; i++) {
        if (strcmp(tokens[i], "happy") == 0 || strcmp(tokens[i], "joyful") == 0 || strcmp(tokens[i], "pleased") == 0) {
            positive_words++;
        } else if (strcmp(tokens[i], "sad") == 0 || strcmp(tokens[i], "miserable") == 0 || strcmp(tokens[i], "unhappy") == 0) {
            negative_words++;
        } else {
            neutral_words++;
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
    char* tokens[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    sentence[strcspn(sentence, "\n")] = '\0';
    tokenize(sentence, tokens);
    remove_stop_words(tokens);
    int sentiment = calculate_sentiment(tokens);
    if (sentiment == 1) {
        printf("Positive sentiment\n");
    } else if (sentiment == -1) {
        printf("Negative sentiment\n");
    } else {
        printf("Neutral sentiment\n");
    }
    return 0;
}