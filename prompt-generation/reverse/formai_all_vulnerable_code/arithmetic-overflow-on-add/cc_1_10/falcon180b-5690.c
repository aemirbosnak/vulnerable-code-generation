//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: invasive
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_SIZE 50
#define MAX_WORDS 100

typedef struct {
    char word[MAX_WORD_SIZE];
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*)a;
    const WordFrequency* wordB = (const WordFrequency*)b;

    return strcmp(wordA->word, wordB->word);
}

void readWords(char* filename, WordFrequency* words) {
    FILE* inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_SIZE];
    while (fscanf(inputFile, "%s", word)!= EOF) {
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        int found = 0;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].frequency++;
                found = 1;
                break;
            }
        }

        if (!found) {
            for (int i = 0; i < MAX_WORDS - 1; i++) {
                if (strcmp(words[i].word, "") == 0) {
                    strcpy(words[i].word, word);
                    words[i].frequency = 1;
                    break;
                }
            }
        }
    }

    fclose(inputFile);
}

void displayWords(WordFrequency* words) {
    qsort(words, MAX_WORDS, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    WordFrequency words[MAX_WORDS];
    readWords(argv[1], words);
    displayWords(words);

    return 0;
}