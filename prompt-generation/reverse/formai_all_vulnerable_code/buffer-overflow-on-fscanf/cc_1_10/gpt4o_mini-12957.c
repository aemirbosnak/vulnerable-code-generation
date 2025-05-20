//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 256
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

// Structure to hold a word and its sentiment score
typedef struct {
    char word[MAX_WORD_LENGTH];
    int score;
} SentimentWord;

// Function to categorize sentiment based on score
const char* categorize_sentiment(int score) {
    if(score > 0) {
        return "Positive";
    } else if(score < 0) {
        return "Negative";
    } else {
        return "Neutral";
    }
}

// Function to load sentiment words from a file into an array
int load_sentiment_words(const char *filename, SentimentWord *sentimentWords) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open sentiment words file: %s\n", filename);
        return -1;
    }
    
    int count = 0;
    while(fscanf(file, "%s %d", sentimentWords[count].word, &sentimentWords[count].score) == 2) {
        count++;
    }
    fclose(file);
    return count;
}

// Function to analyze sentiment of a given text
int analyze_sentiment(const char *text, SentimentWord *sentimentWords, int wordCount) {
    int totalScore = 0;

    char *sentenceCopy = strdup(text); // Duplicate sentence to tokenise
    char *word = strtok(sentenceCopy, " ");
    
    while (word != NULL) {
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(word, sentimentWords[i].word) == 0) {
                totalScore += sentimentWords[i].score;
                break;
            }
        }
        word = strtok(NULL, " "); // Get next word
    }

    free(sentenceCopy);
    return totalScore;
}

// Main function to run the sentiment analysis tool
int main() {
    SentimentWord sentimentWords[MAX_WORDS];
    int wordCount = load_sentiment_words("sentiment_words.txt", sentimentWords);
    if(wordCount < 0) {
        return EXIT_FAILURE; // Exit if loading failed
    }

    char inputSentence[MAX_SENTENCE_LENGTH];

    // Main loop for user input
    while (1) {
        printf("Enter a sentence to analyze (or 'exit' to quit): ");
        fgets(inputSentence, sizeof(inputSentence), stdin);
        
        // Remove newline character from string
        size_t len = strlen(inputSentence);
        if (len > 0 && inputSentence[len - 1] == '\n') {
            inputSentence[len - 1] = '\0';
        }

        // Check for exit condition
        if (strcmp(inputSentence, "exit") == 0) {
            break;
        }

        // Analyze the sentiment
        int score = analyze_sentiment(inputSentence, sentimentWords, wordCount);
        printf("Sentiment Score: %d (%s)\n", score, categorize_sentiment(score));
    }

    return EXIT_SUCCESS;
}