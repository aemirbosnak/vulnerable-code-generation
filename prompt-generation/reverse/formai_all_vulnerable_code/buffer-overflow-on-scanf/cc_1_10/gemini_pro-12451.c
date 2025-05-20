//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment dictionary
typedef struct {
    char *word;
    int sentiment;
} SentimentWord;

SentimentWord dictionary[] = {
    {"love", 1},
    {"hate", -1},
    {"happy", 1},
    {"sad", -1},
    {"good", 1},
    {"bad", -1},
    {"excellent", 1},
    {"terrible", -1},
    {"amazing", 1},
    {"awful", -1},
    {"beautiful", 1},
    {"ugly", -1},
    {"delicious", 1},
    {"disgusting", -1},
    {"funny", 1},
    {"boring", -1},
    {"interesting", 1},
    {"dull", -1},
    {"exciting", 1},
    {"depressing", -1},
};

// Calculate the sentiment of a given text
int calculateSentiment(char *text) {
    int sentiment = 0;

    // Tokenize the text
    char *tokens[100];
    int tokenCount = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        tokens[tokenCount] = token;
        tokenCount++;
        token = strtok(NULL, " ");
    }

    // Calculate the sentiment for each token
    for (int i = 0; i < tokenCount; i++) {
        for (int j = 0; j < sizeof(dictionary) / sizeof(SentimentWord); j++) {
            if (strcmp(tokens[i], dictionary[j].word) == 0) {
                sentiment += dictionary[j].sentiment;
            }
        }
    }

    return sentiment;
}

// Print the sentiment of a given text
void printSentiment(char *text) {
    int sentiment = calculateSentiment(text);

    if (sentiment > 0) {
        printf("Positive\n");
    } else if (sentiment < 0) {
        printf("Negative\n");
    } else {
        printf("Neutral\n");
    }
}

// Main function
int main() {
    // Get the text from the user
    char text[100];
    printf("Enter a text: ");
    scanf("%s", text);

    // Calculate and print the sentiment of the text
    printSentiment(text);

    return 0;
}