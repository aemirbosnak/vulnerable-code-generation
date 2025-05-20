//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000

// Function to count words in a sentence
int countWords(char* sentence) {
    int wordCount = 0;
    char* word = strtok(sentence, " ");
    while (word!= NULL) {
        wordCount++;
        word = strtok(NULL, " ");
    }
    return wordCount;
}

// Function to count sentences in a paragraph
int countSentences(char* paragraph) {
    int sentenceCount = 0;
    bool inSentence = false;
    char* sentence = strtok(paragraph, ".");
    while (sentence!= NULL) {
        if (strlen(sentence) > 0) {
            sentenceCount++;
        }
        inSentence =!inSentence;
        sentence = strtok(NULL, ".");
    }
    return sentenceCount;
}

// Function to count paragraphs in a text
int countParagraphs(char* text) {
    int paragraphCount = 0;
    bool inParagraph = false;
    char* paragraph = strtok(text, "\n");
    while (paragraph!= NULL) {
        if (strlen(paragraph) > 0) {
            paragraphCount++;
        }
        inParagraph =!inParagraph;
        paragraph = strtok(NULL, "\n");
    }
    return paragraphCount;
}

// Function to count characters in a string
int countCharacters(char* string) {
    int characterCount = 0;
    while (*string!= '\0') {
        characterCount++;
        string++;
    }
    return characterCount;
}

// Function to print word count statistics
void printWordCountStatistics(int wordCount, int sentenceCount, int paragraphCount, int characterCount) {
    printf("Total words: %d\n", wordCount);
    printf("Total sentences: %d\n", sentenceCount);
    printf("Total paragraphs: %d\n", paragraphCount);
    printf("Total characters: %d\n", characterCount);
}

int main() {
    char text[MAX_SENTENCE_LENGTH];
    printf("Enter your text:\n");
    fgets(text, MAX_SENTENCE_LENGTH, stdin);

    // Remove newline character from text
    int textLength = strlen(text);
    if (text[textLength - 1] == '\n') {
        text[textLength - 1] = '\0';
    }

    int wordCount = countWords(text);
    int sentenceCount = countSentences(text);
    int paragraphCount = countParagraphs(text);
    int characterCount = countCharacters(text);

    printWordCountStatistics(wordCount, sentenceCount, paragraphCount, characterCount);

    return 0;
}