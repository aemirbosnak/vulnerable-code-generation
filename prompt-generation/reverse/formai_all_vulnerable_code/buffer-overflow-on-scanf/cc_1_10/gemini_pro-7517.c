//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

// Define the sentiment scores for each word
const int SENTIMENT_SCORES[] = {
    [0]  = -1, // "bad"
    [1]  = 1,  // "good"
    [2]  = -2, // "terrible"
    [3]  = 2,  // "amazing"
    [4]  = -3, // "horrible"
    [5]  = 3,  // "wonderful"
    [6]  = -4, // "atrocious"
    [7]  = 4,  // "fantastic"
    [8]  = -5, // "abysmal"
    [9]  = 5,  // "brilliant"
};

// Get the sentiment score for a given word
int get_sentiment_score(const char *word) {
    for (int i = 0; i < sizeof(SENTIMENT_SCORES) / sizeof(int); i++) {
        if (strcmp(word, SENTIMENT_SCORES[i]) == 0) {
            return i;
        }
    }

    // Word not found, return 0
    return 0;
}

// Analyze the sentiment of a given sentence
int analyze_sentiment(const char *sentence) {
    // Tokenize the sentence into words
    char *words[100];
    int num_words = 0;
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Compute the sentiment score for each word
    int sentiment_score = 0;
    for (int i = 0; i < num_words; i++) {
        sentiment_score += get_sentiment_score(words[i]);
    }

    // Return the sentiment score for the sentence
    return sentiment_score;
}

int main() {
    // Get the input sentence from the user
    char sentence[100];
    printf("Enter a sentence: ");
    scanf("%s", sentence);

    // Analyze the sentiment of the sentence
    int sentiment_score = analyze_sentiment(sentence);

    // Print the sentiment score
    printf("Sentiment score: %d\n", sentiment_score);

    return 0;
}