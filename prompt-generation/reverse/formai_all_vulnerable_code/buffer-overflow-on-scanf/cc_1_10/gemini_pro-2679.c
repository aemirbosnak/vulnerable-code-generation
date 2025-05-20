//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment dictionary
typedef struct {
    char *word;
    int sentiment;
} SentimentEntry;

SentimentEntry sentiment_dictionary[] = {
    {"love", 1},
    {"happy", 1},
    {"joyful", 1},
    {"excited", 1},
    {"thrilled", 1},
    {"delighted", 1},
    {"peaceful", 1},
    {"serene", 1},
    {"tranquil", 1},
    {"calm", 1},

    {"hate", -1},
    {"sad", -1},
    {"depressed", -1},
    {"angry", -1},
    {"frustrated", -1},
    {"disappointed", -1},
    {"anxious", -1},
    {"stressed", -1},
    {"worried", -1},
    {"fearful", -1}
};

// Calculate the sentiment of a given text
int calculate_sentiment(char *text) {
    int sentiment = 0;

    // Tokenize the text
    char *token = strtok(text, " ");
    while (token != NULL) {
        // Find the sentiment of the token in the dictionary
        for (int i = 0; i < (sizeof(sentiment_dictionary) / sizeof(SentimentEntry)); i++) {
            if (strcmp(token, sentiment_dictionary[i].word) == 0) {
                sentiment += sentiment_dictionary[i].sentiment;
            }
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    return sentiment;
}

// Print the sentiment of a given text
void print_sentiment(char *text) {
    int sentiment = calculate_sentiment(text);

    if (sentiment > 0) {
        printf("The text is positive.\n");
    } else if (sentiment < 0) {
        printf("The text is negative.\n");
    } else {
        printf("The text is neutral.\n");
    }
}

int main() {
    // Get the text from the user
    char text[100];
    printf("Enter a text: ");
    scanf("%s", text);

    // Calculate the sentiment of the text
    int sentiment = calculate_sentiment(text);

    // Print the sentiment of the text
    printf("The sentiment of the text is: %d\n", sentiment);

    return 0;
}