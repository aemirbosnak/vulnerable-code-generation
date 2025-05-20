//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store the word and its sentiment score
typedef struct {
    char *word;
    int sentiment;
} WordSentiment;

// Declare an array of WordSentiment structs to store the sentiment dictionary
WordSentiment sentimentDictionary[] = {
    {"abandon", -2},
    {"abandoned", -2},
    {"abhor", -3},
    {"abhorred", -3},
    {"abhorrent", -3},
    {"abhorrence", -3},
    {"abide", 1},
    {"abiding", 1},
    {"ability", 2},
    {"able", 2}
};

// Get the sentiment score for a given word
int get_sentiment(char *word) {
    // Loop through the sentiment dictionary and compare the word to each word in the dictionary
    for (int i = 0; i < sizeof(sentimentDictionary) / sizeof(WordSentiment); i++) {
        if (strcmp(word, sentimentDictionary[i].word) == 0) {
            // If the word is found in the dictionary, return the sentiment score
            return sentimentDictionary[i].sentiment;
        }
    }

    // If the word is not found in the dictionary, return 0
    return 0;
}

// Perform sentiment analysis on a given text
int analyze_sentiment(char *text) {
    // Split the text into an array of words
    char *words[100];
    char *word;
    int num_words = 0;
    word = strtok(text, " ");
    while (word != NULL) {
        words[num_words] = word;
        num_words++;
        word = strtok(NULL, " ");
    }

    // Calculate the sentiment score for each word in the text
    int sentiment_score = 0;
    for (int i = 0; i < num_words; i++) {
        sentiment_score += get_sentiment(words[i]);
    }

    // Return the sentiment score for the text
    return sentiment_score;
}

// Print the sentiment analysis results
void print_results(int sentiment_score) {
    if (sentiment_score > 0) {
        printf("The text has a positive sentiment.\n");
    } else if (sentiment_score < 0) {
        printf("The text has a negative sentiment.\n");
    } else {
        printf("The text has a neutral sentiment.\n");
    }
}

// Main function
int main() {
    // Get the text from the user
    char text[100];
    printf("Enter some text: ");
    gets(text);

    // Perform sentiment analysis on the text
    int sentiment_score = analyze_sentiment(text);

    // Print the sentiment analysis results
    print_results(sentiment_score);

    return 0;
}