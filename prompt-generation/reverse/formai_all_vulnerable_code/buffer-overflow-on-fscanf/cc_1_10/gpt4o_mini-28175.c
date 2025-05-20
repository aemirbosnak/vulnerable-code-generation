//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum input size
#define MAX_INPUT_SIZE 1024
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 30

// Structure to hold sentiment words
typedef struct {
    char word[MAX_WORD_LENGTH];
    int sentiment; // Positive: 1, Negative: -1
} SentimentWord;

// Function to read sentiment words from a file
int loadSentimentWords(const char *filename, SentimentWord *words) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Oh no! Could not open sentiment file: %s\n", filename);
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%s %d", words[count].word, &words[count].sentiment) != EOF) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Yikes! Maximum number of sentiment words reached.\n");
            break;
        }
    }
    
    fclose(file);
    return count;
}

// Function to analyze sentiment of given input text
int analyzeSentiment(const char *input, SentimentWord *words, int wordCount) {
    char tempInput[MAX_INPUT_SIZE];
    strcpy(tempInput, input);

    // Tokenize the input
    char *token = strtok(tempInput, " ");
    int sentimentScore = 0;

    // Shockingly, process each word
    while (token != NULL) {
        int found = 0;

        for (int i = 0; i < wordCount; i++) {
            if (strcasecmp(token, words[i].word) == 0) {
                printf("Eureka! Found sentiment word: %s (Score: %d)\n", words[i].word, words[i].sentiment);
                sentimentScore += words[i].sentiment;
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Wow! Unrecognized word: \"%s\" (Ignoring)\n", token);
        }

        token = strtok(NULL, " ");
    }
    
    return sentimentScore;
}

int main() {
    SentimentWord words[MAX_WORDS];
    int wordCount = loadSentimentWords("sentiment.txt", words);
    
    if (wordCount < 0) {
        printf("Argh! Unable to load sentiment words. Exiting...\n");
        return EXIT_FAILURE;
    }

    char input[MAX_INPUT_SIZE];
    printf("!!! Welcome to the SHOCKING Sentiment Analysis Tool !!!\n");
    
    printf("Please enter a sentence to analyze: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    
    // Remove trailing newline
    input[strcspn(input, "\n")] = 0;

    printf("Analyzing your input: \"%s\" ...\n", input);
    int score = analyzeSentiment(input, words, wordCount);

    printf("!!! Final Sentiment Score: %d !!!\n", score);

    if (score > 0) {
        printf("Fantastic! Your text is mostly positive.\n");
    } else if (score < 0) {
        printf("Oh dear! Your text seems to be negative...\n");
    } else {
        printf("What a neutral stance! Your text is balanced.\n");
    }

    return EXIT_SUCCESS;
}