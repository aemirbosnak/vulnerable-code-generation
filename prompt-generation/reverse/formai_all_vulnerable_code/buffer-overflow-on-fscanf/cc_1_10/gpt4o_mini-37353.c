//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFreq;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int compare(const void *a, const void *b) {
    WordFreq *wordFreqA = (WordFreq *) a;
    WordFreq *wordFreqB = (WordFreq *) b;
    return strcmp(wordFreqA->word, wordFreqB->word);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    WordFreq wordFreqs[MAX_WORDS];
    int totalWords = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", word) != EOF) {
        // Convert word to lowercase
        toLowerCase(word);

        // Check if the word is already in the list
        int found = 0;
        for (int i = 0; i < totalWords; i++) {
            if (strcmp(wordFreqs[i].word, word) == 0) {
                wordFreqs[i].count++;
                found = 1;
                break;
            }
        }

        // If word not found, add it to the list
        if (!found) {
            strncpy(wordFreqs[totalWords].word, word, MAX_WORD_LENGTH);
            wordFreqs[totalWords].count = 1;
            totalWords++;
        }
    }

    fclose(file);

    // Sort words based on lexicographical order
    qsort(wordFreqs, totalWords, sizeof(WordFreq), compare);

    // Print the word frequencies
    printf("Word Frequency Count:\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", wordFreqs[i].word, wordFreqs[i].count);
    }

    return 0;
}