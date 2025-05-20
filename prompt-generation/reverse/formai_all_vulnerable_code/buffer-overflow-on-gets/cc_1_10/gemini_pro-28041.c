//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment scores for each word
const int SENTIMENT_SCORES[] = {
    [0] = -1,  // "bad"
    [1] = 1,   // "good"
    [2] = -2,  // "terrible"
    [3] = 2,   // "excellent"
    [4] = -3,  // "awful"
    [5] = 3,   // "amazing"
};

// Calculate the sentiment score for a given sentence
int calculate_sentiment(char *sentence) {
    int score = 0;

    // Tokenize the sentence into words
    char *words[100];
    int num_words = 0;
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Calculate the sentiment score for each word
    for (int i = 0; i < num_words; i++) {
        int index = -1;
        for (int j = 0; j < 6; j++) {
            if (strcmp(words[i], SENTIMENT_SCORES[j]) == 0) {
                index = j;
                break;
            }
        }

        if (index != -1) {
            score += SENTIMENT_SCORES[index];
        }
    }

    return score;
}

// Print a smiley face or a frowny face based on the sentiment score
void print_sentiment(int score) {
    if (score > 0) {
        printf(":)");
    } else {
        printf(":(");
    }
}

int main() {
    // Get the sentence from the user
    char sentence[100];
    printf("Enter a sentence: ");
    gets(sentence);

    // Calculate the sentiment score for the sentence
    int score = calculate_sentiment(sentence);

    // Print the smiley face or frowny face based on the sentiment score
    printf("The sentiment of the sentence is: ");
    print_sentiment(score);

    return 0;
}