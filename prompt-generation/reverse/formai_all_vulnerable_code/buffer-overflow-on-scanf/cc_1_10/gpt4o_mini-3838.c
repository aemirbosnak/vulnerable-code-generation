//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_LENGTH 1000

typedef struct {
    char text[MAX_LENGTH];
    int score;
} Sentence;

// Function Prototypes
void welcomeMessage();
void tokenizeSentences(const char *text, Sentence sentences[], int *count);
void calculateSentenceScores(Sentence sentences[], int count);
void summarizeText(Sentence sentences[], int count, int summaryLength);
void clearInputBuffer();

// Main Function
int main() {
    welcomeMessage();

    char inputText[MAX_LENGTH];
    Sentence sentences[MAX_SENTENCES];
    int sentenceCount = 0;

    printf("Please enter the text you wish to summarize:\n");
    fgets(inputText, sizeof(inputText), stdin);
    
    tokenizeSentences(inputText, sentences, &sentenceCount);
    calculateSentenceScores(sentences, sentenceCount);
    
    int summaryLength;
    printf("How many sentences should the summary contain? ");
    scanf("%d", &summaryLength);
    
    summarizeText(sentences, sentenceCount, summaryLength);
    
    return 0;
}

void welcomeMessage() {
    printf("Welcome to the Peaceful Text Summarizer!\n");
    printf("This program will help you condense your thoughts into a peaceful summary.\n");
    printf("Relax, take a deep breath, and let the words flow.\n");
}

void tokenizeSentences(const char *text, Sentence sentences[], int *count) {
    char *token;
    char *textCopy = strdup(text);  // Make a modifiable copy of the input text
    
    token = strtok(textCopy, ".!?"); // Tokenize based on sentence-ending punctuation
    while (token != NULL && *count < MAX_SENTENCES) {
        strcpy(sentences[*count].text, token);
        sentences[*count].score = 0; // Initialize sentence score to 0
        (*count)++;
        token = strtok(NULL, ".!?");
    }
    
    free(textCopy); // Release memory
}

void calculateSentenceScores(Sentence sentences[], int count) {
    const char *keywords[] = {"peace", "harmony", "tranquil", "serene", "calm", "breathe", "balance"};
    int keywordCount = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < keywordCount; j++) {
            if (strstr(sentences[i].text, keywords[j]) != NULL) {
                sentences[i].score++;
            }
        }
    }
}

void summarizeText(Sentence sentences[], int count, int summaryLength) {
    printf("\n#### Peaceful Summary ####\n");
    
    // Sort sentences based on scores in descending order
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (sentences[i].score < sentences[j].score) {
                Sentence temp = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp;
            }
        }
    }
    
    for (int i = 0; i < summaryLength && i < count; i++) {
        printf("%s. ", sentences[i].text);
    }
    printf("\nThank you for using the Peaceful Text Summarizer. May your thoughts be calm and collected.\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}