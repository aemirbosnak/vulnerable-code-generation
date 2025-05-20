//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

bool isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void readFile(char* fileName, WordFrequency* wordFrequencies) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", fileName);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int wordLength = 0;
    int wordCount = 0;

    while ((fscanf(file, "%s", word))!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            if (!isAlpha(word[i])) {
                word[i] = '\0';
                break;
            }
        }
        wordLength = strlen(word);

        int index = hash(word, wordLength);
        if (wordFrequencies[index].count == 0) {
            strcpy(wordFrequencies[index].word, word);
            wordFrequencies[index].count = 1;
        } else {
            wordFrequencies[index].count++;
        }

        wordCount++;
    }

    fclose(file);
}

int hash(char* word, int wordLength) {
    int sum = 0;
    for (int i = 0; i < wordLength; i++) {
        sum += word[i];
    }
    return sum % MAX_WORDS;
}

void printFrequencies(WordFrequency* wordFrequencies) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (wordFrequencies[i].count > 0) {
            printf("%s\t%d\n", wordFrequencies[i].word, wordFrequencies[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    WordFrequency wordFrequencies[MAX_WORDS];
    readFile(argv[1], wordFrequencies);

    printFrequencies(wordFrequencies);

    return 0;
}