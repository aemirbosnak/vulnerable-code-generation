//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment dictionary
char *sentiment_dictionary[] = {
    "great", "good", "excellent", "awesome",
    "bad", "terrible", "horrible", "awful"
};

// Get the sentiment of a sentence
int get_sentiment(char *sentence) {
    // Tokenize the sentence
    char *tokens[100];
    int num_tokens = tokenize(sentence, tokens);

    // Initialize the sentiment score
    int sentiment_score = 0;

    // Iterate over the tokens
    for (int i = 0; i < num_tokens; i++) {
        // Find the token in the sentiment dictionary
        int index = find_token(tokens[i], sentiment_dictionary);

        // If the token is in the sentiment dictionary, add its score to the sentiment score
        if (index != -1) {
            sentiment_score += sentiment_dictionary[index];
        }
    }

    // Return the sentiment score
    return sentiment_score;
}

// Tokenize a sentence into an array of tokens
int tokenize(char *sentence, char *tokens[]) {
    // Allocate memory for the tokens
    char *token = strtok(sentence, " ");
    int num_tokens = 0;

    // Iterate over the sentence tokens
    while (token != NULL) {
        // Add the token to the array of tokens
        tokens[num_tokens] = token;
        num_tokens++;

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Return the number of tokens
    return num_tokens;
}

// Find a token in an array of tokens
int find_token(char *token, char *tokens[]) {
    // Iterate over the array of tokens
    for (int i = 0; i < sizeof(tokens) / sizeof(char *); i++) {
        // If the token is found, return its index
        if (strcmp(token, tokens[i]) == 0) {
            return i;
        }
    }

    // If the token is not found, return -1
    return -1;
}

// Print the sentiment of a sentence
void print_sentiment(char *sentence, int sentiment_score) {
    // Print the sentence
    printf("Sentence: %s\n", sentence);

    // Print the sentiment score
    printf("Sentiment score: %d\n", sentiment_score);

    // Print the sentiment
    if (sentiment_score > 0) {
        printf("Sentiment: positive\n");
    } else if (sentiment_score < 0) {
        printf("Sentiment: negative\n");
    } else {
        printf("Sentiment: neutral\n");
    }
}

// Main function
int main() {
    // Get the sentence from the user
    char sentence[100];
    printf("Enter a sentence: ");
    gets(sentence);

    // Get the sentiment of the sentence
    int sentiment_score = get_sentiment(sentence);

    // Print the sentiment of the sentence
    print_sentiment(sentence, sentiment_score);

    return 0;
}