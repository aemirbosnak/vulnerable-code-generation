//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a sentence
#define MAX_SENTENCE_LENGTH 1024

// Define the number of sentiment categories
#define NUM_SENTIMENT_CATEGORIES 3

// Define the sentiment categories
char *sentiment_categories[] = {"positive", "neutral", "negative"};

// Define the sentiment scores for each word
int sentiment_scores[] = {
    1,  // "good"
    -1, // "bad"
    0,  // "neutral"
};

// Define the number of words in the sentiment dictionary
#define NUM_SENTIMENT_WORDS 3

// Define the sentiment dictionary
char *sentiment_words[] = {"good", "bad", "neutral"};

// Get the sentiment score for a sentence
int get_sentiment_score(char *sentence) {
    int score = 0;

    // Tokenize the sentence
    char *tokens[MAX_SENTENCE_LENGTH];
    int num_tokens = tokenize(sentence, tokens);

    // For each token, look up its sentiment score
    for (int i = 0; i < num_tokens; i++) {
        char *token = tokens[i];

        int found = 0;
        for (int j = 0; j < NUM_SENTIMENT_WORDS; j++) {
            if (strcmp(token, sentiment_words[j]) == 0) {
                score += sentiment_scores[j];
                found = 1;
                break;
            }
        }

        // If the token was not found in the sentiment dictionary,
        // assume it has a neutral sentiment
        if (!found) {
            score += 0;
        }
    }

    // Return the sentiment score
    return score;
}

// Tokenize a sentence into an array of tokens
int tokenize(char *sentence, char **tokens) {
    int num_tokens = 0;

    char *token = strtok(sentence, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    return num_tokens;
}

// Print the sentiment analysis results
void print_sentiment_analysis_results(int sentiment_score) {
    if (sentiment_score > 0) {
        printf("The sentence has a positive sentiment.\n");
    } else if (sentiment_score == 0) {
        printf("The sentence has a neutral sentiment.\n");
    } else {
        printf("The sentence has a negative sentiment.\n");
    }
}

// Main function
int main() {
    // Get the sentence from the user
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    gets(sentence);

    // Get the sentiment score for the sentence
    int sentiment_score = get_sentiment_score(sentence);

    // Print the sentiment analysis results
    print_sentiment_analysis_results(sentiment_score);

    return 0;
}