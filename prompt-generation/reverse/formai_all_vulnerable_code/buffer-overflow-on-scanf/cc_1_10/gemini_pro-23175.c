//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment dictionary
typedef struct {
    char *word;
    int sentiment;
} SentimentDictionaryEntry;

SentimentDictionaryEntry dictionary[] = {
    {"love", 1},
    {"hate", -1},
    {"good", 1},
    {"bad", -1},
    {"happy", 1},
    {"sad", -1},
    {"beautiful", 1},
    {"ugly", -1},
    {"amazing", 1},
    {"terrible", -1},
};

// Calculate the sentiment of a given text
int calculateSentiment(char *text) {
    int sentiment = 0;

    // Tokenize the text
    char *token = strtok(text, " ");
    while (token != NULL) {
        // Look up the sentiment of the token in the dictionary
        for (int i = 0; i < sizeof(dictionary) / sizeof(SentimentDictionaryEntry); i++) {
            if (strcmp(token, dictionary[i].word) == 0) {
                sentiment += dictionary[i].sentiment;
            }
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    return sentiment;
}

// Print the sentiment of a given text
void printSentiment(char *text) {
    int sentiment = calculateSentiment(text);

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

    // Calculate and print the sentiment of the text
    printSentiment(text);

    return 0;
}