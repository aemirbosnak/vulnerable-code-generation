//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment dictionary
char *sentiment_dict[] = {
    "bad", "terrible", "awful",
    "good", "great", "excellent"
};

// Define the sentiment values
int sentiment_values[] = {
    -1, -2, -3,
    1, 2, 3
};

// Get the sentiment value of a word
int get_sentiment_value(char *word) {
    for (int i = 0; i < sizeof(sentiment_dict) / sizeof(char *); i++) {
        if (strcmp(word, sentiment_dict[i]) == 0) {
            return sentiment_values[i];
        }
    }

    return 0;
}

// Analyze the sentiment of a sentence
int analyze_sentiment(char *sentence) {
    int total_sentiment = 0;
    char *word;

    // Tokenize the sentence
    word = strtok(sentence, " ");
    while (word != NULL) {
        // Get the sentiment value of the word
        total_sentiment += get_sentiment_value(word);

        // Get the next word
        word = strtok(NULL, " ");
    }

    return total_sentiment;
}

int main() {
    // Get the sentence from the user
    char sentence[100];
    printf("Enter a sentence: ");
    gets(sentence);

    // Analyze the sentiment of the sentence
    int sentiment = analyze_sentiment(sentence);

    // Print the sentiment of the sentence
    if (sentiment < 0) {
        printf("The sentence has a negative sentiment.\n");
    } else if (sentiment > 0) {
        printf("The sentence has a positive sentiment.\n");
    } else {
        printf("The sentence has a neutral sentiment.\n");
    }

    return 0;
}