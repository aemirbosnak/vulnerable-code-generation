//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment scores for each word
int sentiment_scores[] = {
    [0] = 0, // "a"
    [1] = 0, // "an"
    [2] = 0, // "and"
    [3] = 0, // "are"
    [4] = 1, // "bad"
    [5] = 1, // "beautiful"
    [6] = 1, // "best"
    [7] = 1, // "better"
    [8] = -1, // "bored"
    [9] = -1, // "broken"
    [10] = 1, // "cool"
    [11] = 1, // "excellent"
    [12] = -1, // "fail"
    [13] = 1, // "fantastic"
    [14] = -1, // "fine"
    [15] = 1, // "good"
    [16] = -1, // "great"
    [17] = 1, // "happy"
    [18] = -1, // "horrible"
    [19] = 1, // "interesting"
    [20] = -1, // "lonely"
    [21] = 1, // "lovely"
    [22] = -1, // "mad"
    [23] = 1, // "nice"
    [24] = -1, // "not"
    [25] = 1, // "ok"
    [26] = 1, // "perfect"
    [27] = -1, // "poor"
    [28] = 1, // "pretty"
    [29] = -1, // "sad"
    [30] = 1, // "super"
    [31] = -1, // "terrible"
    [32] = 1, // "wonderful"
    [33] = -1, // "worst"
    [34] = 0, // "you"
    [35] = 0, // "your"
};

// Define the number of words in the sentiment dictionary
int num_words = sizeof(sentiment_scores) / sizeof(int);

// Calculate the sentiment score of a given sentence
int sentiment(char *sentence) {
    // Tokenize the sentence into words
    char *words[100];
    int num_words = 0;
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Calculate the sentiment score of each word
    int score = 0;
    for (int i = 0; i < num_words; i++) {
        int index = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (strcmp(words[i], &c) == 0) {
                index = c - 'a';
                break;
            }
        }
        if (index >= 0 && index < num_words) {
            score += sentiment_scores[index];
        }
    }

    // Return the overall sentiment score
    return score;
}

// Get the sentiment of a given sentence from the user
int main() {
    // Get the sentence from the user
    char sentence[100];
    printf("Enter a sentence: ");
    gets(sentence);

    // Calculate the sentiment score of the sentence
    int score = sentiment(sentence);

    // Print the sentiment score
    printf("Sentiment score: %d\n", score);

    return 0;
}