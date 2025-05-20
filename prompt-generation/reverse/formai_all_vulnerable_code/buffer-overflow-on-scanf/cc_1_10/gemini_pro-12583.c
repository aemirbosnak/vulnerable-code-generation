//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: imaginative
#include <stdio.h>
#include <string.h>

// Define a struct to hold the sentiment analysis result
typedef struct {
    float positive;
    float neutral;
    float negative;
} SentimentAnalysisResult;

// Function to analyze the sentiment of a given text
SentimentAnalysisResult analyze_sentiment(const char *text) {
    // Initialize the result struct
    SentimentAnalysisResult result = {0.0, 0.0, 0.0};

    // Create an array of positive words
    const char *positive_words[] = {"good", "great", "excellent", "awesome", "superb"};
    // Create an array of negative words
    const char *negative_words[] = {"bad", "terrible", "horrible", "awful", "worst"};

    // Loop through the text and count the occurrences of each positive and negative word
    for (int i = 0; i < strlen(text); i++) {
        for (int j = 0; j < sizeof(positive_words) / sizeof(char *); j++) {
            if (strstr(text + i, positive_words[j]) != NULL) {
                result.positive++;
            }
        }
        for (int j = 0; j < sizeof(negative_words) / sizeof(char *); j++) {
            if (strstr(text + i, negative_words[j]) != NULL) {
                result.negative++;
            }
        }
    }

    // Calculate the neutral score as the remaining percentage
    result.neutral = 100.0 - result.positive - result.negative;

    // Return the result
    return result;
}

// Function to print the sentiment analysis result
void print_sentiment_analysis_result(const SentimentAnalysisResult *result) {
    printf("Positive: %.2f%%\n", result->positive);
    printf("Neutral: %.2f%%\n", result->neutral);
    printf("Negative: %.2f%%\n", result->negative);
}

int main() {
    // Get the text from the user
    char text[1024];
    printf("Enter the text to analyze: ");
    scanf("%s", text);

    // Analyze the sentiment of the text
    SentimentAnalysisResult result = analyze_sentiment(text);

    // Print the sentiment analysis result
    print_sentiment_analysis_result(&result);

    return 0;
}