//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_WORD_LENGTH 50
#define MAX_VOCABULARY_SIZE 1000

// Function to convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

// Structure to hold sentiment word and its score
typedef struct {
    char word[MAX_WORD_LENGTH];
    int score;
} SentimentWord;

// Function to load sentiment words from a file
int load_sentiment_words(const char *filename, SentimentWord *sentiment_words) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open sentiment words file");
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%s %d", sentiment_words[count].word, &sentiment_words[count].score) != EOF) {
        count++;
        if (count >= MAX_VOCABULARY_SIZE) break; // Prevent overflow
    }

    fclose(file);
    return count;
}

// Function to tokenize and analyze sentiment of a line of text
int analyze_sentiment(const char *line, SentimentWord *sentiment_words, int sentiment_word_count) {
    char *token;
    char *line_copy = strdup(line);
    if (line_copy == NULL) {
        perror("Failed to allocate memory");
        return 0;
    }

    // Tokenizing the line into words
    int score = 0;
    token = strtok(line_copy, " ,.-\n");
    while (token != NULL) {
        to_lowercase(token);

        // Compare token with sentiment words
        for (int i = 0; i < sentiment_word_count; i++) {
            if (strcmp(token, sentiment_words[i].word) == 0) {
                score += sentiment_words[i].score;
                break;
            }
        }

        token = strtok(NULL, " ,.-\n");
    }

    free(line_copy);
    return score;
}

// Function to perform sentiment analysis on a file
void analyze_file(const char *filename, SentimentWord *sentiment_words, int sentiment_word_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open input text file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        int score = analyze_sentiment(line, sentiment_words, sentiment_word_count);
        printf("Line: %sScore: %d\n", line, score);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <sentiment_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    SentimentWord sentiment_words[MAX_VOCABULARY_SIZE];
    int sentiment_word_count = load_sentiment_words(argv[1], sentiment_words);
    if (sentiment_word_count < 0) {
        return EXIT_FAILURE;
    }

    analyze_file(argv[2], sentiment_words, sentiment_word_count);
    return EXIT_SUCCESS;
}