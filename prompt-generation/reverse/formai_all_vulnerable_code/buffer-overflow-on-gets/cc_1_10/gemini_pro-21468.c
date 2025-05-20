//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment dictionary
static const char *sentiment_dictionary[] = {
    "positive", "happy", "good", "great", "awesome",
    "negative", "sad", "bad", "terrible", "awful"
};

// Get the sentiment of a given word
int get_sentiment(const char *word) {
    for (int i = 0; i < sizeof(sentiment_dictionary) / sizeof(char *); i++) {
        if (strcmp(word, sentiment_dictionary[i]) == 0) {
            return i;
        }
    }
    return -1;
}

// Analyze the sentiment of a given text
int analyze_sentiment(const char *text) {
    int sentiment = 0;
    char *token;

    // Tokenize the text into words
    token = strtok(text, " ");
    while (token != NULL) {
        // Get the sentiment of each word
        int word_sentiment = get_sentiment(token);
        if (word_sentiment != -1) {
            sentiment += word_sentiment;
        }
        token = strtok(NULL, " ");
    }

    return sentiment;
}

// Main function
int main() {
    // Get the text to analyze from the user
    char text[1024];
    printf("Enter the text to analyze: ");
    gets(text);

    // Analyze the sentiment of the text
    int sentiment = analyze_sentiment(text);

    // Print the result
    if (sentiment > 0) {
        printf("The text has a positive sentiment.\n");
    } else if (sentiment < 0) {
        printf("The text has a negative sentiment.\n");
    } else {
        printf("The text has a neutral sentiment.\n");
    }

    return 0;
}