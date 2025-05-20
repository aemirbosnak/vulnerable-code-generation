//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: grateful
#include <stdio.h>
#include <string.h>

// Define the sentiment scores for each word
int sentiment_scores[] = {
    [0] = 0,  // "I"
    [1] = 1,  // "am"
    [2] = 2,  // "so"
    [3] = 3,  // "grateful"
    [4] = 4,  // "for"
    [5] = 5,  // "your"
    [6] = 6,  // "help"
};

// Define the number of words in the dictionary
int num_words = sizeof(sentiment_scores) / sizeof(sentiment_scores[0]);

// Get the sentiment score for a given word
int get_sentiment_score(char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, sentiment_scores[i]) == 0) {
            return i;
        }
    }
    return -1;
}

// Get the sentiment score for a given sentence
int get_sentence_sentiment(char *sentence) {
    char *words[100];
    int num_words = 0;
    int sentiment_score = 0;

    // Tokenize the sentence into words
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Get the sentiment score for each word and sum them up
    for (int i = 0; i < num_words; i++) {
        int score = get_sentiment_score(words[i]);
        if (score != -1) {
            sentiment_score += score;
        }
    }

    return sentiment_score;
}

// Main function
int main() {
    char sentence[100];

    // Get the sentence from the user
    printf("Enter a sentence: ");
    scanf("%s", sentence);

    // Get the sentiment score for the sentence
    int sentiment_score = get_sentence_sentiment(sentence);

    // Print the sentiment score
    printf("The sentiment score is: %d\n", sentiment_score);

    return 0;
}