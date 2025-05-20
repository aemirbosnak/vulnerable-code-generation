//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_WORD_COUNT 100
#define POSITIVE_WORDS_FILE "positive-words.txt"
#define NEGATIVE_WORDS_FILE "negative-words.txt"

typedef struct {
    char word[MAX_WORD_LENGTH];
} Word;

Word positiveWords[MAX_WORD_COUNT];
Word negativeWords[MAX_WORD_COUNT];
int positiveCount = 0;
int negativeCount = 0;

// Function to load words from a file into an array
int loadWords(const char *filename, Word *words, int maxCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open the words file");
        return 0;
    }
    
    int count = 0;
    while (count < maxCount && fscanf(file, "%s", words[count].word) != EOF) {
        count++;
    }
    
    fclose(file);
    return count;
}

// Function to analyze sentiment of a sentence
void analyzeSentiment(const char *sentence) {
    int positiveScore = 0;
    int negativeScore = 0;

    char *token = strtok(sentence, " ");
    while (token != NULL) {
        for (int i = 0; i < positiveCount; i++) {
            if (strcasecmp(token, positiveWords[i].word) == 0) {
                positiveScore++;
                break;
            }
        }
        for (int i = 0; i < negativeCount; i++) {
            if (strcasecmp(token, negativeWords[i].word) == 0) {
                negativeScore++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    printf("Positive Score: %d\n", positiveScore);
    printf("Negative Score: %d\n", negativeScore);

    if (positiveScore > negativeScore) {
        printf("Overall Sentiment: Positive\n");
    } else if (negativeScore > positiveScore) {
        printf("Overall Sentiment: Negative\n");
    } else {
        printf("Overall Sentiment: Neutral\n");
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];

    // Load positive and negative words
    positiveCount = loadWords(POSITIVE_WORDS_FILE, positiveWords, MAX_WORD_COUNT);
    negativeCount = loadWords(NEGATIVE_WORDS_FILE, negativeWords, MAX_WORD_COUNT);

    printf("Sentiment Analysis Tool\n");
    printf("Enter a sentence for analysis (Type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        fgets(sentence, sizeof(sentence), stdin);
        sentence[strcspn(sentence, "\n")] = 0; // Remove newline character

        if (strcasecmp(sentence, "exit") == 0) {
            break; // Exit the loop if the user types 'exit'
        }

        analyzeSentiment(sentence);
        printf("\n");
    }

    return 0;
}