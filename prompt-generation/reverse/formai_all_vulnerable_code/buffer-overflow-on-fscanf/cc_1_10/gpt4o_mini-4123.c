//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000
#define MAX_SENTENCE_LENGTH 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int positive;
    int negative;
} SentimentWord;

SentimentWord sentimentDictionary[MAX_WORDS];
int wordCount = 0;

void loadSentimentDictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %d %d", sentimentDictionary[wordCount].word,
                  &sentimentDictionary[wordCount].positive,
                  &sentimentDictionary[wordCount].negative) == 3) {
        wordCount++;
    }

    fclose(file);
}

int getSentimentValue(const char *word) {
    for (int i = 0; i < wordCount; i++) {
        if (strcasecmp(sentimentDictionary[i].word, word) == 0) {
            return sentimentDictionary[i].positive - sentimentDictionary[i].negative;
        }
    }
    return 0; // unknown word
}

void analyzeSentiment(const char *sentence) {
    char word[MAX_WORD_LENGTH];
    int totalSentiment = 0;
    int wordCountInSentence = 0;

    const char *ptr = sentence;
    while (sscanf(ptr, "%s", word) == 1) {
        totalSentiment += getSentimentValue(word);
        wordCountInSentence++;
        ptr += strlen(word) + 1; // Move pointer past the current word
    }

    printf("Sentence: %s\n", sentence);
    printf("Total Sentiment Score: %d | Word Count: %d\n", totalSentiment, wordCountInSentence);
    
    if (totalSentiment > 0) {
        printf("Overall Sentiment: Positive\n\n");
    } else if (totalSentiment < 0) {
        printf("Overall Sentiment: Negative\n\n");
    } else {
        printf("Overall Sentiment: Neutral\n\n");
    }
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char inputSentence[MAX_SENTENCE_LENGTH];
    
    loadSentimentDictionary("sentiment.txt");

    printf("Welcome to the Sentiment Analysis Tool!\n");
    printf("Type your sentences below (type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        if (!fgets(inputSentence, sizeof(inputSentence), stdin)) {
            break; // end on input error
        }

        inputSentence[strcspn(inputSentence, "\n")] = 0; // remove newline
        if (strcasecmp(inputSentence, "exit") == 0) {
            break; // user wants to exit
        }

        analyzeSentiment(inputSentence);
    }

    printf("Exiting the Sentiment Analysis Tool. Goodbye!\n");
    return 0;
}