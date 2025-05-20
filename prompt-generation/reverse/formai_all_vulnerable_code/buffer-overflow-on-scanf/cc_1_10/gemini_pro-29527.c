//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize the sentiment dictionary
char *sentiment_dictionary[] = {
    "awesome", "great", "super", "fantastic", "wonderful",
    "bad", "terrible", "horrible", "awful", "dreadful"
};

// Get the sentiment of a word
int get_sentiment(char *word) {
    for (int i = 0; i < sizeof(sentiment_dictionary) / sizeof(char *); i++) {
        if (strcmp(word, sentiment_dictionary[i]) == 0) {
            return i < 5 ? 1 : -1;
        }
    }
    return 0;
}

// Analyze the sentiment of a sentence
int analyze_sentiment(char *sentence) {
    int sentiment = 0;
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        sentiment += get_sentiment(token);
        token = strtok(NULL, " ");
    }
    return sentiment;
}

int main() {
    // Get the sentence from the user
    char sentence[100];
    printf("Enter a sentence: ");
    scanf("%s", sentence);

    // Analyze the sentiment of the sentence
    int sentiment = analyze_sentiment(sentence);

    // Print the result
    if (sentiment > 0) {
        printf("The sentence has a positive sentiment.\n");
    } else if (sentiment < 0) {
        printf("The sentence has a negative sentiment.\n");
    } else {
        printf("The sentence has a neutral sentiment.\n");
    }

    return 0;
}