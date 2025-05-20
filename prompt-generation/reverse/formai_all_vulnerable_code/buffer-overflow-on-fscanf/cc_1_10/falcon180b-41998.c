//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

// Structure to hold word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *wordA = a;
    const WordFrequency *wordB = b;

    return strcmp(wordA->word, wordB->word);
}

bool isValidWord(char *word) {
    int length = strlen(word);

    // Check if word is too long
    if (length > MAX_WORD_LENGTH) {
        return false;
    }

    // Check if word contains only letters
    for (int i = 0; i < length; i++) {
        if (!isalpha(word[i])) {
            return false;
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    // Read words from file and count their frequencies
    while (fscanf(file, "%s", word)!= EOF) {
        if (isValidWord(word)) {
            for (int i = 0; i < numWords; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].frequency++;
                    break;
                }
            }
        } else {
            printf("Invalid word: %s\n", word);
        }

        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }

        strcpy(words[numWords].word, word);
        words[numWords].frequency = 1;
        numWords++;
    }

    fclose(file);

    // Sort words by frequency
    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    // Print word frequencies
    printf("Word frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}