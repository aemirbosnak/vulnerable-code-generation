//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void processFile(const char *filename);
void countWordsAndSentences(FILE *file, int *wordCount, int *sentenceCount, WordCount *wordList, int *uniqueWordCount);
void printStatistics(int wordCount, int sentenceCount, WordCount *wordList, int uniqueWordCount);

int main() {
    char filename[100];

    printf("Enter the filename to process: ");
    scanf("%s", filename);

    processFile(filename);

    return 0;
}

void processFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    int wordCount = 0;
    int sentenceCount = 0;
    int uniqueWordCount = 0;
    WordCount wordList[MAX_WORDS] = {0};

    countWordsAndSentences(file, &wordCount, &sentenceCount, wordList, &uniqueWordCount);

    printStatistics(wordCount, sentenceCount, wordList, uniqueWordCount);

    fclose(file);
}

void countWordsAndSentences(FILE *file, int *wordCount, int *sentenceCount, WordCount *wordList, int *uniqueWordCount) {
    char line[MAX_LINE_LENGTH];
    char *token;

    while (fgets(line, sizeof(line), file)) {
        (*sentenceCount)++; // Increment sentence count for each line

        token = strtok(line, " \n\t");
        while (token != NULL) {
            (*wordCount)++; // Increment word count

            // Normalize the word to lowercase for counting
            for (int i = 0; token[i]; i++) {
                token[i] = tolower(token[i]);
            }

            int found = 0;
            for (int i = 0; i < *uniqueWordCount; i++) {
                if (strcmp(wordList[i].word, token) == 0) {
                    wordList[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found && *uniqueWordCount < MAX_WORDS) {
                strcpy(wordList[*uniqueWordCount].word, token);
                wordList[*uniqueWordCount].count = 1;
                (*uniqueWordCount)++;
            }

            token = strtok(NULL, " \n\t");
        }
    }
}

void printStatistics(int wordCount, int sentenceCount, WordCount *wordList, int uniqueWordCount) {
    printf("\n--- Text Processing Statistics ---\n");
    printf("Total Words: %d\n", wordCount);
    printf("Total Sentences: %d\n", sentenceCount);
    printf("Total Unique Words: %d\n", uniqueWordCount);
    printf("\nMost Frequent Words:\n");

    int maxFrequency = 0;
    for (int i = 0; i < uniqueWordCount; i++) {
        if (wordList[i].count > maxFrequency) {
            maxFrequency = wordList[i].count;
        }
    }

    for (int i = 0; i < uniqueWordCount; i++) {
        if (wordList[i].count == maxFrequency) {
            printf("%s: %d times\n", wordList[i].word, wordList[i].count);
        }
    }
    
    printf("---------------------------------\n\n");
}