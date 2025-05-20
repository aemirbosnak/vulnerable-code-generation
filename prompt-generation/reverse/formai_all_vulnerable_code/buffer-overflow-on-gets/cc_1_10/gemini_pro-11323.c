//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment dictionary
typedef struct sentiment_dict {
    char *word;
    int score;
} sentiment_dict;

// Initialize the sentiment dictionary
sentiment_dict dict[] = {
    { "good", 1 },
    { "bad", -1 },
    { "great", 2 },
    { "terrible", -2 },
    { "amazing", 3 },
    { "awful", -3 },
    { "excellent", 4 },
    { "horrible", -4 },
    { "wonderful", 5 },
    { "dreadful", -5 }
};

// Calculate the sentiment score of a given text
int calculate_sentiment(char *text) {
    int score = 0;
    char *word;

    // Tokenize the text
    word = strtok(text, " ");
    while (word != NULL) {
        // Find the word in the sentiment dictionary
        for (int i = 0; i < sizeof(dict) / sizeof(dict[0]); i++) {
            if (strcmp(word, dict[i].word) == 0) {
                // Add the word's score to the total score
                score += dict[i].score;
                break;
            }
        }

        // Get the next word
        word = strtok(NULL, " ");
    }

    return score;
}

// Print the sentiment analysis results
void print_results(int score) {
    if (score > 0) {
        printf("The text has a positive sentiment.\n");
    } else if (score < 0) {
        printf("The text has a negative sentiment.\n");
    } else {
        printf("The text has a neutral sentiment.\n");
    }
}

int main() {
    // Get the text from the user
    char text[100];
    printf("Enter the text you want to analyze: ");
    gets(text);

    // Calculate the sentiment score of the text
    int score = calculate_sentiment(text);

    // Print the sentiment analysis results
    print_results(score);

    return 0;
}