//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: single-threaded
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
        str[i] = tolower((unsigned char)str[i]);
    }
}

int findWordIndex(WordFrequency *frequencies, const char *word, int totalWords) {
    for (int i = 0; i < totalWords; i++) {
        if (strcmp(frequencies[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

int compareFrequencies(const void *a, const void *b) {
    return ((WordFrequency *)b)->count - ((WordFrequency *)a)->count;
}

void countWordFrequencies(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    WordFrequency frequencies[MAX_WORDS];
    int totalWords = 0;

    char buffer[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", buffer) != EOF) {
        toLowerCase(buffer);
        
        int index = findWordIndex(frequencies, buffer, totalWords);
        if (index != -1) {
            frequencies[index].count++;
        } else {
            if (totalWords < MAX_WORDS) {
                strcpy(frequencies[totalWords].word, buffer);
                frequencies[totalWords].count = 1;
                totalWords++;
            } else {
                printf("Max word limit reached, unable to count more words.\n");
                break;
            }
        }
    }
    fclose(file);

    qsort(frequencies, totalWords, sizeof(WordFrequency), compareFrequencies);

    printf("Word Frequency Count:\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", frequencies[i].word, frequencies[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    countWordFrequencies(argv[1]);

    return EXIT_SUCCESS;
}