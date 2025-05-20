//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define MAX_SENTENCES 100
#define MAX_WORDS 100

// A structure to hold sentences
typedef struct {
    char* sentences[MAX_SENTENCES];
    int count;
} SentenceArray;

// A structure to hold word frequencies
typedef struct {
    char* word;
    int frequency;
} WordFreq;

// Function prototypes
void toLowerCase(char* str);
SentenceArray splitIntoSentences(char* text);
WordFreq* extractWordFrequencies(char* text, int* size);
void summarizeText(const char* text, int sentenceLimit);
void freeResources(SentenceArray sentenceArray, WordFreq* wordFreqs, int size);

int main() {
    char text[MAX_LENGTH];

    printf("Enter the text you want to summarize (max %d characters):\n", MAX_LENGTH);
    fgets(text, MAX_LENGTH, stdin); // Read input text

    int sentenceLimit;
    printf("Enter the maximum number of sentences for the summary: ");
    scanf("%d", &sentenceLimit);

    summarizeText(text, sentenceLimit);

    return 0;
}

// Convert string to lowercase for uniformity
void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Split the text into sentences based on punctuation
SentenceArray splitIntoSentences(char* text) {
    SentenceArray sentenceArray;
    sentenceArray.count = 0;

    char* token = strtok(text, ".!?");
    while (token != NULL && sentenceArray.count < MAX_SENTENCES) {
        sentenceArray.sentences[sentenceArray.count] = strdup(token);
        sentenceArray.count++;
        token = strtok(NULL, ".!?");
    }
    return sentenceArray;
}

// Extract word frequencies from text
WordFreq* extractWordFrequencies(char* text, int* size) {
    char* token;
    WordFreq* wordFreqs = malloc(MAX_WORDS * sizeof(WordFreq));
    *size = 0;

    token = strtok(text, " ,;\n");
    while (token != NULL) {
        toLowerCase(token);
        int found = 0;
        for (int i = 0; i < *size; i++) {
            if (strcmp(wordFreqs[i].word, token) == 0) {
                wordFreqs[i].frequency++;
                found = 1;
                break;
            }
        }
        if (!found && *size < MAX_WORDS) {
            wordFreqs[*size].word = strdup(token);
            wordFreqs[*size].frequency = 1;
            (*size)++;
        }
        token = strtok(NULL, " ,;\n");
    }
    return wordFreqs;
}

// Summarize the text based on frequency
void summarizeText(const char* text, int sentenceLimit) {
    // Create a mutable copy of text to use strtok
    char* mutableText = strdup(text);
    SentenceArray sentences = splitIntoSentences(mutableText);
    
    int wordFreqSize;
    WordFreq* wordFreqs = extractWordFrequencies(mutableText, &wordFreqSize);

    // Sort sentences by a simple heuristic based on word frequencies
    for (int i = 0; i < sentences.count; i++) {
        int score = 0;
        char* sentence = sentences.sentences[i];
        char* word = strtok(sentence, " ,;\n");
        while (word != NULL) {
            toLowerCase(word);
            for (int j = 0; j < wordFreqSize; j++) {
                if (strcmp(wordFreqs[j].word, word) == 0) {
                    score += wordFreqs[j].frequency;
                    break;
                }
            }
            word = strtok(NULL, " ,;\n");
        }
        printf("Sentence: \"%s\" - Score: %d\n", sentences.sentences[i], score);
    }

    printf("\nTop %d Sentences of Summary:\n", sentenceLimit);
    for (int i = 0; i < sentenceLimit && i < sentences.count; i++) {
        printf("%s.\n", sentences.sentences[i]);
        free(sentences.sentences[i]); // Free each sentence after printing
    }

    free(mutableText);
    freeResources(sentences, wordFreqs, wordFreqSize);
}

// Free allocated memory
void freeResources(SentenceArray sentenceArray, WordFreq* wordFreqs, int size) {
    for (int i = 0; i < size; i++) {
        free(wordFreqs[i].word);
    }
    free(wordFreqs);
}