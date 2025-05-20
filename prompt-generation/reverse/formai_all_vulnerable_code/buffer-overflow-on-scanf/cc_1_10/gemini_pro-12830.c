//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

// Define the sentiment scores for each word
int sentiment_scores[] = {
    [0] = 0, [1] = -1, [2] = 1, [3] = -2, [4] = 2,
    [5] = -3, [6] = 3, [7] = -4, [8] = 4, [9] = -5,
    [10] = 5
};

// Define the list of words and their corresponding sentiment scores
char *words[] = {
    "bad", "terrible", "awful", "worst", "horrible",
    "good", "great", "excellent", "best", "wonderful"
};

// Get the sentiment score for a given word
int get_sentiment_score(char *word) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(word, words[i]) == 0) {
            return sentiment_scores[i];
        }
    }
    return 0;
}

// Get the sentiment score for a given sentence
int get_sentiment_score_sentence(char *sentence) {
    int score = 0;
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        score += get_sentiment_score(word);
        word = strtok(NULL, " ");
    }
    return score;
}

// Print the sentiment score for a given sentence
void print_sentiment_score(char *sentence) {
    int score = get_sentiment_score_sentence(sentence);
    printf("Sentiment score: %d\n", score);
}

int main() {
    // Get the input sentence from the user
    char sentence[MAX_WORD_LEN];
    printf("Enter a sentence: ");
    scanf("%s", sentence);

    // Print the sentiment score for the sentence
    print_sentiment_score(sentence);

    return 0;
}