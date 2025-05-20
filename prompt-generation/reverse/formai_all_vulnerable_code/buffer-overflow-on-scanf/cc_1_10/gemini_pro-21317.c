//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment scores for each word
const char *positive_words[] = {"good", "great", "excellent", "wonderful", "amazing"};
const char *negative_words[] = {"bad", "terrible", "awful", "horrible", "worst"};

// Define the number of positive and negative words
const int num_positive_words = sizeof(positive_words) / sizeof(char *);
const int num_negative_words = sizeof(negative_words) / sizeof(char *);

// Function to calculate the sentiment score of a sentence
int calculate_sentiment(const char *sentence) {
    // Initialize the sentiment score to 0
    int sentiment = 0;

    // Tokenize the sentence into words
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        // Check if the word is a positive word
        for (int i = 0; i < num_positive_words; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                sentiment++;
                break;
            }
        }

        // Check if the word is a negative word
        for (int i = 0; i < num_negative_words; i++) {
            if (strcmp(token, negative_words[i]) == 0) {
                sentiment--;
                break;
            }
        }

        // Get the next word
        token = strtok(NULL, " ");
    }

    // Return the sentiment score
    return sentiment;
}

// Main function
int main() {
    // Get the input sentence from the user
    char sentence[100];
    printf("Enter a sentence: ");
    scanf("%s", sentence);

    // Calculate the sentiment score of the sentence
    int sentiment = calculate_sentiment(sentence);

    // Print the sentiment score
    printf("The sentiment score is: %d\n", sentiment);

    return 0;
}