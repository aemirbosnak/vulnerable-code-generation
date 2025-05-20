//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: portable
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 1024 // Maximum length of string to analyze
#define POSITIVE_WORDS_FILE "positive_words.txt" // File containing positive words
#define NEGATIVE_WORDS_FILE "negative_words.txt" // File containing negative words

int main() {
    char input_str[MAX_STR_LEN]; // Input string to analyze
    int sentiment_score = 0; // Overall sentiment score of the input string
    int positive_score = 0; // Number of positive words in the input string
    int negative_score = 0; // Number of negative words in the input string

    // Read positive words from file
    FILE *fp = fopen(POSITIVE_WORDS_FILE, "r");
    if (fp == NULL) {
        printf("Error opening file: %s", POSITIVE_WORDS_FILE);
        return 1;
    }
    char positive_word[20]; // Maximum length of a positive word is 20 characters
    while (fscanf(fp, "%s", positive_word) != EOF) {
        // Search for positive word in the input string
        if (strstr(input_str, positive_word) != NULL) {
            sentiment_score++; // Increase overall sentiment score
            positive_score++; // Increase positive score
        }
    }
    fclose(fp);

    // Read negative words from file
    fp = fopen(NEGATIVE_WORDS_FILE, "r");
    if (fp == NULL) {
        printf("Error opening file: %s", NEGATIVE_WORDS_FILE);
        return 1;
    }
    char negative_word[20]; // Maximum length of a negative word is 20 characters
    while (fscanf(fp, "%s", negative_word) != EOF) {
        // Search for negative word in the input string
        if (strstr(input_str, negative_word) != NULL) {
            sentiment_score--; // Decrease overall sentiment score
            negative_score++; // Increase negative score
        }
    }
    fclose(fp);

    // Print results
    printf("Sentiment analysis result:\n");
    printf("Positive words: %d\n", positive_score);
    printf("Negative words: %d\n", negative_score);
    if (sentiment_score > 0) {
        printf("Overall sentiment: Positive\n");
    } else if (sentiment_score < 0) {
        printf("Overall sentiment: Negative\n");
    } else {
        printf("Overall sentiment: Neutral\n");
    }

    return 0;
}