//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

bool compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b) > 0;
}

void countWords(char *text, WordFrequency *wordFrequencies) {
    char word[MAX_WORD_LENGTH];
    int wordLength = 0;
    bool inWord = false;

    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (!inWord) {
                inWord = true;
                word[wordLength++] = tolower(text[i]);
            }
        } else {
            if (inWord) {
                word[wordLength] = '\0';
                qsort(wordFrequencies, MAX_WORDS, sizeof(WordFrequency), compareWords);
                for (int j = 0; j < MAX_WORDS; j++) {
                    if (strcmp(wordFrequencies[j].word, word) == 0) {
                        wordFrequencies[j].count++;
                        break;
                    } else if (j == MAX_WORDS - 1) {
                        if (wordFrequencies[j].count == 0) {
                            strcpy(wordFrequencies[j].word, word);
                            wordFrequencies[j].count = 1;
                        } else {
                            printf("Error: Maximum number of words reached.\n");
                            exit(1);
                        }
                    }
                }
                inWord = false;
                wordLength = 0;
            }
        }
    }
}

void printWordFrequencies(WordFrequency *wordFrequencies) {
    qsort(wordFrequencies, MAX_WORDS, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < MAX_WORDS; i++) {
        if (wordFrequencies[i].count > 0) {
            printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
        }
    }
}

int main() {
    char text[1000000];
    WordFrequency wordFrequencies[MAX_WORDS];

    printf("Enter text:\n");
    fgets(text, sizeof(text), stdin);

    countWords(text, wordFrequencies);
    printWordFrequencies(wordFrequencies);

    return 0;
}