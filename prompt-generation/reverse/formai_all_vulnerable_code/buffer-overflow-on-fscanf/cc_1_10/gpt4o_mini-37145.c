//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Structure to hold word and its count
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// Function prototypes
void processFile(const char *filename, WordCount words[], int *wordCount);
void sortWords(WordCount words[], int wordCount);
void displayTopWords(const WordCount words[], int wordCount, int topN);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <top N words>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    int topN = atoi(argv[2]);
    
    WordCount words[MAX_WORDS] = {0};
    int wordCount = 0;

    processFile(filename, words, &wordCount);
    sortWords(words, wordCount);
    displayTopWords(words, wordCount, topN);

    return 0;
}

void processFile(const char *filename, WordCount words[], int *wordCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        // Normalize the word to lowercase and strip punctuation
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        
        // Check if word already exists in array
        int found = 0;
        for (int i = 0; i < *wordCount; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is new, add it to the list
        if (!found && *wordCount < MAX_WORDS) {
            strcpy(words[*wordCount].word, word);
            words[*wordCount].count = 1;
            (*wordCount)++;
        }
    }

    fclose(file);
}

void sortWords(WordCount words[], int wordCount) {
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = i + 1; j < wordCount; j++) {
            if (words[j].count > words[i].count) {
                WordCount temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void displayTopWords(const WordCount words[], int wordCount, int topN) {
    printf("Top %d words:\n", topN);
    for (int i = 0; i < topN && i < wordCount; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}