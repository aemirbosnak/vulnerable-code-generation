//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define DICTIONARY_SIZE 10

typedef struct {
    char *word;
    int sentiment_value; // 1 for positive, -1 for negative
} SentimentDictEntry;

SentimentDictEntry sentiment_dictionary[DICTIONARY_SIZE] = {
    {"happy", 1},
    {"joyful", 1},
    {"love", 1},
    {"great", 1},
    {"excellent", 1},
    {"sad", -1},
    {"hate", -1},
    {"terrible", -1},
    {"bad", -1},
    {"awful", -1}
};

int get_sentiment_value(const char *word) {
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (strcmp(sentiment_dictionary[i].word, word) == 0) {
            return sentiment_dictionary[i].sentiment_value;
        }
    }
    return 0; // Neutral value for unknown words
}

void analyze_sentiment(const char *text) {
    char word[MAX_LINE_LENGTH];
    int total_sentiment = 0;

    // Tokenizing the text into words
    const char *t = text; // Pointer to traverse the text
    while (sscanf(t, "%s", word) == 1) {
        total_sentiment += get_sentiment_value(word);
        t += strlen(word) + 1; // Move pointer to the next word
    }

    // Display the results
    if (total_sentiment > 0) {
        printf("Overall sentiment: Positive\n");
    } else if (total_sentiment < 0) {
        printf("Overall sentiment: Negative\n");
    } else {
        printf("Overall sentiment: Neutral\n");
    }
}

void read_input_and_analyze() {
    char input[MAX_LINE_LENGTH * 10]; // Arbitrary length for user input
    printf("Enter text for sentiment analysis (Ctrl+D to end):\n");

    // Read all lines of input
    while (fgets(input, sizeof(input), stdin)) {
        analyze_sentiment(input);
    }
}

int main() {
    read_input_and_analyze();
    return 0;
}