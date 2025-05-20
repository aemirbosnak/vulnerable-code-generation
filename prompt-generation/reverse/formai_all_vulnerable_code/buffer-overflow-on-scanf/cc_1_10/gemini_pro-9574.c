//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment dictionary
typedef struct {
    char *word;
    int sentiment;
} SentimentEntry;

SentimentEntry sentimentDictionary[] = {
    { "amazing", 5 },
    { "great", 4 },
    { "good", 3 },
    { "ok", 2 },
    { "bad", 1 },
    { "terrible", 0 }
};

// Tokenize the input text into words
char **tokenize(char *text) {
    char **tokens = malloc(sizeof(char *) * 100);
    int numTokens = 0;

    char *token = strtok(text, " ");
    while (token != NULL) {
        tokens[numTokens++] = token;
        token = strtok(NULL, " ");
    }

    return tokens;
}

// Get the sentiment of a single word
int getWordSentiment(char *word) {
    for (int i = 0; i < sizeof(sentimentDictionary) / sizeof(SentimentEntry); i++) {
        if (strcmp(word, sentimentDictionary[i].word) == 0) {
            return sentimentDictionary[i].sentiment;
        }
    }

    return 0;
}

// Get the sentiment of a piece of text
int getTextSentiment(char *text) {
    char **tokens = tokenize(text);

    int totalSentiment = 0;
    for (int i = 0; i < 100; i++) {
        if (tokens[i] == NULL) {
            break;
        }

        totalSentiment += getWordSentiment(tokens[i]);
    }

    free(tokens);

    return totalSentiment;
}

// Main function
int main() {
    // Get the input text from the user
    char text[100];
    printf("Enter a piece of text: ");
    scanf("%s", text);

    // Get the sentiment of the text
    int sentiment = getTextSentiment(text);

    // Print the sentiment
    printf("The sentiment of the text is: %d\n", sentiment);

    return 0;
}