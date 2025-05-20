//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment scores for each word
#define POSITIVE_SCORE 1
#define NEGATIVE_SCORE -1

// Create a function to analyze the sentiment of a sentence
int analyze_sentiment(char *sentence) {
  
    int i, score = 0;     // Declare variables
    char *words[100];    // Array to store words
  
    // Tokenize the sentence into words
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        words[i++] = token;
        token = strtok(NULL, " ");
    }

    // Calculate the sentiment score for each word
    for (i = 0; i < strlen(words); i++) {
        if (strcmp(words[i], "good") == 0 || strcmp(words[i], "great") == 0) {
            score += POSITIVE_SCORE;
        } else if (strcmp(words[i], "bad") == 0 || strcmp(words[i], "terrible") == 0) {
            score += NEGATIVE_SCORE;
        }
    }

    // Return the overall sentiment score
    return score;
}

int main() {
    char sentence[100];

    // Get the sentence from the user
    printf("Enter a sentence: ");
    gets(sentence);

    // Analyze the sentiment of the sentence
    int score = analyze_sentiment(sentence);

    // Print the sentiment score
    if (score > 0) {
        printf("The sentence has a positive sentiment.\n");
    } else if (score < 0) {
        printf("The sentence has a negative sentiment.\n");
    } else {
        printf("The sentence has a neutral sentiment.\n");
    }

    return 0;
}