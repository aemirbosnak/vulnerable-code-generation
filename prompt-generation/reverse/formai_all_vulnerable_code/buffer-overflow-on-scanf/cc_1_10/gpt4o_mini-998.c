//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: imaginative
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

int compare(const void *a, const void *b) {
    WordFrequency *wf1 = (WordFrequency *)a;
    WordFrequency *wf2 = (WordFrequency *)b;
    return wf2->count - wf1->count; // Sort by count descending
}

void normalizeWord(char *word) {
    char *p = word;
    while (*p) {
        *p = tolower(*p);
        p++;
    }
}

int addWord(WordFrequency *words, int *wordCount, const char *word) {
    for (int i = 0; i < *wordCount; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return 0; // Found and updated
        }
    }
    // New word case
    if (*wordCount < MAX_WORDS) {
        strncpy(words[*wordCount].word, word, MAX_WORD_LENGTH);
        words[*wordCount].count = 1;
        (*wordCount)++;
        return 1; // New word added
    }
    return -1; // No space left
}

int main() {
    FILE *file;
    char filename[100];
    char buffer[256];
    WordFrequency words[MAX_WORDS];
    int wordCount = 0;

    printf("Enter the filename (without spaces): ");
    scanf("%s", filename);
    
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return EXIT_FAILURE;
    }

    printf("File opened successfully. Analyzing word frequency...\n");

    while (fgets(buffer, sizeof(buffer), file)) {
        char *token = strtok(buffer, " ,.!?;:\n");
        while (token != NULL) {
            normalizeWord(token);
            if (strlen(token) > 0) {
                if (addWord(words, &wordCount, token) == -1) {
                    fprintf(stderr, "Error: Too many unique words!\n");
                    fclose(file);
                    return EXIT_FAILURE;
                }
            }
            token = strtok(NULL, " ,.!?;:\n");
        }
    }

    fclose(file);

    // Sort the words according to frequency
    qsort(words, wordCount, sizeof(WordFrequency), compare);

    // Display the word frequencies
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    // Print summary
    printf("\nTotal unique words recorded: %d\n", wordCount);

    return EXIT_SUCCESS;
}