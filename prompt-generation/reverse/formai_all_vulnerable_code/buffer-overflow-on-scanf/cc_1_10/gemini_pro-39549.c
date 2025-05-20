//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment dictionary
const char *sentiment_dictionary[] = {
    "love", "happy", "joyful", "excited", "thrilled",
    "hate", "sad", "angry", "depressed", "miserable",
    "neutral"
};

// Define the sentiment scores
const int sentiment_scores[] = {
    1, 1, 1, 1, 1,
    -1, -1, -1, -1, -1,
    0
};

// Get the sentiment score of a word
int get_sentiment_score(const char *word) {
    for (int i = 0; i < sizeof(sentiment_dictionary) / sizeof(char *); i++) {
        if (strcmp(word, sentiment_dictionary[i]) == 0) {
            return sentiment_scores[i];
        }
    }

    // If the word is not found in the dictionary, return 0 (neutral)
    return 0;
}

// Analyze the sentiment of a text
int analyze_sentiment(const char *text) {
    // Split the text into words
    char *words[100];
    int num_words = 0;
    char *word = strtok(text, " ");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Calculate the sentiment score of each word
    int sentiment_score = 0;
    for (int i = 0; i < num_words; i++) {
        sentiment_score += get_sentiment_score(words[i]);
    }

    // Return the overall sentiment score
    return sentiment_score;
}

// Print the sentiment of a text
void print_sentiment(const char *text) {
    int sentiment_score = analyze_sentiment(text);

    if (sentiment_score > 0) {
        printf("The text is positive.\n");
    } else if (sentiment_score < 0) {
        printf("The text is negative.\n");
    } else {
        printf("The text is neutral.\n");
    }
}

// Main function
int main() {
    // Get the text from the user
    char text[100];
    printf("Enter a text: ");
    scanf("%s", text);

    // Analyze the sentiment of the text
    print_sentiment(text);

    return 0;
}