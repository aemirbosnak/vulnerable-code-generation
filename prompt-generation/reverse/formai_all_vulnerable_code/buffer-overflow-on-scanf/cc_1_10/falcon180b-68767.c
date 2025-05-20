//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100
#define MIN_WORD_LENGTH 3
#define SENTIMENT_SCORE_RANGE -100.0 to 100.0

// Function to tokenize a string into words
void tokenize(char* str, char** tokens) {
    int num_tokens = 0;
    char* token = strtok(str, ",.!?;:");
    while(token!= NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, ",.!?;:");
    }
    tokens[num_tokens] = NULL;
}

// Function to calculate the sentiment score of a word
double sentiment_score(char* word) {
    int i;
    double score = 0.0;
    for(i = 0; i < strlen(word); i++) {
        if(isalpha(word[i])) {
            score += tolower(word[i]) - 'a' + 1;
        }
    }
    return score;
}

// Function to calculate the sentiment score of a sentence
double calculate_sentiment_score(char* sentence) {
    double score = 0.0;
    char* tokens[MAX_WORDS];
    int num_tokens = 0;
    tokenize(sentence, tokens);
    int i;
    for(i = 0; i < num_tokens; i++) {
        int word_length = strlen(tokens[i]);
        if(word_length >= MIN_WORD_LENGTH && word_length <= MAX_WORD_LENGTH) {
            score += sentiment_score(tokens[i]);
        }
    }
    return score / num_tokens;
}

// Function to print the sentiment score of a sentence
void print_sentiment_score(double score) {
    if(score >= 0.0) {
        printf("Positive\n");
    }
    else if(score <= 0.0) {
        printf("Negative\n");
    }
    else {
        printf("Neutral\n");
    }
}

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    scanf("%s", sentence);
    double score = calculate_sentiment_score(sentence);
    print_sentiment_score(score);
    return 0;
}