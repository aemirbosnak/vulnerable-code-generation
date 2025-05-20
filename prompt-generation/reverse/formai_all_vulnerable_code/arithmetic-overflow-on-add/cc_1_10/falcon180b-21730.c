//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readFile(FILE* file, WordCount* wordCounts) {
    char ch;
    int wordLen = 0;
    char word[MAX_WORD_LENGTH];

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word[wordLen++] = tolower(ch);
        } else if (wordLen > 0) {
            word[wordLen] = '\0';
            for (int i = 0; i < MAX_WORDS; i++) {
                if (strcmp(wordCounts[i].word, word) == 0) {
                    wordCounts[i].count++;
                    break;
                } else if (i == MAX_WORDS - 1) {
                    // If no match found, add new word
                    strcpy(wordCounts[i].word, word);
                    wordCounts[i].count = 1;
                }
            }
            wordLen = 0;
        }
    }

    if (wordLen > 0) {
        word[wordLen] = '\0';
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(wordCounts[i].word, word) == 0) {
                wordCounts[i].count++;
                break;
            } else if (i == MAX_WORDS - 1) {
                // If no match found, add new word
                strcpy(wordCounts[i].word, word);
                wordCounts[i].count = 1;
            }
        }
    }
}

void printWordCounts(WordCount* wordCounts) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (wordCounts[i].count > 0) {
            printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }
}

int main() {
    FILE* file;
    WordCount wordCounts[MAX_WORDS];

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    readFile(file, wordCounts);
    fclose(file);

    printWordCounts(wordCounts);

    return 0;
}