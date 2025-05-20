//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define DICT_SIZE 20

char *positive_words[DICT_SIZE] = {
    "happy", "joyful", "awesome", "fantastic", 
    "great", "good", "love", "excellent", 
    "wonderful", "success", "cheerful", "pleasant", 
    "positive", "fun", "lucky", "delightful", 
    "brilliant", "beautiful", "amazing", "victory"
};

char *negative_words[DICT_SIZE] = {
    "sad", "angry", "terrible", "awful", 
    "bad", "hate", "poor", "disappointing", 
    "horrible", "failure", "gloomy", "displeased", 
    "negative", "frustrated", "unlucky", "miserable", 
    "boring", "ugly", "shameful", "defeat"
};

int check_sentiment(char *word) {
    for (int i = 0; i < DICT_SIZE; i++) {
        if (strcasecmp(word, positive_words[i]) == 0) {
            return 1; // Positive sentiment
        }
        if (strcasecmp(word, negative_words[i]) == 0) {
            return -1; // Negative sentiment
        }
    }
    return 0; // Neutral sentiment
}

void analyze_sentiment(const char *input_text) {
    char word[MAX_WORD_LENGTH];
    int positive_count = 0, negative_count = 0, neutral_count = 0;

    // Tokenizing the input text
    const char *p = input_text;
    while (sscanf(p, "%s", word) > 0) {
        int sentiment = check_sentiment(word);
        if (sentiment == 1) {
            positive_count++;
        } else if (sentiment == -1) {
            negative_count++;
        } else {
            neutral_count++;
        }
        while (*p && *p != ' ') p++; // Move to the next word
        while (*p && *p == ' ') p++; // Skip spaces
    }

    // Displaying the results
    printf("\nSentiment Analysis Result:\n");
    printf("Positive words count: %d\n", positive_count);
    printf("Negative words count: %d\n", negative_count);
    printf("Neutral words count: %d\n", neutral_count);

    if (positive_count > negative_count) {
        printf("Overall Sentiment: Positive\n");
    } else if (negative_count > positive_count) {
        printf("Overall Sentiment: Negative\n");
    } else {
        printf("Overall Sentiment: Neutral\n");
    }
}

int main() {
    char input_text[MAX_LINE_LENGTH];

    printf("Enter text for sentiment analysis (max %d characters):\n", MAX_LINE_LENGTH);
    if (fgets(input_text, sizeof(input_text), stdin)) {
        // Removing newline character
        input_text[strcspn(input_text, "\n")] = 0;
        analyze_sentiment(input_text);
    } else {
        fprintf(stderr, "Error reading input.\n");
    }

    return 0;
}