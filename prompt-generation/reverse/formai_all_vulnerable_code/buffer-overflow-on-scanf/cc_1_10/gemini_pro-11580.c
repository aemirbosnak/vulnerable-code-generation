//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a word and its sentiment value
typedef struct {
    char *word;
    int sentiment;
} WordSentiment;

// Create an array of WordSentiment structs to store the sentiment dictionary
WordSentiment sentiment_dictionary[] = {
    {"good", 1},
    {"bad", -1},
    {"great", 2},
    {"terrible", -2},
    {"amazing", 3},
    {"awful", -3}
};

// Get the sentiment value of a word from the dictionary
int get_sentiment(char *word) {
    for (int i = 0; i < sizeof(sentiment_dictionary) / sizeof(WordSentiment); i++) {
        if (strcmp(word, sentiment_dictionary[i].word) == 0) {
            return sentiment_dictionary[i].sentiment;
        }
    }

    // If the word is not found in the dictionary, return 0
    return 0;
}

// Analyze the sentiment of a sentence
int analyze_sentiment(char *sentence) {
    // Split the sentence into words
    char *words[100];
    int num_words = 0;
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Calculate the total sentiment value of the sentence
    int total_sentiment = 0;
    for (int i = 0; i < num_words; i++) {
        total_sentiment += get_sentiment(words[i]);
    }

    // Return the total sentiment value
    return total_sentiment;
}

int main() {
    // Get the sentence to analyze from the user
    char sentence[100];
    printf("Enter a sentence to analyze: ");
    scanf("%s", sentence);

    // Analyze the sentiment of the sentence
    int sentiment = analyze_sentiment(sentence);

    // Print the sentiment of the sentence
    if (sentiment > 0) {
        printf("The sentence has a positive sentiment.\n");
    } else if (sentiment < 0) {
        printf("The sentence has a negative sentiment.\n");
    } else {
        printf("The sentence has a neutral sentiment.\n");
    }

    return 0;
}