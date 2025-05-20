//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 100
#define SUMMARY_LENGTH 200

typedef struct {
    char word[MAX_LENGTH];
    int count;
} WordCount;

void processText(const char *filename, WordCount *wordCounts, int *wordCount);
void sortWordCounts(WordCount *wordCounts, int wordCount);
void summarizeText(WordCount *wordCounts, int wordCount, char *summary);
void printSummary(const char *summary);

int main() {
    WordCount wordCounts[MAX_WORDS] = {0};
    int wordCount = 0;
    char summary[SUMMARY_LENGTH] = {0};
    const char *filename = "input.txt"; // Input text file

    processText(filename, wordCounts, &wordCount);
    sortWordCounts(wordCounts, wordCount);
    summarizeText(wordCounts, wordCount, summary);
    printSummary(summary);

    return 0;
}

void processText(const char *filename, WordCount *wordCounts, int *wordCount) {
    FILE *file = fopen(filename, "r");
    char buffer[MAX_LENGTH];
    
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", buffer) != EOF) {
        int found = 0;
        for (int i = 0; i < *wordCount; i++) {
            if (strcmp(wordCounts[i].word, buffer) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }
        if (!found && *wordCount < MAX_WORDS) {
            strncpy(wordCounts[*wordCount].word, buffer, MAX_LENGTH);
            wordCounts[*wordCount].count = 1;
            (*wordCount)++;
        }
    }

    fclose(file);
}

void sortWordCounts(WordCount *wordCounts, int wordCount) {
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = i + 1; j < wordCount; j++) {
            if (wordCounts[i].count < wordCounts[j].count) {
                WordCount temp = wordCounts[i];
                wordCounts[i] = wordCounts[j];
                wordCounts[j] = temp;
            }
        }
    }
}

void summarizeText(WordCount *wordCounts, int wordCount, char *summary) {
    int length = 0;
    for (int i = 0; i < wordCount && i < 5; i++) { // Get top 5 words for summary
        length += snprintf(summary + length, SUMMARY_LENGTH - length, "%s (%d), ", wordCounts[i].word, wordCounts[i].count);
        if (length >= SUMMARY_LENGTH - 5) break; // Avoid buffer overflow
    }
    summary[length - 2] = '.'; // Replace last comma with a period
    summary[length - 1] = '\0'; // Null terminate string
}

void printSummary(const char *summary) {
    printf("Text Summary:\n%s\n", summary);
}