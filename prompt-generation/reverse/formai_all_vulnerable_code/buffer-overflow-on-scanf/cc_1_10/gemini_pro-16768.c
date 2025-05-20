//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to hold the sentiment analysis results
typedef struct {
    int positive;
    int negative;
    int neutral;
} sentiment_analysis_results;

// A function to perform sentiment analysis on a given string
sentiment_analysis_results sentiment_analysis(char *string) {
    // Initialize the results struct
    sentiment_analysis_results results = {0, 0, 0};

    // Convert the string to lowercase
    for (int i = 0; i < strlen(string); i++) {
        string[i] = tolower(string[i]);
    }

    // A list of positive words
    char *positive_words[] = {"good", "great", "excellent", "awesome", "superb"};

    // A list of negative words
    char *negative_words[] = {"bad", "terrible", "horrible", "awful", "dreadful"};

    // Iterate over the string and count the number of positive and negative words
    for (int i = 0; i < strlen(string); i++) {
        for (int j = 0; j < sizeof(positive_words) / sizeof(char *); j++) {
            if (strstr(string, positive_words[j]) != NULL) {
                results.positive++;
            }
        }

        for (int j = 0; j < sizeof(negative_words) / sizeof(char *); j++) {
            if (strstr(string, negative_words[j]) != NULL) {
                results.negative++;
            }
        }
    }

    // Calculate the neutral score
    results.neutral = strlen(string) - results.positive - results.negative;

    // Return the results
    return results;
}

// A main function to test the sentiment analysis function
int main() {
    // Get the input string from the user
    char input[1024];
    printf("Enter a string to analyze: ");
    scanf("%s", input);

    // Perform sentiment analysis on the string
    sentiment_analysis_results results = sentiment_analysis(input);

    // Print the results
    printf("Positive: %d\n", results.positive);
    printf("Negative: %d\n", results.negative);
    printf("Neutral: %d\n", results.neutral);

    return 0;
}