//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int compare(const void *a, const void *b) {
    return ((WordFrequency *)b)->count - ((WordFrequency *)a)->count;
}

void countWordFrequencies(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    WordFrequency wordFrequencies[MAX_WORDS] = {0};
    int totalWords = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        // Remove punctuation and convert to lowercase
        for (int i = 0; word[i]; i++) {
            if (ispunct(word[i])) {
                word[i] = '\0';
                break; // Stop at the first punctuation
            }
        }
        
        toLowerCase(word);

        // Check if the word is already in the list
        int found = 0;
        for (int i = 0; i < totalWords; i++) {
            if (strcmp(wordFrequencies[i].word, word) == 0) {
                wordFrequencies[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is new, add it to the list
        if (!found && totalWords < MAX_WORDS) {
            strcpy(wordFrequencies[totalWords].word, word);
            wordFrequencies[totalWords].count = 1;
            totalWords++;
        }
    }
    
    fclose(file);

    qsort(wordFrequencies, totalWords, sizeof(WordFrequency), compare);

    printf("Word Frequencies:\n");
    printf("%-20s %s\n", "Word", "Count");
    printf("--------------------\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%-20s %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    countWordFrequencies(argv[1]);
    return EXIT_SUCCESS;
}