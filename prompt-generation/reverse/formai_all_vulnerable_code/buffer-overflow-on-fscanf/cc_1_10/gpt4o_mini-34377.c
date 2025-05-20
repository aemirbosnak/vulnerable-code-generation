//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 100

typedef struct {
    char word[WORD_LENGTH];
    int sentiment; // 1 for positive, -1 for negative, 0 for neutral
} WordSentiment;

WordSentiment sentiment_dict[MAX_WORDS];
int dict_size = 0;

// Function to load the sentiment dictionary from a file
void load_sentiment_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %d", sentiment_dict[dict_size].word, &sentiment_dict[dict_size].sentiment) != EOF) {
        dict_size++;
    }

    fclose(file);
}

// Function to get the sentiment of a word
int get_word_sentiment(const char *word) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(sentiment_dict[i].word, word) == 0) {
            return sentiment_dict[i].sentiment;
        }
    }
    return 0; // Default to neutral if word is not found
}

// Function to analyze the sentiment of a sentence
void analyze_sentiment(const char *sentence) {
    char *token;
    char sentence_copy[1024];
    strcpy(sentence_copy, sentence);
    
    token = strtok(sentence_copy, " ");
    int total_sentiment = 0;
    int word_count = 0;

    while (token != NULL) {
        int sentiment = get_word_sentiment(token);
        total_sentiment += sentiment;
        word_count++;
        token = strtok(NULL, " ");
    }

    double average_sentiment = (word_count == 0) ? 0 : (double)total_sentiment / word_count;

    printf("Analyzed Sentence: '%s'\n", sentence);
    printf("Total Sentiment: %d\n", total_sentiment);
    printf("Average Sentiment: %.2f\n", average_sentiment);

    if (average_sentiment > 0) {
        printf("Overall sentiment: Positive 😊\n");
    } else if (average_sentiment < 0) {
        printf("Overall sentiment: Negative 😞\n");
    } else {
        printf("Overall sentiment: Neutral 😐\n");
    }
}

// Main function
int main() {
    // Load the sentiment dictionary
    load_sentiment_dictionary("sentiment.txt");

    // Sample sentences for analysis
    char *sentences[] = {
        "I love programming",
        "C is a very powerful language",
        "I hate bugs",
        "This is a neutral statement",
        "Life is beautiful and sometimes painful"
    };

    // Analyze each sentence
    for (int i = 0; i < sizeof(sentences) / sizeof(sentences[0]); i++) {
        analyze_sentiment(sentences[i]);
        printf("\n");
    }

    return 0;
}