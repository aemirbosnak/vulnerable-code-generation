//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

int word_exists(WordFrequency *wordArr, int count, const char *word) {
    for (int i = 0; i < count; i++) {
        if (strcmp(wordArr[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void count_word_frequency(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s for reading\n", filename);
        return;
    }

    char buffer[MAX_WORD_LENGTH];
    WordFrequency wordArr[MAX_WORDS];
    int wordCount = 0;

    // Read words from the file
    while (fscanf(file, "%s", buffer) != EOF) {
        to_lower_case(buffer);
        int index = word_exists(wordArr, wordCount, buffer);
        if (index != -1) {
            wordArr[index].frequency++;
        } else {
            strcpy(wordArr[wordCount].word, buffer);
            wordArr[wordCount].frequency = 1;
            wordCount++;
        }
    }
    fclose(file);

    // Sort the words by frequency
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - i - 1; j++) {
            if (wordArr[j].frequency < wordArr[j + 1].frequency) {
                // Swap
                WordFrequency temp = wordArr[j];
                wordArr[j] = wordArr[j + 1];
                wordArr[j + 1] = temp;
            }
        }
    }

    // Print the word frequencies
    printf("Word Frequency Count:\n");
    printf("--------------------\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordArr[i].word, wordArr[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    count_word_frequency(argv[1]);
    return 0;
}