//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment scores for each word
int sentiment_scores[] = {
    [0] = 0,  // "not"
    [1] = -1, // "bad"
    [2] = 1,  // "good"
    [3] = -2, // "terrible"
    [4] = 2,  // "excellent"
};

// Get the sentiment score for a given word
int get_sentiment_score(char *word) {
    for (int i = 0; i < sizeof(sentiment_scores) / sizeof(int); i++) {
        if (strcmp(word, sentiment_scores[i]) == 0) {
            return sentiment_scores[i];
        }
    }

    return 0;  // Return 0 for words not found in the sentiment dictionary
}

// Analyze the sentiment of a given sentence
int analyze_sentiment(char *sentence) {
    // Tokenize the sentence into words
    char *words[100];
    int num_words = 0;
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Calculate the total sentiment score
    int total_score = 0;
    for (int i = 0; i < num_words; i++) {
        total_score += get_sentiment_score(words[i]);
    }

    return total_score;
}

// Main function
int main() {
    // Get the input sentence from the user
    char sentence[100];
    printf("Enter a sentence: ");
    gets(sentence);

    // Analyze the sentiment of the sentence
    int sentiment_score = analyze_sentiment(sentence);

    // Print the sentiment score
    if (sentiment_score > 0) {
        printf("The sentence has a positive sentiment.\n");
    } else if (sentiment_score < 0) {
        printf("The sentence has a negative sentiment.\n");
    } else {
        printf("The sentence has a neutral sentiment.\n");
    }

    return 0;
}