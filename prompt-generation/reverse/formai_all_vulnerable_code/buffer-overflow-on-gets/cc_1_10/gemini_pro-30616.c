//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment dictionary.
const char *sentiment_dict[] = {
    "love", "great", "amazing", "superb", "excellent",
    "good", "fine", "ok", "okay", "alright",
    "bad", "terrible", "awful", "dreadful", "horrible",
    "worst"
};

// Get the sentiment of a word.
int get_sentiment(const char *word) {
    for (int i = 0; i < sizeof(sentiment_dict) / sizeof(char *); i++) {
        if (strcmp(word, sentiment_dict[i]) == 0) {
            return i;
        }
    }

    // If the word is not in the dictionary, return 0.
    return 0;
}

// Analyze the sentiment of a text.
int analyze_sentiment(const char *text) {
    // Tokenize the text.
    char *tokens[100];
    int num_tokens = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // Calculate the sentiment of each word.
    int sentiments[num_tokens];
    for (int i = 0; i < num_tokens; i++) {
        sentiments[i] = get_sentiment(tokens[i]);
    }

    // Calculate the average sentiment.
    int sum = 0;
    for (int i = 0; i < num_tokens; i++) {
        sum += sentiments[i];
    }
    int avg_sentiment = sum / num_tokens;

    // Return the average sentiment.
    return avg_sentiment;
}

// Print the sentiment of a text.
void print_sentiment(const char *text) {
    int sentiment = analyze_sentiment(text);

    switch (sentiment) {
        case 0:
            printf("The sentiment is neutral.\n");
            break;
        case 1:
            printf("The sentiment is positive.\n");
            break;
        case -1:
            printf("The sentiment is negative.\n");
            break;
    }
}

// Main function.
int main() {
    // Get the text from the user.
    char text[1000];
    printf("Enter the text: ");
    gets(text);

    // Analyze the sentiment of the text.
    print_sentiment(text);

    return 0;
}