//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;
    return strcmp(wordA->word, wordB->word);
}

void countWords(FILE *file, WordFrequency *wordFrequencies) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0'; // Remove newline character
        int i;
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
                break;
            }
        }
        int wordLength = strlen(word);
        if (wordLength > 0) {
            int j;
            for (j = 0; j < MAX_WORD_LENGTH && j < wordLength; j++) {
                wordFrequencies[i].word[j] = tolower(word[j]);
            }
            wordFrequencies[i].word[j] = '\0';
            wordFrequencies[i].frequency++;
        }
    }
}

void sortWords(WordFrequency *wordFrequencies) {
    qsort(wordFrequencies, MAX_WORDS, sizeof(WordFrequency), compareWords);
}

void printWords(WordFrequency *wordFrequencies) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (wordFrequencies[i].frequency > 0) {
            printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    WordFrequency wordFrequencies[MAX_WORDS];
    countWords(file, wordFrequencies);
    sortWords(wordFrequencies);
    printWords(wordFrequencies);
    fclose(file);
    return 0;
}