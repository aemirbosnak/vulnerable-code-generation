//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_NAME 256

// Function prototypes
void analyzeText(const char* fileName);
void processWord(const char* word, int* totalWords, int* totalLetters);
void displayResults(int totalWords, int totalLetters);

int main() {
    char fileName[MAX_FILE_NAME];

    printf("Welcome to the Sherlock Holmes Word Count Tool!\n");
    printf("In this dark alley of literature, words are our clues.\n");
    printf("Please enter the name of the text file to analyze: ");
    scanf("%s", fileName);

    analyzeText(fileName);

    return 0;
}

void analyzeText(const char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        fprintf(stderr, "Oh dear Watson! I cannot find the file: %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    int totalWords = 0;
    int totalLetters = 0;

    while (fscanf(file, "%s", word) != EOF) {
        processWord(word, &totalWords, &totalLetters);
    }

    fclose(file);
    displayResults(totalWords, totalLetters);
}

void processWord(const char* word, int* totalWords, int* totalLetters) {
    // Filtering out punctuation from the word
    int length = strlen(word);
    char cleanWord[MAX_WORD_LENGTH];
    int j = 0;

    for (int i = 0; i < length; i++) {
        if (isalpha(word[i])) {
            cleanWord[j++] = word[i];
        }
    }
    cleanWord[j] = '\0';

    if (j > 0) {
        (*totalWords)++;
        *totalLetters += j;
    }
}

void displayResults(int totalWords, int totalLetters) {
    printf("\nElementary, my dear Watson...\n");
    printf("Total words analyzed: %d\n", totalWords);
    printf("Total letters counted: %d\n", totalLetters);
    printf("Thus, the case is closed!\n");
}