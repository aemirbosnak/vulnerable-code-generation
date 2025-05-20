//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare an array of funny words
char *funny_words[] = {
    "lol", "lmao", "rofl", "haha", "hehe", "teehee", "giggle", "chuckle", "snicker", "grin"
};

// Declare a function to analyze the sentiment of a string
int analyze_sentiment(char *string) {
    // Initialize the sentiment score to 0
    int sentiment_score = 0;

    // Iterate over the string and check if it contains any funny words
    for (int i = 0; i < strlen(string); i++) {
        for (int j = 0; j < sizeof(funny_words) / sizeof(funny_words[0]); j++) {
            if (strstr(string, funny_words[j]) != NULL) {
                // If a funny word is found, increment the sentiment score
                sentiment_score++;
            }
        }
    }

    // Return the sentiment score
    return sentiment_score;
}

// Declare a function to print the sentiment analysis results
void print_results(int sentiment_score) {
    // Print the sentiment score
    printf("Sentiment score: %d\n", sentiment_score);

    // Print a funny message based on the sentiment score
    if (sentiment_score > 0) {
        printf("Looks like you're having a good time! Let's party!\n");
    } else {
        printf("Oh no, you seem to be a bit down. Don't worry, I'll tell you a funny joke!\n");
    }
}

// Declare the main function
int main() {
    // Get the input string from the user
    char input_string[100];
    printf("Enter a string: ");
    scanf("%s", input_string);

    // Analyze the sentiment of the input string
    int sentiment_score = analyze_sentiment(input_string);

    // Print the sentiment analysis results
    print_results(sentiment_score);

    return 0;
}