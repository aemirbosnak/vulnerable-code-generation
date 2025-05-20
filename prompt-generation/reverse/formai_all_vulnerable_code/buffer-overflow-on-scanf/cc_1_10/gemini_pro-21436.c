//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_SENTENCES 100

// Structure to represent a word and its sentiment score
typedef struct {
    char* word;
    int score;
} Word;

// Structure to represent a sentence and its sentiment score
typedef struct {
    char* sentence;
    int score;
} Sentence;

// Array of positive and negative words
char* positiveWords[] = { "good", "great", "excellent", "superb", "awesome" };
char* negativeWords[] = { "bad", "terrible", "awful", "horrible", "disgusting" };

// Function to tokenize a sentence into words
char** tokenizeSentence(char* sentence) {
    char** words = malloc(MAX_WORDS * sizeof(char*));
    int wordCount = 0;

    char* token = strtok(sentence, " ");
    while (token != NULL) {
        words[wordCount++] = token;
        token = strtok(NULL, " ");
    }

    return words;
}

// Function to calculate the sentiment score of a sentence
int calculateSentenceScore(char** words, int wordCount) {
    int score = 0;

    for (int i = 0; i < wordCount; i++) {
        char* word = words[i];

        // Check if the word is in the list of positive words
        for (int j = 0; j < 5; j++) {
            if (strcmp(word, positiveWords[j]) == 0) {
                score++;
            }
        }

        // Check if the word is in the list of negative words
        for (int j = 0; j < 5; j++) {
            if (strcmp(word, negativeWords[j]) == 0) {
                score--;
            }
        }
    }

    return score;
}

// Function to analyze the sentiment of a text
void analyzeSentiment(char* text) {
    // Tokenize the text into sentences
    char** sentences = malloc(MAX_SENTENCES * sizeof(char*));
    int sentenceCount = 0;

    char* sentence = strtok(text, ".");
    while (sentence != NULL) {
        sentences[sentenceCount++] = sentence;
        sentence = strtok(NULL, ".");
    }

    // Calculate the sentiment score for each sentence
    Sentence* results = malloc(sentenceCount * sizeof(Sentence));
    for (int i = 0; i < sentenceCount; i++) {
        char** words = tokenizeSentence(sentences[i]);
        int wordCount = 0;

        while (words[wordCount] != NULL) {
            wordCount++;
        }

        results[i].sentence = sentences[i];
        results[i].score = calculateSentenceScore(words, wordCount);
    }

    // Print the results
    for (int i = 0; i < sentenceCount; i++) {
        printf("Sentence: %s\n", results[i].sentence);
        printf("Sentiment score: %d\n", results[i].score);
        printf("\n");
    }
}

int main() {
    // Get the text from the user
    char* text = malloc(1000 * sizeof(char));
    printf("Enter the text you want to analyze: ");
    scanf("%s", text);

    // Analyze the sentiment of the text
    analyzeSentiment(text);

    return 0;
}