//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readFile(FILE* file, WordFrequency* words) {
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        int i = 0;
        while (line[i]!= '\0') {
            if (isalpha(line[i])) {
                char* word = &line[i];
                while (isalpha(line[i])) {
                    i++;
                }
                line[i] = '\0';
                strcpy(words[getWordIndex(words, word)].word, word);
                words[getWordIndex(words, word)].count++;
                i--;
            }
            i++;
        }
    }
}

int getWordIndex(WordFrequency* words, char* word) {
    int index = 0;
    while (index < MAX_WORDS && strcmp(words[index].word, word)!= 0) {
        index++;
    }
    return index;
}

void printFrequencies(WordFrequency* words, int numWords) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        if (words[i].count > 0) {
            printf("%s\t%d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    readFile(file, words);

    int numWords = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            numWords++;
        }
    }

    printFrequencies(words, numWords);

    fclose(file);
    return 0;
}