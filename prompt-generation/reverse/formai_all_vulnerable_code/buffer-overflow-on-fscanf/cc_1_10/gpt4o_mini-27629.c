//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REVIEW_LENGTH 1024
#define SENTIMENT_FILE "sentiments.txt"

typedef struct {
    char *word;
    int sentiment; // 1 for positive, -1 for negative
} Sentiment;

typedef struct {
    Sentiment *sentiments;
    size_t size;
} SentimentList;

// Function to load sentiments from a file into SentimentList
SentimentList load_sentiments(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open sentiment file.\n");
        exit(EXIT_FAILURE);
    }

    SentimentList list;
    list.size = 0;
    list.sentiments = malloc(sizeof(Sentiment) * 100); // Initial size

    char word[MAX_REVIEW_LENGTH];
    int sentiment;
    while (fscanf(file, "%s %d", word, &sentiment) != EOF) {
        if (list.size % 100 == 0) {
            list.sentiments = realloc(list.sentiments, sizeof(Sentiment) * (list.size + 100));
        }
        list.sentiments[list.size].word = strdup(word);
        list.sentiments[list.size].sentiment = sentiment;
        list.size++;
    }
    fclose(file);
    return list;
}

// Function for sentiment analysis of a review
int analyze_sentiment(const char *review, SentimentList *sentiment_list) {
    int total_sentiment = 0;
    char *token = strtok((char *)review, " ");
    
    while (token != NULL) {
        for (size_t i = 0; i < sentiment_list->size; i++) {
            if (strcmp(token, sentiment_list->sentiments[i].word) == 0) {
                total_sentiment += sentiment_list->sentiments[i].sentiment;
                break; // No need to check further if we found the word
            }
        }
        token = strtok(NULL, " ");
    }
    
    return total_sentiment;
}

// Function to get sentiment description
const char *get_sentiment_description(int sentiment_value) {
    if (sentiment_value > 0) {
        return "Positive";
    } else if (sentiment_value < 0) {
        return "Negative";
    } else {
        return "Neutral";
    }
}

int main() {
    SentimentList sentiment_list = load_sentiments(SENTIMENT_FILE);

    char review[MAX_REVIEW_LENGTH];
    printf("Enter a review for sentiment analysis (max %d characters):\n", MAX_REVIEW_LENGTH - 1);
    if (fgets(review, MAX_REVIEW_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        exit(EXIT_FAILURE);
    }

    // Removing new line character if present
    review[strcspn(review, "\n")] = 0;

    int sentiment_value = analyze_sentiment(review, &sentiment_list);
    const char *sentiment_description = get_sentiment_description(sentiment_value);
    
    printf("Sentiment analysis result: %s (Value: %d)\n", sentiment_description, sentiment_value);

    // Clean up
    for (size_t i = 0; i < sentiment_list.size; i++) {
        free(sentiment_list.sentiments[i].word);
    }
    free(sentiment_list.sentiments);

    return 0;
}