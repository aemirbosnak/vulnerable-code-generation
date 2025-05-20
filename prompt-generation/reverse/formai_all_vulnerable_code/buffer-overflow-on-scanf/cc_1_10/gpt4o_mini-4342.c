//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Structure to hold a word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// Function prototypes
void processFile(const char *filename);
void toLowerCase(char *str);
int addWord(WordCount *wordCounts, int *wordCountSize, const char *word);
void printWordCounts(WordCount *wordCounts, int wordCountSize);
void trimNewline(char *str);

int main() {
    char filename[100];
    
    printf("Welcome to the Text Processing Program!\n");
    printf("Please enter the filename (with extension): ");
    scanf("%s", filename);
    
    processFile(filename);
    
    return 0;
}

void processFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    char line[256];
    int totalLines = 0, totalWords = 0, totalCharacters = 0;
    WordCount wordCounts[MAX_WORDS] = {0};
    int wordCountSize = 0;

    while (fgets(line, sizeof(line), file)) {
        trimNewline(line);  // Clean the line from newline character
        totalLines++;
        totalCharacters += strlen(line);

        char *token = strtok(line, " ");
        while (token != NULL) {
            toLowerCase(token);  // Normalize the word to lower case
            totalWords += addWord(wordCounts, &wordCountSize, token);
            token = strtok(NULL, " ");
        }
    }

    fclose(file);
    
    printf("\nText Processing Complete!\n");
    printf("Total Lines: %d\n", totalLines);
    printf("Total Words: %d\n", totalWords);
    printf("Total Characters: %d\n", totalCharacters);
    
    printWordCounts(wordCounts, wordCountSize);
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int addWord(WordCount *wordCounts, int *wordCountSize, const char *word) {
    for (int i = 0; i < *wordCountSize; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            wordCounts[i].count++;
            return 0;  // Word already exists
        }
    }
    // New word
    if (*wordCountSize < MAX_WORDS) {
        strcpy(wordCounts[*wordCountSize].word, word);
        wordCounts[*wordCountSize].count = 1;
        (*wordCountSize)++;
        return 1;  // New word added
    }
    return 0;  // Word list is full
}

void printWordCounts(WordCount *wordCounts, int wordCountSize) {
    printf("\nWord Frequency Count:\n");
    for (int i = 0; i < wordCountSize; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

void trimNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}