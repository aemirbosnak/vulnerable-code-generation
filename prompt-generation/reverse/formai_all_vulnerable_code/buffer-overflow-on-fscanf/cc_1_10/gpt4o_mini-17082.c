//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int sentiment; // -1 for negative, 1 for positive
} SentimentWord;

SentimentWord sentimentWords[MAX_WORDS];
int sentimentWordCount = 0;

void loadSentimentWords(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open sentiment words file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %d", sentimentWords[sentimentWordCount].word, &sentimentWords[sentimentWordCount].sentiment) != EOF) {
        sentimentWordCount++;
        if (sentimentWordCount >= MAX_WORDS) break; // Prevent overflow
    }

    fclose(file);
}

int getSentiment(const char *word) {
    for (int i = 0; i < sentimentWordCount; i++) {
        if (strcmp(sentimentWords[i].word, word) == 0) {
            return sentimentWords[i].sentiment;
        }
    }
    return 0; // Neutral if not found
}

void analyzeSentiment(const char *text) {
    char *token = strtok(text, " ");
    int totalSentiment = 0;
    int wordCount = 0;

    while (token != NULL) {
        int sentiment = getSentiment(token);
        totalSentiment += sentiment;
        wordCount++;
        token = strtok(NULL, " ");
    }

    printf("Analyzed %d words.\n", wordCount);
    if (totalSentiment > 0) {
        printf("Overall sentiment: Positive\n");
    } else if (totalSentiment < 0) {
        printf("Overall sentiment: Negative\n");
    } else {
        printf("Overall sentiment: Neutral\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <sentiment_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    loadSentimentWords(argv[1]);

    FILE *textFile = fopen(argv[2], "r");
    if (!textFile) {
        perror("Could not open text file");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), textFile)) {
        line[strcspn(line, "\n")] = 0; // Remove newline character
        printf("Analyzing: %s\n", line);
        analyzeSentiment(line);
        printf("\n");
    }

    fclose(textFile);
    return EXIT_SUCCESS;
}