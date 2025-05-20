//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of input string
#define MAX_LEN 1000

// Define the sentiment threshold
#define SENTIMENT_THRESHOLD 0.6

// Define the positive and negative word lists
char *positive_words[] = {"happy", "love", "great", "excited", "amazing"};
int num_positive_words = 5;

char *negative_words[] = {"sad", "hate", "terrible", "disappointed", "upset"};
int num_negative_words = 5;

// Function to tokenize the input string
int tokenize(char *str, char *tokens[]) {
    int num_tokens = 0;
    char *ptr = strtok(str, " ");
    while (ptr != NULL) {
        tokens[num_tokens++] = ptr;
        ptr = strtok(NULL, " ");
    }
    return num_tokens;
}

// Function to calculate the sentiment score of the input string
double calculate_sentiment_score(char *str) {
    char *tokens[MAX_LEN];
    int num_tokens = tokenize(str, tokens);

    int num_positive = 0, num_negative = 0;
    for (int i = 0; i < num_tokens; i++) {
        for (int j = 0; j < num_positive_words; j++) {
            if (strcmp(tokens[i], positive_words[j]) == 0) {
                num_positive++;
                break;
            }
        }
        for (int j = 0; j < num_negative_words; j++) {
            if (strcmp(tokens[i], negative_words[j]) == 0) {
                num_negative++;
                break;
            }
        }
    }

    if (num_positive + num_negative == 0) {
        return 0.0;
    } else {
        return ((double) num_positive) / (num_positive + num_negative);
    }
}

// Main function
int main() {
    char input_str[MAX_LEN];
    printf("Enter a sentence to analyze: ");
    scanf("%[^\n]", input_str);

    double sentiment_score = calculate_sentiment_score(input_str);
    if (sentiment_score >= SENTIMENT_THRESHOLD) {
        printf("The sentiment of the sentence is positive\n");
    } else {
        printf("The sentiment of the sentence is negative\n");
    }

    return 0;
}