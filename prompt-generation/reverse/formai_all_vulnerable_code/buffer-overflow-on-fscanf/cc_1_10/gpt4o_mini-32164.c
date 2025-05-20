//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_WORD_LENGTH 32
#define MAX_WORDS 128

// Structure to hold sentiment words and their corresponding scores
typedef struct {
    char word[MAX_WORD_LENGTH];
    int score; // score can be positive for positive words, negative for negative
} SentimentWord;

// Functions
void loadSentimentWords(SentimentWord *sentimentWords, int *wordCount);
int analyzeSentiment(const char *sentence, SentimentWord *sentimentWords, int wordCount);
void processInputText(const char *filename, SentimentWord *sentimentWords, int wordCount);

int main() {
    SentimentWord sentimentWords[MAX_WORDS];
    int wordCount = 0;

    // Load sentiment words from file
    loadSentimentWords(sentimentWords, &wordCount);

    // Analyze sentiments from a text file
    const char *inputFilename = "input.txt";
    processInputText(inputFilename, sentimentWords, wordCount);

    return 0;
}

void loadSentimentWords(SentimentWord *sentimentWords, int *wordCount) {
    FILE *file = fopen("sentiment_words.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening sentiment words file.\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %d", sentimentWords[*wordCount].word, &sentimentWords[*wordCount].score) != EOF) {
        (*wordCount)++;
        if (*wordCount >= MAX_WORDS) {
            break;
        }
    }

    fclose(file);
}

int analyzeSentiment(const char *sentence, SentimentWord *sentimentWords, int wordCount) {
    int totalScore = 0;
    char word[MAX_WORD_LENGTH];
    const char *ptr = sentence;

    // Split sentence into words by space or punctuation
    while (sscanf(ptr, "%s", word) > 0) {
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcasecmp(word, sentimentWords[i].word) == 0) {
                totalScore += sentimentWords[i].score;
                found = 1;
                break;
            }
        }
        if (!found) {
            totalScore += 0; // Word not found, do nothing
        }
        while (*ptr != ' ' && *ptr != '\0') {
            ptr++;
        }
        while (*ptr == ' ') {
            ptr++;
        }
    }

    return totalScore;
}

void processInputText(const char *filename, SentimentWord *sentimentWords, int wordCount) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening input text file.\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        // Remove newline character
        line[strcspn(line, "\n")] = 0;
        int sentimentScore = analyzeSentiment(line, sentimentWords, wordCount);
        printf("Sentiment score for: \"%s\" is %d\n", line, sentimentScore);
    }

    fclose(file);
}