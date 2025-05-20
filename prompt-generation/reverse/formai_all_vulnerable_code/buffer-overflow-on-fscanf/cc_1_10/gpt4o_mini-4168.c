//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REVIEW_LEN 1024
#define MAX_WORD_LEN 128
#define NUM_WORDS 5

// Function prototypes
void load_sentiment_words(const char* sentiment_file, char sentiment_words[NUM_WORDS][MAX_WORD_LEN], int sentiment_scores[NUM_WORDS]);
int analyze_sentiment(const char* review, char sentiment_words[NUM_WORDS][MAX_WORD_LEN], int sentiment_scores[NUM_WORDS]);
void classify_sentiment(int score);

int main() {
    char sentiment_words[NUM_WORDS][MAX_WORD_LEN];
    int sentiment_scores[NUM_WORDS];
    char review[MAX_REVIEW_LEN];

    // Load sentiment words and their associated scores
    load_sentiment_words("sentiment.txt", sentiment_words, sentiment_scores);

    // Get user input
    printf("Enter a review (max %d characters):\n", MAX_REVIEW_LEN - 1);
    fgets(review, MAX_REVIEW_LEN, stdin);
    
    // Analyze sentiment
    int sentiment_score = analyze_sentiment(review, sentiment_words, sentiment_scores);
    classify_sentiment(sentiment_score);

    return 0;
}

void load_sentiment_words(const char* sentiment_file, char sentiment_words[NUM_WORDS][MAX_WORD_LEN], int sentiment_scores[NUM_WORDS]) {
    FILE* file = fopen(sentiment_file, "r");
    if (file == NULL) {
        perror("Error opening sentiment file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NUM_WORDS; i++) {
        fscanf(file, "%s %d", sentiment_words[i], &sentiment_scores[i]);
    }
    fclose(file);
}

int analyze_sentiment(const char* review, char sentiment_words[NUM_WORDS][MAX_WORD_LEN], int sentiment_scores[NUM_WORDS]) {
    int total_score = 0;
    char* token = strtok((char*)review, " ,.-");

    while (token != NULL) {
        for (int i = 0; i < NUM_WORDS; i++) {
            if (strcmp(token, sentiment_words[i]) == 0) {
                total_score += sentiment_scores[i];
                break;
            }
        }
        token = strtok(NULL, " ,.-");
    }

    return total_score;
}

void classify_sentiment(int score) {
    if (score > 0) {
        printf("The sentiment of the review is Positive (Score: %d)\n", score);
    } else if (score < 0) {
        printf("The sentiment of the review is Negative (Score: %d)\n", score);
    } else {
        printf("The sentiment of the review is Neutral (Score: %d)\n", score);
    }
}