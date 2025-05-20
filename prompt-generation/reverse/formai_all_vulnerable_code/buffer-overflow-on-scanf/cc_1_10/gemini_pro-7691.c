//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment scores for each word
int sentiment_scores[] = {
    ['a'] = 1,
    ['b'] = -1,
    ['c'] = 2,
    ['d'] = -2,
    ['e'] = 3,
    ['f'] = -3,
    ['g'] = 4,
    ['h'] = -4,
    ['i'] = 5,
    ['j'] = -5,
};

// Get the sentiment score for a given word
int get_sentiment_score(char word) {
    int score = sentiment_scores[(int) word];
    if (score == 0) {
        return 0;
    } else if (score > 0) {
        return 1;
    } else {
        return -1;
    }
}

// Get the sentiment score for a given sentence
int get_sentence_score(char *sentence) {
    int score = 0;
    for (int i = 0; i < strlen(sentence); i++) {
        score += get_sentiment_score(sentence[i]);
    }
    return score;
}

int main() {
    // Get the sentence from the user
    char sentence[1024];
    printf("Enter a sentence: ");
    scanf("%s", sentence);

    // Get the sentiment score for the sentence
    int score = get_sentence_score(sentence);

    // Print the sentiment score
    printf("The sentiment score for the sentence is: %d\n", score);

    return 0;
}