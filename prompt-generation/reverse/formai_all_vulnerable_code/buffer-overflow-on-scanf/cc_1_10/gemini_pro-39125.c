//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment dictionary
typedef struct {
    char *word;
    int sentiment;
} SentimentEntry;

// Create a sentiment dictionary
SentimentEntry sentimentDictionary[] = {
    {"excellent", 1},
    {"good", 1},
    {"ok", 0},
    {"bad", -1},
    {"terrible", -1}
};

// Get the sentiment of a word
int getWordSentiment(char *word) {
    for (int i = 0; i < sizeof(sentimentDictionary) / sizeof(SentimentEntry); i++) {
        if (strcmp(word, sentimentDictionary[i].word) == 0) {
            return sentimentDictionary[i].sentiment;
        }
    }

    // If the word is not found in the dictionary, return 0
    return 0;
}

// Analyze the sentiment of a text
int analyzeSentiment(char *text) {
    // Tokenize the text
    char *tokens = strtok(text, " ");

    // Calculate the sentiment of the text
    int sentiment = 0;
    while (tokens != NULL) {
        sentiment += getWordSentiment(tokens);
        tokens = strtok(NULL, " ");
    }

    // Return the sentiment of the text
    return sentiment;
}

// Print the sentiment of a text
void printSentiment(char *text) {
    int sentiment = analyzeSentiment(text);

    if (sentiment > 0) {
        printf("The sentiment of the text is positive.\n");
    } else if (sentiment < 0) {
        printf("The sentiment of the text is negative.\n");
    } else {
        printf("The sentiment of the text is neutral.\n");
    }
}

// Main function
int main() {
    // Get the text from the user
    char text[100];
    printf("Enter the text: ");
    scanf("%s", text);

    // Analyze the sentiment of the text
    printSentiment(text);

    return 0;
}