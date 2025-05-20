//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define SENTIMENT_THRESHOLD 0.5

// Function to tokenize the input sentence
char *tokenize_sentence(char *sentence) {
    char *token = strtok(sentence, ",.?!;:");
    char *result = malloc(MAX_WORD_LENGTH * sizeof(char));
    strcpy(result, token);
    return result;
}

// Function to calculate the sentiment score of a word
double calculate_sentiment_score(char *word) {
    double score = 0;
    int i;
    for (i = 0; i < strlen(word); i++) {
        if (isalpha(word[i])) {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                score += 0.1;
            } else {
                score -= 0.1;
            }
        }
    }
    return score;
}

// Function to calculate the overall sentiment of the input text
double calculate_overall_sentiment(char *text) {
    double positive_score = 0;
    double negative_score = 0;
    char *word;
    while ((word = tokenize_sentence(text))!= NULL) {
        double score = calculate_sentiment_score(word);
        if (score > 0) {
            positive_score += score;
        } else {
            negative_score += score;
        }
        free(word);
    }
    double overall_score = (positive_score - negative_score) / (positive_score + negative_score);
    return overall_score;
}

int main() {
    char text[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence:\n");
    fgets(text, MAX_SENTENCE_LENGTH, stdin);
    double sentiment_score = calculate_overall_sentiment(text);
    if (sentiment_score >= SENTIMENT_THRESHOLD) {
        printf("The sentiment of the input text is positive.\n");
    } else {
        printf("The sentiment of the input text is negative.\n");
    }
    return 0;
}