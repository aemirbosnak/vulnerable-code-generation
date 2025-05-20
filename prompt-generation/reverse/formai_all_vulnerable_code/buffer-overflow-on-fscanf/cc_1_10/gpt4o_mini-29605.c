//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int sentiment; // +1 for positive, -1 for negative, 0 for neutral
} SentimentWord;

SentimentWord sentimentDictionary[DICTIONARY_SIZE];
int dictionarySize = 0;

void loadSentimentDictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open sentiment dictionary");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %d", sentimentDictionary[dictionarySize].word, &sentimentDictionary[dictionarySize].sentiment) != EOF) {
        dictionarySize++;
        if (dictionarySize >= DICTIONARY_SIZE) {
            printf("Warning: Dictionary size limit reached. Some words might be skipped.\n");
            break;
        }
    }
    fclose(file);
}

int getSentimentScore(const char *word) {
    for (int i = 0; i < dictionarySize; i++) {
        if (strcmp(sentimentDictionary[i].word, word) == 0) {
            return sentimentDictionary[i].sentiment;
        }
    }
    return 0; // neutral if word is not found
}

void analyzeSentiment(const char *text) {
    char word[MAX_WORD_LENGTH];
    int totalSentiment = 0;
    int wordCount = 0;

    const char *ptr = text;
    while (sscanf(ptr, " %1023s", word) == 1) {
        for (char *p = word; *p; p++) *p = tolower(*p); // Convert to lowercase
        totalSentiment += getSentimentScore(word);
        wordCount++;
        ptr += strlen(word);
    }

    if (wordCount == 0) {
        printf("No words found to analyze sentiment.\n");
        return;
    }

    float averageSentiment = (float)totalSentiment / wordCount;

    printf("Total Sentiment Score: %d\n", totalSentiment);
    printf("Average Sentiment Score: %.2f\n", averageSentiment);

    if (averageSentiment > 0) {
        printf("Overall Sentiment: Positive\n");
    } else if (averageSentiment < 0) {
        printf("Overall Sentiment: Negative\n");
    } else {
        printf("Overall Sentiment: Neutral\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <sentiment_dictionary> <text_input>\n", argv[0]);
        return EXIT_FAILURE;
    }

    loadSentimentDictionary(argv[1]);

    FILE *file = fopen(argv[2], "r");
    if (!file) {
        perror("Failed to open text input file");
        return EXIT_FAILURE;
    }

    char text[MAX_LINE_LENGTH];
    while (fgets(text, sizeof(text), file)) {
        analyzeSentiment(text);
    }

    fclose(file);
    return EXIT_SUCCESS;
}