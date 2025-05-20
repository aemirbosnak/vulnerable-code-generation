//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: realistic
#include <stdio.h>
#include <string.h>

// Define the sentiment scores for each word
int sentiment_scores[] = {
    [0] = 0, // Neutral
    [1] = -1, // Negative
    [2] = 1,  // Positive
};

// Define the list of words and their sentiment scores
char *words[] = {
    "bad", "terrible", "awful",
    "good", "great", "excellent",
};

// Get the sentiment score for a given word
int get_sentiment_score(char *word) {
    for (int i = 0; i < sizeof(words) / sizeof(char *); i++) {
        if (strcmp(word, words[i]) == 0) {
            return sentiment_scores[i];
        }
    }

    // Return 0 if the word is not found in the list
    return 0;
}

// Analyze the sentiment of a given text
int analyze_sentiment(char *text) {
    // Split the text into words
    char *words[strlen(text)];
    int num_words = 0;
    char *word = strtok(text, " ");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Calculate the sentiment score for each word
    int sentiment_score = 0;
    for (int i = 0; i < num_words; i++) {
        sentiment_score += get_sentiment_score(words[i]);
    }

    // Return the overall sentiment score
    return sentiment_score;
}

int main() {
    // Get the text to analyze from the user
    char text[100];
    printf("Enter the text to analyze: ");
    scanf("%s", text);

    // Analyze the sentiment of the text
    int sentiment_score = analyze_sentiment(text);

    // Print the sentiment score
    printf("The sentiment score is: %d\n", sentiment_score);

    return 0;
}